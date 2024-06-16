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

struct TRIE{
    vector<int> dep;
    vector<string> node;
    vector<map<string, int>> next;
    void init(){
        dep.assign(1, 0);
        node.assign(1, "");
        next.assign(1, map<string, int>());
    }
    void insert(vector<string> S){
        int cur = 0;
        for(auto s:S){
            if(next[cur].find(s) != next[cur].end()){
                cur = next[cur][s];
            }else{
                dep.pb(dep[cur] + 1);
                node.pb(s);
                next.pb(map<string, int>());
                next[cur][s] = next.size() - 1;
                cur = next[cur][s];
            }
        }
    }
    void dfs(int cur){
        if(cur != 0) {
            for(int i = 1; i < dep[cur]; ++i) cout << "--";
            cout << node[cur] << '\n';
        }
        for(auto [s, id]:next[cur]){
            dfs(id);
        }
    }
}trie;

void solve(){
    int n; cin >> n;
    trie.init();
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        vector<string> S(k);
        for(auto &s:S) cin >> s;
        trie.insert(S);
    }
    trie.dfs(0);
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
