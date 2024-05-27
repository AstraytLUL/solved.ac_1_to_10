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

int know[105];
vector<int> adj[105];

void solve(){
    int n, m; cin >> n >> m;
    int k; cin >> k;
    queue<int> bfs;
    for(int i = 1; i <= k; ++i){
        int x; cin >> x;
        know[x] = 1;
        bfs.push(x);
    }
    int ans = 0;
    vector<vector<int>> query(m + 1);
    for(int i = 1; i <= m; ++i){
        int c; cin >> c;
        for(int j = 1; j <= c; ++j){
            int x; cin >> x;
            adj[x].pb(i + n);
            adj[i + n].pb(x);
            query[i].pb(x);
        }
    }
    while(bfs.size()){
        int u = bfs.front();
        bfs.pop();
        for(auto v:adj[u]){
            if(know[v]) continue;
            know[v] = 1;
            bfs.push(v);
        }
    }
    for(int i = 1; i <= m; ++i){
        bool not_ok = 0;
        for(int x:query[i]){
            not_ok |= know[x];
        }
        if(!not_ok) ans++;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
