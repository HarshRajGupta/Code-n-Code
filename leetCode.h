#define LeetCode \
signed main(void) { \
    std::cerr << std::fixed << std::setprecision(12) \
              << "<== Compilation: #Sucessful ==>" \
              << '\n' << std::endl; \
    auto __STARTING_TIME = std::chrono::high_resolution_clock::now(); \
    Solution().test(); \
    std::cerr << "\n<== RunTime: " \
              << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - __STARTING_TIME).count()) / 1e9 \
              << " sec ==>\n\n"; \
    return 0; \
}
