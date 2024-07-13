let
	pkgs = import <nixpkgs> {};
in

pkgs.mkShellNoCC {
	packages = with pkgs; [
		cmake
		gcc
		sfml
		flac
		tbb
		gbenchmark
		openal
	];
}