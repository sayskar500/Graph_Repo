#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[1000001]; 
vector<ll> tr[1000001]; // transpose graph
vector<ll> order;
vector<ll> scc;
ll vis[1000001],v[1000001];

void dfs(ll v)
{
  vis[v]=1;
  for(auto u:adj[v])
  {
    if(vis[u]==0) dfs(u);
  }
  order.push_back(v);
}

void dfs1(ll v)
{
  vis[v]=1;
  for(auto u:tr[v])
  {
    if(vis[u]==0) dfs1(u);
  }
  scc.push_back(v);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t,n,m,a,b;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
      adj[i].clear();
      tr[i].clear();
      vis[i]=0;
    }
    order.clear();
    for(ll i=1;i<=m;i++)
    {
      cin>>a>>b;
      adj[a].push_back(b);
      tr[b].push_back(a);
    }
    for(ll i=1;i<=n;i++)
    {
      if(vis[i]==0) dfs(i);
    }
    for(ll i=1;i<=n;i++)
    {
      vis[i]=0;
    }
    for(ll i=1;i<=n;i++)
    {
      if(vis[order[n-i]]==0)
      {
        scc.clear();
        dfs1(order[n-i]);
        
        cout<<"dfs1() called from "<<order[n-i]<<" and printing scc"<<endl;
        for(auto node:scc) cout<<node<<" ";
        cout<<endl;
      }
    }
  }
  return 0;
}
