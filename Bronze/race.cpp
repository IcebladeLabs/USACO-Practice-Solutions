#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

bool canMakeIt(int distanceRemaining, int speed, int x) {
  while (distanceRemaining > 0) {
    if (speed > 1) {
      speed--;
    }
    distanceRemaining -= speed;
  }
  if (speed > x) {
    return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("race.in", "r", stdin);
  freopen("race.out", "w", stdout);

  int k, n; cin >> k >> n;
  vector<int> xs(n); for (int i = 0; i < n; i++) { cin >> xs[i]; }

  for (int i = 0; i < n; i++) {
    int speed = 0;
    int distance = 0;
    int time = 0;

    while (distance < k) {
      if (canMakeIt(k - distance - speed - 1, speed + 1, xs[i])) {
        speed++;
      }
      else if (!canMakeIt(k - distance - speed, speed, xs[i])) {
        speed--;
      }

      time++;
      distance += speed;
    }

    cout << time << endl;
  }
}