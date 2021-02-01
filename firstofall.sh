#! /bin/bash

gcc ./src/connection.cpp ./src/defines.h -o connection
gcc ./src/newhotspot.cpp ./src/defines.h -o newhotspot
gcc ./src/reusing.ccp ./src/defines.h -o reusing
