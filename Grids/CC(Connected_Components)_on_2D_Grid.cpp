#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

ll n,m;
bool vis[1001][1001];
ll v[1001][1001];

bool chk(ll x,ll y)
{
	if(x<1 or x>n or y<1 or y>m) return false;

	if(vis[x][y]==true or v[x][y]==0) return false;

	return true;
}

ll dx[]={-1, 0, 1, 0};
ll dy[]={0, 1, 0, -1};

void dfs(ll a,ll b)
{
	vis[a][b]=1;

	for(ll i=0;i<4;i++)
	{
		if(chk(a+dx[i],b+dy[i]))
		{
			dfs(a+dx[i],b+dy[i]);
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
  		cin>>v[i][j];
  	}
  }

  ll cnt=0;

  for(ll i=1;i<=n;i++)
  {
  	for(ll j=1;j<=m;j++)
  	{
  		if(vis[i][j]==0 and v[i][j]==1)
  		{
  			cnt++;
  			dfs(i,j);
  		} 
  	}
  }

  cout<<"Connected Components = "<<cnt<<"\n";
  return 0;
}
