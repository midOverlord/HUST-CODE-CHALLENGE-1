///https://codeforces.com/gym/105733/problem/A
#include <bits/stdc++.h>

using namespace std;

void process(void) {
    int n; cin >> n;
    set<char> gdsc;
    set<char> bkac;
    string s; cin >> s;
    for(auto c: s) {
        if(c == 'G' || c == 'D' || c == 'S' || c == 'C') {
            gdsc.insert(c);
        }
        if(c == 'B' || c == 'K' || c == 'A' || c == 'C') {
            bkac.insert(c);
        }
        if(gdsc.size() == 4 && bkac.size() == 4) return void(cout << "DRAW" << '\n');
        if(gdsc.size() == 4) return void(cout << "GDSC" << '\n');
        if(bkac.size() == 4) return void(cout << "BKAC" << '\n');
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}