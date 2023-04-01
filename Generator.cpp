#include <bits/stdc++.h>

const long long MOD = 1e9 + 7, L = 211;
#define pr ((int)(rand()*(rand()%7+1)*(rand()%7+1)*1ll%MOD)/(rand()%7+1))
#define r ((pr * (rand() & 1 ? -1 : 1)))

class Solution {
    void generateArray(int n = rand() % L) {
        printf("%d\n", n); while (n--) printf("%d ", r); printf("\n");
    }
    void generatePArray(int n = rand() % L) {
        printf("%d\n", n); while (n--) printf("%d ", pr); printf("\n");
    }
    void generateBArray(int n = rand() % L) {
        printf("%d\n", n); while (n--) printf("%d ", rand() & 1); printf("\n");
    }
    void generateString(int n = rand() % L) {
        printf("%d\n", n); while (n--) printf("%c", 'a' + rand() % 26); printf("\n");
    }
    void generateUString(int n = rand() % L) {
        printf("%d\n", n); while (n--) printf("%c", 'A' + rand() % 26); printf("\n");
    }
    void generateTestCase(void) {
        /* generate test case */
        // generateArray();
        // generatePArray();
        generateBArray();
        // generateString();
        // generateUString();
    }
public:
    void test(void) {
        int t = rand() % 7 + 1; printf("%d\n", t);
        while (t--) generateTestCase();
    }
};

#ifdef __TEST__
__TEST__
#endif