#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

ll char_hash[26];
ll dp1[26][100003];
ll dp2[26][100003];
ll n;

ll y_cnt(string s) {
    ll cnt = 0;
    for(ll i = n-1; i >= 0; --i) {
        ll temp = s[i] - 'a';

        for(ll j = 0; j < temp; ++j) {
            cnt += char_hash[j];
        }

        char_hash[temp] -= 1;
    }

    return cnt;
}

void init_cnt(string s) {
    for(ll i = 0; i < n; ++i) {
        char_hash[s[i]-'a'] += 1;
    }
}

int main() {
    ll t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        n = s.length();

        memset(char_hash, 0, sizeof(char_hash));
        init_cnt(s);
        ll cnt = y_cnt(s);

        ll min_cnt = 9223372036854775807;

        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));

        // Filling in dp1 matrix
        for(ll i = 0; i < 26; ++i) {
            ll temp = s[0] - 'a';

            if(temp < i)
                dp1[i][0] = 1;
            
            for(ll j = 1; j < n; ++j) {
                temp = s[j] - 'a';
                if(i > temp)
                    dp1[i][j] = dp1[i][j-1] + 1;
                else
                    dp1[i][j] = dp1[i][j-1];
            }
        }

        // Filling in dp2 matrix
        for(ll i = 0; i < 26; ++i) {
            ll temp = s[n-1] - 'a';
            if(temp > i)
                dp2[i][n-1] = 1;
            
            for(ll j = n-2; j >= 0; --j) {
                ll temp = s[j] - 'a';
                if(i < temp)
                    dp2[i][j] = dp2[i][j+1] + 1;
                else
                    dp2[i][j] = dp2[i][j+1];
            }
        }

        for(ll i = 0; i < n; ++i) {
            ll ini_cnt = cnt;
            ll temp = s[i] - 'a';

            if(i == 0) {
                ini_cnt -= dp2[temp][i+1];
                for(ll j = 0; j < 26; ++j) {
                    ll x = abs(j-temp);
                    ll temp_cnt = dp2[j][i+1];
                    min_cnt = min(ini_cnt+x+temp_cnt, min_cnt);
                }
            } else if(i == n-1) {
                ini_cnt -= dp1[temp][i-1];
                for(ll j = 0; j < 26; ++j) {
                    ll x = abs(j-temp);
                    ll temp_cnt = dp1[j][i-1];
                    min_cnt = min(ini_cnt+x+temp_cnt, min_cnt);
                }
            } else {
                ini_cnt -= dp1[temp][i-1];
                ini_cnt -= dp2[temp][i+1];
                for(ll j = 0; j < 26; ++j) {
                    ll x = abs(j-temp);
                    ll temp_cnt = dp1[j][i-1]+dp2[j][i+1];
                    min_cnt = min(ini_cnt+x+temp_cnt, min_cnt);
                }
            }
        }

        cout << min_cnt << endl;
    }
}