#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, have;
struct Pro {
    int d, t;
    bool operator < (const Pro & rhs) const {
        return d < rhs.d;
    }
}p[100100];
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    int cas = 0;
    while(T--) {
        cout << "Case " << ++cas <<  ": ";
        cin >> n >> have;
        for(int i = 0; i < n; i++) {
            cin >> p[i].d;
        }
        for(int i = 0; i < n;i++) {
            cin >> p[i].t;
        }
        sort(p, p + n);
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < n;i++) {
            sum += p[i].t;
            if(sum > have) {
                break;
            }
            cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}