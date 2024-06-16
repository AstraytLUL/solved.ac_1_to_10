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

struct _node{
    int val = 0;
    _node *ls = nullptr, *rs = nullptr;
};

_node *sgt;

int size(_node* n){
    return (n == nullptr ? 0 : n->val);
}

void modify(_node *&n, int p, int x, int l, int r){
    if(n == nullptr){
        n = new _node();
    }
    if(l == r){
        n->val += x;
        return;
    }
    int mid = (l + r) / 2;
    if(p <= mid){
        modify(n->ls, p, x, l, mid);
    }else{
        modify(n->rs, p, x, mid + 1, r);
    }
    n->val = (n->ls ? n->ls->val : 0) + (n->rs ? n->rs->val : 0);
}

int query(_node *&n, int k, int l, int r){
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(n->ls != nullptr && size(n->ls) >= k){
        return query(n->ls, k, l, mid);
    }
    else if(n->rs != nullptr && size(n->ls) < k){
        return query(n->rs, k - size(n->ls), mid + 1, r);
    }
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        int op; cin >> op;
        if(op == 1){
            int k; cin >> k;
            int p = query(sgt, k, 1, 1000000);
            modify(sgt, p, -1, 1, 1000000);
            cout << p << '\n';
        }else{
            int p, x; cin >> p >> x;
            modify(sgt, p, x, 1, 1000000);
        }
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
