#include <bits/stdc++.h>

namespace DECLARATIONS {
  using namespace std;

  using ll = long long;
  using PI = pair<int, int>;
  template<class T> using V = vector<T>;
  using VI = V<int>;
#define _1 first
#define _2 second

#ifdef MY_DEBUG
# define DEBUG(x) x
#else
# define DEBUG(x)
#endif

  template<class T>
  inline void debug(T &A) {
    DEBUG(
        for (const auto &a : A) {
          cerr << a << " ";
        }
        cerr << '\n';
    )
  }

  template<class T>
  inline void debug_dim2(T &A) {
    DEBUG(
        for (const auto &as : A) {
          debug(as);
        }
    )
  }

  template<typename ... Args>
  inline void debug(const char *format, Args const &... args) {
    DEBUG(
        fprintf(stderr, format, args ...);
        cerr << '\n';
    )
  }

  template<typename ... Args>
  string format(const std::string &fmt, Args ... args) {
    size_t len = std::snprintf(nullptr, 0, fmt.c_str(), args ...);
    std::vector<char> buf(len + 1);
    std::snprintf(&buf[0], len + 1, fmt.c_str(), args ...);
    return std::string(&buf[0], &buf[0] + len);
  }
}
using namespace DECLARATIONS;

const int MOD = 1000000007;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  debug("N:%d", N);

  return 0;
}