

/* * * * * * * * * * * * * * 		
#                          *
#  @Author  AYUSH AGRAWAL  *
#                          *
# * * * * * * * * * * * * */


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define MOD 10000007
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

ll dist(ll x1,ll y1,ll x2,ll y2,ll r1,ll r2)
{
	ll mid = r2-r1;

	ll dd = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

	if(dd>mid*mid)
		return 1;

	return 0;
}

ll distance(ld x1,ld y1,ld x2,ld y2,ll r)
{
	ld dd = (ld)(x1-x2)*(x1-x2) + (ld)(y1-y2)*(y1-y2);

	if(dd>=(ld)r*r)
		return 1;
	else 
		return 0;
}

int main()
{
	ll t;
	s(t);

	cout<<fixed<<setprecision(10);

	while(t--)
	{
		ll x1,y1,r1,x2,y2,r2;
		cin>>x1>>y1>>r1>>x2>>y2>>r2;

		if(r1>r2 || dist(x1,y1,x2,y2,r1,r2))
		{
			cout<<"YES\n";

			if(x1==x2 && y1==y2)
				cout<<(double)x1+r1<<" "<<(double)y1<<"\n";
			else
			{
				if(x1==x2)
				{
					if(y1<y2)
						cout<<(double)x1<<" "<<(double)y1-r1<<"\n";
					else
						cout<<(double)x1<<" "<<(double)y1+r1<<"\n";

					continue;
				}

				ld mm = (ld)(y1-y2)/(x1-x2);
				ld cc = y1 - (ld)mm*x1;

				if(x2<x1)
				{
					ld low = x1,mid,hi = x1+MOD,yy,fx,fy;

					while(low<=hi)
					{
						mid = (low+hi)/2;

						yy = mm*mid + cc;

						if(distance((ld)x1,(ld)y1,mid,yy,r1))
						{
							fx = mid;
							fy = yy;
							hi = mid-0.000000001;
						}
						else
							low = mid+0.0000000001;
					}

					cout<<(double)fx<<" "<<(double)fy<<"\n";
				}

				if(x1<x2)
				{
					ld low = x1,mid,hi = x1-MOD,yy,fx,fy;

					while(hi<=low)
					{
						mid = (low+hi)/2;

						yy = mm*mid + cc;

						if(distance(x1,y1,mid,yy,r1))
						{
							fx = mid;
							fy = yy;
							hi = mid+0.000000001;
						}
						else
							low = mid-0.0000000001;
					}

					cout<<(double)fx<<" "<<(double)fy<<"\n";
				}


			}
			
		}
		else
			cout<<"NO\n";

	}
	return 0;
}