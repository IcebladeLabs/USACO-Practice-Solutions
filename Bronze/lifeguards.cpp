#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n; cin >> n;

  vector<int> start(n), end(n);
  for (int i = 0; i < n; i++) { cin >> start[i] >> end[i]; }

  int fmax = 0;
  for (int i = 0; i < n; i++) {
    vector<int> arr(1000, 0);
    int tempmax = 0;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        for (int k = start[j]; k < end[j]; k++) {
          arr[k]++;
        }
      }
    }
    for (int j = 0; j < 1000; j++) {
      if (arr[j] != 0) {
        tempmax++;
      }
    }
    fmax = max(fmax, tempmax);
  }

  cout << fmax;
}