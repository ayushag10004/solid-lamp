

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

struct qry
{
	ll code;
	ll eat;
	ll in;
	bool ans;

	qry()
	{
		ans = false;
	}
};

struct slot
{
	ll code;
	ll eat;
};

bool comp1(struct slot lhs, struct slot rhs)
{
	return (double)lhs.eat/lhs.code>=(double)rhs.eat/rhs.code;		
}

bool comp2(struct qry lhs, struct qry rhs)
{
	return lhs.eat<rhs.eat;
}

bool comp3(struct qry lhs, struct qry rhs)
{
	return lhs.in<rhs.in;
}

ll tt()
{
	time_t current_time;
	current_time = time(NULL);
	cout<<current_time<<"------------------\n";
}

struct slot st[100005];

struct qry qq[100005];

int main()
{
	ll initial_time = tt();
	ll t=100,g=1;
	// s(t);

	while(t--)
	{	
		// tt();
		ll d,s,i,cc=0,ee=0;
		// s(d); s(s);
		d = s = 100000;

		for(i=0;i<s;i++)
			{	
				st[i].code = rand()%10000 + 1;
				st[i].eat = rand()%10000 + 1;
				// s(st[i].code), s(st[i].eat);
				cc+=st[i].code;
			}

		sort(st,st+s,comp1);

		for(i=0;i<d;i++)
		{		
			qq[i].code = rand()%10000 + 1;
			qq[i].code = rand()%10000 + 1;
			// s(qq[i].code);
			// s(qq[i].eat);
			qq[i].in = i;
		}

		sort(qq,qq+d,comp2);

		ll qin = 0,diff;
		double frac,max_code;

		for(i=0;i<s;i++)
		{
			frac = (double)st[i].code/st[i].eat;

			while(qin<d && qq[qin].eat<=ee+st[i].eat)
			{
				diff = qq[qin].eat-ee;
				max_code = (double)cc - (double)frac*diff;

				if((double)qq[qin].code<=(double)max_code)
					qq[qin].ans = true;

				++qin;
			}

			cc-=st[i].code;
			ee+=st[i].eat;
		}

		sort(qq,qq+d,comp3);

		string fin;

		for(i=0;i<d;i++)
		if(qq[i].ans)
			fin+='Y';
		else
			fin+='N';

		// cout<<"Case #"<<g<<": "<<fin<<"\n";
		// ++g;
	}

	cout<< tt() - initial_time<<"\n";

	return 0;
}