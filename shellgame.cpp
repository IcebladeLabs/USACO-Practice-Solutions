#include <cstdio>
#include <iostream>
#include <array>

using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  array<int, 3> arr;
  arr[0] = 0;
  arr[1] = 1;
  arr[2] = 2;

  int count1, count2, count3;
  count1 = count2 = count3 = 0;

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int swap1, swap2, access;
    cin >> swap1 >> swap2 >> access;
    swap1--, swap2--, access--;
    int temp = arr[swap1];
    arr[swap1] = arr[swap2];
    arr[swap2] = temp;
    if (arr[access] == 0) {
      count1++;
    } else if (arr[access] == 1) {
      count2++;
    } else {
      count3++;
    }
  }

  cout << max(count1, max(count2, count3));
}