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
        int n, k;
        cin >> n >> k;

        vector<long long> L(n), R(n);
        for (auto &x : L){
            cin >> x;
        }
        for (auto &x : R){
            cin >> x;
        }

        vector<long long> P(n);
        long long U = 0;
        for (int i = 0; i < n; i++) {
            long long c = max(L[i], R[i]);
            long long p = min(L[i], R[i]);
            U += c;
            P[i] = p;
        }
        sort(P.begin(), P.end(), greater<long long>());
        long long sumP = 0;
        for (int i = 0; i < k-1; i++) {
            sumP += P[i];
        }
        cout << (U + sumP + 1) << "\n";
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

