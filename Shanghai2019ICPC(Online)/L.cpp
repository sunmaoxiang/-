#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll ans[1000002][11] = {0};
void init() {
    for(int i = 1; i <= (int)1e6; i++) {
        for(int B = 2; B <= 10; B++) {
            int N = i;
            ll res = 0;
            while(N) {
                res += N % B;
                N /= B;
            }
            ans[i][B] = res;
            ans[i][B] += ans[i-1][B];
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    int cas = 0;
    init();
    while(T--) {
        int N, B;
        scanf("%d%d", &N,&B);
        printf("Case #%d: %lld\n", ++cas, ans[N][B]);
    }
    return 0;
}

