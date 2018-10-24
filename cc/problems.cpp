#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int prob [200006][35];
int hashArray [101];
vii ans;

bool compare_as_ints (ii i,ii j) {
  return (i.first<j.first);
}

int calculateDifficulty() {
    int cnt = 0;
    int current = -1;

    for(int i = 1; i <= 100; ++i) {
        if(hashArray[i]) {
            if(current != -1 && current > hashArray[i])
                ++cnt;
            current = hashArray[i];
        }
    }

    return cnt;
}

int main() {
    int p, s;

    scanf("%d %d", &p, &s);

    for(int i = 0; i < 2*p; ++i) {
        for(int j = 0; j < s; ++j) {
            scanf("%d", &prob[i][j]);
        }
    }

    memset(hashArray, 0, sizeof(hashArray));

    for(int i = 0; i < 2*p; i = i+2) {
        memset(hashArray, 0, sizeof(hashArray));
        for(int j = 0; j < s; ++j) {
            int score = prob[i][j];
            hashArray[score] = prob[i+1][j];
        }

        int diff = calculateDifficulty();
        ans.push_back(make_pair(diff, int(i/2+1)));
    }

    stable_sort(ans.begin(), ans.end(), compare_as_ints);

    for(int i = 0; i < ans.size(); ++i)
        //printf("%d %d\n", ans[i].second, ans[i].first);
        printf("%d\n", ans[i].second);

    return 0;
}