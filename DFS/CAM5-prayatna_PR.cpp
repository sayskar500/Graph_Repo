#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int

vector<ll> adj[100001];
ll vis[100001];

void dfs(ll v)
{
  vis[v]=1;
  for(auto u:adj[v])
  {
    if(vis[u]==0) dfs(u);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,e;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
      adj[i].clear();
      vis[i]=0;
    }
    while(e--)
    {
      ll a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    ll cnt=0;
    for(int i=0;i<n;i++)
    {
      if(vis[i]==0) cnt++,dfs(i);
    }
    cout<<cnt<<"\n";
  }
  return 0;
}
