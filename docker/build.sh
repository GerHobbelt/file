#!/bin/bash
cd ../
mkdir -p bins/x86
mkdir -p bins/i686

echo Building x86_64...
docker build . -f docker/x86_64/Dockerfile -t x86-64-linux
echo Running...
CID=$(docker run --name x86linux -itd x86-64-linux)
echo Copying...
docker cp x86linux:/usr/local/lib/libmagic.la bins/x86
docker cp x86linux:/usr/local/lib/libmagic.so bins/x86
docker cp x86linux:/usr/local/lib/libmagic.so.1 bins/x86
docker cp x86linux:/usr/local/lib/libmagic.so.1.0.0 bins/x86
echo Removing...
docker kill $CID
docker rm $CID


echo Building i686...
docker build . -f docker/i686/Dockerfile -t i686-linux
echo Running...
CID=$(docker run --name i686linux -itd i686-linux)
echo Copying...
docker cp i686linux:/usr/local/lib/libmagic.la bins/i686
docker cp i686linux:/usr/local/lib/libmagic.so bins/i686
docker cp i686linux:/usr/local/lib/libmagic.so.1 bins/i686
docker cp i686linux:/usr/local/lib/libmagic.so.1.0.0 bins/i686
echo Removing...
docker kill $CID
docker rm $CID

echo Done!