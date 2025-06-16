#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);

  int lx1, ly1, lx2, ly2; cin >> lx1 >> ly1 >> lx2 >> ly2;
  int fx1, fy1, fx2, fy2; cin >> fx1 >> fy1 >> fx2 >> fy2;

  int fmin = (ly2 - ly1) * (lx2 - lx1);
  
  if (fy1 <= ly1 && fy2 >= ly1) {
    if (fx1 <= lx1 && fx2 >= lx2) {
      fmin = min(max(0, ly2 - fy2) * (lx2 - lx1), fmin);
    }
  }
  if (fy1 <= ly2 && fy2 >= ly2) {
    if (fx1 <= lx1 && fx2 >= lx2) {
      fmin = min(max(0, fy1 - ly1) * (lx2 - lx1), fmin);
    }
  }
  if (fx1 <= lx1 && fx2 >= lx1) {
    if (fy1 <= ly1 && fy2 >= ly2) {
      fmin = min(max(0, lx2 - fx2) * (ly2 - ly1), fmin);
    }
  }
  if (fx1 <= lx2 && fx2 >= lx2) {
    if (fy1 <= ly1 && fy2 >= ly2) {
      fmin = min(max(0, fx1 - lx1) * (ly2 - ly1), fmin);
    }
  }

  cout << fmin;
}