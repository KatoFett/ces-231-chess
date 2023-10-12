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
#include "testRunner.h"	  // for tests
#include "square.h"
#include "game.h"
#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"

using namespace std;

/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
void draw(const Game& game, const Interface& ui)
{
   ogstream gout;

   // draw the checkerboard
   gout.drawBoard();

   // draw any selections
   gout.drawHover(ui.getHoverPosition());
   gout.drawSelected(ui.getSelectPosition());

   // draw the possible moves
   if (game.getSelectedPiece() != nullptr)
   {
      set<Square*> possible = game.getSelectedPiece()->getMoves();
      set <Square*> ::iterator it;
      for (it = possible.begin(); it != possible.end(); ++it)
         gout.drawPossible((*it)->getIndex());
   }

   // draw the pieces
   for (int i = 0; i < 64; i++)
   {
      Piece* piece = game.getBoard()[i]->getPiece();
      if (piece != nullptr)
      {
         bool isBlack = piece->getPlayer() == game.getPlayer(1);  // Needs to be adjusted for 4-player chess.
         switch (piece->getName())
         {
         case 'P':
            gout.drawPawn(i, isBlack);
            break;
         case 'K':
            gout.drawKing(i, isBlack);
            break;
         case 'Q':
            gout.drawQueen(i, isBlack);
            break;
         case 'R':
            gout.drawRook(i, isBlack);
            break;
         case 'B':
            gout.drawBishop(i, isBlack);
            break;
         case 'N':
            gout.drawKnight(i, isBlack);
            break;
         }
      }
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
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 

   Game& game = *(Game*)p;

   // draw the board
   draw(game, *pUI);

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
   // Run tests
   TestRunner tests;
   tests.run();

   Game game;
   game.initDefault(true);

   Interface ui("Chess");

   //#ifdef _WIN32
   //   //  int    argc;
   //   //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
   //   //  string filename = argv[1];
   //   if (__argc == 2)
   //      readFile(__argv[1], board);
   //#else // !_WIN32
   //   if (argc == 2)
   //      readFile(argv[1], board);
   //#endif // !_WIN32

      //set everything into action
   ui.run(callBack, &game);

   return 0;
}
