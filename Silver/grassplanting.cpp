#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  int n; cin >> n;

  vector<int> arr(n, 0);

  for (int i = 0; i < n - 1; i++) {
    int a, b; cin >> a >> b;

    arr[a - 1]++; arr[b-1]++;
  }

  int maxconns = 0;

  for (int i = 0; i < n; i++) {
    maxconns = max(maxconns, arr[i]);
  }

  maxconns += 1;
  cout << maxconns;
  
}