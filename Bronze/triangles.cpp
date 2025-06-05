#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n; cin >> n;

  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
  }

  int fmax = 0;
  int tempmax;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i].first == arr[j].first) {
        for (int k = 0; k < n; k++) {
          if (arr[k].second == arr[i].second) {
            tempmax = abs(arr[k].first - arr[i].first) * abs(arr[k].second - arr[j].second);
            fmax = max(tempmax, fmax);
          }
          else if (arr[k].second == arr[j].second) {
            tempmax = abs(arr[k].first - arr[j].first) * abs(arr[k].second - arr[i].second);
            fmax = max(tempmax, fmax);
          }
        }
      }
      if (arr[i].second == arr[j].second) {
        for (int k = 0; k < n; k++) {
          if (arr[k].first == arr[i].first) {
            tempmax = abs(arr[j].first - arr[i].first) * abs(arr[k].second - arr[j].second);
            fmax = max(tempmax, fmax);
          }
          else if (arr[k].first == arr[j].first) {
            tempmax = abs(arr[j].first - arr[i].first) * abs(arr[k].second - arr[i].second);
            fmax = max(tempmax, fmax);
          }
        }
      }
    }
  }

  cout << fmax;
}