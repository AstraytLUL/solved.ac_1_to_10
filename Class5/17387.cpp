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

pii operator- (pii a, pii b){
    return mp(a.ff - b.ff, a.ss - b.ss);
}

int cross(pii v1, pii v2){
    return (v1.ff * v2.ss - v1.ss * v2.ff);
}

int dot(pii v1, pii v2){
    return (v1.ff * v2.ff + v1.ss * v2.ss);
}

int direction(pii v1, pii v2){
    int x = cross(v1, v2);
    if(x != 0) x /= abs(x);
    return x;
}

int onseg(pii a, pii b, pii c){
    int x = direction(a - c, b - c);
    int y = dot(a - c, b - c);
    return (x == 0 && y <= 0);
}

void solve(){
    pii p[4];
    for(int i = 0; i < 4; ++i) cin >> p[i].ff >> p[i].ss;
    int ans = 0;
    ans |= ((direction(p[0] - p[2], p[1] - p[2]) != direction(p[0] - p[3], p[1] - p[3])) && (direction(p[2] - p[0], p[3] - p[0]) != direction(p[2] - p[1], p[3] - p[1])));
    ans |= onseg(p[0], p[1], p[2]);
    ans |= onseg(p[0], p[1], p[3]);
    ans |= onseg(p[2], p[3], p[0]);
    ans |= onseg(p[2], p[3], p[1]);
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
