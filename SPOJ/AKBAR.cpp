#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

bool dfs(int x,int y,int w,vector<int> adj[],vector<int>&vis,vector<int>&p)
{
	if(vis[y]!=-1 and vis[y]!=x) return false;
	vis[y]=x;
	if(w==0) return true;
	for(auto u:adj[y])
	{
		p[u]=y;
		bool ans=dfs(x,u,w-1,adj,vis,p);
		if(ans==false) return false;
	}
	return true;
}

void solve()
{
	ll n,r,m;
  	cin>>n>>r>>m;
  	// for(int i=0;i<=r;i++)
  	// {
  	// 	adj[i].clear();
  	// 	vis[i]=0;
  	// 	//p[i]=0;
  	// }
  	vector<int> adj[n];
  	vector<int> vis(n,-1),p(n,-1);
  	vector<pair<int,int>> v;
  	for(int i=0;i<r;i++)
  	{
  		int a,b;
  		cin>>a>>b;
  		a--;
  		b--;
  		adj[a].push_back(b);
  		adj[b].push_back(a);
  	}
  	for(int i=0;i<m;i++)
  	{
  		int k,s;
  		cin>>k>>s;
  		k--;
  		v.push_back({k,s});
  	}
  	bool ok=true;
  	for(int i=0;i<m;i++)
  	{
  		int a=v[i].first;
  		int b=v[i].second;
  		ok=dfs(a,a,b,adj,vis,p);
  		if(ok==false)
  		{
  			cout<<"No"<<endl;
  			return;
  		}
  	}

  	for(int i=0;i<n;i++)
  	{
  		int q=vis[i];
  		if(q==-1)
  		{
  			cout<<"No"<<endl;
  			return;
  		}
  	}
  	cout<<"Yes"<<endl;
  	return;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin>>t;
  while(t--)
  {
  	solve();
  }
  return 0;
}
