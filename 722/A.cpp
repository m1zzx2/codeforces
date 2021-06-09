#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int tot = 0;
vector<int>e[maxn];
int edge_val_left[maxn];
int edge_val_right[maxn];
ll dp[maxn][2];
bool vis[maxn];
void init(int n){
    tot = 0;
    for(int i = 0; i <= n;i++){
        e[i].clear();
        vis[i]  = false;
        dp[i][0] = dp[i][1] = 0;
    }
}


void add(int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

ll max(ll a, ll b){
    if(a < b){
        a = b;
    }
    return a;
}

ll _abs(ll a){
    if(a < 0){
        a = -a;
    }
    return a;
}
void dfs(int root){
    if(vis[root]){
        return;
    }
    vis[root]  = true;
    int sze = e[root].size();
    for(int i =0 ; i < sze ; i++){
         int v = e[root][i];
         if (root != v && !vis[v]){
            int left_val = edge_val_left[v];
            int right_val = edge_val_right[v];
            int root_left_val =  edge_val_left[root];
            int root_right_val =  edge_val_right[root];
            dfs(v);
            vis[v] = true;
            dp[root][0] =dp[root][0]+ max(dp[v][0] + _abs(left_val -root_left_val), dp[v][1] + abs(right_val - root_left_val));
            dp[root][1] =  dp[root][1]+max(dp[v][0] + _abs(left_val -root_right_val), dp[v][1] + abs(right_val - root_right_val));
         }
    }
}

void format_input(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        init(n);
        for(int i = 1 ;  i <= n;i++){
            int a, b;
            cin>>edge_val_left[i]>>edge_val_right[i];
        }
        for(int i = 1; i < n;i++){
            int a, b;
            cin>>a>>b;
            add(a,b);
            add(b,a);
        }
        dfs(1);
        cout<<max(dp[1][0], dp[1][1])<<endl;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    format_input();
}