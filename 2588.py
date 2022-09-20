# first = int(input())
# second = int(input())

# third = first * (second % 10)
# fourth = first * (int(second % 100 / 10))
# fifth = first * (int(second % 1000 / 100))

# print(third)
# print(fourth)
# print(fifth)

# print(first * second)

A = int(input())
B = input()

AxB2 = A * int(B[2])
AxB1 = A * int(B[1])
AxB0 = A * int(B[0])
AxB = A * int(B)

print(AxB2, AxB1, AxB0, AxB, sep='\n')