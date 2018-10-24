#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[100005];
        int ans = 1;
        int save = 0;

        for(int i=0; i<n; ++i) {
            cin >> arr[i];
            if(i!=0)
                arr[i] += arr[i-1];
            if(arr[i]>=(n-1-i))
                if(!save)
                    save = i;
        }
        
        /*for(int i=1; i<n; ++i)
            arr[i] += arr[i-1];
        
        int ans = 1;*/

        for(int j=0; j<=save; ++j) {
            if(arr[j]+j > save)
                break;
            else {
                j = arr[j] + j;
                ++ans;
            }
        }

        cout << ans << endl;
    }
    return 0;
}