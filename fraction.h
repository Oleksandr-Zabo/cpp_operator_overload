#include "lib.h"
#include "logger.h"

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int* num;
	int* den;
	//for logger
	string _get_object_as_string() const;

public:
	//constructors
	Fraction();
	Fraction(int num);
	Fraction(int num, int den);

	Fraction(int* num);
	Fraction(int* num, int* den);

	//copy constructor
	Fraction(const Fraction& f);

	//destructor
	~Fraction();

	

	//setters

	inline void setNum(int num);
	inline void setDen(int den);
	
	inline void setNum(int* num);
	inline void setDen(int* den);

	//getters
	inline int getNum() const;
	inline int getDen() const;

	//methods
	
	void print() const;

	void print(int numerator, int denominator) const;
	void print(int* numerator, int* denominator) const;

	friend ostream& operator << (ostream& os, const Fraction& f);
	//friend - from documentation
	//The friend keyword in C++ is used to grant access 
	// to private or protected members of a class to functions 
	// or other classes that are declared as friends.


	void print(Fraction f) const;

	Fraction add(Fraction f);
	void print_add(Fraction f);
	Fraction operator+(Fraction f);//overloading operator +
	
	Fraction sub(Fraction f);
	void print_sub(Fraction f);
	Fraction operator-(Fraction f);

	Fraction mul(Fraction f);
	void print_mul(Fraction f);
	Fraction operator*(Fraction f);

	Fraction div(Fraction f);
	void print_div(Fraction f);
	Fraction operator/(Fraction f);

	bool operator==(Fraction f);
};

#endif // !FRACTION_H

