#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[1000001];
ll vis[1000001],low[1000001],in[1000001];
ll timer;

// low array stores the lowest ancestor that cn be reached from that node.

void dfs(ll v, ll p)
{  
   vis[v]=1;
   in[v]=low[v]=timer;
   timer++;
   for(auto u:adj[v])
   {
     if(u==p) continue;
     if(vis[u]==1)
     {
     	low[v]=min(low[v],in[u]);
     }
     else 
     {
     	dfs(u,v);
     	if(low[u]>in[v]) cout<<v<<"-->"<<u<<" is bridge"<<"\n";
     	low[v]=min(low[v],low[u]);
     }
   }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

   // -1 for the parent of root node.

    dfs(1, -1); 
  return 0;
}
