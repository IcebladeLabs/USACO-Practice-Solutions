#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio();
  cin.tie(nullptr);
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int k, n; cin >> k >> n;

  vector<vector<int>> count(n, vector<int>(n, 0));

  int inhelp = 0;
  for (int i = 0; i < k; i++) {
    vector<int> arr;
    for (int j = 0; j < n; j++) {
      cin >> inhelp;
      arr.push_back(inhelp);
    }

    for (int w = 0; w < n; w++) {
      for (int l = w + 1; l < n; l++) {
        count[arr[w] - 1][arr[l] - 1]++;
      }
    }
  }
  
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (count[i][j] == k)
      {
        ret++;
      }
    }
  }
  cout << ret;
}