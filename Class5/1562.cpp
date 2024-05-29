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
#define mod 1000000000

int dp[100][10][1024];

void solve(){
    int n; cin >> n;
    for(int i = 0; i < 10; ++i){
        dp[0][i][(1<<i)] = 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 10; ++j){
            for(int s = 0; s < 1024; ++s){
                if(j != 0) dp[i][j][(s | (1<<j))] += dp[i - 1][j - 1][s];
                if(j != 9) dp[i][j][(s | (1<<j))] += dp[i - 1][j + 1][s];
                dp[i][j][(s | (1<<j))] %= mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < 10; ++i){
        ans = (ans + dp[n - 1][i][1023]) % mod;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
