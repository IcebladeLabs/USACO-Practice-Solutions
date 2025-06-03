#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n; cin >> n;

  vector<int> in(n); for (int i = 0; i < n; i++) { cin >> in[i]; }

  vector<pair<int, int>> master;
  int fullcount = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      master.push_back(pair<int, int> {i, j});
    }
  }

  for (int i = 0; i < master.size(); i++) {
    int sum = 0;
    for (int j = master[i].first; j <= master[i].second; j++) {
      sum += in[j];
    }
    double average = (double) sum / (master[i].second - master[i].first + 1);
    for (int j = master[i].first; j <= master[i].second; j++) {
      if (average == (double) in[j]) {
        fullcount++;
        break;
      }
    }
  }
  cout << fullcount;
}