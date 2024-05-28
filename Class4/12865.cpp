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
#define maxn 100005
#define mod 1000000007

void solve(){
    int n, k; cin >> n >> k;
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    for(int i = 1; i <= n; ++i){
        int w, v; cin >> w >> v;
        for(int i = w; i <= k; ++i){
            dp[1][i] = max(dp[1][i], dp[0][i - w] + v);
        }
        dp[0] = dp[1];
    }
    cout << dp[1][k] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
