# Build containers
build-dev:
	docker compose build

# Run ephemeral dev shell (cross-platform)
run-dev:
	docker compose run -it --rm ros2-dev bash

# Clean up containers, volumes, and build artifacts
clean:
	docker compose down --volumes --remove-orphans