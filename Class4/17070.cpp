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

int g[25][25], dp[25][25][3];

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> g[i][j];
        }
    }
    dp[1][2][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(g[i][j] == 0) 
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];
            if(g[i][j] == 0 && g[i][j - 1] == 0 && g[i - 1][j] == 0) 
                dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            if(g[i][j] == 0) 
                dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];
        }
    }
    cout << dp[n][n][0] + dp[n][n][1] + dp[n][n][2] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
