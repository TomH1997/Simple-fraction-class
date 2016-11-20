#include "fraction.h"
#include <iostream>
#include <algorithm>

int fraction::gcd(int a, int b){
	int m = std::min(a,b);
	while(m){
		if(a%m==0&&b%m==0)
			return m;
		m--;
	}
}

int fraction::lcm(int a, int b){
	int m = std::max(a,b);
	while(m){
		if(m%a==0&&m%b==0)
			return m;
		m++;
	}
}

void fraction::print(){
	std::cout<<"The fraction is "<<numerator<<"/"<<denominator<<std::endl;
}

fraction::fraction(){
	numerator = 1;
	denominator = 1;
}

fraction::fraction(int m, int n){
	if(n==0){
		std::cout<<"Denominator cannot be 0. Set to default.\n";
		numerator = 1;
		denominator = 1;
	}
	else{
		int a = gcd(m,n);
		numerator = m/a;
		denominator = n/a;
	}
}

bool fraction::operator ==(fraction & frac) {
	return(frac.numerator==this->numerator&&frac.denominator==this->denominator);
}
bool fraction::operator <(fraction & frac){
	int m = lcm(frac.denominator,this->denominator);
	return(frac.numerator*m/frac.denominator>this->numerator*m/this->denominator);
}
bool fraction::operator >(fraction & frac){
	int m = lcm(frac.denominator,this->denominator);
	return(frac.numerator*m/frac.denominator<this->numerator*m/this->denominator);
}
bool fraction::operator <=(fraction & frac){
	return(*this<frac||*this==frac);
}
bool fraction::operator >=(fraction & frac){
	return(*this>frac||*this==frac);
}

bool fraction::operator ==(double a) {
	return(this->numerator==a*this->denominator);
}
bool fraction::operator <(double a){
	return(this->numerator<a*this->denominator);
}
bool fraction::operator >(double a){
	return(this->numerator>a*this->denominator);
}
bool fraction::operator <=(double a){
	return(this->numerator<=a*this->denominator);
}
bool fraction::operator >=(double a){
	return(this->numerator>=a*this->denominator);
}

fraction fraction::operator+(fraction & frac){
	int m = frac.denominator*this->numerator+frac.numerator*this->denominator;
	int n = frac.denominator*this->denominator;
	if(m==0)	n=1;
	return fraction(m,n);
}
fraction fraction::operator-(fraction & frac){
	int m = frac.denominator*this->numerator-frac.numerator*this->denominator;
	int n = frac.denominator*this->denominator;
	if(m==0)	n=1;
	return fraction(m,n);
}
fraction fraction::operator*(fraction & frac){
	int m = frac.numerator*this->numerator;
	int n = frac.denominator*this->denominator;
	if(m==0)	n=1;
	return fraction(m,n);
}
fraction fraction::operator/(fraction & frac){
	if(frac.numerator==0){
		std::cout<<"Cannot be divided by 0, set to original fraction.\n";
		return *this;
	}
	else{
		int m = this->numerator*frac.denominator;
		int n = this->denominator*frac.numerator;
		return fraction(m,n);
	}
}

fraction fraction::operator+(int a){
	return fraction(numerator+a*denominator,denominator);
}
fraction fraction::operator-(int a){
	return fraction(numerator-a*denominator,denominator);
}
fraction fraction::operator*(int a){
	return fraction(numerator*a,denominator);
}
fraction fraction::operator/(int a){
	if(a==0){
		std::cout<<"Cannot be divided by 0, set to original fraction.\n";
		return *this;
	}
	else{
		return fraction(numerator,denominator*a);
	}
}

void fraction::operator+=(fraction & frac){
	int m = frac.denominator*this->numerator+frac.numerator*this->denominator;
	int n = frac.denominator*this->denominator;
	if(m==0)	this->denominator=1;
	else{
		this->numerator = m/gcd(m,n);
		this->denominator = n/gcd(m,n);
	}
}
void fraction::operator-=(fraction & frac){
	int m = frac.denominator*this->numerator-frac.numerator*this->denominator;
	int n = frac.denominator*this->denominator;
	if(m==0)	this->denominator=1;
	else{
		this->numerator = m/gcd(m,n);
		this->denominator = n/gcd(m,n);
	}
}
void fraction::operator*=(fraction & frac){
	int m = frac.numerator*this->numerator;
	int n = frac.denominator*this->denominator;
	if(m==0)	this->denominator=1;
	else{
		this->numerator = m/gcd(m,n);
		this->denominator = n/gcd(m,n);
	}
}
void fraction::operator/=(fraction & frac){
	if(frac.numerator==0)	std::cout<<"Cannot be divided by 0, set to original fraction.\n";
	else{
		int m = this->numerator*frac.denominator;
		int n = this->denominator*frac.numerator;
		this->numerator = m/gcd(m,n);
		this->denominator = n/gcd(m,n);
	}
}
void fraction::operator+=(int a){
	this->numerator += a*this->denominator;
	if(this->numerator==0)	this->denominator=1;
	else{
		this->numerator /= gcd(this->numerator,this->denominator);
		this->denominator /= gcd(this->numerator,this->denominator);
	}
}
void fraction::operator-=(int a){
	this->numerator -= a*this->denominator;
	if(this->numerator==0)	this->denominator=1;
	else{
		this->numerator /= gcd(this->numerator,this->denominator);
		this->denominator /= gcd(this->numerator,this->denominator);
	}
}
void fraction::operator*=(int a){
	this->numerator *= a;
	if(this->numerator==0)	this->denominator=1;
	else{
		this->numerator /= gcd(this->numerator,this->denominator);
		this->denominator /= gcd(this->numerator,this->denominator);
	}
}
void fraction::operator/=(int a){
	if(a==0){
		std::cout<<"Cannot divided by zero. Back to the original value."<<std::endl;
	}
	else{
		this->denominator *= a;
		this->numerator /= gcd(this->numerator,this->denominator);
		this->denominator /= gcd(this->numerator,this->denominator);
	}
}
