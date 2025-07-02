#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);

  int n, q; cin >> n >> q;

  vector<vector<int>> index(n + 1, vector<int>(3, 0));
  for (int i = 1; i <= n; i++) {
    int iter; cin >> iter; iter--;
    index[i][0] = index[i - 1][0];
    index[i][1] = index[i - 1][1];
    index[i][2] = index[i - 1][2];
    index[i][iter]++;
  }

  for (int i = 0; i < q; i++) {
    int a, b; cin >> a >> b;
    cout << index[b][0] - index[a - 1][0] << " " << index[b][1] - index[a - 1][1] << " " << index[b][2] - index[a - 1][2] << endl;
  }
}