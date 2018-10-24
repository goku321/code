#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        ll scores[n];

        for(int i=0; i<n; ++i)
            cin >> scores[i];
        
        int ans = k;
        sort(scores, scores+n);

        for(int i=n-k; i>=0; --i) {
            if(scores[i] == scores[i-1])
                ++ans;
            else
                break;
        }

        cout << ans << endl;
    }
}