#include "common.h"

ll sum(VI &A) {
  ll s = 0;
  for (int i : A) s += i;
  return s;
}

V<ll> cum_sum(VI &A) {
  V<ll> res(A.size() + 1);
  res[0] = 0;
  for (int i = 0; i < A.size(); ++i) {
    res[i + 1] = res[i] + A[i];
  }
  return res;
}

template <class T>
T max(V<T> &A) {
  return *std::max_element(A.begin(), A.end());
}

template <class T>
T min(V<T> &A) {
  return *std::min_element(A.begin(), A.end());
}

void remove(VI &A, int x) {
  A.erase(std::remove(A.begin(), A.end(), x), A.end());
}

VI distinct(VI &A) {
  VI res(A);
  sort(res.begin(), res.end());
  res.erase(unique(res.begin(), res.end()), res.end());
  return res;
}

/**
 * multisetのキーをiterateする方法
 */
void unique(std::multiset<int> A, const function<void(int)>& f) {
  for (auto it = A.begin(); it != A.end(); it = std::upper_bound(it, A.end(), *it)) {
    f(*it);
  }
}

int msb(int i) {
  i |= (i >>  1);
  i |= (i >>  2);
  i |= (i >>  4);
  i |= (i >>  8);
  i |= (i >> 16);
  return i - (((unsigned int)i) >> 1);
}

int log2(int x) {
  int i = 0;
  while(x >>= 1) i++;
  return i;
}