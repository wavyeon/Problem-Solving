numbers = [int(input()) for i in range(10)]
print(sum(numbers) // 10)
print(max(numbers, key = numbers.count)) ## max 함수의 key 값으로 count 줄 수 있음!