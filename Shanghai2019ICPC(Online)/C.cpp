#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
// -------------------- FFT --------------------/
typedef long double db;
const db PI = acos(-1.0);
struct Complex {
    db x, y;
    Complex(db x=0.0, db y=0.0) : x(x), y(y) {}
    Complex operator - (const Complex &b) const {
        return Complex(x-b.x, y-b.y);
    }
    Complex operator + (const Complex &b) const {
        return Complex(x+b.x, y+b.y);
    }
    Complex operator * (const Complex &b) const {
        return Complex(x*b.x-y*b.y, x*b.y+y*b.x);
    }
};
void change(Complex y[], int len) {
    for(int i = 1, j = len / 2; i < len - 1; i++) {
        if(i < j) swap(y[i], y[j]);
        int k = len / 2;;
        while(j >= k) {
            j -= k;
            k /= 2;
        }
        if(j < k) j+=k;
    }
}
void fft(Complex y[], int len, int on) {
    change(y, len);
    for(int h = 2; h <= len; h<<=1) {
        Complex wn(cos(-on*2*PI/h), sin(-on*2*PI/h));
        for(int j = 0; j < len; j+=h) {
            Complex w(1, 0);
            for(int k = j; k < j + h / 2; k++) {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u + t;
                y[k+h/2] = u - t;
                w = w*wn;
            }
        }
    }
    if(on == -1) {
        for(int i = 0; i < len; i++) {
            y[i].x /= len;
        }
    }
}
// -------------------------FFT-------------------------/
const int maxn = 1e6 + 100;
int a[maxn], b[maxn], c[maxn], n;
ll ca[maxn], cb[maxn], cc[maxn];
ll ans;
ll sum[maxn];
Complex x1[maxn], x2[maxn];
int len0,len;
void update(ll a[], ll b[], ll c[], int cc[]) {
    int len = 1;
    while(len < 2 * len0) len<<=1;
    for(int i = 0; i < len0; i++) {
        x1[i] = Complex(a[i], 0);
    }
    for(int i = len0; i < len; i++) {
        x1[i] = Complex(0,0);
    }
    fft(x1, len, 1);
    for(int i = 0; i < len0; i++) {
        x2[i] = Complex(b[i], 0);
    }
    for(int i = len0; i < len; i++) {
        x2[i] = Complex(0,0);
    }
    fft(x2, len, 1);
    for(int i = 0; i < len; i++) {
        x1[i] = x1[i] * x2[i];
    }
    fft(x1, len, -1);
    for(int i = 0; i < len; i++) {
        sum[i] = (ll)(x1[i].x + 0.5);
    }
    for(int i = 1; i < len; i++) sum[i] += sum[i-1];
    for(int i = 0; i < n; i++) {
        ans+=sum[cc[i]-1];
    }
}
ll suma[maxn], sumb[maxn], sumc[maxn];

int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d", &n);
        
        len0=0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            len0=max(len0,a[i]);
        }
        for(int j = 0; j < n; j++) {
            scanf("%d", &b[j]);
            len0=max(len0,b[j]);
        }
        for(int k = 0; k < n; k++) {
            scanf("%d", &c[k]);
            len0=max(len0,c[k]);
        }
        for(int i = 0; i  <= len0; i++) ca[i]=cb[i]=cc[i]=0;
        for(int i = 0; i < n; i++) {
            ca[a[i] ]++;cb[b[i] ]++;cc[c[i] ]++;
        }
        len0++;
        if(n < 6000) {
            for(int i = 0; i  <= len0 + 1000; i++) suma[i]=sumb[i]=sumc[i]=0;
            ll res = 1LL*n*n*n;
            for(int i = len0-1; i >= 0; i--) {
                suma[i] = ca[i] + suma[i+1];
                sumb[i] = cb[i] + sumb[i+1];
                sumc[i] = cc[i] + sumc[i+1];
            }
            ll cnt = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    ll temp = a[i] + b[j];
                    cnt += sumc[temp+1];
                    temp = b[i] + c[j];
                    cnt += suma[temp+1];
                    temp = a[i] + c[j];
                    cnt += sumb[temp+1];
                }
            }
            res-=cnt;
            printf("%lld\n",res);
        }
        else {
            ans = 0;
            update(ca,cb,cc,c);
            update(ca,cc,cb,b);
            update(cb,cc,ca,a);
            printf("%lld\n", 1LL * n * n * n - ans);
        }
    }
    return 0;
}

