#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

ll n;
bool vis[35][35];
char v[35][35];
ll dist[35][35];

bool chk(ll x,ll y)
{
	if(x<1 or x>n or y<1 or y>n) return false;
	if(vis[x][y]==true or v[x][y]=='T') return false;

	return true;
}

ll dx[]={-1, 0, 1, 0};
ll dy[]={0, 1, 0, -1};

void bfs(ll a,ll b)
{
	queue<pair<ll,ll>> q;
	vis[a][b]=1;
	q.push({a,b});
	dist[a][b]=0;
	while(!q.empty())
	{
       ll x=q.front().first;
       ll y=q.front().second;
       q.pop();
       for(ll i=0;i<4;i++)
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
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll e,f,g,h;
  cin>>n;
  for(ll i=1;i<=n;i++)
  {
  	for(ll j=1;j<=n;j++)
  	{
  		cin>>v[i][j];
  		if(v[i][j]=='S')
  		{
  			e=i;
  			f=j;
  		}
  		if(v[i][j]=='E')
  		{
  			g=i;
  			h=j;
  		}
  	}
  }

  bfs(e,f);
  cout<<dist[g][h]<<"\n";
  return 0;
}
