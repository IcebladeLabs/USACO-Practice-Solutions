#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int b, n; cin >> n >> b;

  int xpos[n], ypos[n];
  for (int i = 0; i < n; i++) {
    cin >> xpos[i] >> ypos[i];
  }

  int fmax = n;
  int horiz;
  int vert;
  int q1, q2, q3, q4;
  
  for (int i : xpos) {
    vert = i - 1;
    for (int j : ypos) {
      horiz = j - 1;
      q1 = q2 = q3 = q4 = 0;
      for (int k = 0; k < n; k++) {
        if (xpos[k] > vert) {
          if (ypos[k] > horiz) {
            q1++;
          }
          else {
            q4++;
          }
        }
        else {
          if (ypos[k] > horiz) {
            q2++;
          }
          else {
            q3++;
          }
        }
      }
      fmax = min(max(max(q1, q2), max(q3, q4)), fmax);
    }
  }
  cout << fmax;
}