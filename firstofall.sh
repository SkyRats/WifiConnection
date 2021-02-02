#! /bin/bash

gcc ./src/connection.c ./src/defines.h -o connection
gcc ./src/newhotspot.c ./src/defines.h -o newhotspot
gcc ./src/reusing.c ./src/defines.h -o reusing
