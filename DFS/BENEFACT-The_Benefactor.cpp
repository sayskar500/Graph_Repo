#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int

vector<vector<pair<ll,ll>>> F;
ll vis[50001];
ll res=0,ind=0;

void dfs(ll v,ll d)
{
  if(res<d)
  {
    res=d;
    ind=v;
  }
  vis[v]=1;
  for(ll i=0;i<F[v].size();i++)
  {
    if(vis[F[v][i].first]==0)
    {
      dfs(F[v][i].first,d+F[v][i].second);
    }
  }
  vis[v]=0;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin>>t;
  for(ll j=0;j<t;j++)
  {
    ll n;
    cin>>n;
    F=vector<vector<pair<ll,ll>>> (n+1);
    for(ll i=1;i<n;i++)
    {
      ll a,b,c;
      cin>>a>>b>>c;
      F[a].push_back(make_pair(b,c));
      F[b].push_back(make_pair(a,c));
    }
    res=0;
    ind=0;
    dfs(1,0);
    res=0;
    dfs(ind,0);
    cout<<res<<"\n";
  }
  return 0;
}
