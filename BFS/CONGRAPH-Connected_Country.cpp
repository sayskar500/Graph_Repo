#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[4000000];
bool vis[4000000];

void dfs(ll v)
{
	vis[v]=true;
	for(auto u:adj[v])
	{
		if(!vis[u]) dfs(u);
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m;
  cin>>n>>m;
  for(ll i=1;i<=m;i++)
  {
    ll u,v;
  	cin>>u>>v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  } 
  ll cnt=0;
  for(ll i=0;i<n;i++)
  {
  	if(!vis[i])
  	{
  		dfs(i);
  		cnt++;
  	}
  }
  cout<<cnt-1<<"\n";
  return 0;
}
