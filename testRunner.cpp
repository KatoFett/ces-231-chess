#include "testRunner.h"
#include <iostream>

using namespace std;

void TestRunner::run()
{
	testPawn();
	testBoard();
	cout << "All tests pass.";
}

void TestRunner::testPawn()
{
	TestPawn test;
	test.run();
}

void TestRunner::testBoard()
{
	TestBoard test;
	test.run();
}