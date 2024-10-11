<style>
	pre {
		background-color: #f8f8f8;
		border: 1px solid #ddd;
		border-radius: 4px;
		padding: 10px;
		overflow: auto;
	}

	code {
		font-family: 'Courier New', Courier, monospace;
		color: #d63384;
	}

	.language-docker {
		color: #007acc;
	}
</style>

# Docker

<br>

This bonus aims to create a Docker that reproduces a basic Unix environment with only the necessaries dependencies installed to prove that the project can be run on any machine.

<br>

## Dockerfile

---

<br>

Let's breakdown the Dockerfile. 

<br>

First, we set the base image for the Docker:

<br>

```Dockerfile
FROM ubuntu:22.04
```

Then, we install 

<br>

## Dependencies

---

<br>

Here's the list of the installed dependencies:

<br>

- **CMake:** configures and build complex projects in C/C++, such as software libraries or applications
- **g++:** compiles C++ source code into machine-executable binaries
- **build-essential:** provides the fundamental tools for building software from source
- **libsndfile1:** library for reading and writing files containing sampled audio data
- **libsndfile1-dev:** includes header files and other development resources necessary for compiling programs that use `libsndfile1`
- **libopenal-dev:** development files for OpenAL (Open Audio Library), a cross-platform API for rendering 3D audio
- **libvorbis-dev:** development files for the Ogg Vorbis audio codec
- **libogg-dev:** development libraries for the Ogg multimedia container format
- **libxrandr-dev:** development files for `libXrandr`, a library for configuring and managing the screen resolution and output on X11-based systems
- **libxcursor-dev:** development files for `libXcursor`, a library for managing and loading X11 cursors
- **libx11-dev:** development files for libX11, the core X11 client library
- **wget:** command-line utility to download files from the web
- **xterm:** terminal emulator for the X Window System, provides a command-line interface within an X11 environment
- **alsa-base:** configures ALSA (Advanced Linux Sound Architecture), the sound system used on most Linux distributions
- **alsa-utils:** collection of command-line utilities for managing and configuring ALSA sound drivers
- **libasound2:** provides audio and MIDI functionality on Linux systems
- **libasound2-dev:** contains the header files and additional resources necessary for compiling programs that need to interface directly with ALSA
- **pulseaudio:** provides a higher-level interface for managing audio on Linux systems

<br>

It may seem like a lot but these dependencies are very basic ones.

<br>

We also install the `libFLAC`, a library that implements the Free Lossless Audio Codec (FLAC). It is used by programs to encode or decode audio files in the FLAC format. We need it because the SFML (Simple and Fast Multimedia Library), that we use as graphic library for this project, needs the `libFLAC` to handle FLAC decoding.

<br>

## How it works?

---

<br>

