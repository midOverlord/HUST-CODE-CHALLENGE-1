///https://codeforces.com/gym/105733/problem/E
#include <bits/stdc++.h>

using namespace std;

#define  MASK(i)  (1LL << (i))

const int MAXN = 1e3 + 5;
const int LG = 10;

int n, m, s, a[MAXN][MAXN], sq[2];
long long pref[MAXN][MAXN], st[2][LG + 1][MAXN];

long long calc(int r1, int c1, int r2, int c2) {
    return pref[r2][c2] - pref[r2][c1 - 1] - pref[r1 - 1][c2] + pref[r1 - 1][c1 - 1];
}

long long get(int x, int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(st[x][k][l], st[x][k][r - MASK(k) + 1]);
}

void process(void) {
    cin >> n >> m >> s;
    sq[0] = n - s + 1; sq[1] = m - s + 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + a[i][j];
        }
    }
    for(int i = 1; i <= sq[0]; i++) {
        long long cur = 0;
        for(int j = 1; j <= sq[1]; j++) {
            cur = max(cur, calc(i, j, i + s - 1, j + s - 1));
        }
        st[0][0][i] = cur;
    }
    for(int j = 1; j <= sq[1]; j++) {
        long long cur = 0;
        for(int i = 1; i <= sq[0]; i++) {
            cur = max(cur, calc(i, j, i + s - 1, j + s - 1));
        }
        st[1][0][j] = cur;
    }
    for(int x = 0; x <= 1; x++) {
        for(int k = 1; MASK(k) <= sq[x]; k++) {
            for(int i = 1; i + MASK(k) - 1 <= sq[x]; i++) {
                st[x][k][i] = max(st[x][k - 1][i], st[x][k - 1][i + MASK(k - 1)]);
            }
        }
    }
    long long ans = 0;
    for(int i = 1; i <= sq[0]; i++) {
        for(int j = 1; j <= sq[1]; j++) {
            long long cur = calc(i, j, i + s - 1, j + s - 1);
            long long add = 0;
            if(i + s <= sq[0]) add = max(add, get(0, i + s, sq[0]));
            if(j + s <= sq[1]) add = max(add, get(1, j + s, sq[1]));
            ans = max(ans, cur + add);
        }
    }
    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}