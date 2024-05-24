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

vector<vector<int>> g;

pii add(pii a, pii b){
    return {a.ff + b.ff, a.ss + b.ss};
}

pii count(int lx, int rx, int ly, int ry){
    pii ret(0, 0);
    int w = 0, b = 0;
    for(int i = lx; i < rx; ++i){
        for(int j = ly; j < ry; ++j){
            if(g[i][j] == 0) w++;
            else b++;
        }
    }
    if(w == 0) return pii(0, 1);
    if(b == 0) return pii(1, 0);
    ret = add(ret, count(lx, (lx + rx) / 2, ly, (ly + ry) / 2));
    ret = add(ret, count(lx, (lx + rx) / 2, (ly + ry) / 2, ry));
    ret = add(ret, count((lx + rx) / 2, rx, ly, (ly + ry) / 2));
    ret = add(ret, count((lx + rx) / 2, rx, (ly + ry) / 2, ry));
    return ret;
}

void solve(){
    int n; cin >> n;
    g.assign(n, vector<int> (n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> g[i][j];
        }
    }
    pii ans = count(0, n, 0, n);
    cout << ans.ff << '\n' << ans.ss << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
