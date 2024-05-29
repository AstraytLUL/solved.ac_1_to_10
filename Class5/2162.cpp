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
#define maxn 3005
#define mod 1000000007

int dsu[maxn], sz[maxn];

struct segment{
    pii l, r;
};

pii operator-(pii a, pii b){
    return mp(a.ff - b.ff, a.ss - b.ss);
}

int cross(pii a, pii b){
    return a.ff * b.ss - a.ss * b.ff;
}

int dot(pii a, pii b){
    return a.ff * b.ff + a.ss * b.ss;
}

int direction(pii a, pii b, pii o){
    pii v1 = (a - o), v2 = (b - o);
    int x = cross(v1, v2);
    if(x != 0) x /= abs(x);
    return x;
}
 
bool onseg(pii a, pii b, pii o){
    int x = cross(a - o, b - o);
    int y = dot(a - o, b - o);
    return (x == 0)&&(y <= 0);
}

bool intersec(pii p1, pii p2, pii p3, pii p4){
    bool flag = 0;
    flag |= (direction(p1, p2, p3) != direction(p1, p2, p4)) && (direction(p3, p4, p1) != direction(p3, p4, p2));
    flag |= onseg(p1, p2, p3);
    flag |= onseg(p1, p2, p4);
    flag |= onseg(p3, p4, p1);
    flag |= onseg(p3, p4, p2);
    return flag;
}

void init(int n){
    for(int i = 1; i <= n; ++i) dsu[i] = i, sz[i] = 1;
}

int root(int u){
    return (dsu[u] == u ? u : dsu[u] = root(dsu[u]));
}

void join(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return;
    if(u < v) swap(u, v);
    dsu[u] = v;
    sz[v] += sz[u];
}

void solve(){
    int n; cin >> n;
    init(n);
    vector<segment> seg(n + 1);
    for(int i = 1; i <= n; ++i){
        auto &[p1, p2] = seg[i];
        cin >> p1.ff >> p1.ss;
        cin >> p2.ff >> p2.ss;
        if(p1 > p2) swap(p1, p2);
        for(int j = i - 1; j >= 1; --j){
            auto &[p3, p4] = seg[j];
            bool ok = intersec(p1, p2, p3, p4) || intersec(p3, p4, p1, p2);
            if(ok) join(i, j);
        }
    }
    set<int> st;
    int max_size = 1;
    for(int i = 1; i <= n; ++i){
        int v = root(i);
        st.insert(v);
        max_size = max(max_size, sz[v]);
    }
    cout << st.size() << '\n';
    cout << max_size << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
