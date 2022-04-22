#include <iostream>
#include <assert.h>
#include "Rational.h"
using namespace std;

bool assert_equals(int a, int b);

void test_constructors();

void test_additions();
void test_subtractions();
void test_multiplications();
void test_divisions();

void test_increment();
void test_decrement();

void test_assignment();
void test_comparison();


int main() {
	// Rational x(1,3);
	// x.print_fraction();
	// cout << x.to_double() << endl;

	// Rational y(2,3);
	// y.print_fraction();
	// cout << y.to_double() << endl;

	// (x + y).print_fraction();

	// (Rational(7,10) - Rational(2,5)).print_fraction();
	// (Rational(9,10) * Rational(7,5)).print_fraction();
	// (Rational(13,21) / Rational(16,33)).print_fraction();

	// (Rational(3,4) + 1 + Rational(2,5) * 2).print_fraction();
	// (Rational(16/12) / 2 + Rational(1235, 982183)).print_fraction();
	// cout << (Rational(1, 4) < Rational(1, 3)) << endl;

	// x += y;
	// x.print_fraction();
	// x += 1;
	// x.print_fraction();

	// x = y;

	// x.print_fraction();
	// cout << x.to_double() << endl;
	// cout << (x == y) << endl;
	// x += 1;
	// cout << (x <= y) << endl;
	// cout << (x >= y) << endl;


	// Systematic testing of all features
	test_constructors();

	test_additions();
	test_subtractions();
	test_multiplications();
	// test_divisions();

	// test_increment();
	// test_decrement();

	// test_assignment();
	// test_comparison();
}

bool assert_equals(int a, int b) {
	cout << "Testing if " << a << " == " << " b: " << ((a == b) ? "True" : "False") << endl;
	return (a == b);
}

void test_constructors() {
	cout << "Testing regular constructors" << endl;
	Rational x(1,2);
	Rational y(2,3);

	assert(x.getNumerator() == 1);
	assert(x.getDenominator() == 2);
	assert(y.getNumerator() == 2);
	assert(y.getDenominator() == 3);

	cout << "Testing with double operators" << endl;
	Rational a(1.5,2.5);
	Rational b(2.5,3.5);

	assert(a.getNumerator() == 1); 
	assert(a.getDenominator() == 2);
	assert(b.getNumerator() == 2);
	assert(b.getDenominator() == 3);

	cout << "Testing single int constructor" << endl;
	Rational c(5);
	Rational d(198283019);

	assert(c.getDenominator() == 1);
	assert(d.getNumerator() == 198283019);

	cout << "Testing whole number constructors" << endl;
	Rational e(6, 2);
	assert(e.getNumerator() == 3);
	assert(e.getDenominator() == 1);
	cout << "All constructor tests successful!" << endl;
}

void test_additions() {
	cout << "Testing addition operators" << endl;

	Rational x(1,2);
	Rational y(2,3);
	Rational z = x + y;
	assert(z.getNumerator() == 7);
	assert(z.getDenominator() == 6);

	cout << "Testing large numbers" <<endl;
	Rational a(15, 37);
	Rational b(36, 3);
	Rational c = a + b;
	assert(c.getDenominator() == 37);
	assert(c.getNumerator() == 459);

	cout << "Testing integer addition" << endl;

	Rational i(15,2);
	Rational j(15);

	assert((i + 1).getNumerator() == 17);
	assert((i + 1).getDenominator() == 2);
	assert((i + 1).getDenominator() == i.getDenominator());

	assert((i + j).getNumerator() == (i + 15).getNumerator());
	assert((i + j).getDenominator() == (i + 15).getDenominator());
	cout << "Addition tests succesful!" << endl;
}

void test_subtractions() {
	cout << "Testing subtraction operators" << endl;

	Rational x(1,2);
	Rational y(2,3);
	Rational z = x - y;

	assert(z.getNumerator() == -1);
	assert(z.getDenominator() == 6);

	cout << "Testing large numbers" <<endl;
	Rational a(15, 37);
	Rational b(36, 3);
	Rational c = a - b;
	assert(c.getDenominator() == 37);
	assert(c.getNumerator() == -429);

	cout << "Testing integer subtraction" << endl;

	Rational i(15,2);
	Rational j(15);

	assert((i - 1).getNumerator() == 13);
	assert((i - 1).getDenominator() == 2);
	assert((i - 1).getDenominator() == i.getDenominator());

	assert((i - j).getNumerator() == (i - 15).getNumerator());
	assert((i - j).getDenominator() == (i - 15).getDenominator());
	cout << "subtraction tests succesful!" << endl;
}

void test_multiplications() {
	cout << "Testing Multiplications" << endl;
	assert((Rational(3,4) * Rational(4,5)).getNumerator() == 3);
	assert((Rational(3,4) * Rational(4,5)).getDenominator() == 5);

	assert((Rational(1,4) * 4).getDenominator() == 1);
	assert((Rational(1,4) * 4).getNumerator() == 1);
	assert((Rational(2,4) * 4).getNumerator() == 2);
	assert((Rational(2,4) * 4).getDenominator() == 1);

	cout << "Multiplication testing complete" << endl;
}







