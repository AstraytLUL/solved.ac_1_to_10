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

struct Shark{
    int s = 0, d = 0, w = 0;
    Shark(){}
    Shark(int _s, int _d, int _w):s(_s), d(_d), w(_w){}
};

Shark chmax(Shark a, Shark b){
    return (a.w > b.w ? a : b);
}

int _dx[4] = {-1, 1, 0, 0}, _dy[4] = {0, 0, 1, -1};

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<Shark>> shark(n + 5, vector<Shark>(m + 5));
    for(int i = 0; i < k; ++i){
        int x, y; cin >> x >> y;
        cin >> shark[x][y].s >> shark[x][y].d >> shark[x][y].w;
    }
    int ans = 0;
    for(int cur = 1; cur <= m; ++cur){
        for(int i = 1; i <= n; ++i){
            if(shark[i][cur].w != 0){
                ans += shark[i][cur].w;
                shark[i][cur] = Shark();
                break;
            }
        }
        vector<vector<Shark>> new_shark(n + 5, vector<Shark>(m + 5));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(shark[i][j].w == 0) continue;
                auto [s, d, w] = shark[i][j];
                int x = i, y = j, r = s;
                if(d == 1){
                    int mv = x - 1;
                    if(s >= mv) {
                        x = 1, d = 2;
                        r -= mv;
                        int t = r / (n - 1);
                        r %= (n - 1);
                        if(t % 2 == 1) {
                            d = 1; 
                            x = n - r;
                        }else{
                            x = r + 1;
                        }
                    }else{
                        x -= s;
                    }
                }else if(d == 2){
                    int mv = n - x;
                    if(s >= mv) {
                        x = n, d = 1;
                        r -= mv;
                        int t = r / (n - 1);
                        r %= (n - 1);
                        if(t % 2 == 1) {
                            d = 2; 
                            x = r + 1;
                        }else{
                            x = n - r;
                        }
                    }else{
                        x += s;
                    }
                }else if(d == 4){
                    int mv = y - 1;
                    if(s >= mv) {
                        y = 1, d = 3;
                        r -= mv;
                        int t = r / (m - 1);
                        r %= (m - 1);
                        if(t % 2 == 1) {
                            d = 4; 
                            y = m - r;
                        }else{
                            y = r + 1;
                        }
                    }else{
                        y -= s;
                    }
                }else if(d == 3){
                    int mv = m - y;
                    if(s >= mv) {
                        y = m, d = 4;
                        r -= mv;
                        int t = r / (m - 1);
                        r %= (m - 1);
                        if(t % 2 == 1) {
                            d = 3; 
                            y = r + 1;
                        }else{
                            y = m - r;
                        }
                    }else{
                        y += s;
                    }
                }
                new_shark[x][y] = chmax(new_shark[x][y], Shark(s, d, w));
            }
        }
        shark = new_shark;
    }
    cout << ans << '\n';
}

signed main(){
    starburst
    int t = 1; //cin >> t;
    while(t--) solve();
}
