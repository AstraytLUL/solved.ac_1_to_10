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

vector<vector<int>> MUL(vector<vector<int>> A, vector<vector<int>> B){
    vector<vector<int>> ret(8, vector<int> (8, 0));
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            for(int k = 0; k < 8; ++k){
                ret[i][j] += A[i][k] * B[k][j];
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

vector<vector<int>> fastpow(vector<vector<int>> A, int b){
    vector<vector<int>> ret(8, vector<int> (8, 0));
    for(int i = 0; i < 8; ++i) ret[i][i] = 1;
    for(; b; b >>= 1){
        if(b & 1) ret = MUL(ret, A);
        A = MUL(A, A);
    }
    return ret;
}

void solve(){
    vector<vector<int>> G(8, vector<int>(8, 0));
    G[0][1] = 1, G[0][2] = 1;
    G[1][0] = 1, G[1][2] = 1, G[1][3] = 1;
    G[2][0] = 1, G[2][1] = 1, G[2][3] = 1, G[2][4] = 1;
    G[3][1] = 1, G[3][2] = 1, G[3][4] = 1, G[3][5] = 1;
    G[4][2] = 1, G[4][3] = 1, G[4][5] = 1, G[4][6] = 1;
    G[5][3] = 1, G[5][4] = 1, G[5][7] = 1;
    G[6][4] = 1, G[6][7] = 1;
    G[7][5] = 1, G[7][6] = 1;
    int n; cin >> n;
    G = fastpow(G, n);
    cout << G[0][0] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
