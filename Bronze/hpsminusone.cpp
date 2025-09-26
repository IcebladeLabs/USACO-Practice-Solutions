#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, m; cin >> n >> m;

  vector<vector<int>> wins(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    string in; cin >> in;
    for (int j = 0; j < in.size(); j++) {
      if (in[j] == 'W') {
        wins[i][j] = 1;
        wins[j][i] = -1;
      }
      else if (in[j] == 'L') {
        wins[i][j] = -1;
        wins[j][i] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    int cow = 0;
    for (int j = 0; j < n; j++) {
      if (wins[l - 1][j] == -1 && wins[r - 1][j] == -1) {
        cow++;
      }
    }
    int winpairs = 0;
    winpairs += cow * n;
    winpairs += cow * (n - cow);
    cout << winpairs << endl;
  }
}