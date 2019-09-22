#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const ll p0 = 509;
const ll p1 = 521;
ll P[35];
const int MAXN = 1e5 + 10;
char s[MAXN];
char t[MAXN];
int n;
int m;
int ans[MAXN];
/**
 用来求询问串的Hash值
 **/
inline ll getHash(char*str, int len) {
    ll ret = p0*(str[1]-'a'+1) + p1*(str[len] - 'a'+1);
    ll res = 0;
    for(int i = 2; i < len; i++) {
        res += P[str[i] - 'a' + 1];  // !
    }
    return ret + res;
}
vector<ll> v[MAXN];
vector<ll> tp;
ll HH[MAXN];
int l[MAXN];
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    P[0] = 1;
    for(int i = 1; i <= 30; i++) P[i] = P[i-1] * 10007;
   
    int T;
    scanf("%d", &T);
    while(T--) {
        
        scanf("%s", s + 1);
        for(int i = 0; i < MAXN; i++) v[i].clear();
        n = (int)strlen(s + 1);
        scanf("%d", &m);
        
        for(int i = 0; i < m; i++) {
            scanf("%s", t + 1);
            int len = (int)strlen(t + 1);
            l[i] = len;
            HH[i] = getHash(t, len);
            v[len].push_back(i);
        }
        for(int i = 0; i < MAXN; i++){
            if(v[i].size() == 0) continue;
            tp.clear();
            int len = i;
            if(len > n) continue;
            ll tmp = 0;
            tmp = p0*(s[1]-'a' + 1) + p1*(s[len] - 'a'+1);
            for(int i = 2; i < len; i++) tmp += P[ s[i] - 'a' + 1 ];
            tp.push_back(tmp);
            //cout << len << " " << tmp << endl;
            for(int i = 2; i <= n; i++) {
                int R = len + i - 1;
                if(R > n) break;
                tmp+=p1*(s[R]-'a'+1);
                tmp+=P[s[R-1]-'a'+1];
                tmp-=p1*(s[R-1]-'a'+1);
                tmp+=p0*(s[i]-'a'+1);
                tmp-=P[s[i]-'a'+1];
                tmp-=p0*(s[i-1]-'a'+1);
                tp.push_back(tmp);
            }
            sort(tp.begin(), tp.end());
            for(auto & it : v[len] ) {
                ans[it] = upper_bound(tp.begin(), tp.end(), HH[it]  ) - lower_bound(tp.begin(), tp.end(), HH[it]  );
            }
        }
        for(int i = 0; i < m; i++) {
            cout << ans[i] << endl;
        }
        
        
    }
    return 0;
}
/*
 1
 abccdefgdaaacdcdfegaada
 4
 gadaa
 abccd
 defg
 aa
 */
