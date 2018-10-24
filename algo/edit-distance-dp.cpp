#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int minEditDistance(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistanceDP(string x, string y, int m, int n) {
    int dp[m+1][n+1];

    for(int i=0; i<=m; ++i)
        dp[0][i] = i;
    
    for(int j=0; j<=n; ++j)
        dp[j][0] = j;
    
    // Fill the dp matrix
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=n; ++j) {
            if(x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1];

            else if(x[i-1] == y[j-2] && x[i-2] == y[j-1])
                dp[i][j] = dp[i-2][j-2] + 1;

            else
                dp[i][j] = 1 + minEditDistance(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "lnikniapkr";
    string s2 = "linkinpark";
    cout << editDistanceDP(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}