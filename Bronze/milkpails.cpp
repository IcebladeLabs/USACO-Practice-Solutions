#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  int x, y, m; cin >> x >> y >> m;

  int fmin = 2147483647;
  for (int i = 0; i <= m / x; i++) {
    fmin = min(fmin, (m - (i * x)) % y);
  }

  cout << m - fmin;
}