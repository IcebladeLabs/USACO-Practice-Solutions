#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

bool isNice(int n, vector<int> arr) {
  set<int> used = {};
  int current = -1;
  for (int i = 0; i < n; i++) {
    if (current != arr[i]) {
      if (used.count(arr[i]) == 0) {
        used.insert(current);
        current = arr[i];
      }
      else {
        return false;
      }
    }
  }
  return true;
}

vector<int> transformArr(int from, int to, vector<int> arr) {
  vector<int> ret;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == from) { ret.push_back(to); }
    else { ret.push_back(arr[i]); }
  }
  return ret;
}

vector<pair<int, int>> allTransforms(set<int> s) {
  vector<pair<int, int>> arr;
  for (auto i : s) {
    for (auto j : s) {
      if (i != j) {
        arr.push_back({i, j});
      }
    }
  }
  return arr;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q; cin >> n >> q;
  vector<int> input(n); for (int i = 0; i < n; i++) { cin >> input[i]; }
  set<int> uniques(input.begin(), input.end());

  vector<tuple<set<int>, vector<int>, int>> mainiterator;
  mainiterator.push_back({uniques, input, 0});

  int mindiff = 300000;
  while (mainiterator.size() > 0) {
    if (isNice(n, get<1>(mainiterator[0]))) {
      int diff = 0;
      for (int i = 0; i < n; i++) {
        if (input[i] != get<1>(mainiterator[0])[i]) { diff++; }
      }
      mindiff = min(diff, mindiff);
      mainiterator.erase(mainiterator.begin());
      continue;
    }

    vector<pair<int, int>> choices = allTransforms(get<0>(mainiterator[0]));

    for (auto i : choices) {
      set<int> s = get<0>(mainiterator[0]);
      s.erase(i.first);
      vector<int> v = get<1>(mainiterator[0]);
      v = transformArr(i.first, i.second, v);
      int swaps = get<2>(mainiterator[0]);
      swaps += 1;
      mainiterator.push_back({s, v, swaps});
    }
    mainiterator.erase(mainiterator.begin());
  }

  cout << mindiff;
}