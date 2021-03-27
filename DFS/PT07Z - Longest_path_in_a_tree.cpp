#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[10001];
ll vis[10001];
ll dsit[10001];

ll maxD,maxN;

void dfs(ll v,ll d)
{
  vis[v]=1;
  if(d>maxD) maxD=d,maxN=v;
  for(auto u:adj[v])
  {
    if(vis[u]==0) dfs(u,d+1);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t,h;
  cin>>t;
  h=t;
  while(h--)
  {
    ll a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  maxD=-1;
  dfs(1,0);

  for(int i=1;i<=t;i++) vis[i]=0;

  maxD=-1;
  dfs(maxN,0);
  cout<<maxD<<endl;
  return 0;
}
