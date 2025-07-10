#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("lemonade.in", "r", stdin);
  freopen("lemonade.out", "w", stdout);

  int n; cin >> n;

  vector<int> arr(n); for (int i = 0; i < n; i++) { cin >> arr[i]; }
  sort(arr.rbegin(), arr.rend());

  int count = 0;

  while (count < n) {
    if (arr[count] >= count) {
      count++;
    }
    else {
      break;
    }
  }
  
  cout << count;
}