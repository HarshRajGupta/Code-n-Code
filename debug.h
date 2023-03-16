#ifdef _GLIBCXX_IOSTREAM

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
        << " sec ==>\n\n";
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
    std::cerr << " : ";
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
inline void __PRINT_VARIABLE(const T &x) {
    if (std::rank<T>::value == 0) {
        std::cerr << '[';
        unsigned long long f = 0;
        for (auto i : x) std::cerr << (f++ ? ", " : ""), __PRINT_VARIABLE(i);
        std::cerr << ']';
    }
    else std::cerr << "NA";

}
#endif

template <typename T>
struct __ARRAY {
    T* val;
    int size;
    __ARRAY() {
        val = NULL;
        size = 0;
    }
    __ARRAY(T __VAL[], const int __SIZE) {
        val = __VAL;
        size = __SIZE;
    }
};

template <typename T>
void __PRINT_VARIABLE(const __ARRAY<T> &x) {
    std::cerr << '[';
    for (int i = 0; i < x.size; ++i) {
        __PRINT_VARIABLE(x.val[i]);
        if (i + 1 < x.size) {
            std::cerr << ", ";
        }
    }
    std::cerr << ']';
}

void __DEBUG_VAR(std::vector<std::string> &s) {
    std::cerr << "\n}\n";
}

template <typename T, typename... V>
void __DEBUG_VAR(std::vector<std::string> &s, const T t, V... v) {
    std::cerr << '\t' << *s.begin() << ": ";
    s.erase(s.begin());
    __PRINT_VARIABLE(t);
    if (sizeof...(v)) std::cerr << ",  \n";
    __DEBUG_VAR(s, v...);
}

#ifndef debug
#define debug(x...)                                        \
    {                                                      \
        std::vector<std::string> __VARIABLES_LIST;         \
        std::string CURR_VARIABLE = "", ALL_VARIABLE = #x; \
        for (auto i : ALL_VARIABLE)                        \
        {                                                  \
            if (i == ',')                                  \
            {                                              \
                __VARIABLES_LIST.push_back(CURR_VARIABLE); \
                CURR_VARIABLE = "";                        \
            }                                              \
            else if (i != ' ')                             \
                CURR_VARIABLE.push_back(i);                \
        }                                                  \
        __VARIABLES_LIST.push_back(CURR_VARIABLE);         \
        std::cerr << "{ " << #x << " } => {\n";            \
        __DEBUG_VAR(__VARIABLES_LIST, x);                  \
    }
#endif
#endif