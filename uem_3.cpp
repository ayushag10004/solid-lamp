

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

ll pp[500],p[300005];
const ll lim = 2e11;

int main()
{	
	ll i,j;

	for(i=2;i<=450;i++)
	if(pp[i]==0)
	{
		for(j=i*2;j<=450;j+=i)
			pp[j] = 1;
	}

	pp[2] = 1;

	vector< pair<ll,ll> > vv;
	ll pr,in;

	for(i=2;i<=200000;i++)
	if(p[i]==0)
	{
		for(j=i*2;j<=200000;j+=i)
			p[j] = 1;

		pr = i;
		in = 1;

		while(pr<=lim)
		{	
			if(pp[in+1]==0)
				vv._pb(_mp(pr,in+1));

			pr*=i;
			++in;
		}
	}	

	sort(vv.begin(),vv.end());

	ll size = vv.size();

	for(i=1;i<size;i++)
		vv[i].ss+=vv[i-1].ss;

	ll t,l,r,in1,in2;
	s(t);

	while(t--)
	{
		s(l); s(r);

		in1 = lower_bound(vv.begin(),vv.end(),_mp(l,(ll)-MOD)) - vv.begin();
		in2 = lower_bound(vv.begin(),vv.end(),_mp(r+1,(ll)-MOD)) - vv.begin();

		ll aa = 0;

		if(in1>0)
			aa = vv[in1-1].ss;
		
		ll bb = 0;

		if(in2>0)
			bb = vv[in2-1].ss;

		cout<<bb-aa<<"\n";	    	
	}
	return 0;
}