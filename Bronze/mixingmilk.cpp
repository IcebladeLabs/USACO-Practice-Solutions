#include <iostream>
#include <cstdio>
#include <array>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  array<int, 3> milk;
  array<int, 3> capacity;
  int c1, m1, c2, m2, c3, m3;
  cin >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;
  milk[0] = m1; milk[1] = m2; milk[2] = m3;
  capacity[0] = c1; capacity[1] = c2; capacity[2] = c3;

  int transfer;
  for (int i = 0; i < 100; i++)
  {
      int bucket1 = i % 3;
      int bucket2 = (i + 1) % 3;

      transfer = min(capacity[bucket2] - milk[bucket2], milk[bucket1]);
      milk[bucket1] -= transfer;
      milk[bucket2] += transfer;
  }

  cout << milk[0] << endl << milk[1] << endl << milk[2];
}