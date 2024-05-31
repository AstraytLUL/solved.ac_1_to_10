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
    int n; cin >> n;
    vector<pii> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i].ff;
        a[i].ss = i;
    }
    int m; cin >> m;
    vector<pii> b(m);
    for(int i = 0; i < m; ++i){
        cin >> b[i].ff;
        b[i].ss = i;
    }
    sort(a.begin(), a.end(), [&](pii a, pii b){return (a.ff == b.ff ? a.ss < b.ss : a.ff > b.ff);});
    int mx = 0;
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        int s = (ans.size() ? ans.back() + 1 : 0);
        if(a[i].ss < mx) continue;
        for(int j = s; j < m; ++j){
            if(a[i].ff == b[j].ff){
                ans.pb(j);
                mx = max(mx, a[i].ss);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto x:ans) cout << b[x].ff << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
