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

int n, ans = 0;
int G[25][25];

void moveL(vector<vector<int>> &G){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int cur = j + 1;
            while(cur < n && G[i][cur] == 0){
                cur++;
            }
            if(cur == n) {
                j = cur;
                continue;
            }
            if(G[i][cur] == G[i][j]){
                G[i][j] *= 2;
                G[i][cur] = 0;
                j = cur;
            }else{
                j = cur - 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 1; j < n; ++j){
            int cur = j;
            while(cur > 0 && G[i][cur - 1] == 0){
                G[i][cur - 1] = G[i][cur];
                G[i][cur] = 0;
                cur--;
            }
        }
    }
}

void moveR(vector<vector<int>> &G){
    for(int i = 0; i < n; ++i){
        for(int j = n - 1; j >= 0; --j){
            int cur = j - 1;
            while(cur >= 0 && G[i][cur] == 0){
                cur--;
            }
            if(cur == -1) {
                j = cur;
                continue;
            }
            if(G[i][cur] == G[i][j]){
                G[i][j] *= 2;
                G[i][cur] = 0;
                j = cur;
            }else{
                j = cur + 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = n - 2; j >= 0; --j){
            int cur = j;
            while(cur < n - 1 && G[i][cur + 1] == 0){
                G[i][cur + 1] = G[i][cur];
                G[i][cur] = 0;
                cur++;
            }
        }
    }
}

void moveU(vector<vector<int>> &G){
    for(int j = 0; j < n; ++j){
        for(int i = 0; i < n; ++i){
            int cur = i + 1;
            while(cur < n && G[cur][j] == 0){
                cur++;
            }
            if(cur == n) {
                i = cur;
                continue;
            }
            if(G[cur][j] == G[i][j]){
                G[i][j] *= 2;
                G[cur][j] = 0;
                i = cur;
            }else{
                i = cur - 1;
            }
        }
    }
    for(int j = 0; j < n; ++j){
        for(int i = 1; i < n; ++i){
            int cur = i;
            while(cur > 0 && G[cur - 1][j] == 0){
                G[cur - 1][j] = G[cur][j];
                G[cur][j] = 0;
                cur--;
            }
        }
    }
}

void moveD(vector<vector<int>> &G){
    for(int j = 0; j < n; ++j){
        for(int i = n - 1; i >= 0; --i){
            int cur = i - 1;
            while(cur >= 0 && G[cur][j] == 0){
                cur--;
            }
            if(cur == -1) {
                i = cur;
                continue;
            }
            if(G[cur][j] == G[i][j]){
                G[i][j] *= 2;
                G[cur][j] = 0;
                i = cur;
            }else{
                i = cur + 1;
            }
        }
    }
    for(int j = 0; j < n; ++j){
        for(int i = n - 2; i >= 0; --i){
            int cur = i;
            while(cur < n - 1 && G[cur + 1][j] == 0){
                G[cur + 1][j] = G[cur][j];
                G[cur][j] = 0;
                cur++;
            }
        }
    }
}

void calc(string s){
    if(s.size() == 5){
        vector<vector<int>> g(n, vector<int> (n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) g[i][j] = G[i][j];
        }
        for(auto c:s){
            if(c == 'L') moveL(g);
            if(c == 'R') moveR(g);
            if(c == 'U') moveU(g);
            if(c == 'D') moveD(g);
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                ans = max(ans, g[i][j]);
                //cout << g[i][j] << ' ' ;
            }
            //cout << '\n';
        }
        return;
    }
    calc(s + "L");
    calc(s + "R");
    calc(s + "U");
    calc(s + "D");
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> G[i][j];
        }
    }
    calc("");
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
