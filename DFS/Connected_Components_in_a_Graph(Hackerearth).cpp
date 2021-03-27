#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[100001];
ll n;
bool visited[100001];

void dfs(ll v)
{
  visited[v]=true;
  for(auto u:adj[v])
  {
    if(!visited[u]) dfs(u);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll e;
  cin>>n>>e;
  for(int i=1;i<=e;i++)
  {
    ll u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ll cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(!visited[i])
    {
      dfs(i);
      cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}
