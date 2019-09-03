#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 2e5 + 10;
int n, x[maxn], y[maxn], mxx,mxy;
map<int, int> ctx;
map<int, int> cty;
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        printf("Case %d: ", ++cas);
        ctx.clear(); cty.clear();
        scanf("%d", &n);
        mxx = mxy = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &x[i], &y[i]);
            mxx = max(++ctx[x[i]], mxx);
            mxy = max(++cty[y[i]], mxy);
        }
        if(ctx.size() == 1 || cty.size() == 1) {
            cout << n << " " << 1 << endl;
        }
        else if(mxx == 1 && mxy == 1) {
            cout << 2 << " " << 1LL * n * (n - 1) / 2 << endl;
        }
        else {
            int ctx1 = 0, ctx2 = 0, cty1 = 0, cty2 = 0;
            for(auto & it : ctx) {
                if(it.second == mxx) ctx1++;
                else if(it.second == mxx - 1) ctx2++;
            }
            for(auto & it : cty) {
                if(it.second == mxy) cty1++;
                else if(it.second == mxy - 1) cty2++;
            }
            ll ans1 = 1LL * ctx1 * cty1;
            ll ans2 = 1LL * ctx1 * cty2 + 1LL * ctx2 * cty1;
            for(int i = 0; i < n; i++) {
                if(mxx == ctx[x[i]] && mxy == cty[y[i]]) {
                    ans1--;
                    ans2++;
                }
                else if(mxx + mxy - 1 == ctx[x[i]] + cty[y[i]]) {
                    ans2--;
                }
            }
            if(ans1 == 0) {
                cout << mxx + mxy - 1 << " " << ans2 << endl;
            }
            else {
                cout << mxx + mxy << " " << ans1 << endl;
            }
        }
    }
    return 0;
}
