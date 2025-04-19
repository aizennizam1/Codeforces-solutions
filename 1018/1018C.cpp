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

const long long INF = (long long)4e18;

long long solve_chain(int n, vector<long long>& cost, vector<array<bool,4>>& forbidden){
    vector<array<long long,2>> dp(n+1, {INF, INF});
    dp[1][0] = 0;
    dp[1][1] = cost[0];
    for(int i = 2; i <= n; i++){
        dp[i][0] = dp[i][1] = INF;
        for(int prev = 0; prev <= 1; prev++){
            if(dp[i-1][prev] >= INF){
                continue;
            }
            for(int cur = 0; cur <= 1; cur++){
                int mask = (prev<<1) | cur;
                if(!forbidden[i-1][mask]){
                    dp[i][cur] = min(dp[i][cur], dp[i-1][prev] + (cur ? cost[i-1] : 0));
                }
            }
        }
    }
    return min(dp[n][0], dp[n][1]);
}

void solve(){
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<long long>> h(n, vector<long long>(n));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> h[i][j];

        vector<long long> a(n), b(n);
        for(long long &x: a){
            cin >> x;
        }
        for(long long &x: b){
            cin >> x;
        }
        
        vector<array<bool,4>> row(n, {false,false,false,false});
        vector<array<bool,4>> col(n, {false,false,false,false});

        for(int i = 0; i < n; i++){
            for(int j = 0; j+1 < n; j++){
                long long d = h[i][j] - h[i][j+1];
                if(d == 0){
                    col[j+1][0] = col[j+1][3] = true;
                } else if(d == 1){
                    col[j+1][1] = true;
                } else if(d == -1){
                    col[j+1][2] = true; 
                }
            }
        }
        for(int j = 0; j < n; j++){
            for(int i = 0; i+1 < n; i++){
                long long d = h[i][j] - h[i+1][j];
                if(d == 0){
                    row[i+1][0] = row[i+1][3] = true;
                } else if(d == 1){
                    row[i+1][1] = true;
                } else if(d == -1){
                    row[i+1][2] = true;
                }
            }
        }
        long long rowCost = solve_chain(n, a, row);
        long long colCost = solve_chain(n, b, col);

        long long ans = (rowCost >= INF || colCost >= INF) ? -1 : (rowCost + colCost);
        cout << ans << "\n";
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

