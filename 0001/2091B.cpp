#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        int sum = 0, count = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] * count >= x) {
                count = 1;
                sum++;
            } else {
                count++;
            }
        }
        cout << sum << endl;
    }
}

