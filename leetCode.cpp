#include <bits/stdc++.h>
using namespace std;

const int lB(vector<int> &arr, const int t) {
    int l = 0,  r = (arr.size() - 1);
    if (arr[l] >= t) return l - 1;
    if (arr[r] < t) return r;
    int ans = l - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] >= t) r = (mid - 1);
        else ans = mid, l = (mid + 1);
    }
    return ans;
}

const int bS(const vector<int> &arr, const int t) {
    int l = 0, r = (arr.size() - 1);
    while (l <= r) {
        const int mid = (l + r) >> 1;
        if (arr[mid] == t)
            return mid;
        else if (arr[mid] > t)
            r = (mid - 1);
        else
            l = (mid + 1);
    }
    return ((arr[l] == t) ? l : ((arr[r] == t) ? r : -1));
}


vector<int> bruteforce(int n, vector<int> &q) {
    vector<int> ans;
    for (int &i : q) {
        int curr = 0, pos = 1;
        bool inc = true;
        while (curr < n * n) {
            if (pos >= n) inc = false;
            if (inc) {
                curr += pos;
                pos++;
            } else {
                curr += pos;
                pos--;
            }
            if (curr > i) {
                ans.push_back(pos - 1);
                break;
            }
        }
    }
    return ans;
}

vector<int> find_x(int n, int k, vector<int> &q) {
    int curr = 0, pos = 1;
    bool inc = true;
    vector<int> arr;
    while (curr < n * n) {
        if (pos >= n) inc = false;
        if (inc) {
            curr += pos;
            pos++;
            arr.push_back(curr);
        } else {
            curr += pos;
            pos--;
            arr.push_back(curr);
        }
    }
    debug(arr)
    vector<int> ans;
    for (int i : q) {
        int pos = bS(arr, i);
        if (pos != -1) ans.push_back(pos + 1);
        else {
            pos = lB(arr, i) + 1;
            ans.push_back(pos + 1);
        }
    }
    return ans;
}

signed main(void) {
    int n, q; cin >> n >> q;
    vector<int> queries(q);
    for (int &i : queries) cin >> i;
    vector<int> ans = find_x(n, q, queries), brute = bruteforce(n, queries);
    for (int i = 0; i < q; ++i) {
        if (ans[i] != brute[i]) {
            cout << "WA on " << i << ' ' << queries[i] << endl;
            cout << "Expected: " << brute[i] << endl;
            cout << "Got: " << ans[i] << endl;
            // return 0;
        }
    }
    // for (int &i : ans) cout << i << ' ';
    return 0;
}