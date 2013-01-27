#include "stdafx.h"
#include "../Math/SquareMatrix.h"
#include "CppUnitTest.h"
#include <stdlib.h>


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define SIZE 3

typedef double TestType;
extern TestType zeroValue;
extern TestType oneValue;

namespace MathTest
{
	TEST_CLASS(SquareMatrixTest)
	{
	public:
		
		TEST_METHOD(SquareMatrixConstructorTest)
		{
			raytracer::math::SquareMatrix< TestType, SIZE> m(oneValue);
			
			for ( int i = 0; i < SIZE; i++)
			{
				for ( int j = 0; j < SIZE ; j++)
				{
					if (i == j)
					{
						Assert::AreEqual( m.Get( i, j ), oneValue );
					}

					else
					{
						Assert::AreEqual( m.Get( i, j ), zeroValue );
					}

				}

			}
		}

		TEST_METHOD(SquareMatrixGetMinorTest)
		{
			raytracer::math::SquareMatrix< TestType, SIZE> m1(zeroValue);
			int testZahlen = 1;

			for ( int i = 0; i < SIZE; i++)
			{
				for ( int j = 0; j < SIZE ; j++)
				{
					m1.Set(i,j, testZahlen);
					testZahlen++;
				}
			}

			auto m2 = m1.GetMinor(SIZE-1,SIZE-1);

		

			for ( int i = 0; i < SIZE-1; i++)
			{
				for ( int j = 0; j < SIZE-1 ; j++)
				{
					Assert::AreEqual( m1.Get(i,j), m2.Get(i,j) ); 
				}
			}
		}

		TEST_METHOD(SquareMatrixGetDeterminatTest)
		{
			raytracer::math::SquareMatrix< TestType, SIZE> m1(zeroValue);
			int testzahlen = 1;
			for(int i = 0; i < SIZE; i++)
			{
				for(int j = 0; j < SIZE; j++)
				{
					
					m1.Set(i,j, testzahlen++);
				}
			}

			Assert::AreEqual( m1.GetDeterminant(), zeroValue);
		}


	};
}