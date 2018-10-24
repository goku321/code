#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long ll;

int sequence[5003];
ll fact[5003];

void calculate_factorial() {
    fact[1] = 1;
    for(int i = 2; i < 5003; ++i)
        fact[i] = fact[i-1] * i;
}

int main() {
    calculate_factorial();
    int t;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        for(int i = 0; i < n; ++i)
            scanf("%d", &sequence[i]);
        
        sort(sequence, sequence+n);

        ll total_seq = fact[n]/(fact[n-k]*fact[k]);

        printf("%d", total_seq);


    }
    return 0;
}