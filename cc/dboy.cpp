#include<iostream>
#include<cstring>

using namespace std;

int h[1005], k[1005], dp[1005];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i)
            cin >> h[i];
        
        //memset(dp, 2000, sizeof(dp));
        memset(k, 0, sizeof(k));


        int inp;
        for(int i = 0; i < n; ++i) {
            cin >> inp;
            k[inp] = 1;
        }

        for(int i = 1; i <= 1004; ++i)
            dp[i] = 2000;

        for(int i = 1; i <= 1004; ++i) {
            if(k[i])
                dp[i] = 1;
            else {
                for(int m = 1, n = i-1; m <= n; ++m, --n) {
                    if(m+n == i) {
                        //cout << "star" << dp[i] << " " << dp[m]+dp[n] << endl;
                        dp[i] = min(dp[i], dp[m]+dp[n]);
                    }
                }
            }
        }

        /*for(int i = 1; i <= 8; ++i)
            cout << dp[i] << " ";
        */
        int ans = 0;
        for(int i = 0; i < n; ++i)
            ans += dp[2*h[i]];
        
        cout << ans << endl;
    }

    return 0;
}