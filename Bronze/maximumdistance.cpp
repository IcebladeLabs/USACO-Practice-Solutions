#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> x(n);
  vector<int> y(n);

  int in;
  for (int i = 0; i < n; i++)
  {
    cin >> x[i];
  }

  for (int i = 0; i < n; i++)
  {
    cin >> y[i];
  }

  int maxi = 0;
  int distance = 0;
  for (int i = 0; i < n - 1; i++)
  {
      for (int j = i + 1; j < n; j++)
      {
        distance = ((x[i] - x[j]) * (x[i] - x[j])) + ((y[i] - y[j]) * (y[i] - y[j]));
        maxi = max(maxi, distance);
      }
  }

  cout << maxi;
}