#include<iostream>

using namespace std;

int coins[] = {2, 5, 3, 6};

int coinChangeWays(int m, int n) {
    int dp[n+1][m];

    for(int i=0; i<m; ++i)
        dp[0][i] = 1;
    
    for(int i=1; i<n+1; ++i)
        for(int j=0; j<m; ++j) {
            // Including coins[j]
            int x = (i-coins[j]) >= 0 ? dp[i-coins[j]][j] : 0;
            // Excluding coins[j]
            int y = (j>=1) ? dp[i][j-1] : 0;

            dp[i][j] = x + y;
        }

    return dp[n][m-1];
}

int main() {
    int m = 4;
    int n = 10;
    cout << coinChangeWays(m, n) << endl;
}