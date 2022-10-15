import sys
input = sys.stdin.readline

test = int(input())
for i in range(test):
    line = input().split()
    result = 0
    for j in line:
        if j == '@':
            result *= 3
        elif j == '%':
            result += 5
        elif j == '#':
            result -= 7
        else: 
            result = float(j)
    print("%.2f" % result)