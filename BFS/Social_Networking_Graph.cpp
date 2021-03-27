#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007

vector<ll> adj[1000005];
ll vis[1000005],lvl[1000005],dist[1000005];

void bfs(ll v)
{
  queue<ll> q;
  q.push(v);
  vis[v]=1;
  dist[v]=0;
  while(!q.empty())
  {
    ll p=q.front();
    q.pop();
    for(auto u:adj[p])
    {
      if(vis[u]==0)
      {
        vis[u]=1;
        q.push(u);
        dist[u]=dist[p]+1;
        lvl[dist[u]]++;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,e;
  cin>>n>>e;
  while(e--)
  {
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ll m;
  cin>>m;
  for(ll i=0;i<m;i++)
  {
    ll a,b;
    cin>>a>>b;
    for(ll i=0;i<=n;i++)
    {
      lvl[i]=0;
      vis[i]=0;
    }
    bfs(a);
    cout<<lvl[b]<<"\n";
  }
  return 0;
}
