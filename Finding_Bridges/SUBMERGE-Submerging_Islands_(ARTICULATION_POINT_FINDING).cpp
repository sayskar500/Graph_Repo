#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[1000001];
ll vis[1000001],in[1000001],low[1000001],timer;
set<ll> s; // set of articulatin points

void dfs(ll v,ll p)
{
	vis[v]=1;
	in[v]=low[v]=timer++;
	ll c=0; // child count
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
    		c++;
            low[v]=min(low[v],low[u]);
            if(low[u]>=in[v] and p!=-1) s.insert(v); 
    	}
    }
    if(p==-1 and c>1) s.insert(v);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  while(1)
  {
    ll n,m;
    cin>>n>>m;
    if(n==0 and m==0) break;
    ll h=m;
    for(ll i=1;i<=n;i++)
    {
      adj[i].clear();
      vis[i]=0;
    }
    s.clear();
    timer=1;
    while(h--)
    {
      ll a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for(ll i=1;i<=n;i++)
    {
      if(vis[i]=0) dfs(i,-1);
    }
    dfs(1,-1);
    cout<<s.size()<<endl;
  }
  return 0;
}
