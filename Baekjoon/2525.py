hour, minute = map(int, input().split())
time = int(input())
finishMinute = (minute + time) % 60
finishHour = int((hour + (minute + time) / 60) % 24)
print(finishHour, finishMinute)