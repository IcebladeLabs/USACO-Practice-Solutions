#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("censor.in", "r", stdin);
  freopen("censor.out", "w", stdout);

  string in, cen; cin >> in >> cen;

  for (int i = 0; i < in.size(); i++) {
    if (in[i] == cen[0]) {
      bool cut = true;
      for (int j = 0; j < cen.size(); j++) {
        if (in[i + j] != cen[j]) {
          cut = false;
          break;
        }
      }
      if (cut) {
        in.erase(i, cen.size());
        i -= cen.size();
        i = max(i, 0);
      }
    }
  }

  cout << in;
}