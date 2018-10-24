#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int minEditDistance(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistance(string s1, string s2, int m, int n) {
    if(m == 0 && n == 0) return 1;
    else if(m == 0) return 0;
    else if(n == 0) return 1;

    if(s1[m-1] == s2[n-1])
        return editDistance(s1, s2, m-1, n-1);
    
    else
        return editDistance(s1, s2, m-1, n);
}

int main() {
    string s1 = "chocochilatspe";
    string s2 = "chips";
    cout << editDistance(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}