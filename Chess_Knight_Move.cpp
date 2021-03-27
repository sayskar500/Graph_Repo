#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

ll dx[]={-2,-1,1,2,2,1,-1,-2};
ll dy[]={1,2,2,1,-1,-2,-2,-1};
ll t1,t2;
ll vis[10][10],dist[10][10];

bool chk(ll x,ll y)
{
	if(x<1 or x>8 or y<1 or y>8) return false;
	if(vis[x][y]==1) return false;

	return true;
}

ll bfs(ll a,ll b)
{
  queue<pair<ll,ll>> q;
  dist[a][b]=0;
  vis[a][b]=1;
  q.push({a,b});
  if(a==t1 and b==t2) return dist[a][b];
  while(!q.empty())
  {
  	ll x=q.front().first;
  	ll y=q.front().second;
  	q.pop();
  	for(ll i=0;i<8;i++)
  	{
  		if(chk(x+dx[i],y+dy[i]))
  		{
  			ll nx=x+dx[i];
  			ll ny=y+dy[i];
  			dist[nx][ny]=dist[x][y]+1;
  			vis[nx][ny]=1;
  			q.push({nx,ny});
  			if(nx==t1 and ny==t2) return dist[nx][ny];
  		}
  	}
  }
}

ll getX(char c)
{
	return c-'a'+1;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t,g,h;
  cin>>t;
  while(t--)
  {
    char e,f;
    for(ll i=1;i<=8;i++)
    {
    	for(ll j=1;j<=8;j++)
    	{
    		vis[i][j]=0;
    	}
    }
    cin>>e>>f;
    g=getX(e);
    h=f-'0';
    cin>>e>>f;
    t1=getX(e);
    t2=f-'0';
    cout<<bfs(g,h)<<endl;
  }
  return 0;
}
