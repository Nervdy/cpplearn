#include <iostream>
#include "./MS_files/1/Sales_item.h"

using namespace std;

int main()  
{
	// Sales_item curItem, val;
	// if (cin >> curItem) {
	// 	while (cin >> val) {
	// 		if (curItem.isbn() == val.isbn()) {
	// 			curItem += val;
	// 		} else {
	// 			cout << curItem << endl;
	// 			curItem = val;
	// 		}
	// 	}
	// 	cout << curItem << endl;
	// } else {
	// 	cerr << "No Data?!" << endl;
	// 	return -1;
	// }
	unsigned u = 10, u2 = 42;
	cout << u2 - u << endl; 	// 32
	cout << u - u2 << endl;		// 4294967264

	int i = 10, i2 = 42;		
	cout << i2 - i << endl;		// 32
	cout << i - i2 << endl;		// -32
	cout << i - u << endl;		// 0
	cout << u - i << endl;		// 0

	return 0;
}
