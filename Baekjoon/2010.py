# 속도 면에서 input()보다 sys.stdin.readline() 쓰는게 유리!
import sys

num = int(sys.stdin.readline())
sum = 1
for i in range(num):
    tempNum = int(sys.stdin.readline())
    sum+=tempNum

print(sum-num)