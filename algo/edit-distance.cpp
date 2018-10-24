#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

int minEditDistance(int x, int y, int z) {
    return min(min(x, y), z);
}

int editDistance(string s1, string s2, int m, int n) {
    if(m == 0) return n;
    if(n == 0) return m;

    if(s1[m-1] == s2[n-1])
        return editDistance(s1, s2, m-1, n-1);

    else if(s1[m-1] == s2[n-2] and s1[m-2] == s2[n-1])
        return 1 + editDistance(s1, s2, m-2, n-2);
    
    else
        return 1 + minEditDistance(editDistance(s1, s2, m, n-1),
                                   editDistance(s1, s2, m-1, n),
                                   editDistance(s1, s2, m-1, n-1));
}

int main() {
    string s1 = "lnikniapkr";
    string s2 = "linkinpark";
    cout << editDistance(s1, s2, s1.length(), s2.length()) << endl;
    return 0;
}