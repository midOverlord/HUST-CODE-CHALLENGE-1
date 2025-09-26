#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int n, c[MAXN];

bool check(int d) {
    int pre = 0;
    for(int i = 1; i <= n; i++) {
        int _min = max(0, (c[i] - d + 1) / 2);
        int _max = min(c[i], (c[i] + d) / 2);
        int cur = max(_min, pre + max(0, c[i] - c[i - 1]));
        if(cur > _max) return false;
        pre = cur;
    }   
    return true;
}

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i]; c[0] = c[1];
    int INF = *max_element(c + 1, c + n + 1) + 1;
    int l = -1, r = INF;
    while(r - l > 1) {
        int mid = r + l >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << (r == INF ? -1 : r);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}