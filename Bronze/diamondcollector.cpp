#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int n, k; cin >> n >> k;

  vector<int> arr(n);
  for (int i = 0; i < n; i++) { cin >> arr[i]; }

  int maxnum = 0;
  
  for (int i = 0; i < n; i++) {
    int loopmax = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] >= arr[i] && arr[j] <= arr[i] + k) {
        loopmax++;
      }
    }
    maxnum = max(maxnum, loopmax);
  }

  cout << maxnum;
}