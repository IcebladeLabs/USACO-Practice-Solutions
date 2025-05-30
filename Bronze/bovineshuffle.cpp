#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    
    int n; cin >> n;
    
    vector<int> order(n);
    for (int i = 0; i < n; i++) {cin >> order[i];}
    
    vector<int> output(n);
    for (int i = 0; i < n; i++) {cin >> output[i];}
    
    vector<int> temp(n);
    for (int i = 0; i < n; i++) {
        temp[i] = output[order[i] - 1];
    }
    
    for (int i = 0; i < n; i++) {
        output[i] = temp[order[i] - 1];
    }
    
    for (int i = 0; i < n; i++) {
        temp[i] = output[order[i] - 1];
    }
    
    for (int i = 0; i < n; i++) {
        cout << temp[i] << endl;
    }
}