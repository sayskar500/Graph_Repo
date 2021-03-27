#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n;
  vector<pair<int,int>> e(n-1);
  vector<int> ans(n+1,0);
  for(int i=0;i<n-1;i++)
  {
  	cin>>e[i].first>>e[i].second;
    ans[e[i].first]++;
    ans[e[i].second]++;
  }
  int cnt=-1;
  for(int i=1;i<=n;i++)
  {
    if(ans[i]>2) cnt=i;
  }
  int s=0,l=n-2;
  for(int i=0;i<n-1;i++)
  {
    if(e[i].first==cnt or e[i].second==cnt) cout<<s++<<"\n";
    else cout<<l--<<"\n";
  }
  return 0;
}
