#include <iostream>
#include <vector>

using namespace std;

// Returns the longest good sequence with respect to the given binary array.
// If multiple possible longest sequences exist, any of them can be returned.
vector<int> longestGoodSequence(vector<int>& array) {
    int n = array.size();
    // We will keep track of the current good sequence using a stack.
    // The stack will store the indices of the good sequence.
    vector<int> stack;
    for (int i = 0; i < n; i++) {
        // If the current element is a 1, we can always add it to the good sequence.
        if (array[i] == 1) {
            stack.push_back(i);
        } else {
            // If the current element is a 0, we need to check whether it is part of a good sequence.
            // If it is, we will add it to the good sequence. Otherwise, we will discard it.
            int cnt_ones = 0, cnt_zeros = 0;
            for (int j = i; j < n; j++) {
                if (array[j] == 1) {
                    cnt_ones++;
                } else {
                    cnt_zeros++;
                }
                if (cnt_ones - cnt_zeros == j - i) {
                    stack.push_back(i);
                    break;
                }
            }
        }
    }
    // The final good sequence is the one stored in the stack.
    return stack;
}

int main() {
    // Let's test the function with a sample input.
    vector<int> array = {0, 1, 1, 0, 1, 1};
    vector<int> result = longestGoodSequence(array);
    cout << "Longest good sequence: ";
    for (int i : result) {
        cout << i + 1 << " ";
    }
    cout << endl;
    return 0;
}
