#include<iostream>
#include<string>

using namespace std;

bool isShuffle(string s1, string s2, int m, int n) {
    bool dp[m+1][n+1];

    for(int j = 1; j <= n; ++j)
        dp[0][j] = 0;
    
    for(int i = 0; i <= m; ++i)
        dp[i][0] = 1;
    
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            
            else
                dp[i][j] = dp[i-1][j];
        }
    
    /*for(int i = 0; i <= m; ++i) {
        for(int j = 0; j <= n; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    
    return dp[m][n];
}

int main() {
    string s1 = "cchocohilatspe";
    string s2 = "chocolate";
    string s3 = "chips";

    cout << isShuffle(s1, s2, s1.length(), s2.length()) << endl;
    cout << isShuffle(s1, s3, s1.length(), s3.length()) << endl;

    if(isShuffle(s1, s2, s1.length(), s2.length()) && isShuffle(s1, s3, s1.length(), s3.length()))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}