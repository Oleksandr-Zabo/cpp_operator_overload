#include "fraction.h"

//constructors

Fraction::Fraction() {
	num = new int{0};
	den = new int{1};
	Logger::debug(_get_object_as_string() + " created default");
}
Fraction::Fraction(int num) : Fraction::Fraction() {
	*this->num = num;
}
Fraction::Fraction(int num, int den): Fraction::Fraction(num) {
	*this->den = den;
	Logger::debug(_get_object_as_string() + " created with param");
}

Fraction::Fraction(int* num) : Fraction::Fraction() {
	this->num = num;
}
Fraction::Fraction(int* num, int* den): Fraction::Fraction(*num) {
	this->den = den;
	Logger::debug(_get_object_as_string() + " created with param");
}

//copy constructor
Fraction::Fraction(const Fraction& f) {
	num = new int{ *f.num };
	den = new int{ *f.den };
	Logger::debug(_get_object_as_string() + " created with copy");
}

//destructor
Fraction::~Fraction() {
	Logger::error("Destructor called");
	delete num;
	delete den;
}

//for logger
string Fraction::_get_object_as_string() const
{
	stringstream ss;
	ss << "Fraction object <" << (void**)this << ">";
	return ss.str();
}

//setters

inline void Fraction::setNum(int num) {
	this->num = new int{num};
	Logger::warning(_get_object_as_string() + " has changed num");
}
inline void Fraction::setDen(int den) {
	this->den = new int{ den };
	Logger::warning(_get_object_as_string() + " has changed den");
}

inline void Fraction::setNum(int* num) {
	this->num = new int{ *num };
	Logger::warning(_get_object_as_string() + " has changed num");
}
inline void Fraction::setDen(int* den) {
	this->den = new int{ *den };
	Logger::warning(_get_object_as_string() + " has changed den");
}

//getters
inline int Fraction::getNum() const{
	return *num;
	Logger::info("Get num from "+_get_object_as_string());
}
inline int Fraction::getDen() const{
	return *den;
	Logger::info("Get den from " + _get_object_as_string());
}

//methods

//istream& operator>>(istream& is, Fraction& f) {
//	int num, den;
//	cout << "Enter numerator: ";
//	is >> num;
//	cout << "Enter denominator: ";
//	is >> den;
//	f.setNum(num);
//	f.setDen(den);
//	return is;
//}


ostream& operator<<(ostream& os, const Fraction& f) {
	Logger::info("Printing " + f._get_object_as_string());

	if ((*f.num) > (*f.den)) {//if the numerator is greater than the denominator
		int whole = (*f.num) / (*f.den);
		*f.num = (*f.num) % (*f.den);
		os << whole << " " << *f.num << "/" << *f.den << endl;
	}
	else {
		os << *f.num << "/" << *f.den << endl;
	}
	return os;
}


void Fraction::print() const{
	Logger::info("Printing " + _get_object_as_string());
	if ((*num) > (*den)) {//if the numerator is greater than the denominator
		int whole = (*num) / (*den);
		*num = (*num) % (*den);
		cout << whole << " " << *num << "/" << *den << endl;
	}
	else {
		cout << *num << "/" << *den << endl;
	}
	
	cout << endl;
}

void Fraction::print(int numerator, int denominator) const{
	Logger::info("Printing no-class fraction");
	if (numerator > denominator) {//if the numerator is greater than the denominator
		int whole = numerator / denominator;
		numerator = numerator % denominator;
		cout << whole << " " << numerator << "/" << denominator << endl;
	}
	else {
		cout << *num << "/" << *den << endl;
	}
	cout << endl;
}

void Fraction::print(int* numerator, int* denominator) const{
	Logger::info("Printing no-class fraction");
	if ((*numerator) > (*denominator)) {//if the numerator is greater than the denominator
		int whole = (*numerator) / (*denominator);
		*numerator = (*numerator) % (*denominator);
		cout << whole << " " << *numerator << "/" << *denominator << endl;
	}
	else {
		cout << *num << "/" << *den << endl;
	}
	cout << endl;
}

void Fraction::print(Fraction f) const{
	Logger::info("Printing " + _get_object_as_string());
	if ((*f.num) > (*f.den)) {//if the numerator is greater than the denominator
		int whole = (*f.num) / (*f.den);
		*f.num = (*f.num) % (*f.den);
		cout << whole << " " << *f.num << "/" << *f.den << endl;
	}
	else {
		cout << *f.num << "/" << *f.den << endl;
	}
	cout << endl;
}



Fraction Fraction::add(Fraction f) {
	Logger::info("Ading " + _get_object_as_string() + " and " + f._get_object_as_string());
	Fraction result;
	*result.num = (*num) * (*f.den) + (*f.num) * (*den);
	*result.den = (*den) * (*f.den);
	return result;
}

void Fraction::print_add(Fraction f) {

	Fraction result = Fraction::add(f);
	cout << "Addition: ";
	cout << "(" << *num << "/" << *den << ") + (" << f << ") = ";
	cout << result;//from overload operator<<
}

Fraction Fraction::operator+(Fraction f) {
	Fraction result = Fraction::add(f);
	return result;
}

Fraction Fraction::sub(Fraction f) {
	Logger::info("Subtraction " + _get_object_as_string() + " and " + f._get_object_as_string());
	Fraction result;
	*result.num = (*num) * (*f.den) - (*f.num) * (*den);
	*result.den = (*den) * (*f.den);
	return result;
}

void Fraction::print_sub(Fraction f) {
	Fraction result = Fraction::sub(f);
	cout << "Subtraction: ";
	cout << "(" << *num << "/" << *den << ") - (" << f << ") = ";
	print(result);
}

Fraction Fraction::operator-(Fraction f) {
	Fraction result = Fraction::sub(f);
	return result;
}

Fraction Fraction::mul(Fraction f) {
	Logger::info("Multiplication " + _get_object_as_string() + " and " + f._get_object_as_string());
	Fraction result;
	*result.num = (*num) * (*f.num);
	*result.den = (*den) * (*f.den);
	return result;
}
void Fraction::print_mul(Fraction f) {
	Fraction result = Fraction::mul(f);
	cout << "Multiplication: ";
	cout << "(" << *num << "/" << *den << ") * (" << f << ") = ";
	print(result);
}

Fraction Fraction::operator*(Fraction f) {
	Fraction result = Fraction::mul(f);
	return result;
}

Fraction Fraction::div(Fraction f) {
	Logger::info("Division " + _get_object_as_string() + " and " + f._get_object_as_string());
	Fraction result;
	*result.num = (*num) * (*f.den);
	*result.den = (*den) * (*f.num);
	return result;
}
void Fraction::print_div(Fraction f) {
	Fraction result = Fraction::div(f);
	cout << "Division: ";
	cout << "(" << *num << "/" << *den << ") / (" << f << ") = ";
	print(result);
}

Fraction Fraction::operator/(Fraction f) {
	Fraction result = Fraction::div(f);
	return result;
}

bool Fraction::operator==(Fraction f) {
	return (*num == *f.num) && (*den == *f.den);
}