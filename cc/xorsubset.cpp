#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

int arr[1005];
bool dp[1005][1025];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i=0; i<n; ++i)
            cin >> arr[i];
        
        //int dp[n+1][1024];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for(int i=1; i<=n; ++i)
            for(int j=0; j<1024; ++j) {
                dp[i][j] = dp[i-1][j] | dp[i-1][arr[i]^j];
            }
        
        ll maxAns = k;

        for(ll i=1; i<1024; ++i)
            maxAns = max(dp[n][i]*(i^k), maxAns);
        
        cout << maxAns << endl;
    }

    return 0;
}