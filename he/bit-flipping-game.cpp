#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

string bitStrings[1000006];
int hashMap[1000006];

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i)
        cin >> bitStrings[i];
    
    memset(hashMap, 0, sizeof(hashMap));
    
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < bitStrings[i].length(); ++j) {
            if(bitStrings[i][j] == '1')
                hashMap[j] = 1;
        }
    
    ll cnt = 0;
    for(int i = 0; i < 1000006; ++i) {
        if(hashMap[i])
            ++cnt;
    }

    if(cnt%2)
        cout << 'A' << endl << cnt << endl;
    else
        cout << 'B' << endl << cnt << endl;

    return 0;
}