FROM	nixos/nix

RUN		nix-channel --update

RUN		nix-env -iA cmake gcc sfml flac tbb gbenchmark openal

RUN		mkdir Gomoku

COPY	./ /Gomoku

WORKDIR	/Gomoku