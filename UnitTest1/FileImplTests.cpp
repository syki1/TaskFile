#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/FileImpl.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			/*  Klasa FileImpl powinna mieæ konstruktor
			    przyjmuj¹cy parametr ze œcie¿k¹ do pliku i parametr wskazuj¹cy
				czy plik jest otwierany tylko do odczytu. */

			const char* name = "file.txt";
			bool readOnly = false;
			FileImpl obj(name, readOnly);
			Assert::AreEqual(obj.fileName, name);
			Assert::AreEqual(obj.readOnly, readOnly);
		}
		TEST_METHOD(TestMethod2)
		{

		}
	

	};
}