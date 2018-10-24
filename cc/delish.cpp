#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

ll arr[100005], minLeft[100005], maxLeft[100005], minRight[100005], maxRight[100005];

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        
        minLeft[0] = maxLeft[0] = arr[0];
        minRight[n-1] = maxRight[n-1] = arr[n-1];

        // Fill minLeft
        for(int i = 1; i < n; ++i)
            minLeft[i] = min(minLeft[i-1]+arr[i], arr[i]);
        
        // Fill maxLeft
        for(int i = 1; i < n; ++i)
            maxLeft[i] = max(maxLeft[i-1]+arr[i], arr[i]);
        
        // Fill minRight
        for(int i = n-2; i > -1; --i)
            minRight[i] = min(minRight[i+1]+arr[i], arr[i]);
        
        // Fill maxRight
        for(int i = n-2; i > -1; --i)
            maxRight[i] = max(maxRight[i+1]+arr[i], arr[i]);

        ll ans = 0;

        for(int i = 0; i < n-1; ++i) {
            ans = max(ans, abs(minLeft[i] - maxRight[i+1]));
            ans = max(ans, abs(maxLeft[i] - minRight[i+1]));
        }
        
        cout << ans << endl;
    }
}