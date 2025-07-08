#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int n; cin >> n;

  vector<vector<int>> arr(n + 1, vector<int>(3, 0)); 
  for (int i = 1; i <= n; i++) {
    arr[i][0] = arr[i - 1][0];
    arr[i][1] = arr[i - 1][1];
    arr[i][2] = arr[i - 1][2];
    char in; cin >> in;
    if (in == 'H') {
      arr[i][0]++;
    }
    else if (in == 'P') {
      arr[i][1]++;
    }
    else {
      arr[i][2]++;
    }
  }

  int fmax = 0;
  for (int i = 1; i <= n; i++) {
    int tempmax = 0;
    tempmax += max(max(arr[i][0], arr[i][1]), arr[i][2]);
    tempmax += max(max(arr[n][0]-arr[i][0], arr[n][1]-arr[i][1]), arr[n][2]-arr[i][2]);
    fmax = max(fmax, tempmax);
  }

  cout << fmax;
}