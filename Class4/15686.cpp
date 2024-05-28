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

int popcount(int x){
    int ret = 0;
    for(; x; x >>= 1) ret += (x & 1);
    return ret;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<pii> pos1, pos2;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int x; cin >> x;
            if(x == 1) pos1.pb(mp(i, j));
            if(x == 2) pos2.pb(mp(i, j));
        }
    }
    int k = pos2.size(), ans = 1e18;
    for(int s = 0; s < (1<<k); ++s){
        if(popcount(s) != m) continue;
        int sum = 0;
        for(int j = 0; j < pos1.size(); j++){
            int dist = 1e18;
            for(int i = 0; i < k; ++i){
                if((s & (1<<i)) == 0) continue;
                dist = min(dist, abs(pos2[i].ff - pos1[j].ff) + abs(pos2[i].ss - pos1[j].ss));
            }
            sum += dist;
        }
        
        ans = min(ans, sum);
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
