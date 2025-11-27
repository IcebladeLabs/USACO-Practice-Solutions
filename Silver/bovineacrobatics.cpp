#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m, k; cin >> n >> m >> k;

  vector<pair<int, int>> cows(n, pair<int, int>());

  for (int i = 0; i < n; i++) {
    cin >> cows[i].first >> cows[i].second;
  }

  sort(cows.rbegin(), cows.rend());

  vector<int> towers(m, 2000000000);
  int count = 0;

  for (int i = 0; i < n; i++) {
    int tindex = 0;
    while (cows[i].second > 0 && tindex < m) {
      if (towers[tindex] >= cows[i].first + k) {
        towers[tindex] = cows[i].first;
        cows[i].second--;
        count++;
      }
      tindex++;
    }
  }
  cout << count;
}