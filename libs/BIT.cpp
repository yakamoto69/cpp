#include "common.h"

class BIT {
public:
  int N;
  V<ll> bit;
  BIT(int n): N(n + 1), bit(N) {}

  void add(int i, int x) {
    i++;
    while(i < N) {
      bit[i] += x;
      i += i & -i;
    }
  }

  ll query(int i) {
    ll ans = 0ll;
    while(i) {
      ans += bit[i];
      i -= i & -i;
    }
    return ans;
  }
};