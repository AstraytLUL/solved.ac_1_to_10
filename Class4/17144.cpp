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
    int n, m, t; cin >> n >> m >> t;
    vector<vector<int>> G(n + 1, vector<int>(m + 1, 0));
    int x1 = -1, x2 = -1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> G[i][j];
            if(x1 == -1 && G[i][j] == -1) x1 = i;
            else if(x2 == -1 && G[i][j] == -1) x2 = i;
        }
    }
    while(t--){
        vector<vector<int>> new_G(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(G[i][j] < 0) {
                    new_G[i][j] = -1;
                    continue;
                }
                int k = G[i][j] / 5;
                if(i != 1 && G[i - 1][j] != -1) new_G[i - 1][j] += k, G[i][j] -= k;
                if(j != 1 && G[i][j - 1] != -1) new_G[i][j - 1] += k, G[i][j] -= k;
                if(i != n && G[i + 1][j] != -1) new_G[i + 1][j] += k, G[i][j] -= k;
                if(j != m && G[i][j + 1] != -1) new_G[i][j + 1] += k, G[i][j] -= k;
                new_G[i][j] += G[i][j];
            }
        }
        new_G[x1 - 1][1] = 0;
        new_G[x2 + 1][1] = 0;
        for(int i = x2 + 1; i < n; ++i){
            new_G[i][1] = new_G[i + 1][1];
            new_G[i + 1][1] = 0;
        }
        for(int i = x1 - 1; i > 1; --i){
            new_G[i][1] = new_G[i - 1][1];
            new_G[i - 1][1] = 0;
        }
        for(int j = 1; j < m; ++j){
            new_G[1][j] = new_G[1][j + 1];
            new_G[n][j] = new_G[n][j + 1];
            new_G[1][j + 1] = 0;
            new_G[n][j + 1] = 0;
        }
        for(int i = n; i >= x2 + 1; --i){
            new_G[i][m] = new_G[i - 1][m];
            new_G[i - 1][m] = 0;
        }
        for(int i = 1; i <= x1 - 1; ++i){
            new_G[i][m] = new_G[i + 1][m];
            new_G[i + 1][m] = 0;
        }
        for(int j = m; j > 2; --j){
            new_G[x1][j] = new_G[x1][j - 1];
            new_G[x2][j] = new_G[x2][j - 1];
            new_G[x1][j - 1] = 0;
            new_G[x2][j - 1] = 0;
        }
        G = new_G;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(G[i][j] == -1) continue;
            ans += G[i][j];
        }
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
