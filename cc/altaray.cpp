#include<iostream>
#include<cstring>

using namespace std;

typedef long long ll;

ll arr[100005], dp[100005];

int main() {
    int t;
    cin >> t;

    while(t--) {
        ll N;
        cin >> N;

        for(int i = 0; i < N; ++i)
            cin >> arr[i];
        
        memset(dp, 0, sizeof(dp));
        
        dp[N-1] = 1;

        for(int i = N-2; i > -1; --i) {
            if(arr[i] < 0 && arr[i+1] < 0)
                dp[i] = 1;
            else if(arr[i] >= 0 && arr[i+1] >= 0)
                dp[i] = 1;
            else
                dp[i] = dp[i+1] + 1;
        }

        for(int i = 0; i < N; ++i)
            cout << dp[i] << " ";
        cout << endl;
    }

    return 0;
}