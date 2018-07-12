t = int(input())

for i in range(t):
    n, m = map(int, input().split())
    sequence = list(map(int, input().split()))

    cnt = 0

    for num in sequence:
        if num % m == 0:
            cnt += 1
    
    good_sequences = pow(2, cnt) - 1

    print(good_sequences)