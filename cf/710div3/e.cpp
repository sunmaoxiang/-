#include <cstdio>
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
const int maxn = 200005;
int q[maxn];
int a[maxn];
int b[maxn];
int main()
{
   // freopen("./i.txt", "r", stdin);
    int t;
    cin >> t;
    for(;t--;) {
        int n;cin>>n;
        for(int i = 0; i < n; i++) {
            cin >> q[i];
        }
        deque<int> mx,mn;
        int j = 1; 
        for(int i = 0; i < n;i++) {
            a[i] = b[i] = q[i];
            while(j < q[i]) {
                mx.push_back(j);
                mn.push_back(j);
                j++;
            }
            j++;
            while( i + 1 < n && q[i] == q[i+1]  ) {
                //cout << mn.front() <<" " << mx.front() << endl;
                i++;
                a[i] = mn.front(); mn.pop_front();
                b[i] = mx.back(); mx.pop_back();
            }
            // cout << "----" << endl;
        }
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        for(int i = 0; i < n; i++) cout << b[i] << " ";
        cout << endl;
        
    }
    return 0;
}
/*
4
7
3 3 4 4 7 7 7
4
1 2 3 4
7
3 4 5 5 5 7 7
1
1
*/
/*
3 1 4 2 7 5 6 
3 2 4 1 7 6 5 
1 2 3 4 
1 2 3 4 
3 4 5 1 2 7 6 
3 4 5 2 1 7 6 
1 
1 
*/