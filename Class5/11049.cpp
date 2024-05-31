//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

int dp[505][505];

void solve(){
    int n; cin >> n;
    vector<pii> v(n);
    for(auto &[x, y]:v) cin >> x >> y;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j) dp[i][j] = 1e18;
    }
    for(int len = 2; len <= n; ++len){
        for(int l = 0, r = len - 1; r < n; ++l, ++r){
            for(int k = l; k < r; ++k){
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + v[l].ff * v[k].ss * v[r].ss);
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
