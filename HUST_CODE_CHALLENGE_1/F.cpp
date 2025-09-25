///https://codeforces.com/gym/105733/problem/F
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
const long double INF = 1e10;

int n, k, a[MAXN], b[MAXN]; 
long double p[MAXN];

void process(void) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    vector<long double> dp(k + 1, -INF), _dp(k + 1, -INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int cur = 0; cur <= k; cur++) _dp[cur] = -INF;
        for(int cur = 0; cur <= k; cur++) {
            int nxt = (cur == k ? 0 : cur);
            long double prize = 0;
            _dp[nxt] = max(_dp[nxt], dp[cur] + prize);
            if(cur == k) {
                prize = p[i] * (2 * a[i] + b[i]) - b[i];
                nxt = 1;
            } else {
                prize = p[i] * (a[i] + b[i]) - b[i];
                nxt = cur + 1;
            }
            _dp[nxt] = max(_dp[nxt], dp[cur] + prize);
        }
        swap(dp, _dp);
    }
    cout << fixed << setprecision(9) << *max_element(dp.begin(), dp.end());
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}