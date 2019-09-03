//#include <bits/stdc++.h>
//
//using namespace std;
//
//typedef long long ll;
//
//set<string> vis;
//
//
//int main() {
//    for(int n = 1; n <= 100; n++) {
//        cout << n << ": ";
//        vis.clear();
//        string b = "";
//        for(int i = 1; i <= n; i++) {
//            b += char(i + '0');
//        }
//        vis.insert(b);
//        int cnt = 1;
//        queue<string> qu;
//        qu.push(b);
//        while(!qu.empty()) {
//            string u = qu.front(); qu.pop();
//            string t = u;
//            for(int i = 0; i < n / 2; i++) {
//                swap(u[i], u[(n + 1) / 2 + i]);
//            }
//            if(!vis.count(u)) {
//
//                vis.insert(u);
//                qu.push(u);cnt++;
//            }
//            for(int i = 0; i < n; i++) {
//                if((i + 1)%2==0) swap(t[i], t[i-1]);
//            }
//            if(!vis.count(t)) {
//                vis.insert(t);
//                qu.push(t); cnt++;
//            }
//        }
//        cout << cnt << endl;
//    }
//    return 0;
//}


#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;cin >> t;
    }
    if(n == 1) {
        cout << 1;
    }
    else if(n == 2) cout << 2;
    else if(n == 3) cout << 6;
    else if(n % 4==0) cout<<4;
    else if(n % 4 == 1) cout << 2 * n;
    else if(n % 4 == 2) cout << n;
    else cout << 12 ;

    return 0;
}

