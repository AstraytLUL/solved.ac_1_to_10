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
    vector<pii> v(n);
    vector<int> dp(n), prev(n);
    for(auto &[x, y]:v) cin >> x >> y;
    sort(v.begin(), v.end());
    vector<pii> tmp;
    int cur = -1, mx = -1;
    for(int i = 0; i < n; ++i){
        if(tmp.empty()){
            tmp.pb(mp(v[i].ss, i));
            dp[i] = 1, prev[i] = i;
        }else if(tmp.back().ff < v[i].ss){
            tmp.pb(mp(v[i].ss, i));
            dp[i] = tmp.size(), prev[i] = tmp[tmp.size() - 2].ss;
        }else{
            auto it = lower_bound(tmp.begin(), tmp.end(), mp(v[i].ss, v[i].ff));
            int k = it - tmp.begin();
            *it = mp(v[i].ss, i);
            if(k == 0) dp[i] = 1, prev[i] = i;
            else dp[i] = k + 1, prev[i] = tmp[k - 1].ss;
        }
        if(dp[i] > mx){
            cur = i, mx = dp[i];
        }
    }
    cout << n - mx << '\n';
    set<int> ans, rmv;
    ans.insert(cur);
    while(cur != prev[cur]){
        cur = prev[cur];
        ans.insert(cur);
    }
    for(int i = 0; i < n; ++i){
        if(ans.find(i) != ans.end()) continue;
        rmv.insert(i);
    }
    for(auto x:rmv) cout << v[x].ff << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
