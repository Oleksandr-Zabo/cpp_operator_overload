#include "complex.h"

bool Logger::is_print_logs = true;



int main()
{
	Complex c1(3, 4);
	Complex c2(2, 3);

	c1.print();
	cout << c2 << endl;

	c1.print_add(c2);
	Complex result = c1 + c2;
	cout << result << endl;
	//~ result

	c2.print_sub(c1);
	Complex result1 = c1 - c2;
	cout << result1 << endl;

	c1.print_mul(c2);
	Complex result2 = c1 * c2;
	cout << result2 << endl;

	c1.print_div(c2);
	Complex result3 = c1 / c2;
	cout << result3 << endl;


	cout << "Is complex numbers egual(0-no/1-yes): " << (c1 == c2) << endl;

	cout << "Is complexs numbers egual(0-no/1-yes): " << (c1 == c1) << endl;
	system("pause");
	return 0;
}