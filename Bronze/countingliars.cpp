#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;

  vector<int> dir(n), num(n);
  vector<int> tocheck;
  for (int i = 0; i < n; i++) {
    char in;
    cin >> in;
    if (in == 'G') {
      dir[i] = 1;
    }
    else {
      dir[i] = 0;
    }
    cin >> num[i];
    tocheck.push_back(num[i] + 1); tocheck.push_back(num[i]);
  }

  int fmin = 2147483647;
  for (int i = 0; i < tocheck.size(); i++) {
    int liars = 0;
    for (int j = 0; j < n; j++) {
      if (dir[j] == 1 && tocheck[i] < num[j]) {
        liars++;
      }
      else if (dir[j] == 0 && tocheck[i] > num[j]) {
        liars++;
      }
    }
    fmin = min(fmin, liars);
  }

  cout << fmin;
}