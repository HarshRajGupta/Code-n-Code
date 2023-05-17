#ifdef _GLIBCXX_IOSTREAM

#ifndef __MAIN__
#define __MAIN__ \
    signed main() { \
        std::cerr.tie(NULL); std::cerr.flush(); \
        std::cerr << std::fixed << std::setprecision(6) \
                  << "✅ Compiled Sucessfully ✅\n"; \
        auto __STARTING_TIME__ = std::chrono::high_resolution_clock::now(); \
        if (preCompute()) std::cerr << "  🤖 pC: " << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - __STARTING_TIME__).count()) / 1e9 << " sec 🤖\n"; \
        int32_t __TEST_CASES__; std::cin >> __TEST_CASES__; \
        std::cerr << "   🎯 Test Cases: #" << __TEST_CASES__ << " 🎯\n"<< std::endl; \
        for (int32_t __TEST_CASE__ = 1; __TEST_CASE__ <= __TEST_CASES__; ++__TEST_CASE__) { \
            std::cerr << "\t<== " << "TestCase: #" << __TEST_CASE__ << " ==>\n"; \
            std::cout << "#" << __TEST_CASE__ << ": "; \
            solve(); \
            std::cout << '\n'; \
        } \
        std::cerr << "\n🤖 RunTime: " \
                  << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - __STARTING_TIME__).count()) / 1e9 \
                  << " sec 🤖"; \
        return 0; \
    }
#endif

#ifndef __SOLVE__
#define __SOLVE__ \
    signed main() { \
        std::cerr << std::fixed << std::setprecision(6) \
                  << "  <== Compilation: ✅ ==>" << '\n' << std::endl; \
        auto __STARTING_TIME__ = std::chrono::high_resolution_clock::now(); \
        solve(); \
        std::cerr << "\n<==🤖 RunTime: " \
                  << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - __STARTING_TIME__).count()) / 1e9 \
                  << " 🤖==>"; \
        return 0; \
    }
#endif

#ifndef __TEST__
#define __TEST__ \
    signed main() { \
        srand(time(NULL)); \
        std::cerr << std::fixed << std::setprecision(6) \
                  << "  <== Compilation: ✅ ==>" << '\n' << std::endl; \
        auto __STARTING_TIME__ = std::chrono::high_resolution_clock::now(); \
        Solution().test(); \
        std::cerr << "\n<==🤖 RunTime: " \
                  << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - __STARTING_TIME__).count()) / 1e9 \
                  << " 🤖==>"; \
        return 0; \
    }
#endif


#ifndef __RUN
#define __RUN                                     \
    std::cerr << '\n'                             \
              << "\t<-- "                         \
              << "TestCase: #" << tC << " -->\n", \
        std::cout << "Case #" << tC << ": ", solve(), std::cout << '\n'
#endif

#ifndef __TAG1
#define __TAG1                                              \
    std::cerr.tie(NULL);                                    \
    std::cerr << std::fixed << std::setprecision(12)        \
              << "<== Compilation: #Sucessful ==>" << '\n'; \
    auto __STARTING_TIME = std::chrono::high_resolution_clock::now();
#endif

#ifndef __TAG2
#define __TAG2                                                                 \
    std::cerr                                                                  \
        << "\n<== RunTime: "                                                   \
        << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>( \
                std::chrono::high_resolution_clock::now() - __STARTING_TIME)   \
                .count()) /                                                    \
               1e9                                                             \
        << " sec ==>";
#endif

template <typename T> void __PRINT_VARIABLE(const T &x);

void __PRINT_VARIABLE(const int &x) { std::cerr << x; }
void __PRINT_VARIABLE(const long &x) { std::cerr << x; }
void __PRINT_VARIABLE(const long long &x) { std::cerr << x; }
void __PRINT_VARIABLE(const unsigned &x) { std::cerr << x; }
void __PRINT_VARIABLE(const unsigned long &x) { std::cerr << x; }
void __PRINT_VARIABLE(const unsigned long long &x) { std::cerr << x; }
void __PRINT_VARIABLE(const float &x) { std::cerr << x; }
void __PRINT_VARIABLE(const double &x) { std::cerr << x; }
void __PRINT_VARIABLE(const long double &x) { std::cerr << x; }
void __PRINT_VARIABLE(const char &x) { std::cerr << '\'' << x << '\''; }
void __PRINT_VARIABLE(const char *x) { std::cerr << '\"' << x << '\"'; }
void __PRINT_VARIABLE(const bool &x) { std::cerr << std::boolalpha << x; }

#ifdef _GLIBCXX_STRING // header file of string
void __PRINT_VARIABLE(const std::string &x) {
    std::cerr << '\"' << x << '\"';
}
#endif

