#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

const static int INF=1e9;
ll n,m,e,f,g,h;
bool vis[1005][1005];
ll v[1005][1005],dist[1005][1005],cost[1005][1005];

bool chk(ll w, ll z)
{
    if(w<1 or w>n or z<1 or z>m) return false;
    if(vis[w][z]==true or v[w][z]==1) return false;

    return true;
}

ll dx[]={-1, 0, 1, 0};
ll dy[]={0, 1, 0, -1};

void dijkstra(ll a,ll b)
{
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
    pq.push({cost[n][1],{a,b}});
    vis[a][b]=1;
    dist[a][b]=cost[a][b];
    while(!pq.empty())
    {
        ll cur_d=pq.top().first;
        pair<ll,ll> curr=pq.top().second;
        ll x=curr.first;
        ll y=curr.second;
        pq.pop();
        //if(vis[x][y]) continue;
        //vis[x][y]=1;
        for(ll i=0;i<4;i++)
        {
            if(chk(x+dx[i],y+dy[i]) and cur_d+cost[x+dx[i]][y+dy[i]]<dist[x+dx[i]][y+dy[i]])
            {
                ll na=x+dx[i];
                ll nb=y+dy[i];
                vis[na][nb]=1;
                dist[na][nb]=dist[x][y]+cost[na][nb];
                pq.push({dist[na][nb],{na,nb}});
            }
        }
    }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m;
  for(ll i=1;i<=n;i++)
  {
      for(ll j=1;j<=m;j++)
      {
          dist[i][j]=INF;
      }
  }
  for(ll i=1;i<=n;i++)
  {
      for(ll j=1;j<=m;j++)
      {
          cin>>v[i][j];
      }
  }
  for(ll i=1;i<=n;i++)
  {
      for(ll j=1;j<=m;j++)
      {
          cin>>cost[i][j];
      }
  }
  for(ll i=1;i<=n;i++)
  {
      for(ll j=1;j<=m;j++)
      {
          if(v[i][j]==1) cost[i][j]=INF;
      }
  }
  e=n,f=1;
  dijkstra(e,f);
  g=1,h=m;
  cout<<dist[g][h]<<"\n";
  return 0;
} 