#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> in(n);
  for (int i = 0; i < n; i++) { cin >> in[i]; }

  sort(in.begin(), in.end());

  int count = 1; int uni = in[0];
  for (int i = 0; i < n; i++) {
    if (in[i] != uni)
    {
      uni = in[i];
      count++;
    }
  }
  cout << count;
}