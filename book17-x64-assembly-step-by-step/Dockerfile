# Use the x86_64 architecture
FROM --platform=linux/amd64 ubuntu:24.04

# Prevent interactive prompt during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update and install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    nasm \
    gdb \
    sudo \
    software-properties-common

# Unminimize the Ubuntu image to get basic utilities
RUN yes | unminimize

# Set bash as the default shell
SHELL ["/bin/bash", "-c"]

# Create a user for non-root operations
RUN useradd -m -s /bin/bash mbassale && echo "mbassale ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Switch to the new user
USER mbassale

# Set the working directory
WORKDIR /home/mbassale

# Default command
CMD ["/bin/bash"]

