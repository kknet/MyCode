#! /usr/bin/env python3

import random

n = 10
alpha = ['0','1','2','3','4','5','6','7','8','9','#']
for i in range(n):
    string = ""
    lenth = random.randint(1,10)
    for j in range(lenth):
        string = string + alpha[random.randint(0,10)]
    print(string)
