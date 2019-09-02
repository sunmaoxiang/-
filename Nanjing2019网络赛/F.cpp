#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
set<int> st;
set<int>::iterator it;
int a[100010];
int nxt[100010], d[100010];
int dp(int u) {
    if(nxt[u]==-1) return 1;
    if(~d[u]) return d[u];
    return d[u] = 1 + dp(nxt[u]);
}
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        st.clear();
        for(int i = 1; i <= min(k + 1,n); i++) {
            st.insert(a[i]);
        }
        
        for(int i = 1; i <= n; i++) {
            it = st.lower_bound(a[i]);
            if(it==st.begin()) nxt[a[i]] = -1;
            else {
                nxt[a[i]] = *(--it);
            }
            if(i - k >= 1) st.erase(a[i-k]);
            if(i + k + 1 <= n) st.insert(a[i+k+1]);
        }
        memset(d, -1, sizeof(d));
        for(int i = 1; i <= n; i++) {
            if(i == 1) printf("%d", dp(i));
            else printf(" %d", dp(i));
        }
        printf("\n");
    }
    return 0;
}