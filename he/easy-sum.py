n = int(input())

a = list(map(int, input().split()))

m = int(input())

c = list(map(int, input().split()))

len_c = len(c)

hash_c = [0] * 101

for i in range(len_c):
    hash_c[c[i]] = 1

max_c = max(c)
result = [0] * 101

for i in a:
    for j in range(1, max_c):
        if hash_c[i+j]:
            result[j] = 1

len_result = len(result)

for i in range(1, len_result):
    for j in a:
        if i+j > 100:
            continue
        if result[i] and hash_c[i+j] == 0:
            result[i] = 0

for i in range(len_result):
    if result[i]:
        print(i, end=' ')

print()