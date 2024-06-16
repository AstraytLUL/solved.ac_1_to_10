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

struct segtree{
    vector<int> val1, val2;
    void init(int _n){
        val1.assign(_n * 4, 0);
        val2.assign(_n * 4, 0);
    }
    void modify(int p, int x, int l, int r, int id){
        if(l == r){
            val1[id] = x;
            val2[id] = x;
            return;
        }
        int mid = (l + r) / 2;
        if(p <= mid) modify(p, x, l, mid, id * 2);
        else modify(p, x, mid + 1, r, id * 2 + 1);
        val1[id] = max(val1[id * 2], val1[id * 2 + 1]);
        val2[id] = min(val2[id * 2], val2[id * 2 + 1]);
    }
    int query1(int ql, int qr, int l, int r, int id){
        if(ql <= l && r <= qr) return val1[id];
        int ret = -1e18, mid = (l + r) / 2;
        if(ql <= mid) ret = max(ret, query1(ql, qr, l, mid, id * 2));
        if(mid < qr) ret = max(ret, query1(ql, qr, mid + 1, r, id * 2 + 1));
        return ret;
    }
    int query2(int ql, int qr, int l, int r, int id){
        if(ql <= l && r <= qr) return val2[id];
        int ret = 1e18, mid = (l + r) / 2;
        if(ql <= mid) ret = min(ret, query2(ql, qr, l, mid, id * 2));
        if(mid < qr) ret = min(ret, query2(ql, qr, mid + 1, r, id * 2 + 1));
        return ret;
    }
}sgt;

void solve(){
    int n, m; cin >> n >> m;
    sgt.init(n);
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        sgt.modify(i, x, 1, n, 1);
    }
    for(int i = 1; i <= m; ++i){
        int l, r; cin >> l >> r;
        cout << sgt.query2(l, r, 1, n, 1) << ' ' << sgt.query1(l, r, 1, n, 1) << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
