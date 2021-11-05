#include "handle.h"
#include "controller.h"

int main(int argc, char* argv[]) {

	if (argc != 2 || !contain(".csv", argv[1])) {
		cout << "Wrong compiling method!!!\n" << "Please compile as follow: assignment1_group10.exe <filename>.csv" << endl;
	}
	
	int length;
	myArray col1, col2;
	// read csvFile then store the value into the vector
	read_csvFile(argv[1], col1, col2);
	col1.shrinksize(), col2.shrinksize();
	quickSort(col1.getArray(), 0, col1.getSize());
	quickSort(col2.getArray(), 0, col2.getSize());
	col1.print();
	/*cout << "X_mode is : " << find_mode_new(col1.getArray(), col1.getSize()) << endl;
	cout << "Y_mode is : " << find_mode_new(col2.getArray(), col2.getSize()) << endl;;*/
	return 0;
}