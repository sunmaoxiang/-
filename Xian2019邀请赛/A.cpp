#include <bits/stdc++.h>
using namespace std;

int t[110];

int main() {
    int n, T;
    cin >> n >> T;
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t, t + n);
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(sum + t[i] <= T) {
            sum+=t[i];
            cnt++;
        }
        else break;
    }
    printf("%d\n", cnt);
    return 0;
}