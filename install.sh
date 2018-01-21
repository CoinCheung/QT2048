#!/bin/bash


# install the dependencies
python3 -m pip install --user --upgrade numpy cx-freeze pyqt5

# build the c libs
make clean
make exe

mv -ivu ./build/exe*/ ./Pack
