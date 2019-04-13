#ifndef SOLUTION_COMMON_H

#include <bits/stdc++.h>

using std::cout;using std::cin;using std::cerr;
using std::string;using std::vector;using std::pair;using std::set;using std::map;
using std::sort;using std::reverse;
using std::abs;using std::min;using std::max;
using std::lower_bound;
using std::function;
using std::to_string;using std::stoi;

using ll = long long;
using PI = pair<int, int>;
template<class T> using V = vector<T>;
using VI = V<int>;
#define _1 first
#define _2 second

int MOD = (int)1e9 + 7;

#ifdef MY_DEBUG
# define DEBUG(x) x
#else
# define DEBUG(x)
#endif

template <class T>
inline void debug(T &A) {
  DEBUG(
      for (const auto &a : A) {
        cerr << a << " ";
      }
      cerr << '\n';
  )
}

template <class T>
inline void debug_dim2(T &A) {
  DEBUG(
      for (const auto &as : A) {
        debug(as);
      }
  )
}

template <typename ... Args>
inline void debug(const char *format, Args const & ... args) {
  DEBUG(
      fprintf(stderr, format, args ...);
      cerr << '\n';
  )
}

template <typename ... Args>
string format(const std::string& fmt, Args ... args)
{
  size_t len = std::snprintf( nullptr, 0, fmt.c_str(), args ... );
  std::vector<char> buf(len + 1);
  std::snprintf(&buf[0], len + 1, fmt.c_str(), args ... );
  return std::string(&buf[0], &buf[0] + len);
}

#define SOLUTION_COMMON_H

#endif //SOLUTION_COMMON_H
