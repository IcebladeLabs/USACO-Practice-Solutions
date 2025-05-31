#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n; cin >> n;

  vector<int> barn(n);
  for (int i = 0; i < n; i++) { cin >> barn[i]; }

  int fmin = 2147483647;

  int calcmin;
  for (int i = 0; i < n; i++) {
    calcmin = 0;
    for (int j = 0; j < n; j++) {
      calcmin += barn[(i+j) % n] * j;
    }
    fmin = min(calcmin, fmin);
  }

  cout << fmin;
}