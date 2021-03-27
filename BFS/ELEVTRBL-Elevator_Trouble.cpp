#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007
#define maxN 10000005

bool vis[maxN];

ll bfs(ll f,ll s,ll g,ll u,ll d)
{
  queue<pair<ll,ll>> q;
  q.push({s,0});
  ll p=0;
  while(!q.empty())
  {
  	pair<ll,ll> a=q.front();
  	q.pop();
  	p=a.second;
  	vis[a.first]=true;
  	if(a.first==g) return p;
  	p++;
  	if(a.first+u<=f and vis[a.first+u]==false)
  	{
  		vis[a.first+u]=true;
  		q.push({a.first+u,p});
  	}
  	if(a.first-d>=0 and vis[a.first-d]==false)
  	{
  		vis[a.first-d]=true;
  		q.push({a.first-d,p});
  	}
  }
  return -1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll f,s,g,u,d;
  cin>>f>>s>>g>>u>>d;
  ll e=bfs(f,s,g,u,d);
  if(e==-1) cout<<"use the stairs"<<"\n";
  else cout<<e<<"\n";
  return 0;
}
