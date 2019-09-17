#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
vector<pii> v;
/*
 虽然是签到题，但是差分思想挺好的
 */
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        v.clear();
        int n, q;
        scanf("%d%d", &n, &q);
        while(q--){
            int L,R;
            scanf("%d%d", &L, &R);
            v.push_back({L, 1});
            v.push_back({R+1, -1});
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < v.size(); i++) {
            sum += v[i].second;
            if(sum & 1) {
                ans += v[i + 1].first - v[i].first;
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}


/*
 2
 10 2
 2 6
 4 8
 6 3
 1 1
 2 3
 3 4
 */
