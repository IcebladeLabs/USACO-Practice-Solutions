#include <cstdio>
#include <iostream>
#include <array>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  array<int, 100> speed;
  array<int, 100> bessie;

  int miles;
  int whee;
  int speedindex = 0;
  
  for (int i = 0; i < n; i++)
  {
    cin >> miles;
    cin >> whee;
    
    for (int j = 0; j < miles; j++)
    {
      speed[speedindex] = whee;
      speedindex++;
    }
  }

  speedindex = 0;

  for (int i = 0; i < m; i++)
  {
    cin >> miles;
    cin >> whee;

    for (int j = 0; j < miles; j++)
    {
      bessie[speedindex] = whee;
      speedindex++;
    }
  }

  int maxover = 0;
  for (int t = 0; t < 100; t++)
  {
      if ((bessie[t] - speed[t]) > maxover)
      {
        maxover = bessie[t] - speed[t];
      }
  }

  cout << maxover;
}