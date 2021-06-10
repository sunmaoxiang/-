#include <iostream>
#include <cstdio>
using namespace std;

char s[100];

int sum[100];

int main()
{
    //freopen("./i.txt", "r", stdin);
    int t,n,k;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        scanf("%s", s);
        sum[0] = (s[0] == '*');
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i-1] + (s[i] == '*');
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '*') {
                s[i] = 'x';
                ans++;
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] == 'x' && i + k < n && sum[n-1] - sum[i+k] > 0) {
                for(int j = i + k; j > i; j--) {
                    if(s[j] == '*') {
                        ans++;
                        s[j] = 'x';
                        break;
                    }
                }
            }
        }
        for(int i = n-1; i > 0; i--) {
            if(s[i] == 'x') break;
            if(s[i] == '*') {
                s[i] = 'x';
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}