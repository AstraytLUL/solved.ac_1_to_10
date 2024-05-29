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

int dist[5][5] = {{1, 2, 2, 2, 2}, {2, 1, 3, 4, 3}, {2, 3, 1, 3, 4}, {2, 4, 3, 1, 3}, {2, 3, 4, 3, 1}};

void solve(){
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(5, vector<int>(5, 1e18)));
    dp[0][0][0] = 0;
    int op; 
    while(cin >> op){
        if(op == 0) break;
        dp[1].assign(5, vector<int>(5, 1e18));
        for(int i = 0; i <= 4; ++i){
            for(int j = 0; j <= 4; ++j){
                if(i != op) dp[1][i][op] = min(dp[1][i][op], dp[0][i][j] + dist[j][op]);
                if(j != op) dp[1][op][j] = min(dp[1][op][j], dp[0][i][j] + dist[i][op]);
            }
        }
        dp[0] = dp[1];
    }
    int ans = 1e18;
    for(int i = 0; i <= 4; ++i){
        for(int j = 0; j <= 4; ++j){
            ans = min(ans, dp[1][i][j]);
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
