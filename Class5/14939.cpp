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

void click(int x, int y, vector<vector<char>> &G){
    for(int i = -1; i <= 1; ++i){
        if(i != 0) 
            if(G[x + i][y] == 'O') G[x + i][y] = '#';
            else G[x + i][y] = 'O';
        if(G[x][y + i] == 'O') G[x][y + i] = '#';
        else G[x][y + i] = 'O';
    }
}

void solve(){
    vector<vector<char>> G(12, vector<char> (12, '#'));
    for(int i = 1; i <= 10; ++i){
        for(int j = 1; j <= 10; ++j){
            cin >> G[i][j];
        }
    }
    int ans = 1e18;
    for(int s = 0; s < (1<<10); ++s){
        vector<vector<char>> tmp = G;
        int cnt = 0;
        for(int i = 0; i < 10; ++i){
            if(s & (1<<i)) click(1, i + 1, tmp), cnt++;
        }
        for(int i = 1; i < 10; ++i){
            for(int j = 1; j <= 10; ++j){
                if(tmp[i][j] == 'O') click(i + 1, j, tmp), cnt++;
            }
        }
        bool ok = 1;
        for(int i = 1; i <= 10; ++i){
            for(int j = 1; j <= 10; ++j){
                ok &= (tmp[i][j] == '#');
            }
        }
        if(ok) ans = min(ans, cnt);
    }
    cout << (ans == 1e18 ? -1 : ans) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
