# Thresher AUV
## URI Hydrobotics

## Quickstart (Dev)

### Prerequisites
- [Docker Desktop](https://docs.docker.com/get-docker/) (Linux users can install `docker` + `docker-compose` packages)
- Windows users: Ensure WSL2 backend is enabled in Docker Desktop
- GNU Make (Windows only — Linux/macOS already include it)
- The docker container itself is ~5.5 gigabytes

The dev container is built using a larger ROS framework (ROS Humble Desktop), providing some additional simulation and front-end packages you wouldn't necessarily need on the Thresher AUV. 

1. Install [Docker](https://docs.docker.com/get-docker/)

2. Clone this repository:
    ```bash
    git clone https://github.com/URI-Hydrobotics-Team/Thresher.git
    cd Thresher
    ```

    - !!Windows Users!! You may need to install GNU Make to use the Makefile
        1. Install GNU Make
            
            ```bash
            winget install GnuWin32.Make
            ```

        2. Add to your PATH

            1. Open Start Menu --> Edit system environment variables
            2. System Properties --> Environment Variables
            3. Under system (or user) variables select `PATH` --> Edit
            4. Paste the path to where the `make.exe` file is located (usually `C:\Program Files (x86)\GnuWin32\bin`)
            5. Test by opening a new terminal and running `make --version`

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

Regularly run `sudo apt update`, `sudo apt upgrade`

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

## Running the basic Talker/Listener Demo

1. Launch the talker (while within your container)
```bash
cd /auv_ws
source install/setup.bash #Remember to always setup the bash file
ros2 run demo_nodes_cpp talker
```

2. In a separate terminal connect to the currently running container
    1. Look for the name of the existing container with `docker ps`

        It should look like this:
        ```bash
        CONTAINER ID    IMAGE               COMMAND                 CREATED         STATUS          PORTS    NAMES
        <container id>  thresher-ros2-dev   "/ros_entrypoint.sh …"  _ minutes ago   Up _ minutes    <ports>  <names>
        ```
    
    2. Access the existing container:
        ```bash
        docker exec -it <container name> bash
        ```

3. Run the listener in your 2nd terminal
```bash
cd /auv_ws
source install/setup.bash #Remember to always setup the bash file
ros2 run demo_nodes_cpp listener
```

### Note

There's a way to run this in 2 separate containers and still have the listener receive the messages from the talker.