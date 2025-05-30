#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    
    int n; cin >> n;
    
    vector<int> countlist(1000, 0);
    int start, end, bnum;
    for (int i = 0; i < n; i++) {
        cin >> start >> end >> bnum;
        for (int j = start; j < end; j++) {
            countlist[j] += bnum;
        }
    }
    
    int max = 0;
    for (int i = 0; i < 1000; i++) {
        if (countlist[i] > max) {
            max = countlist[i];
        }
    }
    
    cout << max;
}