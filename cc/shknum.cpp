#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef unsigned long ul;
typedef long long ll;

int countSetBits(ul num) {
    int count = 0;
    while(num) {
        count += num & 1;
        num >>= 1;
    }

    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        ul num;
        cin >> num;

        if(num == 1) {
            cout << 2 << endl;
            continue;
        }

        if(countSetBits(num) == 2) {
            cout << 0 << endl;
            continue;
        }

        if(countSetBits(num) == 1) {
            cout << 1 << endl;
            continue;
        }

        

        int pos = (int)(log2(num));
        //cout << pos << " " << countSetBits(num) << endl;
        ul x = 2147483648UL;
        //cout << countSetBits(x) << endl;
        ul y = x;
        //y >>= 1;

        ul minSteps = 9999999999UL;
        while(x) {
            y = x;
            y >>= 1;
        while(y) {
            ul z = x | y;
            if(z > num)
                minSteps = min((ul)abs(z-num), minSteps);
            else
                minSteps = min((ul)abs(num-z), minSteps);
            y >>= 1;
        }
        x >>= 1;
        }
        cout << minSteps << endl;
    }
}