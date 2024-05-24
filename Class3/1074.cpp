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
//#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

int find(int n, int r, int c){
    if(n == 0) return 0;
    int k = (1<<n);
    int add = k / 2 * k / 2;
    if(r < k / 2 && c < k / 2){
        return find(n - 1, r, c);
    }else if(r < k / 2){
        return add + find(n - 1, r, c - k / 2);
    }else if(c < k / 2){
        return 2 * add + find(n - 1, r - k / 2, c);
    }else{
        return 3 * add + find(n - 1, r - k / 2, c - k / 2);
    }
}

void solve(){
    int n, r, c; cin >> n >> r >> c;
    cout << find(n, r, c) << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