#ifdef _GLIBCXX_UTILITY // header file of pair
template <typename T, typename V>
void __PRINT_VARIABLE(const std::pair<T, V> &x) {   // pair
    std::cerr << '(';
    __PRINT_VARIABLE(x.first);
    std::cerr << ", ";
    __PRINT_VARIABLE(x.second);
    std::cerr << ')';
}
#endif

#ifdef _GLIBCXX_QUEUE // header file of queue
template <typename T>
void __PRINT_VARIABLE(const std::queue<T> &x) {   // queue
    auto f = x;
    std::cerr << '[';
    while (!f.empty()) {
        __PRINT_VARIABLE(f.front());
        f.pop();
        if (!f.empty()) std::cerr << ", ";
    }
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::priority_queue<T> &x) {   // max heap
    auto f = x;
    std::cerr << '[';
    while (!f.empty()) {
        __PRINT_VARIABLE(f.top());
        f.pop();
        if (!f.empty()) std::cerr << ", ";
    }
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(
    const std::priority_queue<T, std::vector<T>, std::greater<T>>
    &x) {   // min heap
    auto f = x;
    std::cerr << '[';
    while (!f.empty()) {
        __PRINT_VARIABLE(f.top());
        f.pop();
        if (!f.empty()) std::cerr << ", ";
    }
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_STACK // header file of stack
template <typename T>
void __PRINT_VARIABLE(const std::stack<T> &x) {
    auto f = x;
    std::cerr << '[';
    while (!f.empty()) {
        std::cerr << f.top();
        f.pop();
        if (!f.empty()) std::cerr << ", ";
    }
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_VECTOR // header file of vector
template <typename T>
void __PRINT_VARIABLE(const std::vector<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

template <typename T, std::size_t SIZE>
void __PRINT_VARIABLE(const std::array<T, SIZE> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

#ifdef _GLIBCXX_FORWARD_LIST
template <typename T>
void __PRINT_VARIABLE(const std::forward_list<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_LIST
template <typename T>
void __PRINT_VARIABLE(const std::list<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}
#endif

template <typename T>
void __PRINT_VARIABLE(const std::set<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::multiset<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

template <typename K, typename V>
void __PRINT_VARIABLE(const std::map<K, V> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x) {
        std::cerr << (f++ ? ", " : "") << '(';
        __PRINT_VARIABLE(i.first);
        std::cerr << " : ";
        __PRINT_VARIABLE(i.second);
        std::cerr << ')';
    }
    std::cerr << ']';
}

template <typename K, typename V>
void __PRINT_VARIABLE(const std::multimap<K, V> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x) {
        std::cerr << (f++ ? ", " : "") << '(';
        __PRINT_VARIABLE(i.first);
        std::cerr << " : ";
        __PRINT_VARIABLE(i.second);
        std::cerr << ')';
    }
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::unordered_set<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::unordered_multiset<T> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x)
        std::cerr << (f++ ? ", " : ""),
            __PRINT_VARIABLE(i);
    std::cerr << ']';
}

template <typename K, typename V>
void __PRINT_VARIABLE(const std::unordered_map<K, V> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x) {
        std::cerr << (f++ ? ", " : "") << '(';
        __PRINT_VARIABLE(i.first);
        std::cerr << " : ";
        __PRINT_VARIABLE(i.second);
        std::cerr << ')';
    }
    std::cerr << ']';
}

template <typename K, typename V>
void __PRINT_VARIABLE(const std::unordered_multimap<K, V> &x) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (const auto &i : x) {
        std::cerr << (f++ ? ", " : "") << '(';
        __PRINT_VARIABLE(i.first);
        std::cerr << " : ";
        __PRINT_VARIABLE(i.second);
        std::cerr << ')';
    }
    std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const T &x) {
    std::cerr << "NA";
}

void __DEBUG_VAR(std::queue<std::string> &s) {
    std::cerr << "\n}\n";
}

template <typename T, typename... V>
void __DEBUG_VAR(std::queue<std::string> &s, const T t, V... v) {
    std::cerr << '\t' << s.front() << ": ";
    s.pop();
    __PRINT_VARIABLE(t);
    if (sizeof...(v)) std::cerr << ",  \n";
    __DEBUG_VAR(s, v...);
}

#ifndef debug
#define debug(x...)                                        \
    {                                                      \
        std::queue<std::string> __VARIABLES_LIST;         \
        std::string CURR_VARIABLE = "", ALL_VARIABLE = #x; \
        for (auto &i : ALL_VARIABLE)                        \
        {                                                  \
            if (i == ',')                                  \
            {                                              \
                __VARIABLES_LIST.push(CURR_VARIABLE); \
                CURR_VARIABLE = "";                        \
            }                                              \
            else if (i != ' ')                             \
                CURR_VARIABLE.push_back(i);                \
        }                                                  \
        __VARIABLES_LIST.push(CURR_VARIABLE);         \
        std::cerr << "{ " << #x << " } => {\n";            \
        __DEBUG_VAR(__VARIABLES_LIST, x);                  \
    }
#endif
#endif