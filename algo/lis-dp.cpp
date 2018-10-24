#include<iostream>

using namespace std;

int arr[] = {-9999, 10, 22, 9, 33, 21, 50, 41, 60, 80};

int lis(int n) {
    int dp[n+2][n+2];

    // base case
    for(int i = 0; i <= n; ++i)
        dp[i][n+1] = 0;
    
    for(int j = n; j >= 1; --j) {
        for(int i = 0; i < j; ++i) {
            if(arr[i] >= arr[j])
                dp[i][j] = dp[i][j+1];
            else
                dp[i][j] = max(dp[i][j+1], 1+dp[j][j+1]);
        }
    }

    return dp[0][1];
}

int main() {
    int n = 10;
    cout << lis(n) << endl;
}