#! /usr/bin/bash
g++ main.cpp -o main
./main < data > out
rm -f ./main