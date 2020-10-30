#include "FileImpl.h"
#include <stdio.h>

using namespace std;

FileImpl::FileImpl(const char* fileName, bool readOnly = 1)
{
	FileImpl::fileName = fileName;
	FileImpl::readOnly = readOnly;
}

FileImpl::~FileImpl()
{
	close();
}

void FileImpl::read()
{
	FILE* fp;
	char c;
	fp = fopen(fileName, "rb");

	if (fp == NULL) 
	{
		exceptionFileException.printException(exception::errorCode::FileException);
	}
	else
	{
		for (c = getc(fp); c != EOF; c = getc(fp))
		{
			printf("%c", c);
		}
	}
	fclose(fp);	
}

void FileImpl::write()
{
	if (!readOnly)
	{
		IOException.printException(exception::errorCode::IOException);
		cout << "Mode read only" << endl;
	}
	else
	{
		FILE *fPtr;
		char filePath[100];
		const int BUFFER_SIZE = 100;
		char dataToAppend[BUFFER_SIZE];

		fPtr = fopen(fileName, "ab");

		if (fPtr == NULL)
		{
			exceptionFileException.printException(exception::errorCode::FileException);
		}
		else
		{
			cout << "Enter date to append" << endl;
			fflush(stdin);
			if (fgets(dataToAppend, BUFFER_SIZE, stdin) == NULL)
				IOException.printException(exception::errorCode::IOException);
			fputs(dataToAppend, fPtr);
		}
	}
}

unsigned long FileImpl::sizeOf()
{
	FILE* fp;
	int count = 0;
	char filename[50];
	char c;
	fp = fopen(fileName, "r");

	if (fp == NULL) 
	{
		exceptionFileException.printException(exception::errorCode::FileException);
		return 0;
	}

	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		count = count + 1;
	}

	fclose(fp);

	cout << "The file has " << count << " characters " << endl;

	return count;
}

void FileImpl::close()
{
	if (filePointer != NULL)
		filePointer = NULL;
	cout << "File closed" << endl;
	
}

void FileImpl::setFilePointer(unsigned long* filePointer)
{
	//Todo Implementation	
}
