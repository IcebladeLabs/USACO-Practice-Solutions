#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("pairup.in", "r", stdin);
  freopen("pairup.out", "w", stdout);

  int n; cin >> n;
  map<int, int> main;

  for (int i = 0; i < n; i++) {
    int key, value; cin >> value >> key;
    if (main.count(key) == 0) {
      main.insert({key, value});
    }
    else {
      main[key] += value;
    }
  }

  int fmax = 0;

  auto itone = main.begin();
  auto ittwo = main.end(); ittwo--;
  
  while (true) {
    fmax = max(fmax, itone->first + ittwo->first);
    if (itone->second == 0) {
      itone++;
    }
    else {
      itone->second--;
    }
    if (ittwo->second == 0) {
      ittwo--;
    }
    else {
      ittwo->second--;
    }
    if (itone->first >= ittwo->first) {
      break;
    }
  }

  cout << fmax;
}