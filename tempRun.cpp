#include <bits/stdc++.h>
using namespace std;


double averageOfMaxAndMin(const int arr[], int n) {
    double MAX = arr[0], MIN = arr[0];
    for (int i = 0; i < n; ++i) {
        MAX = max((int)MAX, arr[i]);
        MIN = min((int)MIN, arr[i]);
    }
    return (MAX + MIN) / 2;
}


int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << averageOfMaxAndMin(arr, n);
    return 0;
}