#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

const int maxN=10;
vector<ll> adj[1001];
ll lvl[1001],LCA[1001][maxN+1];

void dfs(ll v,ll l,ll p)
{
	lvl[v]=l;
	LCA[v][0]=p;
	for(auto u:adj[v])
	{
	  if(u!=p) dfs(u,l+1,v);
	}
}

void init(ll n)
{
	dfs(1,0,-1);
	for(ll i=1;i<=maxN;i++)
	{
		for(ll j=1;j<=n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				ll w=LCA[j][i-1];
				LCA[j][i]=LCA[w][i-1];
			}
		}
	}
}

ll lca(ll a,ll b)
{
	if(lvl[a]>lvl[b]) swap(a,b);
	ll d=lvl[b]-lvl[a];
	while(d>0)
	{
		ll r=log2(d);
		b=LCA[b][r];
		d-=(1<<r);
	}
	if(a==b) return a;
	for(ll i=maxN;i>=0;i--)
	{
		if(LCA[a][i]!=-1 and LCA[a][i]!=LCA[b][i])
		{
			a=LCA[a][i];
			b=LCA[b][i];
		}
	}
	return LCA[a][0];
}

ll getDist(ll a,ll b)
{
	ll h=lca(a,b);
	return lvl[a]+lvl[b]-2*lvl[h];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t,n,a,b,x,y;
	cin>>n; 
  	for(ll i=1;i<=n;i++)
  	{
  		for(ll j=0;j<=maxN;j++)
  		{
  			LCA[i][j]=-1;
  		}
  	}
  	for(ll i=1;i<n;i++) 
  	{
  		cin>>a>>b;
  		adj[a].push_back(b);
  		adj[b].push_back(a);
  	}
  	init(n);
  	ll q;
  	cin>>q;
  	while(q--)
  	{
  		cin>>x>>y;
  		cout<<getDist(x,y)<<endl;
  	}
    return 0;
}
