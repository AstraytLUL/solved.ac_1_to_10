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
    vector<int> val;
    void init(int _n){
        val.assign(_n * 4, 0);
    }
    void modify(int p, int x, int l, int r, int id){
        if(l == r){
            val[id] = x;
            return;
        }
        int mid = (l + r) / 2;
        if(p <= mid) modify(p, x, l, mid, id * 2);
        else modify(p, x, mid + 1, r, id * 2 + 1);
        val[id] = (val[id * 2] * val[id * 2 + 1]) % mod;
    }
    int query(int ql, int qr, int l, int r, int id){
        if(ql <= l && r <= qr) return val[id];
        int ret = 1, mid = (l + r) / 2;
        if(ql <= mid) ret *= query(ql, qr, l, mid, id * 2), ret %= mod;
        if(mid < qr) ret *= query(ql, qr, mid + 1, r, id * 2 + 1), ret %= mod;
        return ret;
    }
}sgt;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    sgt.init(n);
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        sgt.modify(i, x, 1, n, 1);
    }
    for(int i = 1; i <= m + k; ++i){
        int op; cin >> op;
        if(op == 1){
            int p, x; cin >> p >> x;
            sgt.modify(p, x, 1, n, 1);
        }else{
            int l, r; cin >> l >> r;
            cout << sgt.query(l, r, 1, n, 1) << '\n'; 
        }
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
