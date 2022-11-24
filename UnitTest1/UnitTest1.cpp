
#include "CppUnitTest.h"
#include "../Katy1/GetList.h"
#include "../Katy1/GetList.cpp"
#include "..\Katy1\Book.h"
#include "..\Katy1\Book.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private:
		const std::string testAuthor = "A";

		const std::string testpublisher = "C";

		const int testYear = 33;

		int endSize = 0;

		Book testList[3]
		{
			Book("A","U","C",55,5),
			Book("w","w","w",1,5),
			Book("e","w","w",7,5)
		};

		Book test1TrueList[1]
		{
			Book("A","U","C",55,5),
		};

		Book test2TrueList[1]
		{
			Book("A","U","C",55,5)
		};

		Book test3TrueList[1]
		{
			Book("A","U","C",55,5)
		};

	public:
		bool listComparison(Book* list1, Book* list2, int tempSize)
		{
			for (int i = 0; i < tempSize; i++)
				if (list1[i] != list2[i])
					return false;
			return true;
		}
		TEST_METHOD(TestMethod1)
		{
			Book* endTestList = GetListofBooksByGivenAuthor(testList, 3, testAuthor, endSize);
			Assert::IsTrue(listComparison(endTestList, test1TrueList, endSize));
		}
		TEST_METHOD(TestMethod2)
		{
			Book* endTestList = GetListOfBooksPublisherByGivenPublisher(testList, 3, testpublisher, endSize);
			Assert::IsTrue(listComparison(endTestList, test2TrueList, endSize));
		}
		TEST_METHOD(TestMethod3)
		{
			Book* endTestList = GetListOfBooksPublisherAfterGivenYear(testList, 3, testYear, endSize);
			Assert::IsTrue(listComparison(endTestList, test3TrueList, endSize));
		}
	};
}
