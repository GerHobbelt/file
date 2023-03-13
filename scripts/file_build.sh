##Clone repo
gh repo clone fixxxer23/file

##Build native
cd file
autoreconf -i
./configure
make

##Copy native binaries files to native directory
mkdir native
cp ./src/file ./native/file
cd native
mkdir .libs
cd ..
cp -Lr ./src/.libs/file ./native/.libs/file
cp -Lr ./src/.libs/libmagic.so.* ./native/.libs/

##Build WASM
# Run emconfigure with the normal configure command as an argument.
emconfigure ./configure

##patch script to use native file to compile magic.mgc
sed -i 's/file\/src\/.libs/file\/native\/.libs/g' ./native/file

##Compile WASM
mkdir wasm

source ./build_wasm.sh


