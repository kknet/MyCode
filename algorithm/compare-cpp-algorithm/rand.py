#! /usr/bin/env python3

import random

n = random.randint(1,100000)
n = 10
m = 10
k = random.randint(1,m+n)
print(n,m,k,sep = " ")
for i in range(0,n):
    print(random.randint(0,9),end = " ")
print("")
for i in range(0,m):
    print(random.randint(0,9),end = " ")
print("")