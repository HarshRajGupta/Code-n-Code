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

bool canDo = false;
string s, l, r;
int m;

int index(int pos, char &t) {
    for (int i = pos; i < sz(s); ++i) {
        if (s[i] == t) {
            return i + 1;
        }
    } 
    return sz(s) + 1;
}

bool ans(int pos, int ind) {
    if (pos == sz(l)) {
        if (ind > sz(s)) {
            return true;
        } else {
            return false;
        }
    }
    for (char i = l[pos]; i <= r[pos]; ++i) {
        if (ans(pos + 1, index(ind, i))) {
            return true;
        }
    }
    return false;
}

void solve(void) {
    cin >> s >> m >> l >> r;
    _for(i, m) {
        if (r[i] < l[i]) {
            cout << "NO";
            return;
        }
    }
    if (ans(0, 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

}

bool preCompute(void) {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0;
}

__MAIN__

/*
 * @ScratchPad
*/