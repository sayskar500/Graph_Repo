#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

ll n,m;
bool vis[1005][1005];
ll v[1005][1005],dist[1005][1005];

bool chk(ll a,ll b)
{
	if(a<1 or a>n or b<1 or b>m) return false;
	if(vis[a][b]==true) return false;

	return true;
}

ll dx[]={-1, 0, 1, 0};
ll dy[]={0, 1, 0, -1};

void bfs(ll a,ll b)
{
   queue<pair<ll,ll>> q;
   q.push({a,b});
   dist[a][b]=0;
   vis[a][b]=1;
   while(!q.empty())
   {
   	 ll x=q.front().first;
   	 ll y=q.front().second;
   	 q.pop();
   	 for(ll i=0;i<4;i++)  // only 4 directions considered here. It can be 8 directions as well.
   	 {
   	 	if(chk(x+dx[i],y+dy[i]))
   	 	{
   	 		ll na=x+dx[i];
   	 		ll nb=y+dy[i];

   	 		dist[na][nb]=dist[x][y]+1;
   	 		vis[na][nb]=1;
   	 		q.push({na,nb});
   	 	}
   	 }
   }

   for(ll i=1;i<=n;i++)
   {
   	 for(ll j=1;j<=m;j++)
   	 {
   	 	cout<<dist[i][j]<<" ";
   	 }
   	 cout<<"\n";
   }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll e,f;
  cin>>n>>m;
  cin>>e>>f;
  bfs(e,f);
  // x is the source cell and y is the destination cell.
  return 0;
}
