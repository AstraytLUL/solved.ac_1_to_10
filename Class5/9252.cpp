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
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<pii>> prev(n + 1, vector<pii>(m + 1, mp(0, 0)));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                prev[i][j] = mp(i - 1, j - 1);
            }
            else {
                if(dp[i][j - 1] > dp[i - 1][j]){
                    prev[i][j] = mp(i, j - 1);
                }else{
                    prev[i][j] = mp(i - 1, j);
                }
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n][m] << '\n';
    pii cur(n, m);
    string ans = "";
    while(cur.ff != 0 && cur.ss != 0){
        auto [x, y] = cur;
        if(prev[x][y] == mp(x - 1, y - 1)){
            ans += s[x - 1];
        }
        cur = prev[x][y];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
