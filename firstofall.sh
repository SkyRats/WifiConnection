#! /bin/bash

gcc ./src/connection.c ./src/commonheader.h -o connection
gcc ./src/newhotspot.c ./src/commonheader.h -o newhotspot
gcc ./src/reusing.c ./src/commonheader.h -o reusing
