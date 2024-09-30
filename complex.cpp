#include "complex.h"

//constructors

Complex::Complex() {
	real = new int{ 0 };
	imagine = new int{ 1 };
	Logger::debug(_get_object_as_string() + " created default");
}
Complex::Complex(int real) : Complex::Complex() {
	*this->real = real;
}
Complex::Complex(int real, int imagine) : Complex::Complex(real) {
	*this->imagine = imagine;
	Logger::debug(_get_object_as_string() + " created with param");
}

Complex::Complex(int* real) : Complex::Complex() {
	this->real = real;
}
Complex::Complex(int* real, int* imagine) : Complex::Complex(*real) {
	this->imagine = imagine;
	Logger::debug(_get_object_as_string() + " created with param");
}

//copy constructor
Complex::Complex(const Complex& c) {
	real = new int{ *c.real };
	imagine = new int{ *c.imagine };
	Logger::debug(_get_object_as_string() + " created with copy");
}

//destructor
Complex::~Complex() {
	Logger::error("Destructor called");
	delete real;
	delete imagine;
}

//for logger
string Complex::_get_object_as_string() const
{
	stringstream ss;
	ss << "Complex object <" << (void**)this << ">";
	return ss.str();
}

//setters

inline void Complex::setReal(int real) {
	this->real = new int{ real };
	Logger::warning(_get_object_as_string() + " has changed real");
}
inline void Complex::setImagine(int imagine) {
	this->imagine = new int{ imagine };
	Logger::warning(_get_object_as_string() + " has changed imagine");
}

inline void Complex::setReal(int* real) {
	this->real = new int{ *real };
	Logger::warning(_get_object_as_string() + " has changed real");
}
inline void Complex::setImagine(int* imagine) {
	this->imagine = new int{ *imagine };
	Logger::warning(_get_object_as_string() + " has changed imagine");
}

//getters
inline int Complex::getReal() const {
	return *real;
	Logger::info("Get real from " + _get_object_as_string());
}
inline int Complex::getImagine() const {
	return *imagine;
	Logger::info("Get imagine from " + _get_object_as_string());
}

//methods
bool Complex::not_nullptr() const {
	if (real != nullptr && imagine != nullptr) {
		return 1;
	}
	else {
		return 0;
	}
}


ostream& operator<<(ostream& os, const Complex& c) {
	Logger::info("Printing " + c._get_object_as_string());
	bool a = c.not_nullptr();
	if (a) {
		os << *c.real << "+" << *c.imagine << " i" << endl;
	}
	else {
		Logger::error("Printing incorect data from " + c._get_object_as_string());
		os << "Incorrect data" << endl;
	}
	return os;
}


void Complex::print() const {
	Logger::info("Printing " + _get_object_as_string());
	bool a = Complex::not_nullptr();
	if (a) {
		cout << *real << " + " << *imagine << " i " << endl;
	}
	else {
		Logger::error("Printing incorect data from " + _get_object_as_string());
		cout << "Incorrect data" << endl;
	}

	cout << endl;
}

void Complex::print(int real_num, int imagine_num) const {
	Logger::info("Printing no-class complex");
	cout << real_num << " + " << imagine_num << " i " << endl;
	cout << endl;
}

void Complex::print(int* real_num, int* imagine_num) const {
	Logger::info("Printing no-class complex");
	if (real_num != nullptr && imagine_num != nullptr) {
		cout << real_num << " + " << imagine_num << " i " << endl;
	}
	else {
		cout << *real << "+" << *imagine << " i" << endl;
	}
	cout << endl;
}

void Complex::print(Complex c) const {
	Logger::info("Printing " + _get_object_as_string());
	bool a = c.not_nullptr();
	if (a) {
		cout << *c.real << "+" << *c.imagine << " i" << endl;
	}
	else {
		Logger::error("Printing incorect data from " + c._get_object_as_string());
		cout << "Incorrect data" << endl;
	}
	cout << endl;
}



Complex Complex::add(Complex c) {
	Logger::info("Ading " + _get_object_as_string() + " and " + c._get_object_as_string());
	Complex result;
	*result.real = (*real) + (*c.real);
	*result.imagine = (*imagine) + (*c.imagine);
	return result;
}

void Complex::print_add(Complex c) {

	Complex result = Complex::add(c);
	cout << "Addition: ";
	cout << "(" << *real << "+" << *imagine << "i ) + (" << c << ") = ";
	cout << result;//from overload operator<<
}

Complex Complex::operator+(Complex c) {
	Complex result = Complex::add(c);
	return result;
}

Complex Complex::sub(Complex f) {
	Logger::info("Subtraction " + _get_object_as_string() + " and " + f._get_object_as_string());
	Complex result;
	*result.real = (*real) - (*f.real);
	*result.imagine = (*imagine) - (*f.imagine);
	return result;
}

void Complex::print_sub(Complex c) {
	Complex result = Complex::sub(c);
	cout << "Subtraction: ";
	cout << "(" << *real << "+" << *imagine << "i ) - (" << c << ") = ";
	print(result);
}

Complex Complex::operator-(Complex c) {
	Complex result = Complex::sub(c);
	return result;
}

Complex Complex::mul(Complex f) {
	Logger::info("Multiplication " + _get_object_as_string() + " and " + f._get_object_as_string());
	Complex result;
	*result.real = ((*real) * (*f.real)) - ((*imagine) * (*f.imagine));
	*result.imagine = (*imagine) * (*f.imagine);
	return result;
}
void Complex::print_mul(Complex f) {
	Complex result = Complex::mul(f);
	cout << "Multiplication: ";
	cout << "(" << *real << "+" << *imagine << " i) * (" << f << ") = ";
	print(result);
}

Complex Complex::operator*(Complex f) {
	Complex result = Complex::mul(f);
	return result;
}

Complex Complex::div(Complex f) {
	Logger::info("Division " + _get_object_as_string() + " and " + f._get_object_as_string());
	Complex result;
	double denominator = (*f.real) * (*f.real) + (*f.imagine) * (*f.imagine);
	*result.real = ((*real) * (*f.real) + (*imagine) * (*f.imagine)) / denominator;
	*result.imagine = ((*imagine) * (*f.real) - (*real) * (*f.imagine)) / denominator;
	return result;
}

void Complex::print_div(Complex f) {
	Complex result = Complex::div(f);
	cout << "Division: ";
	cout << "(" << *real << "+" << *imagine << " i) / (" << f << ") = ";
	print(result);
}

Complex Complex::operator/(Complex f) {
	Complex result = Complex::div(f);
	return result;
}

bool Complex::operator==(Complex f) {
	return (*real == *f.real) && (*imagine == *f.imagine);
}