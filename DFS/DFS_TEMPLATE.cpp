#include<bits/stdc++.h>
#define ll long long int;

// SIMPLE IMPLEMENTATION

vector<vector<ll>> adj; // graph represented as an adjacency list
ll n; // number of vertices

vector<bool> visited;

void dfs(ll v)
{
  visited[v] = true;
  for(auto g:adj[v])
  {
    if(!visited[g]) dfs(g);
  }
}

// OPTIMIZED IMPLEMENTATION
/* As described in the applications it might be useful to
also compute the entry and exit times and vertex color.
We will color all vertices with the color 0,
if we haven't visited them, with the color 1 if we visited them,
and with the color 2, if we already exited the vertex.*/

vector<vector<ll>> adj1; // graph represented as an adjacency list
ll n1;

vector<ll> color;

vector<ll> time_in, time_out;
ll dfs_timer=0;

void dfs1(ll v1)
{
  time_in[v1]=dfs_timer++;
  color[v]=1;
  for(auto u:adj1[v1])
  {
    if(color[u]==0) dfs(u);
  }
  color[v1]=2;
  time_out=dfs_timer++;
}
