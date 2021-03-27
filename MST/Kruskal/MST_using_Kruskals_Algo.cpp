#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007

struct edge
{
  int a;
  int b;
  int w;
};

int p[10001];
edge adj[100001];

bool cmp(edge x,edge y)
{
  if(x.w<y.w) return true;
  else return false;
}

int find(int a)
{
  if(p[a]==-1) return a;

  return p[a]=find(p[a]);
}

void merge(int w, int x)
{
  p[w]=x;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m,a,b,w;
  cin>>n>>m;

  for(int i=1;i<=n;i++) p[i]=-1;

  for(int i=0;i<m;i++)
  {
    cin>>adj[i].a>>adj[i].b>>adj[i].w;
  }
  int sum=0;
  sort(adj,adj+m,cmp);

  for(int i=0;i<m;i++)
  {
    a=find(adj[i].a);
    b=find(adj[i].b);
    if(a!=b)
    {
      sum+=adj[i].w;
      merge(a,b);
    }
  }
  cout<<sum<<"\n";
  return 0;
}
