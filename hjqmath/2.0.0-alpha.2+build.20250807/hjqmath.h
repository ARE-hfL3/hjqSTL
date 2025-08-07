//hjqstl2 hjqmath.h version:2.0.0-alpha.2+build.20250807
#ifndef _HJQ_MATH
#define _HJQ_MATH
#define _HJQ_MATH_MAJOR 2
#define _HJQ_MATH_MINOR 0
#define _HJQ_MATH_PATCH 0
#define _HJQ_MATH_FULLVERSION "2.0.0-alpha.2+build.20250807"
#define _HJQ_MATH_VERSION "2.0.0"
#ifndef _HJQ_STL2BASE
#include"stl2base.h"
#endif
#if _HJQ_STL2BASE_MAJOR<2
#error stl2base.h is too old,please update it.
#else
namespace hjq
{
	typedef long double real;
	typedef long long integer;
	const int __ITERS=32;
	const real PI=3.14159265359l;
	const real E=2.71828182846l;
	const real INF=INFINITY;
	const bool isinf(const real &x)
	{
		return x==INF;
	}
	const integer floor(const real &x)
	{
		if(x>0||x==integer(x))
			return integer(x);
		else
			return integer(x)-1;
	}
	const integer ceil(const real &x)
	{
		if(x<0||x==integer(x))
			return integer(x);
		else
			return integer(x)+1;
	}
	const integer round(const real &x)
	{
		if(x-floor(x)<0.5)
			return floor(x);
		else
			return ceil(x);
	}
	template<class T>
	const T abs(const T& x)
	{
		return (x>=0)?x:-x;
	}
	class Angle
	{
		protected:
			real rad;
		public:
			Angle(double rd=0,bool isdeg=0)
			{
				if(!isdeg)
					rad=rd;
				else
					rad=rd/180*PI;
			}
			operator real()const
			{
				return rad;
			}
			const real degree()const
			{
				return rad/PI*180;
			}
	};
	const real sin(const Angle &p)
	{
		integer deg=p.degree();
		deg=(deg%360+360)%360;
		const real sin_2k[]=
		{
			0.017452406437284,
			0.034899496702501,
			0.069756473744125,
			0.139173100960065,
			0.275637355816999,
			0.529919264233205,
			0.898794046299167,
			0.788010753606722,
			-0.970295726275996
		};
		const real cos_2k[]=
		{
			0.999847695156391,
			0.999390827019096,
			0.997564050259824,
			0.990268068741570,
			0.961261695938319,
			0.848048096156426,
			0.438371146789077,
			-0.615661475325658,
			-0.241921895599668
		};
		real sins=0,coss=1;
		for(int i=8; i>=0; i--)
			if(deg&(1<<i))
			{
				real snext,cnext;
				snext=sins*cos_2k[i]+coss*sin_2k[i];
				cnext=coss*cos_2k[i]-sins*sin_2k[i];
				sins=snext;
				coss=cnext;
			}
		return sins;
	}
	const real cos(const Angle &p)
	{
		integer deg=p.degree();
		deg=(deg%360+360)%360;
		const real sin_2k[]=
		{
			0.017452406437284,
			0.034899496702501,
			0.069756473744125,
			0.139173100960065,
			0.275637355816999,
			0.529919264233205,
			0.898794046299167,
			0.788010753606722,
			-0.970295726275996
		};
		const real cos_2k[]=
		{
			0.999847695156391,
			0.999390827019096,
			0.997564050259824,
			0.990268068741570,
			0.961261695938319,
			0.848048096156426,
			0.438371146789077,
			-0.615661475325658,
			-0.241921895599668
		};
		real sins=0,coss=1;
		for(int i=8; i>=0; i--)
			if(deg&(1<<i))
			{
				real snext,cnext;
				snext=sins*cos_2k[i]+coss*sin_2k[i];
				cnext=coss*cos_2k[i]-sins*sin_2k[i];
				sins=snext;
				coss=cnext;
			}
		return coss;
	}
	const real tan(const Angle &p)
	{
		real x=cos(p),y=sin(p);
		if(x==0)
			return INF;
		return y/x;
	}
	const real cot(const Angle &p)
	{
		real x=cos(p),y=sin(p);
		if(y==0)
			Throw(Exception("Cannot divide by 0!"));
		return x/y;
	}
	const real sec(const Angle &p)
	{
		real x=cos(p);
		if(x==0)
			Throw(Exception("Cannot divide by 0!"));
		return 1/x;
	}
	const real csc(const Angle &p)
	{
		real x=sin(p);
		if(x==0)
			Throw(Exception("Cannot divide by 0!"));
		return 1/x;
	}
	const Angle asin(const real &p)
	{
		if(p<-1||p>1)
			Throw(Exception("arcsin Range Error!"));
		const real __eps=1e-12;
		real l=-PI/2,r=PI/2;
		while(r-l>__eps)
		{
			real mid=(l+r)/2;
			if(sin(mid)<p)
				l=mid;
			else
				r=mid;
		}
		return l;
	}
	const Angle acos(const real &p)
	{
		if(p<-1||p>1)
			Throw(Exception("arccos Range Error!"));
		const real __eps=1e-12;
		real l=0,r=PI;
		while(r-l>__eps)
		{
			real mid=(l+r)/2;
			if(cos(mid)>p)
				l=mid;
			else
				r=mid;
		}
		return l;
	}
	const Angle atan(const real &p)
	{
		if(p<=-50)
			return -PI/2;
		if(p>=50)
			return PI/2;
		const real __eps=1e-12;
		real l=-50,r=50;
		while(r-l>__eps)
		{
			real mid=(l+r)/2;
			if(tan(mid)<p)
				l=mid;
			else
				r=mid;
		}
		return l;
	}
	const Angle acot(const real &p)
	{
		if(p<=-50)
			return PI;
		if(p>=50)
			return 0;
		const real __eps=1e-12;
		real l=-50,r=50;
		while(r-l>__eps)
		{
			real mid=(l+r)/2;
			if(cot(mid)>p)
				l=mid;
			else
				r=mid;
		}
		return l;
	}
	class Complex
	{
		public:
			real Real,Imaginary;
			Complex(real r=0,real i=0,bool is_Triangular_form=0)
			{
				if(!is_Triangular_form)
				{
					Real=r;
					Imaginary=i;
				}
				else
				{
					Real=r*cos(i);
					Imaginary=r*sin(i);
				}
			}
			const Complex Conjugate()const
			{
				return Complex(Real,-Imaginary);
			}
			Complex operator+(const Complex &x)const
			{
				return Complex(Real+x.Real,Imaginary+x.Imaginary);
			}
			Complex operator-(const Complex &x)const
			{
				return Complex(Real-x.Real,Imaginary-x.Imaginary);
			}
			Complex operator*(const real &p)const
			{
				return Complex(Real*p,Imaginary*p);
			}
			Complex operator*(const Complex &x)const
			{
				return Complex(Real*x.Real-Imaginary*x.Imaginary,\
				               Real*x.Imaginary+Imaginary*x.Real);
			}
			Complex operator/(const real &p)const
			{
				if(p==0)
					Throw(Exception("Cannot divide by 0!"));
				return Complex(Real/p,Imaginary/p);
			}
			Complex operator/(const Complex x)const
			{
				if(x.Real==0||x.Imaginary==0)
					Throw(Exception("Cannot divide by 0!"));
				return ((*this)*(x.Conjugate()))/(x.Real*x.Real+x.Imaginary*x.Imaginary);
			}
			const real radius()const
			{
				auto sqrt=[](const real &p)->const real
				{
					if(p==0)
						return 0;
					real x=p;
					const int __sqrt_iteration=__ITERS;
					const real __epsilon=1e-15L;
					for(int i=0; i<__sqrt_iteration; i++)
					{
						real next=(x+p/x)/2;
						if(abs(next-x)<__epsilon)
							break;
						x=next;
					}
					return x;
				};
				return sqrt(Real*Real+Imaginary*Imaginary);
			}
			operator real()
			{
				return radius();
			}
			const Angle theta()const
			{
				Angle a=atan(Imaginary/Real);
				return a;
			}
	};
	const Complex Unit_imaginary_number=Complex(0,1);
	const real abs(const Complex& x)
	{
		return x.radius();
	}
	const Complex Square_root(const Complex &x)
	{
		auto sqrt=[](const real &p)->const real
		{
			if(p==0)
				return 0;
			real x=p;
			const int __sqrt_iteration=__ITERS;
			const real __epsilon=1e-15L;
			for(int i=0; i<__sqrt_iteration; i++)
			{
				real next=(x+p/x)/2;
				if(abs(next-x)<__epsilon)
					break;
				x=next;
			}
			return x;
		};
		real r=sqrt(x.radius());
		Angle t=x.theta()/2;
		return Complex(r,t,1);
	}
	const real pow(const real &aa,const real &pp)
	{
		auto sqrt=[](const real &p)->const real
		{
			if(p==0)
				return 0;
			real x=p;
			const int __sqrt_iteration=__ITERS;
			const real __epsilon=1e-15L;
			for(int i=0; i<__sqrt_iteration; i++)
			{
				real next=(x+p/x)/2;
				if(abs(next-x)<__epsilon)
					break;
				x=next;
			}
			return x;
		};
		bool isrev=(pp<0);
		real p=abs(pp);
		integer x=floor(p);
		p-=x;
		real a=aa,res1=1;
		while(x)
		{
			if(x&1)
				res1*=a;
			a*=a;
			x>>=1;
		}
		a=aa;
		real res2=1;
		const int __power_iteration=__ITERS;
		for(int i=0; i<__power_iteration; i++)
		{
			if(p>=1)
			{
				res2*=a;
				p-=1;
			}
			a=sqrt(a);
			p*=2;
		}
		if(isrev)
			return 1/res1/res2;
		else
			return res1*res2;
	}
	const Complex pow(const Complex &aa,const real &pp)
	{
		bool isrev=(pp<0);
		real p=abs(pp);
		integer x=floor(p);
		p-=x;
		Complex a=aa,res1=1;
		while(x)
		{
			if(x&1)
				res1=res1*a;
			a=a*a;
			x>>=1;
		}
		a=aa;
		Complex res2=1;
		const int __power_iteration=__ITERS;
		for(int i=0; i<__power_iteration; i++)
		{
			if(p>=1)
			{
				res2=res2*a;
				p-=1;
			}
			a=Square_root(a);
			p*=2;
		}
		if(isrev)
			return 1/(res1*res2);
		else
			return res1*res2;
	}
	const real ln(const real &a)
	{
		if(a<=0)
			Throw(Exception("The parameter should be greater than 0!"));
		if(a==1)
			return 0;
		double y=(a-1)/(a+1);
		const int __ln_iteration=__ITERS;
		const real __epsilon=1e-15L;
		for(int i=0; i<__ln_iteration; i++)
		{
			double expy=pow(E,y),yn=y-1+a/expy;
			if(abs(yn-y)<__epsilon)
				return yn;
			y=yn;
		}
		return y;
	}
	const Complex ln(const Complex &a)
	{
		return Complex(ln(a.radius()),a.theta());
	}
	const real log(const real &base,const real &a)
	{
		return ln(a)/ln(base);
	}
	const Complex log(const Complex &base,const Complex &a)
	{
		return ln(a)/ln(base);
	}
	const real sinh(const real &p)
	{
		return (pow(E,p)-pow(E,-p))/2;
	}
	const real cosh(const real &p)
	{
		return (pow(E,p)+pow(E,-p))/2;
	}
	const real tanh(const real &p)
	{
		int x=sinh(p),y=cosh(p);
		if(y==0)
			return INF;
		return x/y;
	}
}
#endif
#endif
