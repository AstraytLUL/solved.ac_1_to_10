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

pii operator-(pii a, pii b){
    return pii(a.ff - b.ff, a.ss - b.ss);
}

int cross(pii a, pii b){
    return (a.ff * b.ss - a.ss * b.ff);
}

void solve(){
    int n; cin >> n;
    vector<pii> p(n);
    for(auto &[x, y]:p) cin >> x >> y;
    sort(p.begin(), p.end());
    vector<pii> hul;
    for(int i = 0; i < n; ++i){
        if(hul.size() < 2) {
            hul.pb(p[i]);
            continue;
        }
        int k = hul.size() - 1;
        while(hul.size() >= 2 && cross(p[i] - hul[k], p[i] - hul[k - 1]) >= 0) {
            hul.pop_back();
            --k;
        }
        hul.pb(p[i]);
    }
    int t = hul.size();
    for(int i = n - 2; i >= 0; --i){
        if(hul.size() - t < 1) {
            hul.pb(p[i]);
            continue;
        }
        int k = hul.size() - 1;
        while(hul.size() - t >= 1 && cross(p[i] - hul[k], p[i] - hul[k - 1]) >= 0) {
            hul.pop_back();
            --k;
        }
        hul.pb(p[i]);
    }
    cout << hul.size() - 1 << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
