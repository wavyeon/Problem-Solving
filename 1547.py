ball = [0,1,0,0]
n = int(input())

for i in range(n):
    x, y = map(int, input().split)
    ball[x], ball[y] = ball[y], ball[x] ## python에서 swap하기

print(ball.index(1)) ## 1의 위치 찾기