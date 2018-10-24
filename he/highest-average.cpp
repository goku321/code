#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

double arr[500005], queries[500005];

ll bSearch(ll low, ll high, ll key) {
    ll mid = (low+high)/2;

    if(low == high && arr[mid] < key)
        return low+1;

    if(low > high)
        return 0;
    
    if(arr[mid] >= key)
        bSearch(low, mid-1, key);
    
    else if(arr[mid] < key && arr[mid+1] >= key)
        return mid+1;
    else
        bSearch(mid+1, high, key);
    
}

int main() {
    ll n;
    scanf("%lli", &n);

    for(ll i = 0; i < n; ++i)
        scanf("%f", &arr[i]);
    
    ll q;    
    scanf("%lli", &q);

    for(ll i = 0; i < q; ++i)
        scanf("%f", &queries[i]);
    
    sort(arr, arr+n);

    for(ll i = 1; i < n; ++i) {
        arr[i] = ((i * arr[i-1]) + arr[i]) / (i+1);
    }

    for(ll i = 0; i < q; ++i) {
        ll query = queries[i];
        cout << bSearch(0, n-1, query) << endl;
    }

    return 0;

}