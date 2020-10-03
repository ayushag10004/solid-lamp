

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
}

/******************************************************************************************************/

vector< vector<ll> > v(3);
ll n,aa[1000005];
string s;

ll go(ll a,ll b,ll ln)
{
	if(ln>=n/2)
	{
		aa[a] = aa[b] = 1;
		return 1;
	}

	if(b-a<=1)
		return 0;

	if(b-a==2 && go(a+1,b-1,ln+1))
	{
		aa[a] = aa[b] = 1;
		return 1;
	}
	else if(b-a==3 && s[a+1]==s[b-1] && go(a+1,b-1,ln+2))
	{
		aa[a] = aa[b] = 1;
		return 1;
	}
	else if(b-a==4)
	{
		if(s[a+1]==s[b-1] && go(a+1,b-1,ln+2))
		{
			aa[a] = aa[b] = 1;
			return 1;
		}
		else if(s[a+2]==s[b-2] && go(a+2,b-2,ln+1))
		{
			aa[a] = aa[b] = 1;
			return 1;
		}
	}
	else if(b-a>=5)
	{
		if(s[a+1]==s[b-1] && go(a+1,b-1,ln+2))
		{
			aa[a] = aa[b] = 1;
			return 1;
		}
		
		if(s[a+1]==s[b-2] && go(a+1,b-2,ln+2))
		{
			aa[a] = aa[b] = 1;
			return 1;
		}

		if(s[a+2]==s[b-1] && go(a+2,b-1,ln+2))
		{
			aa[a] = aa[b] = 1;
			return 1;
		}

		if(s[a+2]==s[b-2] && go(a+2,b-2,ln+2))
		{
			aa[a] = aa[b] = 1;
			return 1;
		}
	}

	return 0;
}

int main()
{
	cin>>s;

	n=s.size();
	ll i,j,a,b,ln;

	for(i=0;i<n;i++)
		v[s[i]-'a']._pb(i);

	for(i=0;i<3;i++)
	if(v[i].size()>0)
	{
		a = v[i][0];
		b = v[i][v[i].size()-1];
		ln = 2;

		if(a==b)
			ln = 1;

		if(go(a,b,ln))
		{
			for(j=0;j<n;j++)
				if(aa[j]==1)
					cout<<s[j];

			return 0;
		}

	}	

	cout<<"IMPOSSIBLE\n";

	return 0;
}