FROM	ubuntu:jammy

RUN		apt update && apt upgrade -y

RUN		apt install build-essential wget cmake libogg-dev -y

RUN		mkdir -p Gomoku

COPY	./ /Gomoku

RUN		cd /Gomoku