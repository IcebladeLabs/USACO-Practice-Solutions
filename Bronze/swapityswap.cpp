#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);

  int n, k; cin >> n >> k;
  int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;

  vector<int> order; for (int i = 1; i <= n; i++) { order.push_back(i); }

  vector<int> aswap(a2 - a1 + 1), bswap(b2 - b1 + 1);

  for (int i = 0; i < k; i++) {
    int counter = 0;
    for (int j = a1 - 1; j < a2; j++) {
      aswap[counter] = order[j];
      counter++;
    }
    for (int j = a1 - 1; j < a2; j++) {
      counter--;
      order[j] = aswap[counter];
    }
    counter = 0;
    for (int j = b1 - 1; j < b2; j++) {
      bswap[counter] = order[j];
      counter++;
    }
    for (int j = b1 - 1; j < b2; j++) {
      counter--;
      order[j] = bswap[counter];
    }
  }

  for (int i = 0; i < n; i++) { cout << order[i] << endl; }
}