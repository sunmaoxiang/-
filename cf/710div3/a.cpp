#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main()
{
    //freopen("./i.txt","r",stdin);
    int t;
    cin >> t;
    
    ll n,m,x;
    while(t--) {
        cin >> n >> m >> x;
        cout << ((x - 1) / n) + ( (x - 1) % n ) * m + 1 << endl;
    }
    return 0;
}