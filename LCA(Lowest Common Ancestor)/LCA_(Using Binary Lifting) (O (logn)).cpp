#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

const ll maxN=10;
vector<ll> adj[1001];
ll LCA[1001][maxN+1],lvl[1001];

void dfs(ll v,ll l,ll p)
{
  LCA[v][0]=p;
  lvl[v]=l;
  for(auto u:adj[v])
  {
    if(u!=p) dfs(u,l+1,v);
  }
}

void init(ll n)
{
  dfs(1,0,-1);
  for(ll i=1;i<=maxN;i++)
  {
    for(ll j=1;j<=n;j++)
    {
      if(LCA[j][i-1]!=-1)
      {
        ll p=LCA[j][i-1];
        LCA[j][i]=LCA[p][i-1];
      }
    }
  }
}

ll lca(ll a,ll b)
{ 
  if(lvl[a]>lvl[b]) swap(a,b);
  ll d=lvl[b]-lvl[a];
  while(d>0)
  {
    ll r=log2(d);
    b=LCA[b][r];
    d-=(1<<r);
  }
  if(a==b) return a;
  for(ll i=maxN;i>=0;i--)
  {
    if(LCA[a][i]!=-1 and (LCA[a][i]!=LCA[b][i]))
    {
      a=LCA[a][i];
      b=LCA[b][i];
    }
  }
  return LCA[a][0];
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
    ll w=n;
    for(ll i=1;i<=n;i++)
    {
      adj[i].clear();
      lvl[i]=0;
    } 
    for(ll i=1;i<=n;i++)
    {
      for(ll j=0;j<=maxN;j++)
      {
        LCA[i][j]=-1;
      }
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
          adj[w-n].push_back(v[k]);
          adj[v[k]].push_back(w-n);
        }
      }
      else continue;
    }
    //preprocess();
    init(w);
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
