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

int n, m, s;
vector<int> val;
vector<int> item;
set<vector<int>> st;

void calc(int cur, int d){
    if(d == 0){
        vector<int> t;
        for(auto &x:item) t.pb(val[x - 1]);
        st.insert(t);
        return;
    }
    for(int i = cur; i <= n; ++i){
        item.pb(i);
        calc(i, d - 1);
        item.pop_back();
    }
}

void solve(){
    cin >> n >> m;
    val.assign(n, 0);
    for(auto &x:val) cin >> x;
    sort(val.begin(), val.end());
    calc(1, m);
    for(auto v:st){
        for(auto x:v) cout << x << ' ';
        cout << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
