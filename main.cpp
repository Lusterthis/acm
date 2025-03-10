#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
#define ll long long
#define lll __int128_t
 
struct Point{
    int x;//y;
    int val;
    //Point(int x, int y, int val): x(x), y(y), val(val) {}
 
 
};
// struct Edge{
//  int frm,to;
//  int wht=1;
// };
bool cmp(Point& a, Point& b) {
    return a.val < b.val; 
}
void solve();
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

const int MOD = 1e9 + 7;
//  void dfs(int u, int fa, vector<vector<ll>>& g, vector<ll>& wht){
  
//  }
void solve() {
    ll n;
    cin >> n;
    vector<Point>deg(n+1);//dout(n+1);
    //vector<ll> a(n);
    //ll sum=0;
    vector<pair<ll,ll>>edge;
    vector<vector<ll>> g(n+1);
    vector<ll>wht(n+1);//weight
    for(int i=1;i<=n-1;i++){
        ll u,v;
        cin>>u>>v;
        //sum+=abs(u-v);
        deg[u].val++;
        deg[v].val++;
        deg[u].x=u;
        deg[v].x=v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u,v});
    }
    
    vector<ll>sum(n+1);
    vector<ll>parent(n+1);
    stack<pair<ll,bool>>st;
    st.push({1,0});
    parent[1]=0;
    while(!st.empty()){
        auto [u,flag]=st.top();
        st.pop();
        if(!flag){
            st.push({u,1});
            for(auto v:g[u]){
                if(v==parent[u])continue;
                parent[v]=u;
                st.push({v,0});
            }

        }
        else{
            sum[u]=0;
            for(auto v:g[u]){
                if(v==parent[u])continue;
                sum[u]+=sum[v]+abs(v-u);
                
            } 
        }
    }

}