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
    int S = 0;
    int n; cin >> n;
    for(; n; n--){
        string op; cin >> op;
        if(op == "add"){
            int x; cin >> x;
            x--;
            if((S & (1<<x)) == 0) S ^= (1<<x);
        }
        if(op == "remove"){
            int x; cin >> x;
            x--;
            if((S & (1<<x)) != 0) S ^= (1<<x);
        }
        if(op == "check"){
            int x; cin >> x;
            x--;
            if((S & (1<<x)) != 0) cout << "1\n";
            else cout << "0\n";
        }
        if(op == "toggle"){
            int x; cin >> x;
            x--;
            S ^= (1<<x);
        }
        if(op == "all"){
            S = (1<<20) - 1;
        }
        if(op == "empty"){
            S = 0;
        }
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
