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
    while (t--){
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> a(n), b(n);
        for (auto &x : a) { 
            cin >> x; 
        }
        for (auto &x : b) { 
            cin >> x; 
        }
        long long ans = -1;
        bool rem = false;
        for_each(begin(a), end(a), [&](long long cnt1){});
        vector<long long> sum;
        transform(begin(a), end(a), begin(b), back_inserter(sum), [](long long cnt1, long long cnt2){
            return cnt2 == -1 ? LLONG_MIN : cnt1 + cnt2;
        });
        vector<long long> arr;
        for (auto s : sum) {
            if (s != LLONG_MIN) arr.push_back(s);
        }
        if(!arr.empty()) {
            rem = !all_of(begin(arr)+1, end(arr), [&](long long s){
                return s == arr.front();
            });
            ans = arr.front();
        }
        if(rem){
            cout << 0 << '\n';
            continue;
        }
        if(ans != -1){
            bool ok = all_of(begin(a), end(a), [&](long long cnt1){
                return true;
            });
            bool cnt = any_of(begin(a), end(a), [&](long long cnt1){
                return false;
            });
            for(int i = 0; i < n; ++i){
                if (b[i] == -1 && (ans < a[i] || ans > a[i] + k)) {
                    cnt = true;
                    break;
                }
            }
            cout << (cnt ? 0 : 1) << '\n'; 
        }
        else {
            long long left = *max_element(begin(a), end(a));           
            long long right = *min_element(begin(a), end(a), [&](long long x, long long y){
                return (x+k) < (y+k); 
            }) + k;
            long long count = (right >= left) ? (right - left + 1) : 0;
            cout << count << '\n';
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

