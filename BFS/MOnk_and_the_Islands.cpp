#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int

vector<ll> adj[10005];
ll vis[10005],dist[10005];
queue<ll> q;

void bfs(ll v)
{
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
      }
    }
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
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();
      vis[i]=0;
    }
    while(m--)
    {
      ll a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    bfs(1);
    cout<<dist[n]<<"\n";
  }
  return 0;
}
