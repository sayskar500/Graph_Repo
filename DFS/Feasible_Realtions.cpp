#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int

vector<ll> adj[1000005];
ll vis[1000005],cnt[1000005];
ll ind;

void dfs(ll v)
{
  vis[v]=1;
  cnt[v]=ind;
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
  ll t,n,k,a,b;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    vector<pair<ll,ll>> v;
    for(int i=1;i<=n;i++)
    {
      adj[i].clear();
      vis[i]=0;
    }
    for(int i=1;i<=k;i++)
    {
      string c;
      cin>>a>>c>>b;
      if(c=="=")
      {
        adj[a].push_back(b);
        adj[b].push_back(a);
      }
      else
      {
        v.push_back({a,b});
      }
    }
    for(int i=1;i<=n;i++)
    {
      if(vis[i]==0)
      {
        ind++;
        dfs(i);
      }
    }
    bool f=true;
    for(int i=0;i<v.size();i++)
    {
      a = v[i].first;
      b = v[i].second;
      if(cnt[a]==cnt[b])
      {
        f=false;
        break;
      }
    }
    if(f) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
  }
  return 0;
}
