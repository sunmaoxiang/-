#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 100;
const int N = 26;
char s[MAXN];
int pre[MAXN][26] = {0};

struct PAM {
    int ch[MAXN][N];// 往一个字符串左右添加一个字符对应的结点
    int fail[MAXN]; // 对于后缀回文串来说，失配后能到达的下一个后缀回文
    int cnt[MAXN];  // 本质不同的结点数量，最后需要count函数得到正确结果
    int num[MAXN];  // num[i]表示以i结尾的后缀回文串的数量
    int len[MAXN];  // 每个节点代表的回文串长度
    int pos[MAXN];  // 每种回文串的一个结尾，以此能推左右边界
    int S[MAXN];    // 存字符串
    int last;       // 对应最长后缀回文节点
    int n;          // 字符集数量
    int p;          // 回文树结点数量
    int newnode(int l) {
        for(int i = 0; i < N; i++) ch[p][i] = 0;
        cnt[p] = num[p] = 0;
        len[p] = l;
        return p++;
    }
    void init() {
        p = 0;
        newnode(0);  // 偶结点
        newnode(-1); // 奇结点
        last = 0;
        n = 0;
        S[n] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {
        while(S[n - len[x] - 1] != S[n]) x = fail[x];
        return x;
    }
    void add(int c) {
        c-='a';
        S[++n] = c;
        int cur = get_fail(last);
        if(!ch[cur][c]) {
            int now = newnode(len[cur] + 2);// 新添加一个结点
            fail[now] = ch[get_fail(fail[cur])][c];
            ch[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = ch[cur][c];
        cnt[last]++;
        pos[last] = n;
    }
    void count() {
        for(int i = p - 1; i >= 0; --i) {
            cnt[fail[i]] += cnt[i];
        }
    }
    ll sol() {
        ll ret=0;
        for(int i = 2; i < p; i++) {
            int r = pos[i];
            int l = pos[i] - len[i] + 1;
            ll sum = 0;
            for(int i = 0; i < 26; i++) {
                if(pre[r][i] - pre[l-1][i]) sum++;
            }
            ret += sum * cnt[i];
        }
        return ret;
    }
} pam;
/**
 大体思路是知道每种本质不同回文的个数，然后枚举每个回文（回文数量数量级是字符串长度，所以完全可以）
 然后∑回文的字符集大小 * 回文个数即可
 **/
int main() {
    //freopen("/Users/maoxiangsun/MyRepertory/input.txt", "r", stdin);
    scanf("%s", s);
    int len = (int)strlen(s);
    pam.init();
    for(int i = 1; i <= len; i++) {
        int c = s[i-1] - 'a';
        pam.add(s[i-1]);
        for(int j = 0; j < 26; j++) {
            pre[i][j] = pre[i-1][j];
        }
        pre[i][c]++;
    }
    pam.count();
    cout << pam.sol() << endl;
    return 0;
}

