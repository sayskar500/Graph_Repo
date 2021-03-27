#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define ull unsigned long long int
#define mod 1000000007

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n,q,x,a,b,c;
  cin>>n>>q;
  vector<ll> v(n);
  for(auto&u:v) cin>>u;
  while(q--)
  {
    cin>>x;
    if(x==1)
    {
      cin>>c;
      c--;
      v[c]^=1;
    }
    else
    {
      cin>>a>>b;
      a--;
      b--;
      if(v[b]==1) cout<<"ODD"<<'\n';
      else cout<<"EVEN"<<"\n";
    }
  }
  return 0;
}
