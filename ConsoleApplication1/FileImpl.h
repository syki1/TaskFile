#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"

using namespace std;

class FileImpl : public File
{
public:
	bool readOnly;
	FileImpl(const char *fileName, bool readOnly);
	~FileImpl();
	void close();
	void read(/* length*/ );
	void write();
	unsigned long sizeOf();
private:
	void setFilePointer(unsigned long * filePointer);
	exception IOException, exceptionFileException, InvalidFilePointer;
};

