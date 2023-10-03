#include "testRunner.h"
#include "testPawn.h"
#include "testGame.h"
#include <iostream>

using namespace std;

void TestRunner::run()
{
	testPawn();
	testGame();
	cout << "All tests pass.";
}

void TestRunner::testPawn()
{
	TestPawn test;
	test.run();
}

void TestRunner::testGame()
{
	TestGame test;
	test.run();
}