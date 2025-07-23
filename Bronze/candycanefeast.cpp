#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m; cin >> n >> m;

  vector<long long> cows(n), canes(m);

  for (int i = 0; i < n; i++) { cin >> cows[i]; }
  for (int i = 0; i < m; i++) { cin >> canes[i]; }

  for (int i = 0; i < m; i++) {
    long long eaten = 0;
    for (int j = 0; j < n; j++) {
      if (cows[j] > eaten) {
        long long neweaten = min(canes[i], cows[j]);
        cows[j] += neweaten - eaten;
        eaten = neweaten;
      }
      if (eaten == canes[i]) {
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << cows[i] << endl;
  }
}