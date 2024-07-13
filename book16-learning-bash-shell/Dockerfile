# Use the latest Ubuntu image
FROM ubuntu:latest

# Update package list and install some packages
RUN apt update && apt install -y \
    curl \
    wget \
    vim \
    sudo \
    man-db \
    netpbm \
    && apt clean

# Unminimize the system to allow interactive shell usage
RUN yes | unminimize

# Create a new user 'mbassale' with a home directory
RUN useradd -m -s /bin/bash mbassale

# Add 'mbassale' to the sudo group (optional)
RUN usermod -aG sudo mbassale

# Set password for the 'mbassale' user (optional)
RUN echo 'mbassale:password' | chpasswd

USER mbassale

# Set the working directory to the user's home directory
WORKDIR /home/mbassale

# Set the default command to run when starting the container
CMD ["/bin/bash"]
