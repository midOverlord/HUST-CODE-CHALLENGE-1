///https://codeforces.com/gym/105733/problem/C
#include <bits/stdc++.h>

using namespace std;

void process(void) {
    int n; cin >> n;
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for(int i = 0; i < n; i++) {
        long long x; cin >> x;
        while(x % 2 == 0) {
            cnt[0]++;
            x /= 2;
        }
        while(x % 5 == 0) {
            cnt[1]++;
            x /= 5;
        }
    }
    cout << min(cnt[0], cnt[1]) << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}