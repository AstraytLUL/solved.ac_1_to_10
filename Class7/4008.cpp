/*
今ここから始まる　新しい旅に
Hello! Hello!
I Say Hello! Hello!
なんか反省ばっかしちゃってた　昨日の自分に
Good Bye! Good Bye!
One More Good Bye! Good Bye!
走り出しちゃったこの想いに　理由なんていらないよ
眩しい太陽を浴びて
目的地まだ見えないけれど
靴ひもを結んで　Walk This Way!
*/
#include <bits/stdc++.h>
using namespace std;
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define int ll
#define vi vector<int>
#define pii pair<int,int>
#define mii map<int,int>
#define si stack<int>
#define qi queue<int>
#define upb upper_bound
#define lwb lower_bound
#define pf push_front
#define pb push_back
#define pp push
#define pof pop_front
#define pob pop_back
#define ff first
#define ss second
#define inf 0x7f7f7f7f
#define mod 998244353
#define modd 1000000007
#define N 100005
#define gcd __gcd
#define skip(x) if(x)continue;
#define lowbit(x) x&-x

struct line{
    int m, k, l, r, i;
    int val(int x){
        return m * x + k;
    }
};

int intersec(line l1, line l2){
    double x = (double)(l2.k - l1.k) / (double)(l1.m - l2.m);
    int w = 1; if(x < 0) w = -1;
    x = floor(abs(x));
    return (int) w * x;
}

void solve(){
    int n, a, b, c; cin >> n >> a >> b >> c;
    deque<line> dq; vi v(n), p(n + 1, 0), dp(n + 1, 0);
    for(int i = 0; i < n; ++i) cin >> v[i], p[i + 1] = p[i] + v[i];
    dq.pb({0, 0, -inf, inf, 0});
    for(int i = 1; i <= n; ++i){
        while(p[i] > dq.front().r) dq.pof();
        int mx = dq.front().val(p[i]), k = a * p[i] * p[i] + b * p[i] + c;
        dp[i] = mx + k;
        line nl = {(-2) * a * p[i], a * p[i] * p[i] - b * p[i] + dp[i], -inf, inf, i};
        while(dq.size() && intersec(dq.back(), nl) < dq.back().l) dq.pob();
        if(dq.size()){
            dq.back().r = intersec(dq.back(), nl);
            nl.l = dq.back().r + 1;
        }
        dq.pb(nl);
    }
    cout << dp[n] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}