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
#define mod 1000003

vector<vector<int>> MUL(vector<vector<int>> A, vector<vector<int>> B){
    int n = A.size();
    vector<vector<int>> ret(n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ret[i][j] += A[i][k] * B[k][j];
            }
            ret[i][j] %= mod;
        }
    }
    return ret;
}

vector<vector<int>> fastpow(vector<vector<int>> A, int b){
    int n = A.size();
    vector<vector<int>> ret(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i) ret[i][i] = 1;
    for(; b; b >>= 1){
        if(b & 1) ret = MUL(ret, A);
        A = MUL(A, A);
    }
    return ret;
}

void solve(){
    int n, a, b, t; cin >> n >> a >> b >> t;
    vector<vector<int>> A(55, vector<int>(55, 0));
    int cur = n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char c; cin >> c;
            if(c == '1') A[5 * i][5 * j]++;
            else if(c == '2') {
                A[5 * i][5 * i + 1] = 1;
                A[5 * i + 1][5 * j] = 1;
            }
            else if(c == '3') {
                A[5 * i][5 * i + 1] = 1;
                A[5 * i + 1][5 * i + 2] = 1;
                A[5 * i + 2][5 * j] = 1;
            }
            else if(c == '4') {
                A[5 * i][5 * i + 1] = 1;
                A[5 * i + 1][5 * i + 2] = 1;
                A[5 * i + 2][5 * i + 3] = 1;
                A[5 * i + 3][5 * j] = 1;
            }
            else if(c == '5'){
                A[5 * i][5 * i + 1] = 1;
                A[5 * i + 1][5 * i + 2] = 1;
                A[5 * i + 2][5 * i + 3] = 1;
                A[5 * i + 3][5 * i + 4] = 1;
                A[5 * i + 4][5 * j] = 1;
            }
        }
    }
    A = fastpow(A, t);
    cout << A[5 * (a - 1)][5 * (b - 1)] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}