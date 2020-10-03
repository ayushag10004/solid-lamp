

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define M(x) (x%MOD + MOD)%MOD
#define _pb push_back
#define _mp make_pair
#define ff first
#define ss second
#define s(x) scanf("%lld",&x)
	
ll mul(ll x,ll y)
{ ll ans=1;

  while(y>0)
  { if(y&1)
	ans=(ans*x)%MOD;
	y/=2;
	x=(x*x)%MOD;
  }

  return ans;
};

/******************************************************************************************************/

string aa,bb;

ll go(vector<ll> v, ll in,ll last,ll mask)
{	
	vector<ll> vv(10,0);

	for(i=0;i<10;i++)
	for(j=0;j<=9;j++)
	if(i!=j)
	{
		vv[j] = M(vv[j] + v[i]);
		ans = M(ans + M( v[i]*M( j*mul(10,in) ) ) );
	}
	else
		vv[j] = M(vv[j] + v[i]);

	ll ch=-1;

	if(in+1<aa.size())
		ch = aa[in+1]-'0';

	for(j=0;j<aa[in]-'0';j++)
	if(ch!=j)
	{
		vv[j] = M(vv[j] + 1);
		ans = M(ans + M( 1*M( j*mul(10,in) ) ) );
		ans = M(ans + last);
	}

	if(ch)

}

int main()
{	
	ll t;
	s(t);

	while(t--)
	{
		ll a,b;
		cin>>a>>aa;
		cin>>b>>bb;

		vector <ll> v(10,0);
		v[0] = 1;

		cout<<M(go(v,a-1,0,1) - go(v,b-1,0,0))<<"\n";
	}
	return 0;
}