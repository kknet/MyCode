import random

data = []
ans = []

def multipy():
    sum = 1
    for each in data:
        sum = sum*each
    ans.append((len(data),sum))
    return

def compute(number):
    if number<1:
        multipy()
    for i in range(1,number+1):
        data.append(i)
        compute(number - i)
        data.pop()
    return

if __name__ == '__main__':
    compute(15)
    ans = list(set(ans))
    ans.sort(key = lambda x:x[0])
    for each in ans:
        print(each[0],each[1],sep = ' ')
    
    