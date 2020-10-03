

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

int main()
{
	ll t,g=1;
	s(t);

	while(t--)
	{
		ll n,i,x,y,a,b;
		s(n);

		string str[n];

		for(i=0;i<n;i++)
			cin>>str[i];

		ll ans1 = -1,ans11=0;

		for(i=0;i<n;i++)
		{
			x = i; y = i;

			a = b = 0;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				--x;
				++y;
			}

			x = i+1, y = i-1;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				++x;
				--y;
			}

			if(b>0)
				ans1 = max(ans1, a),++ans11;
		}

		ll ans2 = -1,ans22=0;

		for(i=1;i<n;i++)
		{
			x = i; y = i-1;

			a = b = 0;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				--x;
				++y;
			}

			x = i+1, y = i-2;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				++x;
				--y;
			}

			if(b>0)
				ans2 = max(ans2, a),++ans22;
		}

		ll ans3 = -1,ans33=0;

		for(i=0;i<n;i++)
		{
			x = n-1-i; y = i;

			a = b = 0;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				--x;
				--y;
			}

			x = n-1-i + 1, y = i+1;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				++x;
				++y;
			}

			if(b>0)
				ans3 = max(ans3, a),++ans33;
		}

		ll ans4 = -1,ans44=0;

		for(i=0;i<n;i++)
		{
			x = n-1-i; y = i+1;

			a = b = 0;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				--x;
				--y;
			}

			x = n-1-i + 1, y = i+1 + 1;

			while(x>=0 && x<n && y>=0 && y<n)
			{
				if(str[x][y]=='#')
					++a;
				else
					++b;

				++x;
				++y;
			}

			if(b>0)
				ans4 = max(ans4, a),++ans44;
		}

		ll ans = 0;

		// cout<<ans1<<" "<<ans11<<"\n";
		// cout<<ans2<<" "<<ans22<<"\n";
		// cout<<ans3<<" "<<ans33<<"\n";
		// cout<<ans4<<" "<<ans44<<"\n";

		if(ans1!=-1 && ans3!=-1)
			ans+=min(ans1 + ans11,ans3 + ans33);

		if(ans2!=-1 && ans4!=-1)
			ans+=min(ans2 + ans22,ans4 + ans44);

		cout<<"Case #"<<g<<": "<<ans<<"\n";
		++g;
	}
	return 0;
}