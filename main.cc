#include <iostream>
#include <string>
#include "game.h"
#include "board.h"
#include "player.h"

using namespace std;

int main() {
    string cmd;
    Board *board;
    Game game;
    Player *whiteP;
    Player *blackP;
    string whosTurn = "White";
    bool isSetup = 0;

    while(true) {
        cin >> cmd;
        if(cin.eof()) {
            cout << "Final Score: " << endl;
            cout << "White: " << game.getScore("White") << endl;
            cout << "Black: " << game.getScore("Black") << endl;
        }
        if(cmd == "game") {
            // set board
            if (!isSetup) {
                board.defBoard();
            } 

            // set players
            string wp, bp;
            if (!(cin >> wp >> bp)) cerr << "Invalid input: must enter two players" << endl; // enter two players
            if (wp == "human") {
                whiteP = Player(true, true);
            } // white human
        //else if (wp == "") {

            //} // white computer
            else cerr << "Invalid inputer: player should be computer or human" << endl; // invalid white player
            if (bp == "human") {
                blackP = Player(true, false);
            } // black human
        //else if (bp == ) {

        //} // black computer
            else cerr << "Invalid inputer: player should be computer or human" << endl; // invalid black player

            // start the game
            game.start(whiteP, blackP, board);
            while(!game.getIsFinished()) {
                cin >> cmd;
                if (cmd == "resign") {
                    string whoWon = whosTurn == "Black" ? "White" : "Black";
                    game.setIsFinished(whoWon);
                    game.addScore(whoWon);
                    isSetup = false;                    
                }
                else if (cmd == "move") {
                    if ((whosTurn == "White" && !(whiteP->isHuman())) || (whosTurn == "Black" && !(blackP->isHuman()))) {
                        //computer player
                        //call makeMove(?) method of the computer class
                    }
                    string startPos, endPos;
                    if (!(cin >> startPos >> endPos)) {
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

            while (std::cin >> cmd) {
                char piece;
                std::string pos, colour;

                if (cmd == "+") {
                    if (!(cin >> piece >> pos)) {
                        cerr << "Invalid command: enter correct number of arguments for +" << endl;
                        continue;
                    }
                } else if (cmd == "-") {
                    if (!(cin >> pos)) {
                        cerr << "Invalid command: enter correct number of arguments for -" << endl;
                        continue;
                    }
                } else if (cmd == "=") {
                    if (!(cin >> colour)) {
                        cerr << "Invalid command: enter correct number of arguments for =" << endl;
                        continue;
                    }
                }

                try {
                    board.setUp(cmd, piece, pos, colour);
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