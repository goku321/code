#include<iostream>

using namespace std;

int maxLcs(int a, int b, int c) {
    return max(max(a, b), c);
}

int lcsRecursion(string x, string y, int m, int n) {
    if(m == 0 || n == 0)
        return 0;
    else if(x[m-1] == y[n-1]) {
        return lcsRecursion(x, y, m-1, n-1) + 1;
    } else {
        return 0;
    }
}

int main() {
    string x = "photograph", y = "tomography";
    int m = x.length(), n = y.length();

    int maxAns = 0;

    for(int i=1; i<=m; ++i)
        for(int j=1; j<=n; ++j) {
            maxAns = max(maxAns, lcsRecursion(x, y, i, j));
        }
    cout << maxAns << endl;
}