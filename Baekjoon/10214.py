n = int(input())

for i in range(n):
    yonsei_score=0
    korea_score=0
    for j in range(9):
        y, k = map(int,input().split(" ")) # 한 회당 점수 입력받음
        yonsei_score+=y
        korea_score+=k
    if yonsei_score>korea_score:
        print("Yonsei")
    elif yonsei_score<korea_score:
        print("Korea")
    else:
        print("Draw")