#ifndef FRACTION_H_
#define FRACTION_H_

class fraction{
	private:
		int numerator;
		int denominator;
		int gcd(int a, int b);
		int lcm(int a, int b);
	public:
		bool operator ==(fraction & frac);
		bool operator >(fraction & frac);
		bool operator <(fraction & frac);
		bool operator >=(fraction & frac);
		bool operator <=(fraction & frac);
		bool operator ==(double a);
		bool operator >(double a);
		bool operator <(double a);
		bool operator >=(double a);
		bool operator <=(double a);
		fraction operator+(fraction & frac);
		fraction operator-(fraction & frac);
		fraction operator*(fraction & frac);
		fraction operator/(fraction & frac);
		fraction operator+(int a);
		fraction operator-(int a);
		fraction operator*(int a);
		fraction operator/(int a);
		void operator+=(fraction & frac);
		void operator-=(fraction & frac);
		void operator*=(fraction & frac);
		void operator/=(fraction & frac);
		void operator+=(int a);
		void operator-=(int a);
		void operator*=(int a);
		void operator/=(int a);
		void print();
		fraction();
		fraction(int num, int den);
};
#endif
