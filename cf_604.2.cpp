

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

int play(ll turn,ll a,ll b,ll c,ll d)
{
	ll last = -1;

	while(1)
		{
			if(turn==0)
			{
				if(a>0)
				{
					if(last!=-1 && last!=1)
						break;

					last = 0;
					--a;
				}
				else if(c>0)
				{

					if(last!=-1 && last!=1 && last!=3)
						break;

					last = 2;
					--c;
				}
				else 
					break;

				turn = 1;
			}
			else
			{
				if(b>0)
				{
					if(last!=-1 && last!=0 && last!=2)
						break;

					last = 1;
					--b;
				}
				else if(d>0)
				{
					if(last!=-1 && last!=2)
						break;

					last = 3;
					--d;
				}
				else 
					break;

				turn = 0;
			} 

		}


		if(a+b+c+d==0)
			return 1;
		else
			return 0;
}

void print_play(ll turn,ll a,ll b,ll c,ll d)
{
	ll last = -1;

	while(1)
		{
			// cout<<turn<<": "<<last<<" :: "<<a<<" "<<b<<" "<<c<<" "<<d<<"-> ";
			if(turn==0)
			{
				if(a>0)
				{
					if(last!=-1 && last!=1)
						break;

					last = 0;
					--a;
				}
				else if(c>0)
				{

					if(last!=-1 && last!=1 && last!=3)
						break;

					last = 2;
					--c;
				}
				else 
					break;

				turn = 1;
			}
			else
			{
				if(b>0)
				{
					if(last!=-1 && last!=0 && last!=2)
						break;

					last = 1;
					--b;
				}
				else if(d>0)
				{
					if(last!=-1 && last!=2)
						break;

					last = 3;
					--d;
				}
				else 
					break;

				turn = 0;
			} 

			cout<<last<<" ";
		}


		return;
}


int main()
{
	ll a,b,c,d,i;
	s(a); s(b); s(c); s(d);

	for(i=0;i<=1;i++)
	if(play(i,a,b,c,d))
	{
		cout<<"YES\n";
		print_play(i,a,b,c,d);
		cout<<"\n";
		return 0;
	}

	cout<<"NO\n";
	return 0;
}