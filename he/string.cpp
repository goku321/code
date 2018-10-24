#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int hashMap[26];

void initHashMap(string s) {
    memset(hashMap, 0, sizeof(hashMap));
    for(int i = 0; i < s.length(); ++i)
        hashMap[s[i]-'a'] += 1;
}

int main() {
    int n;
    scanf("%d", &n);

    string s;
    cin >> s;

    initHashMap(s);
    sort(hashMap, hashMap+26);

    for(int i = 25; i > -1; ++i) {
        if(hashMap[i]) {
            cout << n - hashMap[i] << endl;
            break;
        }
    }

    return 0;
}