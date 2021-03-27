#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int

vector<ll> adj[10025];
ll vis[10025],in[10025];
ll cnt,res;

void dfs(ll v)
{
  vis[v]=1;
  cnt++;
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
  ll n,m;
  cin>>n>>m;
  for(ll i=0;i<m;i++)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for(ll i=1;i<=n;i++)
  {
    for(ll j=1;j<=n;j++)
    {
      vis[j]=0;
    }
    cnt=0;
    dfs(i);
    res=max(res,cnt);
  }
  cout<<res<<"\n";
  return 0;
}
