#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long long ll;
#define MODL 1000000007

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

ll prod(ll a, ll b, ll mod) {
    ll res = 0;
    a = a % mod;

    while(b) {
        if(b & 1)
            res = (res + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }

    return res;
}

ll modularExpo(ll x, ll y, ll mod) {
    ll res = 1;
    x = x % mod;

    while(y > 0) {
        // if y is odd
        if(y & 1)
            res = prod(res, x, mod);
        
        x = prod(x, x, mod);
        y >>= 1;
    }

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    ll a, b, n;
    while(t--) {
        cin >> a >> b >> n;

        ll an = modularExpo(a, n, MODL);
        ll bn = modularExpo(b, n, MODL);

        if(a==b) {
            cout << (an+bn) % MODL << endl;
            continue;
        }
        ll ann = modularExpo(a, n, a-b);
        ll bnn = modularExpo(b, n, a-b);
        ll ans = gcd((ann+bnn)%(a-b), a-b);
        cout << ans%MODL << endl;
    }

    return 0;
}