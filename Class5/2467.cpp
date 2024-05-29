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

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    sort(v.begin(), v.end());
    int mdif = 1e18, a, b;
    for(int i = 0; i < n; ++i){
        int goal = -v[i];
        int id = (lower_bound(v.begin(), v.end(), goal) - v.begin());
        if(id != n && id != i && abs(v[i] + v[id]) < mdif){
            a = v[i], b = v[id];
            mdif = abs(v[i] + v[id]);
        }
        if(id != 0 && id - 1 != i  && abs(v[i] + v[id - 1]) < mdif){
            a = v[i], b = v[id - 1];
            mdif = abs(v[i] + v[id - 1]);
        }
        if(id > 1 && id - 2 != i  && abs(v[i] + v[id - 2]) < mdif){
            a = v[i], b = v[id - 2];
            mdif = abs(v[i] + v[id - 2]);
        }
        if(id < n - 1 && id + 1 != i  && abs(v[i] + v[id + 1]) < mdif){
            a = v[i], b = v[id + 1];
            mdif = abs(v[i] + v[id + 1]);
        }
    }
    cout << a << ' ' << b << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
