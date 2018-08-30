#include <iostream>
#include "./MS_files/1/Sales_item.h"

using namespace std;


int main()  
{
	typedef char *pstring;
	char x = 'm';
	pstring a = &x;
	const pstring b = &x;


	cout << x << " "<< *a << " " << *b << endl;

	return 0;
}
