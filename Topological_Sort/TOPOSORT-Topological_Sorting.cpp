#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

vector<ll> adj[100001];
vector<ll> res;
ll ind[100001];

bool kahn(ll v)
{
  priority_queue<ll,vector<ll>,greater<ll>> q; 
  // to keep the output the order in lexicograpgical order in res
  // the min is at the top of the priority queue
  for(ll i=1;i<=v;i++)
  {
    if(ind[i]==0) q.push(i);
  }
  while(!q.empty())
  {
    ll p=q.top();
    res.push_back(p);
    q.pop();
    for(auto u:adj[p])
    {
      ind[u]--;
      if(ind[u]==0) q.push(u);
    }
  }
  return res.size()==v;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m;
  cin>>n>>m;
  while(m--)
  {
  	ll x,y;
  	cin>>x>>y;
  	adj[x].push_back(y);
  	ind[y]++;
  }
  if(!kahn(n)) cout<<"Sandro fails."<<"\n";
  else
  {
    for(auto h:res) cout<<h<<" ";
  }
  return 0;
}
