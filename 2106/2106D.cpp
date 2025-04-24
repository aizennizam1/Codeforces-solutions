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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for(auto& x : a) {
            cin >> x;
        }
        for(auto& x : b) {
            cin >> x;
        }
        vector<int> arr1(m + 1);
        vector<int> arr2(m + 1);
        auto check = [&](vector<int>& dp, int nax) {
            dp.assign(m + 1, nax > 0 ? n : -1);
            dp[ nax > 0 ? 0 : m ] = nax > 0 ? -1 : n;
            int j = nax > 0 ? 0 : m - 1;
            for (int i = (nax > 0 ? 0 : n - 1); i != (nax > 0 ? n : -1) && (nax > 0 ? j < m : j >= 0); i += nax){
                if (a[i] >= b[j]) {
                    dp[ nax > 0 ? j + 1 : j ] = i;
                    j += nax;
                }
            }
        };
        check(arr1, +1);
        check(arr2, -1);

        int cnt = (arr1[m] < n) ? 0 : accumulate(b.begin(), b.end(), INT_MAX, [&, i = 0](int best, int val) mutable {
                    bool ok = (arr1[i] < arr2[i + 1]);
                    ++i;
                    return ok ? min(best, val) : best;
                }
              );
        cout << (cnt == INT_MAX ? -1 : cnt) << '\n';
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

