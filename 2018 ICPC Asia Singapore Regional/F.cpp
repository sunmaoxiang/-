#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 4e6 + 100;
const int inf = 0x3f3f3f3f;
struct Tree {
    int l, r;
    int val;
}tr[maxn << 2];
void build(int o, int l, int r) {
    tr[o].l = l;
    tr[o].r = r;
    tr[o].val = inf;
    if(r == l) return ;
    int mid = (r + l) >> 1;
    build(o<<1, l, mid);
    build(o<<1|1, mid + 1, r);
}
void update(int o, int pos, int v) {
    int L = tr[o].l, R = tr[o].r;
    if(L == R) {
        tr[o].val = v;
        return ;
    }
    int mid = (L + R) / 2;
    if(pos <= mid) update(o<<1, pos, v);
    else update(o<<1|1,pos,v);
    tr[o].val = min(tr[o<<1].val, tr[o<<1|1].val);
}
int query(int o, int l, int r) {
    int L = tr[o].l, R = tr[o].r;
    if(L >= l && R <= r) return tr[o].val;
    int mid = (L + R) >> 1;
    int ret = inf;
    if(l <= mid) ret = min(ret, query(o<<1, l,r));
    if(r > mid) ret = min(ret, query(o<<1|1, l, r));
    return ret;
}
int n;
int nxt[maxn], a[maxn], last[maxn] = {0};
typedef pair<int, int> pii;
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        
    }
    for(int i = n; i >= 1; i--) {
        nxt[i] = last[a[i]];
        last[a[i]] = i;
    }
    pii ans = {inf, inf};
    build(1, 1, n + 1);
    for(int i = 1; i <= n; i++) {
        if(!nxt[i]) continue;
        int v = query(1, i + 1, nxt[i]);
        ans = min(ans, {v, a[i]});
        update(1, nxt[i], a[i]);
    }
    if(ans.first==inf||ans.second==inf) printf("-1");
    else printf("%d %d\n", ans.first, ans.second);
    return 0;
}

