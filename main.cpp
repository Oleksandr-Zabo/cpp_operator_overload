#include "fraction.h"

bool Logger::is_print_logs = true;

int main()
{
	Fraction f1(3, 4);
	Fraction f2(2, 3);
	f1.print();
	cout << f2 << endl;

	f1.print_add(f2);
	Fraction result = f1 + f2;
	cout << result << endl;
	//~ result

	f2.print_sub(f1);
	Fraction result1 = f1 - f2;
	cout << result1 << endl;

	f1.print_mul(f2);
	Fraction result2 = f1 * f2;
	cout << result2 << endl;

	f1.print_div(f2);
	Fraction result3 = f1 / f2;
	cout << result3 << endl;


	cout <<"Is fractions egual(0-no/1-yes): "<< (f1 == f2) << endl;

	cout << "Is fractions egual(0-no/1-yes): " << (f1 == f1) << endl;
	system("pause");
	return 0;
}