#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool greedyChecker(vector<int> arr, int n, int k, int r) {
  vector<int> covered;
  int size = 1;
  covered.push_back(arr[0] + r);
  for (int i = 0; i < n; i++) {
    if (abs(covered.back() - arr[i]) > r) {
      size++;
      covered.push_back(arr[i] + r);
    }
  }
  if (size <= k) {
    return true;
  }
  else {
    return false;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("angry.in", "r", stdin);
  freopen("angry.out", "w", stdout);

  int n, k; cin >> n >> k;

  vector<int>  arr(n); for (int i = 0; i < n; i++) { cin >> arr[i]; }
  sort(arr.begin(), arr.end());

  int r = 1;
  int lower = 1; int upper = arr.back() / 2 + 1;

  while (lower < upper) {
    r = lower + ((upper - lower) / 2);
    if (greedyChecker(arr, n, k, r)) {
      upper = r;
    }
    else {
      lower = r + 1;
      upper *= 2;
    }
  }

  cout << lower;
}