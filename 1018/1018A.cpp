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
        string s;
        cin >> n >> s;
        vector<int> G, H;
        H.reserve(n);
        G.reserve(n);
        H.push_back(1);
        for (int j = 2; j <= n; j++) {
            if (s[j-2] == '<')
                H.push_back(j);
            else
                G.push_back(j);
        }
        int m = G.size();         
        int k = (int)H.size();      
        vector<int> ans(n+1);
        for (int i = 0; i < k; i++) {
            int pos = H[i];
            ans[pos] = (k - i);
        }
        for (int i = 0; i < m; i++) {
            int pos = G[i];
            ans[pos] = (k + 1 + i);
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << (i==n?'\n':' ');
        }
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

