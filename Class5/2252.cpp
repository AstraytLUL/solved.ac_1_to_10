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
#define maxn 32005
#define mod 1000000007

vector<int> adj[maxn];

void solve(){
    int n, m; cin >> n >> m;
    vector<int> t(n + 1), deg(n + 1), ans;
    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        deg[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> bfs;
    for(int i = 1; i <= n; ++i){
        if(deg[i] == 0){
            bfs.push(i);
        }
    }
    while(bfs.size()){
        int u = bfs.top();
        bfs.pop();
        ans.pb(u);
        for(auto v:adj[u]){
            --deg[v];
            if(deg[v] == 0) bfs.push(v);
        }
    }
    for(auto &x:ans) cout << x << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
