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
#define maxn 105
#define mod 1000000007

int dist[maxn][maxn];

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(i != j) dist[i][j] = 1e9;
            else dist[i][j] = 0;
        }
    }
    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = -1, mn = 1e18;
    for(int i = 1; i <= n; ++i){
        int sum = 0;
        for(int j = 1; j <= n; ++j){
            sum += dist[i][j];
        }
        if(sum < mn){
            ans = i; mn = sum;
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
