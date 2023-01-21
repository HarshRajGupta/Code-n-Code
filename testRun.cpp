#include <bits/stdc++.h>
using namespace std;

void sendMail(const string email) {
    cout << email << '\n';
}


void addMail(const string &s, map<string, set<string>> &mp) {
    string address = "", domain = "";
    unsigned int i = 0;
    while (s[i] != '@') {
        address.push_back(s[i++]);
    }
    ++i; // skip @ symbol
    while (i < s.length()) {
        domain.push_back(s[i]);
    }
    mp[domain].insert(address); // adding email
}

void solve(string arr[], int n) {
    map<string, set<string>> mp;
    for (int i = 0; i < n; ++i) {
        addMail(arr[i], mp);
    }
    for (auto i : mp) {
        string email = *i.second.begin() + "@" + i.first;
        sendMail(email);
    }
}


int main() {
    int n; cin >> n;
    string arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    solve(arr, n);
    return 0;
}