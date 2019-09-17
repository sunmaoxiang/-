#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 300 + 10;
const int mod = 1e9 + 7;
int n;
int a[maxn];
int d[maxn * 500];
int sum;
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        for(int i = 0; i <= sum; i++) d[i] = 0;
        d[0] = 1;
        ll res = 0;
        /*
         dui >= sum - dui;
         dui - a[i] <= sum - dui;
         */
        int L = (sum + 1) / 2;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = sum; j >= a[i]; j--) {
                int R = (sum + a[i]) / 2;
                if(j >= L && j <= R) res = ( res + d[j - a[i]] ) % mod;
                d[j]=(d[j] + d[j-a[i]]) % mod;
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
/*
 2
 3
 1 2 2
 3
 1 2 4
 */
