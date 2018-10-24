char_hash = [0] * 26
n = 0

def y_cnt(s):
    cnt = 0
    for i in range(n-1, -1, -1):
        temp = ord(s[i]) - 97
        for j in range(temp):
            cnt = cnt + char_hash[j]
        char_hash[temp] = char_hash[temp] - 1
	
    return cnt

def init_cnt(s):
    for i in range(n):
        char_hash[ord(s[i])-97] = char_hash[ord(s[i])-97] + 1
 

t = int(input())
 
for i in range(t):
    s = input()
    n = len(s)

    init_cnt(s)
    
    cnt = y_cnt(s)
    min_cnt = 9999999999999999999999999

    char = 26

    dp1 = [[0 for x in range(100003)] for y in range(char)]
    dp2 = [[0 for x in range(100003)] for y in range(char)]

    # Filling in dp1 matrix
    for i in range(26):
        temp = ord(s[0]) - 97
        if temp < i:
            dp1[i][0] = 1
        
        for j in range(1, n):
            temp = ord(s[j]) - 97
            if i > temp:
                dp1[i][j] = dp1[i][j-1] + 1
            else:
                dp1[i][j] = dp1[i][j-1]
    
    # Filling in dp2 matrix
    for i in range(26):
        temp = ord(s[n-1]) - 97
        if temp > i:
            dp2[i][n-1] = 1

        for j in range(n-2, -1, -1):
            temp = ord(s[j]) - 97
            if i < temp:
                dp2[i][j] = dp2[i][j+1] + 1
            else:
                dp2[i][j] = dp2[i][j+1]
    
    for i in range(n):
        ini_cnt = cnt
        temp = ord(s[i]) - 97
        if i == 0:
            ini_cnt = ini_cnt - dp2[temp][i+1]
            for j in range(26):
                x = abs(j-temp)
                temp_cnt = dp2[j][i+1]
                min_cnt = min(ini_cnt+x+temp_cnt, min_cnt)
        elif i == n-1:
            ini_cnt = ini_cnt - dp1[temp][i-1]
            for j in range(26):
                x = abs(j-temp)
                temp_cnt = dp1[j][i-1]
                min_cnt = min(ini_cnt+temp_cnt+x, min_cnt)
        else:
            ini_cnt = ini_cnt - dp1[temp][i-1] - dp2[temp][i+1]
            for j in range(26):
                x = abs(j-temp)
                temp_cnt = dp1[j][i-1]+dp2[j][i+1]
                min_cnt = min(ini_cnt+temp_cnt+x, min_cnt)
    	
    print(min_cnt)