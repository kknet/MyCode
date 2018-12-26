#! /usr/bin/env python3

import random

n = random.randint(5,500000)
n = 10
k = random.randint(5,n)
print(n , end = " ")
print(k)
for i in range(0,n):
    print(random.randint(1,100),end = " ")
print("")