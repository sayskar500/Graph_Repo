#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

ll n,m;
bool vis[1001][1001];

bool isValid(ll x,ll y)
{
	if(x<1 or x>n or y<1 or y>m) return false;
	if(vis[x][y]==true) return false;

	return true;
}


ll dx[]={-1, 0, 1, 0};
ll dy[]={0, 1, 0, -1};

void dfs(ll a,ll b)
{
	vis[a][b]=1;
	cout<<a<<" "<<b<<"\n";

	for(ll i=0;i<4;i++)
	{
		if(isValid(a+dx[i],b+dy[i])) dfs(a+dx[i],b+dy[i]);
	}
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>n>>m; // no. of rows and columns
  dfs(1,1);
  return 0;
}
