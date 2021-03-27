#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

ll n,m,s=0,w=0,K=-1,W=-1;
char v[300][300];
bool vis[300][300];
ll dist[300][300];

bool chk(ll x,ll y)
{
	if(x<1 or x>n or y<1 or y>m) return false;
	if(vis[x][y]==true or v[x][y]=='#') return false;
	return true;
}

ll dx[]={-1, 0, 1, 0};
ll dy[]={0, 1, 0, -1};

void dfs(ll a,ll b)
{
	vis[a][b]=1;
	if(v[a][b]=='k') K++;
	if(v[a][b]=='v') W++;
	for(ll i=0;i<4;i++)
	{
		if(chk(a+dx[i],b+dy[i])) dfs(a+dx[i],b+dy[i]);
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
  		cin>>v[i][j];
  		if(v[i][j]=='k') s++;
  		if(v[i][j]=='v') w++;
  	}
  }
  
  memset(vis,0,sizeof(vis));

  for(ll i=1;i<=n;i++)
  {
  	for(ll j=1;j<=m;j++)
  	{
  		if(v[i][j]!='#' and vis[i][j]==0)
  		{
  			K=0,W=0;
  			dfs(i,j);
  			if(K>W) w-=W;
  			else s-=K;
  		}
  	}
  }

  cout<<s<<" "<<w<<"\n";

  return 0;
}
