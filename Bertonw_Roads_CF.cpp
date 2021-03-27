#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[100005];
ll vis[100005],low[100005],in[100005];
ll timer;
bool ok;
vector<pair<ll,ll>> e;

void dfs(ll v,ll p)
{
	vis[v]=1;
	low[v]=in[v]=timer++;
	for(auto u:adj[v])
	{
      if(u==p) continue;
      if(vis[u]==1)
      {
         low[v]=min(low[v],in[u]);
         if(in[v]>in[u])
         {
         	e.push_back({v,u});
         }
      }
      else 
      {
      	dfs(u,v);
      	if(low[u]>in[v])
      	{
      		ok=true;
      		return;
      	} 

      	e.push_back({v,u});
        low[v]=min(low[v],low[u]);
      }
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m,a,b;
  cin>>n>>m;
  ll k=m;
  while(k--)
  {
  	cin>>a>>b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  dfs(1,-1);
  if(ok) cout<<0<<"\n";
  else
  {
    for(auto h:e)
    {
    	cout<<h.first<<" "<<h.second<<"\n";
    }
  }
  return 0;
}
