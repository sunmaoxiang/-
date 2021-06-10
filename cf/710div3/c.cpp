#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char a[30],b[30];
int main()
{
    //freopen("./i.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        unordered_map<string, int> hmp; 
       
        scanf("%s%s",a,b);
        int n = strlen(a);
        int m = strlen(b);
        string tmp = "";
        for(int i = 0; i < n; i++) {
            tmp = "";
            for(int j = i; j < n; j++) {
                tmp+=a[j];
                hmp[tmp]=1;
            }
        }
        for(int i = 0; i < m; i++) {
            tmp = "";
            for(int j = i; j < m; j++) {
                tmp+=b[j];
                if(hmp[tmp] == 1) hmp[tmp]++;
            }
            //cout << tmp << endl;
            
        }
        int mx = 0;
        for(auto & it : hmp) {
            if(it.second > 1) {
                mx = max((int)(it.first.length()), mx);
            }
        }
        // cout << mx << endl;
        cout << n+m-2*mx <<endl;
    }
    return 0;
}