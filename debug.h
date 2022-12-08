#ifdef _GLIBCXX_IOSTREAM

#ifndef __RUN
#define __RUN                                                                  \
  std::cerr << '\n'                                                            \
            << '\t' << "TestCase: #" << tC << '\n',                            \
      std::cout << "Case #" << tC << ": ", solve(), std::cout << '\n'
#endif

#ifndef __TAG0
#define __TAG0                                                                 \
  cerr.tie(NULL);                                                              \
  clock_t __Starting_Time = clock();                                           \
  std::cerr << "-*- Compilation: #Sucessful -*-" << '\n' << "TestCases: #";
#endif

#ifndef __TAG1
#define __TAG1                                                                 \
  cerr.tie(NULL);                                                              \
  std::cerr << fixed << setprecision(12) << "-*- Compilation: #Sucessful -*-"  \
            << '\n';                                                           \
  auto __STARTING_TIME = std::chrono::high_resolution_clock::now();
#endif

#ifndef __TAG2
#define __TAG2                                                                 \
  std::cerr                                                                    \
      << "\n-*- RunTime: "                                                     \
      << ((long double)std::chrono::duration_cast<std::chrono::nanoseconds>(   \
              std::chrono::high_resolution_clock::now() - __STARTING_TIME)     \
              .count()) /                                                      \
             1e9                                                               \
      << " sec -*-" << 12;
#endif

template <typename T> void __PRINT_VARIABLE(const T &x);

void __PRINT_VARIABLE(const int x) { std::cerr << x; }
void __PRINT_VARIABLE(const long x) { std::cerr << x; }
void __PRINT_VARIABLE(const long long x) { std::cerr << x; }
void __PRINT_VARIABLE(const unsigned x) { std::cerr << x; }
void __PRINT_VARIABLE(const unsigned long x) { std::cerr << x; }
void __PRINT_VARIABLE(const unsigned long long x) { std::cerr << x; }
void __PRINT_VARIABLE(const float x) { std::cerr << x; }
void __PRINT_VARIABLE(const double x) { std::cerr << x; }
void __PRINT_VARIABLE(const long double x) { std::cerr << x; }
void __PRINT_VARIABLE(const char x) { std::cerr << '\'' << x << '\''; }
void __PRINT_VARIABLE(const char *x) { std::cerr << '\"' << x << '\"'; }
void __PRINT_VARIABLE(const bool x) { std::cerr << std::boolalpha << x; }

#ifdef _GLIBCXX_STRING // header file of string
void __PRINT_VARIABLE(const std::string &x) { std::cerr << '\"' << x << '\"'; }
#endif

#ifdef _GLIBCXX_UTILITY // header file of pair
template <typename T, typename V>
void __PRINT_VARIABLE(const std::pair<T, V> &x) {
  std::cerr << '(';
  __PRINT_VARIABLE(x.first);
  std::cerr << " : ";
  __PRINT_VARIABLE(x.second);
  std::cerr << ')';
}
#endif

#ifdef _GLIBCXX_QUEUE // header file of queue
template <typename T> void __PRINT_VARIABLE(const std::queue<T> &x) {
  auto f = x;
  std::cerr << '[';
  while (!f.empty()) {
    __PRINT_VARIABLE(f.front());
    f.pop();
    if (!f.empty())
      std::cerr << ", ";
  }
  std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(const std::priority_queue<T> &x) { // max heap
  auto f = x;
  std::cerr << '[';
  while (!f.empty()) {
    __PRINT_VARIABLE(f.top());
    f.pop();
    if (!f.empty())
      std::cerr << ", ";
  }
  std::cerr << ']';
}

template <typename T>
void __PRINT_VARIABLE(
    const std::priority_queue<T, std::vector<T>, std::greater<T>>
        &x) { // min heap
  auto f = x;
  std::cerr << '[';
  while (!f.empty()) {
    __PRINT_VARIABLE(f.top());
    f.pop();
    if (!f.empty())
      std::cerr << ", ";
  }
  std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_STACK // header file of stack
template <typename T> void __PRINT_VARIABLE(const std::stack<T> &x) {
  auto f = x;
  std::cerr << '[';
  while (!f.empty()) {
    std::cerr << f.top();
    f.pop();
    if (!f.empty())
      std::cerr << ", ";
  }
  std::cerr << ']';
}
#endif

#ifdef _GLIBCXX_VECTOR // header file of vector
template <typename T> inline void __PRINT_VARIABLE(const T &x) {
  if (std::rank<T>::value == 0) {
    std::cerr << '[';
    unsigned long long f = 0;
    for (auto i : x)
      std::cerr << (f++ ? ", " : ""), __PRINT_VARIABLE(i);
    std::cerr << ']';
  } else {
    std::cerr << "NA";
  }
}
#endif

void __DEBUG_VAR() { std::cerr << "\n    }\n"; }

template <typename T, typename... V> void __DEBUG_VAR(const T t, V... v) {
  std::cerr << "  ";
  __PRINT_VARIABLE(t);
  if (sizeof...(v))
    std::cerr << ",  \n\t";
  __DEBUG_VAR(v...);
}

#ifndef debug
#define debug(x...)                                                            \
  {                                                                            \
    std::cerr << "{" << #x << "} => {\n\t";                                    \
    __DEBUG_VAR(x);                                                            \
  }
#endif
#else
#ifndef debug
#define debug(...)
#endif
#endif