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
#define maxn 3100
#define mod 1000000007

char G[maxn][maxn * 2];

void gen(int x, int y, int h){
    if(h == 3){
        G[x][y] = '*';
        G[x + 1][y - 1] = G[x + 1][y + 1] = '*';
        G[x + 2][y] = '*';
        G[x + 2][y - 1] = G[x + 2][y + 1] = '*';
        G[x + 2][y - 2] = G[x + 2][y + 2] = '*';
        return;
    }
    gen(x, y, h / 2);
    gen(x + h / 2, y - h / 2, h / 2);
    gen(x + h / 2, y + h / 2, h / 2);
}

void solve(){
    int n; cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 2 * n; ++j){
            G[i][j] = ' ';
        }
    }
    gen(1, n, n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 2 * n; ++j){
            cout << G[i][j];
        }
        cout << '\n';
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
