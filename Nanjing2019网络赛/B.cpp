#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000000 + 100;
int euler[maxn] = {0};
void getEuler() {
    euler[1] = 1;
    for(int i =  2; i < maxn; i++) {
        if(!euler[i]) {
            for(int j = i; j < maxn; j+=i) {
                if(!euler[j]) {
                    euler[j] = j;
                }
                euler[j] = euler[j] / i * (i-1);
            }
        }
    }
}

ll Mod(ll x, ll mod) {
    return x < mod ? x : x % mod + mod;
}
ll qpm(ll x, ll n, ll mod) {
    ll ret = 1;
    while(n) {
        if(n&1) ret = Mod(ret*x,mod);
        n >>= 1;
        x = Mod(x*x,mod);
    }
    return ret;
}

int a, b, m;

int solve(int base, int cur, int m) {
    if(cur == 0 || m == 1) return 1;
    int el = euler[m];
    int x = solve(base, cur-1, el);
    return (int)qpm(base, x, m);
}

int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    getEuler();
    int T;
    scanf("%d", &T);
    
    while(T--) {
        scanf("%d%d%d", &a, &b, &m);
        printf("%d\n", solve(a, b, m) % m);
    }
    return 0;
}
