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

int val[9][9], done = 0;
vector<pii> pos;

bool check(int i, int j, int k){
    for(int x = 0; x < 9; ++x){
        if(x != j && val[i][x] == k) return 0;
        if(x != i && val[x][j] == k) return 0;
    }
    int tx = i / 3, ty = j / 3;
    for(int x = tx * 3; x < tx * 3 + 3; ++x){
        for(int y = ty * 3; y < ty * 3 + 3; ++y){
            if(x == i && y == j) continue;
            if(val[x][y] == k) return 0;
        }
    }
    return 1;
}

void calc(int cur){
    if(done) return;
    if(cur == pos.size()) {
        done = 1;
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                cout << val[i][j];
            }
            cout << '\n';
        }
        return;
    }
    auto [x, y] = pos[cur];
    for(int i = 1; i <= 9; ++i){
        if(check(x, y, i)){
            val[x][y] = i;
            calc(cur + 1);
            val[x][y] = 0;
        }
        if(done) return;
    }
}

void solve(){
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            char c; cin >> c;
            val[i][j] = c - '0';
            if(c == '0'){
                pos.pb(mp(i, j));
            }
        }
    }
    calc(0);
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
