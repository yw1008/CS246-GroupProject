#include <string>
#include <vector>

class Player;
class Board;

class Game {
    std::vector<int> score;
    bool isWhiteTurn;
    bool isFinished;

    Player* whitePlayer;
    Player* blackPlayer;
    Board* board;

public:
    Game();
    ~Game();

    void start(Player* white, Player* black);
    void setUp();
    void makeMove(const std::string &startPos, const std::string &endPos);
    bool isInCheck() const;
    bool isInCheckmate() const;
    void unDo();
    void addScore(const std::string &color);
    int getScore(const std::string &color) const;
    void setIsFinished(const std::string &color);
    bool getIsFinished() const;
};
