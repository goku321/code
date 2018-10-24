#include<iostream>

using namespace std;

int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};

int lis(int prev, int low, int highL) {
    if((highL-low+1) == 0)
        return 0;
    
    int maxLength = lis(prev, low+1, highL);
    
    if(arr[low] > prev) {
        int L = 1 + lis(arr[low], low+1, highL);
        if(L > maxLength)
            maxLength = L;
    }

    return maxLength;
}

int main() {
    int n = 9;
    cout << lis(-9999, 0, 8) << endl;
}