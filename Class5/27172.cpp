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
#define maxn 1000005
#define mod 1000000007

int a[maxn], s[maxn];

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x, a[x] = 1;
    for(int x:v){
        for(int i = x * 2; i < maxn; i += x){
            if(a[i]) s[x]++, s[i]--;
        }
    }
    for(int x:v){
        cout << s[x] << ' ';
    }
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
