#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[340][340];
const ll inf = 1e16;
int n, m;
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                r[i][j] = r[j][i] = inf;
            }
        }
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            r[u][v] = (ll)w;
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                if(r[i][k] == inf) continue;
                for(int j = 0; j < n; j++) {
                    if(r[i][k] != inf && r[k][j] != inf) {
                        r[i][j] = min(r[i][j],r[i][k] + r[k][j]);
                    }
                }
            }
        }
        for(int tt = 0; tt < 6; tt++) {
            int s, t;
            scanf("%d%d", &s, &t);
            for(int k = 0; k < n; k++) {
                for(int i = 0; i < n; i++) {
                    if(r[i][k] == inf) continue;
                    for(int j = 0; j < n; j++) {
                        if(r[i][k] != inf && r[k][j] != inf) {
                            r[i][j] = min(r[i][j],r[i][k] + r[k][j]);
                        }
                    }
                }
            }
            r[s][t] = -r[t][s];
            printf("%lld\n", -r[t][s]);
        }
    }
    return 0;
}