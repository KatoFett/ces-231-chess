#include "testRunner.h"
#include "testPawn.h"
#include "testGame.h"
#include "testKing.h"
#include <iostream>

using namespace std;

void TestRunner::run()
{
	testGame();
	testPawn();
	testKing();
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

void TestRunner::testKing()
{
	TestKing test;
	test.run();
}