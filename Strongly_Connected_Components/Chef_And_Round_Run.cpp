#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[1000001],tr[1000001];
vector<ll> order,scc;
ll vis[1000001],val[1000001];

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
  ll t,res=0;
  cin>>t;
  while(t--)
  {
  	ll n;
  	cin>>n;
  	order.clear();
  	res=0;
  	for(ll i=1;i<=n;i++)
  	{
  		adj[i-1].clear();
  		tr[i-1].clear();
  		vis[i-1]=0;
  		cin>>val[i-1];
  	}
  	for(ll i=1;i<=n;i++)
  	{
  		ll a=i-1;
  		ll b=(i-1+val[i-1]+1)%n;
  		adj[a].push_back(b);
  		tr[b].push_back(a);
  	}
  	for(ll i=1;i<=n;i++) 
  	{
  		if(vis[i-1]==0) dfs(i-1);
  	}
  	for(ll i=1;i<=n;i++) vis[i-1]=0;
  	reverse(order.begin(),order.end());
    for(auto i:order)
    {
    	if(vis[i]==0)
    	{
    		scc.clear();
    		dfs1(i);
    		if(scc.size()==1 and (scc[0]!=adj[scc[0]][0])) continue;
    		res+=scc.size();
    	}
    }
    cout<<res<<"\n";
  }
  return 0;
}
