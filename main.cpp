#include <bits/stdc++.h>
//#include"style.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define ll long long
#define lll __int128_t
#define int ll
std::mt19937_64 rng{std::chrono::system_clock::now().time_since_epoch().count()};

//cout<<'\n;
//const int MOD = 998244353;
struct Point{
    int x;//y;
    int val;
    //Point(int x, int y, int val): x(x), y(y), val(val) {}
 
 
};
// struct Edge{
//  int frm,to;
//  int wht=1;
// };
// bool cmp(Point& a, Point& b) {
//     return a.val < b.val; 
// }
bool cmp(int a, int b) {
    return a > b;
}

void solve();
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

//const int MAXN = 4e4+5;
void solve() {
    int l,r,e;
    cin >> l >> r >> e;
    // vector<int> L(l);
    // vector<int> R(r);
    vector<vector<ll>>adj(l);
    for(int i=0;i<e;++i){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
    }
    vector<int>mtch(r,-1);//右部点的匹配（左部点）
    vector<int>vis(r,0);//右部点是否访问过
    auto dfs=[&](auto dfs,int u)->int{//匈牙利算法,dfs的作用是找增广路
       for(auto v:adj[u]){
        if(vis[v])continue;
        vis[v]=1;
        if(mtch[v]==-1||dfs(dfs,mtch[v])){//如果没有匹配或者可以找到新的匹配,则匹配上来

            mtch[v]=u;
            return 1;
        }
       }
       return 0;

    };
    int ans=0;
    fill(vis.begin(),vis.end(),0);
    for(int i=0;i<l;++i){
        ans+=dfs(dfs,i);
    }
    cout<<ans<<'\n';
    
}