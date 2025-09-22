# Thresher AUV
## URI Hydrobotics

## Quickstart (Dev)
Note: The dev container is minimum of ~5.5 Gbs of storage utilization.

The dev container is built using a larger ROS framework (ROS Humble Desktop), providing some additional simulation and front-end packages you wouldn't necessarily need on the Thresher AUV. 

1. Install [Docker](https://docs.docker.com/get-docker/)

2. Clone this repository:
    ```bash
    git clone https://github.com/URI-Hydrobotics-Team/Thresher.git
    cd Thresher
    ```


    - !!Windows Users!! You may need to isntall  GNU Make to use the Makefile
        1. Install GNU Make
            
            ```bash
            winget install GnuWin32.Make
            ```

        2. Add to your PATH

            1. Open Start Menu --> Edit system environment variables
            2. System Properties --> Environment Varialbes
            3. Under system (or user) variables select `PATH` --> Edit
            4. Paste the path to where the `make.exe` file is located (usually `C:\Program Files (x86)\GnuWin32\bin`)
            5. Test by openeing a new terminal and running `make --version`

3. Build the dev container:
    ```bash
    make build-dev
    ```

4. Run the container:
    ```bash
    make run-dev
    ```

4. Build your ROS workspace:
    ```bash
    cd ~/auv_ws
    colcon build
    source install/setup.bash
    ros2 launch <package_name> <launch_file>
    ```

## Quickstart Runtime

On AUV computer

1. Run the installation bash script (it should only work on Ubuntu version 22.04)
    ```bash
    ./scripts/install_runtime.sh
    ```

2. Build the ROS workspace
    ```bash
    cd ~/auv_ws
    colcon build
    source install/setup.bash
    ros2 launch <package_name> <launch_file>
    ```