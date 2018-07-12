t = int(input())

for i in range(t):
    s = input()
    sorted_string = ''.join(sorted(s, reverse=True))
    
    cnt = 0
    min_cnt = 0

    for j in range(len(s)):
        k = j + 1
        while k < len(s):
            if ord(s[j]) < ord(s[k]):
                min_cnt = min_cnt + 1
            k = k + 1

    for j in range(len(s)):
        cnt = cnt + abs(ord(s[j]) - ord(sorted_string[j]))
    
    if cnt < min_cnt:
        print(cnt)
    else:
        print(min_cnt)