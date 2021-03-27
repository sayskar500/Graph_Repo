#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[100001];
ll vis[100001];

void dfs(ll v)
{
  vis[v]=1;
  for(auto child:adj[v])
  {
    if(vis[child]==0) dfs(child);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m,a,b;
  cin>>n>>m;
  ll h=m;
  while(h--)
  {
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  ll cnt=0;
  for(ll i=1;i<=n;i++)
  {
    if(vis[i]==0)
    {
      dfs(i);
      cnt++;
    }
  }

  if(cnt==1 and m==n-1) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
