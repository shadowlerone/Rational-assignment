#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Rational
{
	public:
		int gcd (int a, int b) {
			if (b == 0) {
				return a;
			} else {
				return gcd(b, a % b); 
			}
		}
		int lcm (int a, int b) {
			return abs(a * b)/gcd(a, b);
		}
		// Constructors
		Rational(int n, int d) {
			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
			if (denominator < 0) {
				denominator *= -1;
				numerator *= -1;
			}

		}
		Rational(int n) {
			numerator = n;
			denominator = 1;
		}

		// Getters
		int getNumerator() {
			return numerator;
		}
		int getDenominator() {
			return denominator;
		}

		// Addition operators
		Rational operator+(const Rational& r) {
			int n = numerator * r.denominator + denominator * r.numerator;
			int d = denominator * r.denominator;
			return Rational(n, d);
		}
		Rational operator+(const int i) {
			int n = numerator + i*denominator;
			int d = denominator;
			return Rational(n, d);
		}

		// subtraction operators
		Rational operator-(const Rational& r) {
			int n = numerator * r.denominator - denominator * r.numerator;
			int d = denominator * r.denominator;
			return Rational(n, d);
		}
		Rational operator-(const int i) {
			int n = numerator - i * denominator;
			int d = denominator;
			return Rational(n, d);
		}

		// Multiplication operator
		Rational operator*(const Rational& r) {
			int n = numerator * r.numerator;
			int d = denominator * r.denominator;
			return Rational(n, d);
		}
		Rational operator*(const int i) {
			int n = numerator * i;
			int d = denominator;
			return Rational(n, d);
		}

		// Division operator
		Rational operator/(const Rational& r) {
			int n = numerator * r.denominator;
			int d = denominator * r.numerator;
			return Rational(n, d);
		}
		Rational operator/(const int i) {
			int n = numerator;
			int d = denominator * i;
			return Rational(n, d);
		}

		// Increment/decrement operators
		Rational& operator++() {
			numerator += denominator;
			return *this;
		}
		Rational& operator--() {
			numerator -= denominator;
			return *this;
		}

		// Assignment operators
		void operator= (const Rational& r) {
			numerator = r.numerator;
			denominator = r.denominator;
		}

		void operator= (const int i) {
			numerator = i;
			denominator = 1;
		}

		void operator+=(const Rational& r) {
			int n = numerator * r.denominator + denominator * r.numerator;
			int d = denominator * r.denominator;

			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		void operator-=(const Rational& r) {
			int n = numerator * r.denominator - denominator * r.numerator;
			int d = denominator * r.denominator;

			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		void operator+=(const int i) {
			int n = numerator + denominator * i;
			int d = denominator;

			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		void operator-=(const int i) {
			int n = numerator - denominator * i;
			int d = denominator;

			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}


		void operator*= (const Rational& r) {
			int n = numerator * r.numerator;
			int d = denominator * r.denominator;
			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		void operator*= (const int i) {
			int n = numerator * i;
			int d = denominator;
			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		void operator/= (const Rational& r) {
			int n = numerator * r.denominator;
			int d = denominator * r.numerator;
			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		void operator/= (const int i) {
			int n = numerator;
			int d = denominator* i ;
			numerator = n/gcd(n, d);
			denominator = d/gcd(n, d);
		}

		// comparison operators
		bool operator< (const Rational& r) {
			return to_double() < (r.to_double());
		}
		bool operator< (const int i) {
			return to_double() < i;
		}
		bool operator< (const double i) {
			return to_double() < i;
		}
		bool operator> (const Rational& r) {
			return to_double() > (r.to_double());
		}
		bool operator> (const int i) {
			return to_double() > i;
		}
		bool operator> (const double i) {
			return to_double() > i;
		}

		bool operator<= (const Rational& r) {
			return to_double() <= (r.to_double());
		}
		bool operator<= (const int i) {
			return to_double() <= i;
		}
		bool operator<= (const double i) {
			return to_double() <= i;
		}
		bool operator>= (const Rational& r) {
			return to_double() >= (r.to_double());
		}
		bool operator>= (const int i) {
			return to_double() >= i;
		}
		bool operator>= (const double i) {
			return to_double() >= i;
		}

		bool operator== (const Rational& r) {
			return (numerator == r.numerator && denominator == r.denominator);
		}
		bool operator== (const int i) {
			return (to_double() == i);
		}
		bool operator== (const double i) {
			return (to_double() == i);
		}


		void print_fraction() {
			cout << numerator << "/" << denominator << endl;
		}


		double to_double() const{
			double d = static_cast<double>(numerator)/static_cast<double>(denominator);
			return d;
		}
		
	private:
		int numerator;
		int denominator;
};

