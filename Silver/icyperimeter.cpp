#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int contributes(vector<vector<pair<bool, bool>>> master, int i, int j) {
  if (i >= 0 && i < master.size() && j >= 0 && j < master.size()) {
    if (master[i][j].first) {
      return 0;
    } else {
      return 1;
    }
  } else {
    return 1;
  }
}

// Returns area, perimeter
pair<int, int> floodfill(vector<vector<pair<bool, bool>>> &master, int i,
                         int j) {
  if (i >= 0 && i < master.size() && j >= 0 && j < master.size())
    if (master[i][j].first && !master[i][j].second) {
      int area, peri;
      master[i][j].second = true;
      area = 1;

      peri = contributes(master, i + 1, j) + contributes(master, i - 1, j) +
             contributes(master, i, j + 1) + contributes(master, i, j - 1);

      pair<int, int> up, down, left, right;
      up = floodfill(master, i, j + 1);
      down = floodfill(master, i, j - 1);
      left = floodfill(master, i + 1, j);
      right = floodfill(master, i - 1, j);

      area += up.first + down.first + right.first + left.first;
      peri += up.second + down.second + right.second + left.second;

      return pair<int, int>(area, peri);
    }

  return pair<int, int>(0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("perimeter.in", "r", stdin);
  //freopen("perimeter.out", "w", stdout);

  int n;
  cin >> n;
  // Pair = (Present, Visited)
  vector<vector<pair<bool, bool>>> master(
      n, vector<pair<bool, bool>>(n, pair<bool, bool>(false, false)));

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;
    for (int j = 0; j < n; j++) {
      if (line[j] == '#') {
        master[i][j].first = true;
      }
    }
  }

  int largestconnected = 0;
  int perioflargest = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (master[i][j].first && !master[i][j].second) {
        pair<int, int> p = floodfill(master, i, j);
        if (p.first > largestconnected) {
          largestconnected = p.first;
          perioflargest = p.second;
        }
      }
    }
  }

  cout << largestconnected << " " << perioflargest;
}