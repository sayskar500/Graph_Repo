#include<bits/stdc++.h>
using namespace std;

vector<int> adj[105];
int label[105];
int n;

bool dfs(int v, int stc)
{
  if(stc==n) return true;
  for(int i=0;i<adj[v].size();i++)
  {
    if(label[adj[v][i]]==0)
    {
      label[adj[v][i]] = 1;

      if(dfs(adj[v][i],stc+1)) return true;

      label[adj[v][i]]= 0;
    }
  }
  return false;
}

bool check()
{
  memset(label, 0, sizeof(label));
  for(int i=1;i<=n;i++)
  {
    label[i]=1;

    if(dfs(i,1)) return true;

    label[i]=0;
  }

  return false;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int m;
    cin>>n>>m;
    for(int i=0;i<m+n;i++) 
    {
      adj[i].clear();
      label[i]=0;
    }
    for(int i = 0; i < m; i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    check()?cout<<"1\n":cout<<"0\n";
  }

}