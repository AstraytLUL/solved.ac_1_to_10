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

void solve(){
    int n, m, sum_v = 0, sum_w = 0; cin >> n >> m;
    vector<int> w(n), v(n);
    for(auto &x:w) cin >> x, sum_w += x;
    for(auto &x:v) cin >> x, sum_v += x;
    vector<vector<int>> dp(2, vector<int>(sum_v + 1, -1e18));
    dp[0][0] = dp[1][0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = v[i]; j <= sum_v; ++j){
            dp[1][j] = max(dp[1][j], dp[0][j - v[i]] + w[i]);
        }
        dp[0] = dp[1];
    }
    int ans = 0;
    for(int i = 0; i <= sum_v; ++i){
        if(dp[0][i] >= m) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
