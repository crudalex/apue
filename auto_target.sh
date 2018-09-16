#!/bin/bash

for i in `ls *.c`; do 
  echo "add_executable($(basename $i .c) $i)"
done  
