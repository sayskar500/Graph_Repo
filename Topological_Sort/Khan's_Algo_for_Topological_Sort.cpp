#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

// Kahn's Algo for undirected graph

vector<ll> adj[1000001];
vector<ll> res; // keeps the sorted sequence
ll ind[1000001]; // to keep the in-degree

void kahn(ll v)
{
  queue<ll> q;
  for(ll i=1;i<=v;i++)
  {
  	if(ind[i]==0) q.push(i);
  }
  while(!q.empty())
  {
  	ll p=q.front();
  	res.push_back(p);
  	q.pop();
  	for(auto u:adj[p])
  	{
  		ind[u]--;
      if(ind[u]==0) q.push(u);
  	}
  }
  cout<<"Top Sort: ";
  for(auto y:res) cout<<y<<" ";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,m,x,y;
  cin>>n>>m;
  for(ll i=1;i<=m;i++)
  {
  	cin>>x>>y;
  	adj[x].push_back(y);
  	ind[y]++;
  }
  kahn(n);
  return 0;
}
