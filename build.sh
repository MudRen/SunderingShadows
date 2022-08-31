#!/bin/bash

if [ ! -d "fluffos" ]; then
    git clone https://gitee.com/mudren/fluffos.git
fi
cp local_options.example fluffos/src/local_options
cd fluffos && git pull
if [ -d "build" ]; then
    rm -rf build
fi
mkdir build && cd build
cmake -DPACKAGE_DB_SQLITE=2 .. && make -j4 install
cd ../../adm/db
if [ ! -f "access.db" ]; then
    cp access.db.example access.db
fi
if [ ! -f "groups.db" ]; then
    cp groups.db.example groups.db
fi
if [ ! -f "privs.db" ]; then
    cp privs.db.example privs.db
fi
cd ../../
