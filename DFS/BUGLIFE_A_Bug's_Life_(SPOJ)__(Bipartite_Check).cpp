#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[2001];
ll vis[2001],col[2001];

bool dfs(ll v,ll c)
{
  vis[v]=1;
  col[v]=c;

  for(auto child:adj[v])
  {
    if(vis[child]==0)
    {
      if(dfs(child,c^1)==false) return false;
    }
    else
    {
      if(col[v]==col[child]) return false;
    }
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  ll k=t;
  while(t--)
  {
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();
      vis[i]=0;
    }
    for(int i=1;i<=m;i++)
    {
      ll x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    bool flag=true;
    //dfs(1,0);
    for(int i=1;i<=n;i++)
    {
      if(vis[i]==0)
      {
        bool res=dfs(i,0);
        if(res==false) flag=false;
      }
    }
    if(flag) cout<<"Scenario #"<<(k-t)<<":"<<endl<<"No suspicious bugs found!"<<endl;
    else cout<<"Scenario #"<<(k-t)<<":"<<endl<<"Suspicious bugs found!"<<endl;
  }
  return 0;
}
