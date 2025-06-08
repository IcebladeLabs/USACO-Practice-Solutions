#include <iostream>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  int n; cin >> n;
  string road; cin >> road;

  for (int length = 1; length <= n; length++) {
    set<string> pieces = {};
    for (int i = 0; i <= n - length; i++) {
      pieces.insert(road.substr(i, length));
    }
    if (pieces.size() == n + 1 - length) {
      cout << length;
      break;
    }
  }
}