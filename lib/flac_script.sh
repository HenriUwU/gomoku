wget https://ftp.osuosl.org/pub/xiph/releases/flac/flac-1.4.3.tar.xz
tar -xvf flac-1.4.3.tar.xz
cd flac-1.4.3
./configure --prefix=$HOME/local
make
make install
export PATH=$HOME/local/bin:$PATH
export LD_LIBRARY_PATH=$HOME/local/lib:$LD_LIBRARY_PATH
export PKG_CONFIG_PATH=$HOME/local/lib/pkgconfig:$PKG_CONFIG_PATH
cd ..
rm -rf flac-1.4.3.tar.xz
rm -rf flac-1.4.3