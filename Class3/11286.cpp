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
    map<int, int> pos, neg;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        if(x == 0){
            if(pos.empty() && neg.empty()){
                cout << "0\n";
            }else if(pos.empty()){
                pii N = *neg.begin();
                cout << -N.ff << '\n';
                neg[N.ff]--;
                if(neg[N.ff] == 0) neg.erase(N.ff);
            }else if(neg.empty()){
                pii P = *pos.begin();
                cout << P.ff << '\n';
                pos[P.ff]--;
                if(pos[P.ff] == 0) pos.erase(P.ff);
            }else{
                pii P = *pos.begin(), N = *neg.begin();
                if(P.ff >= N.ff){
                    cout << -N.ff << '\n';
                    neg[N.ff]--;
                    if(neg[N.ff] == 0) neg.erase(N.ff);
                }else{
                    cout << P.ff << '\n';
                    pos[P.ff]--;
                    if(pos[P.ff] == 0) pos.erase(P.ff);
                }
            }
        }else{
            if(x > 0) pos[x]++;
            else neg[-x]++;
        }
    }
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
