#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[1001];
ll vis[1001],dist[1001];

void dfs(ll node,ll d)
{
  vis[node]=1;
  dist[node]=d;

  for(auto child:adj[node])
  {
    if(vis[child]==0) dfs(child,dist[node]+1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,q,a,b;
  cin>>n;
  for(int i=1;i<=n-1;i++)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1,0);
  cin>>q;
  ll ans=-1,minD=1e9;
  while(q--)
  {
    ll g;
    cin>>g;

    if(dist[g]<minD) {minD=dist[g];ans=g;}
    else
    {
      if(dist[g]==minD and g<ans) ans=g;
    }
  }
  cout<<ans<<endl;
  return 0;
}
