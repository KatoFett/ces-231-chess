/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window,
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;

/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
void draw(const char* board, const Interface& ui, const set <int>& possible)
{
	ogstream gout;

	// draw the checkerboard
	gout.drawBoard();

	// draw any selections
	gout.drawHover(ui.getHoverPosition());
	gout.drawSelected(ui.getSelectPosition());

	// draw the possible moves
	set <int> ::iterator it;
	for (it = possible.begin(); it != possible.end(); ++it)
		gout.drawPossible(*it);

	// draw the pieces
	for (int i = 0; i < 64; i++)
		switch (board[i])
		{
		case 'P':
			gout.drawPawn(i, true);
			break;
		case 'p':
			gout.drawPawn(i, false);
			break;
		case 'K':
			gout.drawKing(i, true);
			break;
		case 'k':
			gout.drawKing(i, false);
			break;
		case 'Q':
			gout.drawQueen(i, true);
			break;
		case 'q':
			gout.drawQueen(i, false);
			break;
		case 'R':
			gout.drawRook(i, true);
			break;
		case 'r':
			gout.drawRook(i, false);
			break;
		case 'B':
			gout.drawBishop(i, true);
			break;
		case 'b':
			gout.drawBishop(i, false);
			break;
		case 'N':
			gout.drawKnight(i, true);
			break;
		case 'n':
			gout.drawKnight(i, false);
			break;
		}
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface* pUI, void* p)
{
	set <int> possible;

	// the first step is to cast the void pointer into a game object. This
	// is the first step of every single callback function in OpenGL. 

	// draw the board
	//draw(board, *pUI, possible);

}


/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ PSTR pCmdLine,
	_In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
	Interface ui("Chess");

	//#ifdef _WIN32
	// //  int    argc;
	// //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
	// //  string filename = argv[1];
	//   if (__argc == 2)
	//      readFile(__argv[1], board);
	//#else // !_WIN32
	//   if (argc == 2)
	//      readFile(argv[1], board);
	//#endif // !_WIN32

	// set everything into action
	//ui.run(callBack, board);        

	return 0;
}
