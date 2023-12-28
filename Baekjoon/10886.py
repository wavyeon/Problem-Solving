vote = int(input())
cute = 0

for _ in range(vote):
    if int(input()) == 1:
        cute += 1

if cute > vote // 2:
    print("Junhee is cute!")
else:
    print("Junhee is not cute!")