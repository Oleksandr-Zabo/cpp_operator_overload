#include "lib.h"
#include "logger.h"

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	int* real;
	int* imagine;
	//for logger
	string _get_object_as_string() const;

public:
	//constructors
	Complex();
	Complex(int real);
	Complex(int real, int imagine);

	Complex(int* real);
	Complex(int* real, int* imagine);

	//copy constructor
	Complex(const Complex& f);

	//destructor
	~Complex();



	//setters

	inline void setReal(int real);
	inline void setImagine(int imagine);

	inline void setReal(int* real);
	inline void setImagine(int* imagine);

	//getters
	inline int getReal() const;
	inline int getImagine() const;

	//methods

	void print() const;

	void print(int real_num, int imagine_num) const;
	void print(int* real_num, int* imagine_num) const;

	friend ostream& operator << (ostream& os, const Complex& c);
	//friend - from documentation
	//The friend keyword in C++ is used to grant access 
	// to private or protected members of a class to functions 
	// or other classes that are declared as friends.


	void print(Complex c) const;

	bool not_nullptr() const;

	Complex add(Complex c);
	void print_add(Complex c);
	Complex operator+(Complex c);//overloading operator +

	Complex sub(Complex c);
	void print_sub(Complex c);
	Complex operator-(Complex c);

	Complex mul(Complex c);
	void print_mul(Complex c);
	Complex operator*(Complex c);

	Complex div(Complex c);
	void print_div(Complex c);
	Complex operator/(Complex c);

	bool operator==(Complex c);
};

#endif // !COMPLEX_H