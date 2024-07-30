{
	pkgs ? import <nixpkgs> { }
}:

pkgs.mkShell {
	nativeBuildInputs = with pkgs; [
		gcc
		stdenv
		sfml
		flac
		tbb
		gbenchmark
		openal
	];
}