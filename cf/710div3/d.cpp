#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int a[200005];
/*
1 2 3
1 1
2
2 3
2 2 2
*/
int main()
{
   // freopen("./i.txt", "r", stdin);
    int t;cin>>t;

    while(t--){
        int n;cin>>n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a,a+n);
        int cur = 0;
        // 1 1 1 4 4 6
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int j = i;
            while(a[i]==a[j]&&j<n)j++;
            
            mx = max(j - i,mx);
           
            i = j - 1;
        }
        // cout <<"=====" << mx << endl;
        if(mx == n) {
            cout << mx << endl;
        }
        else if(n - mx < mx) {
            cout << mx - (n - mx) << endl;
        } else if(n & 1) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }

       
    }
    return 0;
}

// 2 2 2 