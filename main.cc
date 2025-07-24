#include <iostream>
#include <string>
#include <sstream>
#include "game.h"
#include "board.h"
#include "player.h"
#include "human.h"
#include "computer.h"

using namespace std;

int main() {
    string line, cmd;
    Board *board = new Board();    
    Game game;
    Player *whiteP;
    Player *blackP;
    string whosTurn = "White";
    int whiteScore = 0;
    int blackScore = 0;
    bool isSetup = 0;

    while(true) {
        string line; // must get a whole line of the command
        getline (cin, line);
        whiteScore += game.getScore("White");
        blackScore += game.getScore("Black");

        istringstream issProgram(line);
        issProgram >> cmd;
        if(cin.eof()) {
            cout << "Final Score: " << endl;
            cout << "White: " << whiteScore << endl;
            cout << "Black: " << blackScore << endl;
            break;
        }
        if(cmd == "game") {
            // set players
            string wp, bp;
            if (!(issProgram >> wp >> bp)) {
                cerr << "Invalid input: must enter two players" << endl; // enter two players
                continue;
            }
            
            // check if white player is human or computer
            if (wp == "human") {
                whiteP = new Human(true, 0);
            } else if(wp == "comuter[1]") {
                whiteP = new Computer(true, 1);
            }
            else {
                cerr << "Invalid inputer: player should be computer or human" << endl; // invalid white player
                continue;
            }

            // check if black player is human or computer
            if (bp == "human") {
                blackP = new Human(false, 0);
            } else if(bp == "computer[1]") {
                blackP = new Computer(false, 1);
            } else {
                cerr << "Invalid inputer: player should be computer or human" << endl; // invalid black player
                continue;
            } 

            // set default board if it is not setup
            if (!isSetup) {
                board->init();
                board->defBoard();
            } 

            // // start the game
            // game.start(whiteP, blackP, board);
            game.setBoard(board);
            game.setPlayers(whiteP, blackP);

            cout << "The game is started" << endl;
            // need to print starting board
            while(!game.getIsFinished()) {
                // cout << "Enter move/resign/undo for the game" << endl;
                
                // read new input
                getline(cin, line);
                istringstream issGame(line);
                issGame >> cmd;
                if (cmd == "resign") {
                    string whoWon = whosTurn == "Black" ? "White" : "Black";
                    game.setIsFinished(whoWon);
                    game.addScore(whoWon);
                    isSetup = false;                    
                }
                else if (cmd == "move") {
                    if ((whosTurn == "White" && !(whiteP->getLevel() == 0)) || (whosTurn == "Black" && !(blackP->getLevel() == 0))) {
                        if((whosTurn == "White" && (whiteP->getLevel() == 1))) {
                            whiteP->move(*board);
                        } else if(whosTurn == "Black" && (blackP->getLevel() == 1)) {
                            blackP->move(*board);
                        }
                    }
                    string startPos, endPos;
                    if (!(issGame >> startPos >> endPos)) {
                        cerr << "Invalid input: must enter to positions" << endl;
                        continue;
                    }
                    // castling, pawn promotion
                    game.makeMove(startPos, endPos);

                    // if (game.isInCheck()) {
                    //     if (game.isInCheckmate) { // if opponent is in checkmate end the game
                    //         game.setIsFinished(whosTurn);
                    //         game.addScore(whosTurn);
                    //         isSetup = false;
                    //     }
                    // }
                    // else { // check if the game is in stalemate
                    // }
                    whosTurn = whosTurn == "Black" ? "White" : "Black";
                }
                else if (cmd == "undo") {
                    game.undo();
                }
                else {
                    cerr << "Invalid input for the game" << endl;
                }
            } // end the game
        }
        else if (cmd == "setup") {
            cout << "Entered setup mode. Type 'done' when you're finished." << endl;
            isSetup = true;
            board->init();

            while (true) {
                getline(cin, line);
                istringstream issSetup(line);
                issSetup >> cmd;
                
                std::string piece, pos, colour;

                if (cmd == "+") {
                    if (!(issSetup >> piece >> pos)) {
                        cerr << "Invalid command: enter correct number of arguments for +" << endl;
                        continue;
                    }
                } else if (cmd == "-") {
                    if (!(issSetup >> pos)) {
                        cerr << "Invalid command: enter correct number of arguments for -" << endl;
                        continue;
                    }
                } else if (cmd == "=") {
                    if (!(issSetup >> colour)) {
                        cerr << "Invalid command: enter correct number of arguments for =" << endl;
                        continue;
                    }
                }

                try {
                    board->setUp(cmd, piece, pos, colour);
                    if (cmd == "done") {
                        break; // only break if setup is valid
                    }
                } catch (std::invalid_argument &e) {
                    cerr << "Setup error: " << e.what() << endl;
                    continue; // do not break on error
                }
            }
            std::cout << "Exited setup mode.\n"; // finish the setup
        } //setup
        else {
            cerr << "Invalid command" << endl;
            continue;
        }
    }
}