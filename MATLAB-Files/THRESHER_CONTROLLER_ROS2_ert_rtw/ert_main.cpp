#include <stdio.h>
#include <stdlib.h>
#include "THRESHER_CONTROLLER_ROS2.h"
#include "THRESHER_CONTROLLER_ROS2_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "linuxinitialize.h"
#define UNUSED(x)                      x = x

static THRESHER_CONTROLLER_ROS2 THRESHER_CONTROLLER_ROS2_Obj;/* Instance of model class */

#define NAMELEN                        16

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
sem_t stopSem;
sem_t baserateTaskSem;
sem_t subrateTaskSem[1];
int taskId[1];
pthread_t schedulerThread;
pthread_t baseRateThread;
void *threadJoinStatus;
int terminatingmodel = 0;
pthread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int_T tid = *((int_T *) arg);
  int_T subRateId;
  subRateId = tid + 1;
  while (runModel) {
    sem_wait(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;

#ifdef MW_RTOS_DEBUG

    printf(" -subrate task %d semaphore received\n", subRateId);

#endif

    switch (subRateId) {
     case 1:
      THRESHER_CONTROLLER_ROS2_Obj.step1();
      break;

     default:
      break;
    }
  }

  pthread_exit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(THRESHER_CONTROLLER_ROS2_Obj.getRTM()) == (NULL));
  while (runModel) {
    sem_wait(&baserateTaskSem);

#ifdef MW_RTOS_DEBUG

    printf("*base rate task semaphore received\n");
    fflush(stdout);

#endif

    if (rtmStepTask(THRESHER_CONTROLLER_ROS2_Obj.getRTM(), 1)
        ) {
      sem_post(&subrateTaskSem[0]);
    }

    THRESHER_CONTROLLER_ROS2_Obj.step0();
    stopRequested = !((rtmGetErrorStatus(THRESHER_CONTROLLER_ROS2_Obj.getRTM()) ==
                       (NULL)));
    runModel = !stopRequested;
  }

  terminateTask(arg);
  pthread_exit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(THRESHER_CONTROLLER_ROS2_Obj.getRTM(), "stopping the model");
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(sem_post(&subrateTaskSem[i]), 0, "sem_post");
      CHECK_STATUS(sem_destroy(&subrateTaskSem[i]), 0, "sem_destroy");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(pthread_join(subRateThread[i], &threadJoinStatus), 0,
                   "pthread_join");
    }

    runModel = 0;
  }

  /* Terminate model */
  THRESHER_CONTROLLER_ROS2_Obj.terminate();
  sem_post(&stopSem);
  return NULL;
}

int main(int argc, char **argv)
{
  subratePriority[0] = 41;
  rtmSetErrorStatus(THRESHER_CONTROLLER_ROS2_Obj.getRTM(), 0);

  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  THRESHER_CONTROLLER_ROS2_Obj.initialize();

  /* Call RTOS Initialization function */
  myRTOSInit(0.05, 1);

  /* Wait for stop semaphore */
  sem_wait(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(sem_destroy(&timerTaskSem[i]), 0, "sem_destroy");
    }
  }

#endif

  return 0;
}
