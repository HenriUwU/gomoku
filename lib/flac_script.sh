cd /tmp
wget https://ftp.osuosl.org/pub/xiph/releases/flac/flac-1.4.3.tar.xz
tar -xvf flac-1.4.3.tar.xz
cd flac-1.4.3
./configure --prefix=$HOME/local
make
make install
export LD_LIBRARY_PATH=$HOME/local/lib:$LD_LIBRARY_PATH
killall -3 gnome-shell
rm -rf flac-1.4.3.tar.xz
rm -rf flac-1.4.3