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
#define maxn 500005
#define mod 1000000007

int C[maxn], J[maxn];

void solve(){
    int n; cin >> n;
    C[1] = 1;
    J[1] = 1;
    for(int i = 2; i <= n; ++i){
        if(i % 2 == 0){
            C[i] = C[i / 2] * 2;
            J[i] = J[i / 2] * 2 - 1;
        }else{
            C[i] = J[i / 2] * 2;
            J[i] = J[i / 2] * 2 + 1;
        }
    }
    cout << C[n] << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
