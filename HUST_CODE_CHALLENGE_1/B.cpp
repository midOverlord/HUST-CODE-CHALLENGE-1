///https://codeforces.com/gym/105733/problem/B
#include <bits/stdc++.h>

using namespace std;

void process(void) {
    int t; cin >> t;
    queue<pair<int, int>> q;
    while(t--) {
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int x, a; cin >> x >> a;
            q.push({x, a});
        } else {
            int c; cin >> c;
            long long ans = 0;
            while(c) {
                auto &[x, a] = q.front();
                int buy = min(c, x);
                c -= buy;
                ans += 1LL * buy * a;
                if(buy == x) {
                    q.pop();
                } else {
                    x -= buy;
                }
            }
            cout << ans << '\n';
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}