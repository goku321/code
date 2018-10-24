#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

typedef long long ll;

ll arr[100005];

int main() {
    int n, k;

    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> arr[i];

    ll sum = 0, elem = 0;
    int low = 0, high = n-1, queue = 0;
    for(int i = 0; i < k; ++i)
        sum += arr[i];
    ll maxSum = sum;
    int j = n-1;
    for(int i = k-1, j = n-1; i > -1 && j > (n-k); --i, --j) {
        sum -= arr[i];
        sum += arr[j];
        maxSum = max(sum, maxSum);
    }

    cout << maxSum << endl;

    return 0;
}