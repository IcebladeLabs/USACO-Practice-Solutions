#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("notlast.in", "r", stdin);
  freopen("notlast.out", "w", stdout);

  int n; cin >> n;

  map<string, int> dict;
  dict["Bessie"] = dict["Elsie"] = dict["Daisy"] = dict["Gertie"] = dict["Annabelle"] = dict["Maggie"] = dict["Henrietta"] = 0;

  for (int i = 0; i < n; i++) {
    string in; int milk;
    cin >> in >> milk;
    dict[in] += milk;
  }

  vector<pair<int, string>> tosort;
  for (pair<string, int> p : dict) {
    pair<int, string> x = {p.second, p.first};
    tosort.push_back(x);
  }

  sort(tosort.begin(), tosort.end());

  bool tied = false;
  int min = tosort[0].first; int secondmin = -1; int index = -1;
  for (int i = 1; i < tosort.size(); i++) {
    if (tosort[i].first > min && secondmin == -1) {
      secondmin = tosort[i].first;
      index = i;
    }
    else if (tosort[i].first == secondmin) {
      cout << "Tie" << endl;
      tied = true;
    }
    else if (i == tosort.size() - 1 && secondmin == -1) {
      cout << "Tie" << endl;
      tied = true;
    }
  }

  if (!tied) { cout << tosort[index].second << endl; }
}