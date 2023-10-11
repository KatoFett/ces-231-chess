#include "game.h"
#include "player.h"
#include "square.h"
#include "piece.h"

Game* Game::instance;

void Game::initDefault(bool assignPieces)
{
    if (assignPieces) throw "Assign pieces not implemented yet.";

    int whiteColor[] = { 255, 255, 255 };
    int blackColor[] = { 0, 0, 0 };

    board = new Board(8, 8);

    // Create 2 players.
    Player* white = new Player(Direction::UP, whiteColor);
    Player* black = new Player(Direction::DOWN, blackColor);
    addPlayer(*white);
    addPlayer(*black);

    // Create squares.
    bool isDark = true;    // A1 square is always black.
    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Square* square = new Square(isDark);
            board->addSquare(square);
            isDark = !isDark;
        }
    }
}

void Game::addPlayer(Player& player)
{
    players.push_back(&player);
    playerCount++;
}

Move* Game::getLastMoveEnPassant() const
{
    

    if (moves.empty())
        throw "no moves have been made.";
    // If two man chess the previous move 
    if (players.size() == 2)
        return moves[players.size() - 1];
    // If fourman chess check the player two behind them (1st,2nd,3rd,4th)
    int fourManPrev = moves.size() - 2;
    // Modulus will return what player it is currently 
    for (int i = 1; i < 5; i++) {
        if (currentTurn % 4 == i && players.size() == 4 && currentTurn != 1)
            return moves[fourManPrev];
    }
    return nullptr;
}


void Game::move(Square* square)
{
   if (selectedPiece == nullptr) throw "Cannot move without first selecting a piece.";

   Move* move = selectedPiece->moveToSquare(square);
   moves.push_back(move);
}