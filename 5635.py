li = []
for _ in range(int(input())):
    n, d, m, y = input().split()
    li.append([n, int(d), int(m), int(y)])
li.sort(key=lambda x:(x[3],x[2],x[1]))
print(li[-1][0])
print(li[0][0])