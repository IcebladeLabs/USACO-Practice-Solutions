#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);

  int n; cin >> n;

  vector<int> master(26, 0);

  for (int i = 0; i < n; i++) {
    vector<int> currentone(26, 0);
    vector<int> currenttwo(26, 0);
    
    string blockone, blocktwo; cin >> blockone >> blocktwo;

    for (int j = 0; j < blockone.length(); j++) {
      currentone[blockone[j] - 'a']++;
    }

    for (int j = 0; j < blocktwo.length(); j++) {
      currenttwo[blocktwo[j] - 'a']++;
    }

    for (int j = 0; j < 26; j++) {
      master[j] += max(currentone[j], currenttwo[j]);
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << master[i] << endl;
  }
}