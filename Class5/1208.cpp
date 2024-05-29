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
    int n, k; cin >> n >> k;
    int ln = n / 2, rn = n - ln;
    vector<int> l(ln), r(rn);
    for(auto &x:l) cin >> x;
    for(auto &x:r) cin >> x;
    map<int, int> lc, rc;
    for(int s = 0; s < (1<<ln); ++s){
        int t = 0;
        for(int i = 0; i < ln; ++i){
            if((s & (1<<i)) == 0) continue;
            t += l[i];
        }
        lc[t]++;
    }
    for(int s = 0; s < (1<<rn); ++s){
        int t = 0;
        for(int i = 0; i < rn; ++i){
            if((s & (1<<i)) == 0) continue;
            t += r[i];
        }
        rc[t]++;
    }
    int ans = 0;
    for(auto [x, y]:lc){
        int c = k - x, z = 0;
        if(rc.find(c) != rc.end()) z = rc[c];
        ans += y * z;
    }
    if(k == 0) --ans;
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
