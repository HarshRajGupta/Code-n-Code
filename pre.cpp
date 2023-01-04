#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K, S;
    cin >> N >> K >> S; // read in the input

    // check if an SS-good sequence is possible
    // if (S < -N || S > N) {
    //     cout << -2 << endl; // if not, print -2 and exit
    //     return 0;
    // }

    // initialize the SS-good sequence
    vector<int> B(N);
    int sum = 0;
    for (int i = N-1; i >= 0; i--) {
        if (sum + K < S) {
            B[i] = 1;
            sum += K;
        } else if (sum - K > S) {
            B[i] = -1;
            sum -= K;
        } else {
            B[i] = 0;
        }
        K *= 2;
    }

    // print the SS-good sequence
    for (int i = 0; i < N; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
