# Build containers
build-dev:
	docker compose build

# Run interactive shells
run-dev:
	docker compose run --rm ros2-dev bash

# Colcon build inside dev container
colcon-dev:
	docker compose run --rm ros2-dev bash -c "cd /workspace/Thresher && colcon build"
