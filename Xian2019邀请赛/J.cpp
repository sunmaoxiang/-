#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;
const int maxn = 1e5 + 100;
struct Edge {
    int v;
    ll c;
    Edge(int v, ll c) : v(v), c(c) {}
};
int n;
vector<Edge> G[maxn];
int sz[maxn];
ll dis[maxn];
void dfs(int u, int fa) {
    sz[u] = 1;
    for(auto & e:G[u]){
        int v=e.v;
        ll c=e.c;
        if(v == fa) continue;
        dis[v] = dis[u] ^ c;
        dfs(v, u);
        sz[u]+=sz[v];
    }
}
// 树型dp作法，大致是1 - > 2异或是a的的话，如果 1 - > 3异或是a的话，那么2 - > 3异或值就是0喽
ll res;
map<ll, ll> mp;
void dfs1(int u, int fa){
    (res += (mp[dis[u]]*sz[u])%mod)%=mod;
    for(auto & e : G[u]) {
        int v = e.v;
        if(v == fa) continue;
        (mp[dis[u]]+=(n-sz[v]))%=mod;
        dfs1(v,u);
        (mp[dis[u]]+=(-n+sz[v]+mod))%=mod;
    }
    (mp[dis[u]]+=sz[u])%=mod;
}
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 2; i <= n; i++) {
        int fa;
        ll c;
        scanf("%d%lld", &fa, &c);
        G[i].push_back(Edge(fa, c));
        G[fa].push_back(Edge(i, c));
    }
    res = 0;
    dfs(1, -1); dfs1(1, -1);
    printf("%lld\n", res);
    return 0;
}


/*
 5
 1 0
 2 0
 3 0
 4 0
 */
