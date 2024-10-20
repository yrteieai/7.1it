#include "pch.h"
#include "CppUnitTest.h"
#include "../7.1_it/7.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71it
{
    TEST_CLASS(UnitTest71it)
    {
    public:

        TEST_METHOD(TestSort)
        {
            const int rowCount = 3;
            const int colCount = 6;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

            int testMatrix[rowCount][colCount] = {
                { 30, 72, 18, 23, 41, 64 },
                { 29, 35, 47, 55, 20, 41 },
                { 50, 68, 21, 31, 24, 19 }
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    matrix[i][j] = testMatrix[i][j];

            Sort(matrix, rowCount, colCount);

            int expectedMatrix[rowCount][colCount] = {
                { 18, 23, 30, 41, 64, 72 },
                { 47, 55, 29, 20, 41, 35 },
                { 21, 31, 50, 24, 19, 68 }
            };

            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::AreEqual(expectedMatrix[i][j], matrix[i][j], L"Sorting failed");
                }
            }

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }

        TEST_METHOD(TestCalc)
        {
            const int rowCount = 3;
            const int colCount = 6;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                matrix[i] = new int[colCount];

            int testMatrix[rowCount][colCount] = {
                { 18, 23, 30, 41, 64, 72 },
                { 47, 55, 29, 20, 41, 35 },
                { 21, 31, 50, 24, 19, 68 }
            };

            for (int i = 0; i < rowCount; i++)
                for (int j = 0; j < colCount; j++)
                    matrix[i][j] = testMatrix[i][j];

            int S = 0;
            int k = 0;

            Calc(matrix, rowCount, colCount, S, k);

            int expectedS = 346; 
            int expectedK = 8;   

            int expectedMatrix[rowCount][colCount] = {
                {  0, 23, 0, 41, 0, 0 },
                { 47, 55, 29,  0, 41, 35 },
                { 21, 31,  0,  0, 19, 0 }
            };

            Assert::AreEqual(expectedS, S, L"Sum calculation failed");
            Assert::AreEqual(expectedK, k, L"Count calculation failed");

            for (int i = 0; i < rowCount; i++) {
                for (int j = 0; j < colCount; j++) {
                    Assert::AreEqual(expectedMatrix[i][j], matrix[i][j], L"Matrix modification failed");
                }
            }

            for (int i = 0; i < rowCount; i++)
                delete[] matrix[i];
            delete[] matrix;
        }
    };
}
