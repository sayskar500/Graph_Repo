#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[1005];
ll lvl[1005],vis[1005],par[1005];

void dfs(ll v,ll h)
{
    par[v]=h;
    lvl[v]=lvl[h]+1;
    for(auto u:adj[v])
    {
    	if(u!=h)
      {
        dfs(u,v);
      } 
    }
}

ll lca(ll a,ll b)
{
	if(a==b) return a;
	if(lvl[a]>lvl[b]) swap(a,b);
  b=par[b];
	return lca(a,b);
}

void preprocess()
{
  lvl[0]=-1;
  dfs(1,0);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t,x,f,w,z,n;
  cin>>t;
  ll k=t;
  while(t--)
  {
  	cin>>n;
    ll p=n;
    for(ll i=1;i<=n;i++)
    {
      adj[i].clear();
      par[i]=0;
      vis[i]=0;
    } 
  	while(n--)
  	{
  		cin>>x;
  		if(x>0)
  		{
  			vector<ll> v(x);
  			for(ll j=0;j<x;j++)
	  		{
	  			cin>>v[j];
	  		}
	  		for(ll k=0;k<x;k++)
	  		{
	  			adj[p-n].push_back(v[k]);
	  			adj[v[k]].push_back(p-n);
	  		}
  		}
  		else continue;
  	}
    preprocess();
  	ll q;
  	cin>>q;
  	cout<<"Case "<<k-t<<":"<<"\n";
  	while(q--)
  	{
  		cin>>w>>z;
  		cout<<lca(w,z)<<"\n";
  	}
  }
  return 0;
}
