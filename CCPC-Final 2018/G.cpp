#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
const ll mod = (ll)1e9 + 7;
ll c[maxn][10];
void init() {
    c[0][0] = 1;
    for(int i = 1; i <= maxn; i++) {
        c[i][0] = 1;
        for(int j = 1; j <= 4; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
        }
    }
}
int main() {
  //  freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T; cin >> T;
    int cas = 0;
    init();
    while(T--) {
        int n, m;
        cin>>n>>m;
        cout << "Case " << ++cas << ": " << ((c[n][3] + c[n][4] ) * (c[m][3] + c[m][4]))%mod<<endl;
    }
    return 0;
}
