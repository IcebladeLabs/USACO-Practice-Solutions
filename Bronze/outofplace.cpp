#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("outofplace.in", "r", stdin);
  freopen("outofplace.out", "w", stdout);

  int n; cin >> n;

  vector<int> line(n); for (int i = 0; i < n; i++) { cin >> line[i]; }

  for (int i = 1; i < line.size(); i++) {
    if (line[i] == line[i - 1]) {
      line.erase(line.begin() + i);
      i--;
    }
  }

  vector<int> sorted; for (int i = 0; i < line.size(); i++) { sorted.push_back(line[i]); }

  sort(sorted.begin(), sorted.end());

  int swaps = -1;
  for (int i = 0; i < line.size(); i++) {
    if (sorted[i] != line[i]) {
      swaps++;
    }
  }
  
  cout << max(swaps, 0);
}