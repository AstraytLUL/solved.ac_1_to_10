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
#define maxn 10005
#define mod 1000000007

void solve(){
    int a, b; cin >> a >> b;
    vector<int> pre(maxn, -1);
    vector<char> act(maxn, 0);
    pre[a] = a;
    queue<int> bfs;
    bfs.push(a);
    while(bfs.size()){
        int x = bfs.front();
        bfs.pop();
        int d = x * 2 % 10000, s = (x + 9999) % 10000, l = (x % 1000) * 10 + x / 1000, r = (x % 10) * 1000 + x / 10;
        if(d < maxn && pre[d] == -1){
            act[d] = 'D';
            pre[d] = x;
            bfs.push(d);
        }
        if(s < maxn && pre[s] == -1){
            act[s] = 'S';
            pre[s] = x;
            bfs.push(s);
        }
        if(l < maxn && pre[l] == -1){
            act[l] = 'L';
            pre[l] = x;
            bfs.push(l);
        }
        if(r < maxn && pre[r] == -1){
            act[r] = 'R';
            pre[r] = x;
            bfs.push(r);
        }
    }
    int cur = b;
    string ans = "";
    while(cur != a){
        ans += act[cur];
        cur = pre[cur];
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
