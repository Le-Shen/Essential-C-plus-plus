#include<iostream>
using namespace std;

int main()
{
	const int array_size = 128;
	int ia[ array_size ];
	int ival, average, icnt = 0, sum = 0;
	
	while (cin >> ival && icnt < array_size)
			ia[ icnt++ ] = ival;
	
	for ( int ix = 0; ix < icnt; ++ix )
			sum += ia[ ix ];
		
	average = sum / icnt;
	
	cout << "Sum of " << icnt << " elements: "
		 << sum <<". Average: " << average << endl;
	return 0;
}
