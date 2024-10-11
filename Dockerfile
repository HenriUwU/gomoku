# Set base image
FROM	ubuntu:22.04

# Update and upgrade
RUN		apt update && apt upgrade -y

# Install dependencies
RUN		apt install cmake g++ build-essential -y \
		libsndfile1 \
		libsndfile1-dev \
		libopenal-dev \
		libvorbis-dev \
		libogg-dev \
		libxrandr-dev \
		libxcursor-dev \
		libx11-dev \
		wget \
		xterm \
		alsa-base \
		alsa-utils \
		libasound2 \
		libasound2-dev \
		pulseaudio \
		&& rm -rf /var/lib/apt/lists/*

# Download and install libFLAC
RUN		wget http://ftp.de.debian.org/debian/pool/main/f/flac/libflac12_1.4.2+ds-2_amd64.deb && \
		dpkg -i libflac12_1.4.2+ds-2_amd64.deb && \
		apt-get install -f -y

# Clean up
RUN		rm libflac12_1.4.2+ds-2_amd64.deb

# Create the project directory
RUN		mkdir /Gomoku

# Copy the source code, including the SFML library, to the container
COPY	. /Gomoku

# Set the working directory to /Gomoku
WORKDIR	/Gomoku

# Set CMAKE_PREFIX_PATH to point to SFML libraries
ENV		CMAKE_PREFIX_PATH="/Gomoku/lib/SFML/lib/cmake/SFML"

# Set the SFML_DIR variable for find_package
ENV		SFML_DIR="/Gomoku/lib/SFML/lib/cmake/SFML"

# Create a build directory and run CMake
RUN		rm -rf build && mkdir build && cd build && cmake .. -DSNDFILE_INC_DIR=/usr/lib/x86_64-linux-gnu/ -DSNDFILE_LIB_DIR=/usr/include/ && make

# SET XHOST ON THE HOST MACHINE: xhost +local:
# BUILD DOCKER: docker build --no-cache -t gomoku .
# ENTER DOCKER: docker run -it --net=host --env="DISPLAY" -v /tmp/.X11-unix:/tmp/.X11-unix:rw --device /dev/snd gomoku ./Gomoku