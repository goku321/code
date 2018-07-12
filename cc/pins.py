from fractions import gcd

t = int(input())

for i in range(t):
    N = int(input())
    P = 1
    power = 0
    if N % 2 == 0:
        power = N - (N/2)
    else:
        power = N - ((N+1)/2)
    
    Q = str(1) + '0' * int(power)

    print(int(P), int(Q))
