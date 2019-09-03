#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m, c, d, e;
int head[maxn], to[maxn<<1], nxt[maxn<<1], w[maxn << 1], tot;
void addEdge(int u, int v, int cost) {
    to[tot] = v; w[tot] = cost; nxt[tot] = head[u]; head[u] = tot++;
}
typedef pair<int, int> pii;
bool vis[maxn];
int cnt[maxn];
bool judge(ll x) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i = 1; i<= n;i++){
        cnt[i]=0x3f3f3f3f;
        vis[i] = false;
    }
    ll enble = x * d;
    ll have = x * e;
    pq.push({0, 1});
    cnt[1] = 0;
    while(!pq.empty()) {
        pii uc = pq.top(); pq.pop();
        int u = uc.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u]; ~i; i = nxt[i]) {
            int v = to[i];
            if(w[i] > enble) continue;
            if(cnt[v] > cnt[u] + 1) cnt[v] = cnt[u] + 1;
            pq.push({cnt[v], v});
        }
    }
    return have >= cnt[n];
}
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    scanf("%d%d%d", &c, &d, &e);
    memset(head, -1, sizeof(head)); tot = 0;
    for(int i = 0; i < m; i++) {
        int u, v, _w;
        scanf("%d%d%d", &u, &v, &_w);
        addEdge(u, v, _w);
        addEdge(v, u, _w);
    }
    ll L = 0, R = 1e5 + 10;
    ll ans = -1;
    while(L <= R) {
        ll mid = (L + R) >> 1;
        if(judge(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    if(ans==-1) {
        cout<<-1<<endl;
    }
    else {
        cout << ans * c << endl;
    }
    return 0;
}
/*
5 7
1 1 1
1 2 1
1 3 5
1 4 1
2 3 2
2 4 5
3 4 3
3 5 5
*/
