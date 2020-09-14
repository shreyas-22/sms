#! /bin/bash
if [ ! -d bin ]; then
    mkdir -p bin/ 
fi
gcc src/studentid.c -o bin/sms -I src/inc
