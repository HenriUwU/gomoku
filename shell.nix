{
	pkgs ? import <nixpkgs> { }
}:

pkgs.mkShell {
	nativeBuildInputs = with pkgs; [
		gcc
		stdenv
		cmake
		sfml
		flac
		tbb
		gbenchmark
		openal
		ninja
		mesa-demos
		xvfb-run
		drawio-headless
		xorg.xorgserver
		vulkan-tools
		libdrm
	];

	buildInputs = with pkgs; [
		sfml
		flac
		openal
		mesa
		mesa_drivers
		libglvnd
		xorg.libX11
		xorg.libxcb
		xorg.libXrandr
		xorg.libXi
		xorg.libXext
		xorg.libXrender
		xorg.libXtst
		libGLU
	];

	shellHook = ''
		export LIBGL_DEBUG=verbose
		export DISPLAY=:99
		export LD_LIBRARY_PATH=${pkgs.sfml}/lib:${pkgs.mesa}/lib:$LD_LIBRARY_PATH
		export PATH=${pkgs.sfml}/bin:$PATH
	'';
}