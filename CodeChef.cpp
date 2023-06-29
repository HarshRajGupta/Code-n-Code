#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3","Ofast","fast-math","unroll-loops","no-stack-protector","omit-frame-pointer")
#pragma GCC target("sse", "sse2", "sse3", "ssse3", "sse4", "popcnt", "abm", "mmx", "avx", "avx2")
#endif

#ifndef debug
#define debug(...)
#endif

#ifndef __MAIN__
#define __MAIN__ signed main() {preCompute(); signed t; cin >> t; while (t--)solve(), cout << '\n'; return 0;}
#endif

#define int long long
const uint64_t MOD = 1e9 + 7;
const char ln = '\n';

#define _for(i, n) for (int32_t i = 0; i < (int32_t)n; ++i)
#define rep(i, a, n) for (int32_t i = a; i < (int32_t)n; ++i)
#define foreach(i, x) for (auto &i : x)
#define bw(i, n) for (int32_t i = n; i >= 0; --i)

template<class T>using v = vector<T>;
template<class T>using maxHeap = priority_queue<T>;
template<class T>using minHeap = priority_queue<T, vector<T>, greater<T>>;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int index(string &s, int pos, char &t) {
    for (int i = pos; i < sz(s); ++i) {
        if (s[i] == t) return i + 1;
    }
    return sz(s) + 1;
}

bool canDo = false;
string s, l, r;
int m;

void ans(string &s, string &l, string &r, int pos, int ind) {
    if (pos == sz(l)) {
        if (ind > sz(s)) canDo = true;
        return;
    }
    for (char i = l[pos]; i <= r[pos]; ++i) {
        int next = index(s, ind, i);
        ans(s, l, r, pos + 1, next);
        if (canDo) {
            return;
        }
    }
}

void solve(void) {
    cin >> s >> m >> l >> r;
    canDo = false;
    ans(s, l, r, 0, 0);
    if (canDo) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}

bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.flush(); return 0;
}

__MAIN__

/*
 * @ScratchPad
*/