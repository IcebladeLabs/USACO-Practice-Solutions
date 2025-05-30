#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);
    
    int farmer, bessie; cin >> farmer >> bessie;
    
    int distance = 0;
    int displacement = 1;
    
    while (true) {
        distance += abs(displacement);
        if (farmer <= bessie && bessie <= farmer + displacement) {
            break;
        }
        
        if (farmer >= bessie && bessie >= farmer + displacement) {
            break;
        }
        distance += abs(displacement);
        displacement *= -2;
    }
    distance -= abs(bessie - (displacement + farmer));
    cout << distance;
}