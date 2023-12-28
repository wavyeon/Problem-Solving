test = int(input())
for i in range(test):
    repeat, code = input().split()
    result = ""
    for j in code:
        for k in range(int(repeat)):
            result += j
    print(result)