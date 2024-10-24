#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vs = vector<string>;

ll n;
vs bd;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  bd = vs(n);
  for (auto&& x : bd) {
    cin >> x;
  }

  ll max_ans = 0;
  // R
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n - 1; ++j) {
      if (bd[i][j] == bd[i][j + 1]) continue;

      // copy
      auto cp = bd;
      // swap
      auto tmp = cp[i][j];
      cp[i][j] = cp[i][j + 1];
      cp[i][j + 1] = tmp;
      // count R
      for (auto y = 0; y < n; ++y) {
        ll c = 1;
        auto nowchar = cp[y][0];
        for (auto x = 1; x < n; ++x) {
          if (cp[y][x] == nowchar) {
            ++c;
            max_ans = max(max_ans, c);
          } else {
            c = 1;
            nowchar = cp[y][x];
          }
        }
      }
      // count C
      for (auto x = 0; x < n; ++x) {
        ll c = 1;
        auto nowchar = cp[0][x];
        for (auto y = 1; y < n; ++y) {
          if (cp[y][x] == nowchar) {
            ++c;
            max_ans = max(max_ans, c);
          } else {
            c = 1;
            nowchar = cp[y][x];
          }
        }
      }
    }
  }
  // C
  for (auto i = 0; i < n; ++i) {
    for (auto j = 0; j < n - 1; ++j) {
      if (bd[j][i] == bd[j + 1][i]) continue;

      // copy
      auto cp = bd;
      // swap
      auto tmp = cp[j][i];
      cp[j][i] = cp[j + 1][i];
      cp[j + 1][i] = tmp;
      // count R
      for (auto y = 0; y < n; ++y) {
        ll c = 1;
        auto nowchar = cp[y][0];
        for (auto x = 1; x < n; ++x) {
          if (cp[y][x] == nowchar) {
            ++c;
            max_ans = max(max_ans, c);
          } else {
            c = 1;
            nowchar = cp[y][x];
          }
        }
      }
      // count C
      for (auto x = 0; x < n; ++x) {
        ll c = 1;
        auto nowchar = cp[0][x];
        for (auto y = 1; y < n; ++y) {
          if (cp[y][x] == nowchar) {
            ++c;
            max_ans = max(max_ans, c);
          } else {
            c = 1;
            nowchar = cp[y][x];
          }
        }
      }
    }
  }

  cout << max_ans;

  return 0;
}