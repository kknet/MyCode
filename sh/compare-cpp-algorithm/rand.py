#! /usr/bin/env python3

import random

n = random.randint(1,1000)
print(n)
for i in range(0,n):
    print(random.randint(1,100),end = " ")
print("")