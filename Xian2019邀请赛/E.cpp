#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 100;
int n, q;
struct Edge {
    int to, nxt;
}edge[maxn * 2];
int head[maxn], tot;
int deep[maxn], fa[maxn], sz[maxn], son[maxn];
int pos, p[maxn], top[maxn];


/*segment tree*/
struct Tree {
    int l, r, sum;
    int lz;
    void update(int val) {
        sum = val * (r - l + 1);
        lz = val;
    }
}tr[32][maxn << 2];
void build(int o, int l, int r, int cur) {
    tr[cur][o].sum = 0;
    tr[cur][o].lz = -1;
    tr[cur][o].l = l; tr[cur][o].r = r;
    if(l == r) return ;
    int mid = (l + r) / 2;
    build(o<<1, l, mid, cur);
    build(o<<1|1, mid + 1, r, cur);
}
void push_down(int o, int cur) {
    if(tr[cur][o].lz != -1) {
        tr[cur][o << 1].update(tr[cur][o].lz);
        tr[cur][o<<1|1].update(tr[cur][o].lz);
        tr[cur][o].lz = -1;
    }
}
void push_up(int o, int cur) {
    tr[cur][o].sum = tr[cur][o<<1].sum + tr[cur][o<<1|1].sum;
}
void update(int o, int l, int r, int v, int cur) {
    int L = tr[cur][o].l, R = tr[cur][o].r;
    if(L >= l && R <= r) {
        tr[cur][o].sum = (R - L + 1) * v;
        tr[cur][o].lz = v;
        return ;
    }
    push_down(o, cur);
    int mid = (L + R) >> 1;
    if(l <= mid) update(o<<1, l, r, v, cur);
    if(r > mid) update(o<<1|1, l, r, v, cur);
    push_up(o, cur);
}
int query(int o, int l, int r, int cur) {
    int L = tr[cur][o].l, R = tr[cur][o].r;
    if(L >= l && R <= r) {
        return tr[cur][o].sum;
    }
    push_down(o, cur);
    int mid = (L + R) >> 1;
    int ret = 0;
    if(l <= mid) ret += query(o<<1, l, r, cur);
    if(r > mid) ret += query(o<<1|1, l, r, cur);
    return ret;
}
void init() {
    memset(head, -1, sizeof(head)); tot=0;
    memset(son, -1, sizeof(son)); pos=1;
}
void addedge(int u, int v) {
    edge[tot].to = v; edge[tot].nxt = head[u]; head[u] = tot++;
}
void dfs1(int u, int pre, int d) {
    deep[u] = d;
    fa[u] = pre;
    sz[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if(v != pre) {
            dfs1(v, u, d + 1);
            sz[u] += sz[v];
            if(son[u] == -1 || sz[v] > sz[son[u]]) {
                son[u] = v;
            }
        }
    }
}
void dfs2(int u, int sp) {
    top[u] = sp;
    p[u] = pos++;
    if(son[u] == -1) return ;
    dfs2(son[u], sp);
    for(int i = head[u]; i != -1; i = edge[i].nxt) {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u]) {
            dfs2(v,v);
        }
    }
}

void Change(int u, int v, int val, int cur) {
    int f1 = top[u], f2 = top[v];
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        update(1, p[f1], p[u], val, cur);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    update(1, p[u], p[v], val, cur);
}
int Q(int u, int v, int cur) {
    int f1 = top[u], f2 = top[v];
    int ret = 0;
    while(f1 != f2) {
        if(deep[f1] < deep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        ret += query(1, p[f1], p[u], cur);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v]) swap(u, v);
    return query(1, p[u], p[v], cur) + ret;
}

int b[maxn];

int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    init();
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    dfs1(1, -1, 1);
    dfs2(1, 1);
    for(int i = 0; i < 31; i++) build(1, 1, pos, i);
    for(int i = 1; i <= n; i++) {
        for(int k = 0; k < 31; k++) {
            if((b[i] >> k) & 1) {
                Change(i, i, 1, k);
            }
        }
    }
    while(q--) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int s, t;
            scanf("%d%d", &s, &t);
            for(int k = 0; k < 31; k++) {
                if((t >> k) & 1) {
                    Change(1, s, 1, k);
                }
            }
        }
        else if(op == 2) {
            int s, t;
            scanf("%d%d", &s, &t);
            for(int k = 0; k < 31; k++) {
                if(!((t >> k) & 1) ) {
                    Change(1, s, 0, k);
                }
            }
        }
        else if(op == 3) {
            int s, t;
            scanf("%d%d", &s, &t);
            bool flag = false;
            for(int i = 0; i < 31; i++) {
                int x = Q(1, s, i);
                if(  (t >> i) & 1 ) {
                    if(x % 2 == 0) {
                        flag = true;
                        break;
                    }
                }
                else {
                    if(x % 2 == 1) {
                        flag = true;
                        break;
                    }
                }
            }
            flag ? puts("YES") : puts("NO");
        }
    }
    return 0;
}
/*
 6 6
 0 1 0 3 2 3
 2 1
 3 2
 4 1
 5 3
 6 3
 1 3 0
 2 3 1
 1 1 0
 3 5 0
 2 4 1
 3 3 1
 */
