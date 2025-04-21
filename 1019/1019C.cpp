/*
*
*    Author : Girish Kumar Goyal.
*
*/

#include <bits/stdc++.h>

using namespace std;

template < class c > struct rge {
    c b, e;
};
template < class c > rge<c> range(c i, c j){
    return rge<c>{i, j};
}
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);

struct debug {
    ~debug() { cerr << endl; }
    template < class c > typename enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) {
        cerr << boolalpha << i;
        return * this;
    }
    template < class c > typename enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {
        return * this << range(begin(i), end(i)); 
    }
    template < class c, class b > debug & operator << (pair < b, c > d) {
        return * this << "(" << d.first << ", " << d.second << ")";
    }
    template < class c > debug & operator <<(rge<c> d) {
        *this << "[";
        for (auto it = d.b; it != d.e; ++it)
            *this << ", " + 2 * (it == d.b) << *it;
        return * this << "]";
    }
};  
#define imie(...) " [" << #__VA_ARGS__ " : " << (__VA_ARGS__) << "]"

void solve(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n + 1), pre(n + 1), dpM(n + 1, LLONG_MAX), dpG(n + 1, LLONG_MAX);
        vector<bool> valid(n + 1, false);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        pre[0] = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (a[i] <= k ? 1LL : -1LL);
        }
        dpM[1] = pre[1];
        if (pre[1] >= 0) {
            dpG[1] = pre[1];
            valid[1] = true;
        }
        long long total = pre[n];
        bool found = false;
        for (int r = 2; r < n && !found; r++) {
            long long pr = pre[r];
            long long cnt = dpM[r - 1];
            long long nax = dpG[r - 1];
            bool good = valid[r - 1];
            if ((good && nax <= pr) || (good && pr <= total) || (cnt <= pr && pr <= total)) {
                found = true;
                break;
            }
            dpM[r] = min(dpM[r - 1], pr);
            if (pr >= 0) {
                dpG[r] = good ? min(dpG[r - 1], pr) : pr;
                valid[r] = true;
            } else {
                dpG[r] = dpG[r - 1];
                valid[r] = valid[r - 1];
            }
        }
        cout << (found ? "YES\n" : "NO\n");
    }
}

void init_code(){
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){
    init_code();
    solve();
    return 0;
}

