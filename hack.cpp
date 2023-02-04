/**
 *    author: Pratham_Shah10
 *    date: 03.02.2023
**/

#include<bits/stdc++.h>
using namespace std;
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define sz(x) ((ll)(x).size())
#define all(x) x.begin(),x.end()
#define set_bits __builtin_popcountll
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<": "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
void google(int t) {cout << "Case #" << t << ": ";}
ll binexpo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll min(ll a, ll b) {if (a > b) return b; return a;}
ll max(ll a, ll b) {if (a > b) return a; return b;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b) {return ((a * b) / (gcd(a, b)));}
/* ------------------------------------------------------------------------------------------------------------------------------------------------ */
class lazySeg {
private:
    vector<int>seg, lazy;
public:
    lazySeg(int n) {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1, 0);
    }
    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
    int query(int ind, int low, int high, int l, int r) {
        // l r is given range for query
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        //no overlap l r low high || low high l r
        if (low > r || l > high) {
            return 0;
        }
        //complete overlap l low high r
        if (low >= l && high <= r) {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    void update(int ind, int low, int high, int l, int r, int value) {
        // l r is given range for update
        //check if a lazy update is pending
        if (lazy[ind] != 0) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // l r is the given range for update
        // no overlap -> l r low high || low high l r
        if (low > r || l > high) {
            return;
        }
        //complete overlap -> l low high r
        if (low >= l && high <= r) {
            seg[ind] += (high - low + 1) * value;
            if (low != high) {
                lazy[2 * ind + 1] += value;
                lazy[2 * ind + 2] += value;
            }
            return;
        }
        //partial overlap
        int mid = (low + high) >> 1;
        update(2 * ind + 1, low, mid, l, r, value);
        update(2 * ind + 2, mid + 1, high, l, r, value);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};
void solve() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int>arr(n);
        vector<int>ss(n, 0);
        vector<vector<ll>>op(n, vector<ll>(22));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            op[i][0] = arr[i];
            ll cnt = 1;
            while (cnt <= 20) {
                ll sum = 0;
                while (arr[i] > 0) {
                    sum += (arr[i] % 10);
                    arr[i] /= 10;
                }
                arr[i] = sum;
                op[i][cnt] = sum;
                cnt++;
            }
        }
        lazySeg obj(n + 1);
        obj.build(0, 0, n - 1, ss);
        while (q--) {
            int tpy;
            cin >> tpy;
            if (tpy == 1) {
                ll l, r;
                cin >> l >> r;
                obj.update(0, 0, n - 1, l - 1, r - 1, 1);
            }
            else {
                ll x;
                cin >> x;
                ll ans = obj.query(0, 0, n - 1, x - 1, x - 1);
                ans = min(ans, 20);
                cout << op[x - 1][ans] << endl;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    solve();
}

