#include <bits/stdc++.h>

using namespace std;

#define  st  first 
#define  nd  second 
#define  II  pair<int, int>

const int MAXN = 2e5 + 5;

int n, m;
vector<int> visited, hold;
vector<II> g[MAXN];

void dfs(int u) {
    visited[u] = 1;
    for(auto [v, id]: g[u]) if(!visited[v]) {
        hold[id] = 1;
        dfs(v);
    }
}

void process(void) {
    cin >> n >> m;
    visited.assign(n + 1, 0);
    hold.assign(m + 1, 0);
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, i}); g[v].push_back({u, i});
    }
    vector<int> a;
    for(int i = 1; i <= n; i++) if(!visited[i]) {
        dfs(i);
        a.push_back(i);
    }
    vector<int> era;
    for(int i = 1; i <= m; i++) if(!hold[i]) {
        era.push_back(i);
    }
    vector<II> add;
    for(int i = 1; i < a.size(); i++) {
        add.push_back({a[0], a[i]});
    }
    cout << era.size() << '\n';
    for(auto c: era) cout << c << '\n';
    cout << add.size() << '\n';
    for(auto edge: add) cout << edge.first << ' ' << edge.second << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}