#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int

vector<ll> adj[100005];
vector<ll> prime;
ll vis[100005],dist[100005];

bool isPrime(ll x)
{
    for(ll d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

bool valid(ll a,ll b)
{
  ll cnt=0;
  while(a>0)
  {
    if(a%10!=b%10) cnt++;
    a/=10;
    b/=10;
  }
  if(cnt==1) return true;
  else return false;
}

void graph()
{
  for(ll i=1000;i<=9999;i++)
  {
    if(isPrime(i)) prime.push_back(i);
  }

  for(ll i=0;i<prime.size();i++)
  {
    for(ll j=i+1;j<prime.size();j++)
    {
      ll p=prime[i];
      ll r=prime[j];
      if(valid(p,r))
      {
        adj[p].push_back(r);
        adj[r].push_back(p);
      }
    }
  }
}

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
      }
    }
  }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  graph();
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,m;
    cin>>n>>m;
    for(ll i=1000;i<=9999;i++)
    {
      vis[i]=0;
      dist[i]=-1;
    }
    bfs(n);
    if(dist[m]==-1) cout<<"Impossible"<<"\n";
    else cout<<dist[m]<<"\n";
  }
  return 0;
}
