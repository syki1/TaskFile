#pragma once
#include <iostream>
using namespace std;

/*module FileDemo
{
	interface File
	{
		//...
	};

}; */

class File 
{
public:
	const char* fileName;
	unsigned long* filePointer;

protected:
	virtual void read() = 0;
	virtual void write() = 0;
	virtual unsigned long sizeOf() = 0;
	virtual void close() = 0;
	virtual void setFilePointer(unsigned long * filePointer) = 0;

	class exception
	{
	public:
		int errCode;
		char communicate[30];
		enum errorCode
		{
			IOException = 1,
			FileException = 2,
			InvalidFilePointer = 3
		};	
		exception(){};
		void File::exception::printException(int errC)
		{
			if (errCode == 1)
				strcpy(communicate, "Error code: 1, IOException");
			else if (errCode == 2)
				strcpy(communicate, "Error code: 2, FileException");
			else if (errCode == 3)
				strcpy(communicate, "Error code: 3, InvalidFilePointer");

			cout << communicate << endl;
		}
	};
};