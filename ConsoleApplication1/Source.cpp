#include "FileImpl.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2)
		cout << "Too few arguments" << endl;

	cout << "argc = " << argc << endl;
	for (int i = 1; i < argc; i++)
	{
		cout << "argv["<<i<<"] = " << argv[i] << endl;
	}

	FileImpl file(argv[1], argv[2]);
	
	int choice;
	cout << "file name=" << file.fileName << endl;
	cout << "file read only=" << file.readOnly << endl << endl;
	cout << "------------ Main Menu --------------" << endl << endl;
	do{
		cout << "Please make your selection " << endl;
		cout << "1 - Read file " << endl;
		cout << "2 - Write file " << endl;
		cout << "3 - Sizeof file " << endl;
		cout << "4 - Close program " << endl;
		cout << "Selection: " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Read file" << endl;
			file.read();
			break;
		case 2:
			cout << "Write to file" << endl;
			file.write();
			break;
		case 3:
			file.sizeOf();
			break;
		case 4:
			cout << "Closing program" << endl;
			file.~FileImpl();
			break;
		default:
			cout << "Main Menu " << endl;
			cout << "Please make your selection " << endl;
			cout << "1 - Read file " << endl;
			cout << "2 - Write file " << endl;
			cout << "3 - Sizeof file " << endl;
			cout << "4 - Close program " << endl;
			cout << "Selection: " << endl;
			cin >> choice;
		}
	} while (choice != 4);
	return EXIT_SUCCESS;
	
}