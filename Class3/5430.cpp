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
    string op; cin >> op;
    int n; cin >> n;
    deque<int> dq(n);
    string list; cin >> list;
    for(int i = 1, id = 0, cur = 0; i < list.size(); ++i){
        if(list[i] == ',' || list[i] == ']'){
            dq[id] = cur;
            cur = 0, id++;
        }else{
            cur = cur * 10 + list[i] - '0';
        }
    }
    int r = 0;
    for(int i = 0; i < op.size(); ++i){
        if(op[i] == 'D'){
            if(dq.size() == 0){
                cout << "error\n";
                return;
            }
            if(r) dq.pop_back();
            else dq.pop_front();
        }else{
            r ^= 1;
        }
    }
    if(r) reverse(dq.begin(), dq.end());
    int k = dq.size();
    cout << '[';
    for(int i = 0; i < k; ++i){
        cout << dq[i];
        if(i != k - 1) cout << ',';
    }
    cout << "]\n";
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
