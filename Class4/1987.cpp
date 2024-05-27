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

int n, m; 
char G[25][25];
int ans = 0;

void dfs(int i, int j, int s, int d){
    int x;
    ans = max(ans, d);
    if(i > 1){
        x = G[i - 1][j] - 'A';
        if((s & (1<<x)) == 0) dfs(i - 1, j, s ^ (1<<x), d + 1);
    }
    if(i < n){
        x = G[i + 1][j] - 'A';
        if((s & (1<<x)) == 0) dfs(i + 1, j, s ^ (1<<x), d + 1);
    }
    if(j > 1){
        x = G[i][j - 1] - 'A';
        if((s & (1<<x)) == 0) dfs(i, j - 1, s ^ (1<<x), d + 1);
    }
    if(j < m){
        x = G[i][j + 1] - 'A';
        if((s & (1<<x)) == 0) dfs(i, j + 1, s ^ (1<<x), d + 1);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
        }
    }
    int s = G[1][1] - 'A';
    dfs(1, 1, (1 << s), 1);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
