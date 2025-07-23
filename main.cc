#include <iostream>
#include <string>
#include "game.h"
#include "board.h"
#include "player.h"

using namespace std;

int main() {
    string cmd;
    // Board board;
    Game game;
    string whosTurn = "White";
    bool isSetup = 0;

    while(true) {
        cin >> cmd;
        if(cin.eof()) {
            cout << "Final Score: " << endl;
            cout << "White: " << game.getScor("White") << endl;
            cout << "Black: " << game.getScore("Black") << endl;
        }
        if(cmd == "game") {
            string whiteP, blackP;
            if (!(cin >> whiteP >> blackP)) cerr << "Invalid input: must enter two players" << endl; // enter two players
            if (whiteP == "human") {
                
            } // white human
            else if (whiteP == "") {

            } // white computer
            else cerr << "Invalid inputer: player should be computer or human" << endl; // invalid white player
            if (blackP == "human") {

            } // black human
            else if (blackP == ) {

            } // black computer
            else cerr << "Invalid inputer: player should be computer or human" << endl; // invalid black player

            // start the game
            while(!game.getIsFinished()) {
                cin >> cmd;
                if (cmd == "resign") {
                    string whoWon = whosTurn == "Black" ? "White" : "Black";
                    game.addScore(whoWon);
                    game.setIsFinished(whoWon);
                }
                else if (cmd == "move") {
                    if ((whosTurn == "White" && !(game.whitePlayer->isHuman())) || (whosTurn == "Black" && !(game.blackPlayer->isHuman()))) {
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

                    if (game.isInCheck) {
                        if (game.isInCheckmate) { // if opponent is in checkmate end the game
                            game.setIsFinished(whosTurn);
                            game.addScore(whosTurn);
                        }
                    }
                    else { // check if the game is in stalemate
                    }
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
            game.setUp();
        } //setup
        else {
            cerr << "Invalid command" << endl;
            continue
        }
    }
}