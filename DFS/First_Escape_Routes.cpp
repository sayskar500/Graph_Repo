#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[100001];
ll vis[100001];
ll s;

void dfs(ll v)
{
  vis[v]=1;
  s++;

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
  ll t,a,b,n,m;
  cin>>t;
  while(t--)
  {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
      vis[i]=0;
      adj[i].clear();
    }
    for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    ll cnt=0;
    ll res=1;

    for(int i=1;i<=n;i++)
    {
      if(vis[i]==0)
      {
        s=0;
        dfs(i);
        cnt++;

        res=(res*s)%mod;
      }
    }
    cout<<cnt<<" "<<res<<endl;
  }
  return 0;
}
