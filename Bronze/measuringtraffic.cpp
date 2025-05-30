#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);

  int n;
  cin >> n;

  vector<int> state(n), bottom(n), top(n);
  string inhelp;
  for (int i = 0; i < n; i++) {
    cin >> inhelp >> bottom[i] >> top[i];
    if (inhelp == "none") {
      state[i] = 0;
    }
    else if (inhelp == "on") {
      state[i] = 1;
    } else {
      state[i] = -1;
    }
  }

  int flow = 0;
  int fhigh = 10000000;

  
  for (int j = 0; j < n; j++) {
    if (state[j] == 1) {
      flow += bottom[j];
      fhigh += top[j];
    }
    else if (state[j] == -1) {
      flow -= top[j];
      fhigh -= bottom[j];
    } 
    else {
      if (bottom[j] > flow) {
        flow = bottom[j];
      }
      if (top[j] < fhigh) {
        fhigh = top[j];
      }
    }
  }

  int slow = flow;
  int shigh = fhigh;

  for (int j = n - 1; j >= 0; j--) {
    if (state[j] == -1) {
      slow += bottom[j];
      shigh += top[j];
    }
    else if (state[j] == 1) {
      slow -= top[j];
      shigh -= bottom[j];
    } 
    else {
      if (bottom[j] > slow) {
        slow = bottom[j];
      }
      if (top[j] < shigh) {
        shigh = top[j];
      }
    }
  }
  
  slow = max(slow, 0); flow = max(flow, 0);
  cout << slow << " " << shigh << endl;
  cout << flow << " " << fhigh << endl;
}
