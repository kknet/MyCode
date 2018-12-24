#! /usr/bin/bash

g++ std.cpp -o std
g++ me.cpp -o me 
while :
do
    python3 rand.py > data
    ./me < data > me.out
    ./std < data > std.out
    diff -Bb me.out std.out > different.tmp
    if   test -s different.tmp 
    then
        cat different.tmp
        break
    else
        echo "OK!"
    fi
done