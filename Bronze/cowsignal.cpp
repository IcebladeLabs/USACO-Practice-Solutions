#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);
    
    int m, n, k; cin >> m >> n >> k;
    
    string input;
    for (int i = 0; i < m; i++) {
        cin >> input;
        for (int w = 0; w < k; w++) {
            for (int j = 0; j < n; j++) {
                for (int l = 0; l < k; l++) {
                    cout << input[j];
                }
            }
            cout << endl;
        }
    }
}