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
    Player *whiteP;
    Player *blackP;
    string whosTurn = "White";
    int whiteScore = 0;
    int blackScore = 0;
    bool isSetup = 0;

    while(true) {
        string line; // must get a whole line of the command
        getline (cin, line);

        istringstream issProgram(line);
        issProgram >> cmd;
        if(cin.eof()) {
            cout << "Final Score: " << endl;
            cout << "White: " << whiteScore << endl;
            cout << "Black: " << blackScore << endl;
            delete board;
            delete whiteP;
            delete blackP;
            break;
        }
        if(cmd == "game") {
            Game *game = new Game();
            // should initialize the game 
            // set players
            string wp, bp;
            if (!(issProgram >> wp >> bp)) {
                cerr << "Invalid input: must enter two players" << endl; // enter two players
                continue;
            }
            
            // check if white player is human or computer
            if (wp == "human") {
                whiteP = new Human(true, 0);
            } else if(wp == "computer[1]") {
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
            game->setBoard(board);
            game->setPlayers(whiteP, blackP);

            cout << "The game is started" << endl;
            // need to print starting board
            while(!game->getIsFinished()) {
                cout << *board << endl;
                
                // read new input
                getline(cin, line);
                istringstream issGame(line);
                issGame >> cmd;
                if (cmd == "resign") {
                    string whoWon = whosTurn == "Black" ? "White" : "Black";
                    game->setIsFinished();
                    game->addScore(whoWon);
                    whiteScore += game->getScore("White");
                    blackScore += game->getScore("Black");
                    isSetup = false;
                    cout << "Game is resigned. " << whoWon << " is Win!" << endl;
                } else if (cmd == "move") {
                        if ((whosTurn == "White" && !(whiteP->getLevel() == 0)) || (whosTurn == "Black" && !(blackP->getLevel() == 0))) {
                            if((whosTurn == "White" && (whiteP->getLevel() == 1))) {
                                string temp = " ";
                                string temp1 = " ";
                                whiteP->move(temp, temp1, board);
                            } else if(whosTurn == "Black" && (blackP->getLevel() == 1)) {
                                string temp = " ";
                                string temp1 = " ";
                                blackP->move(temp, temp1, board);
                            }
                        } 
                        else {
                            string startPos, endPos;
                            if (!(issGame >> startPos >> endPos)) {
                                cerr << "Invalid input: must enter two positions" << endl;
                                continue;
                            }
                            if (!game->isValidMove(startPos, endPos)) {
                                continue;
                            } 
                            // special move for pawn
                            if (board->isPawn(startPos)) {
                                // promotion
                                if ((startPos[1] == '7' && endPos[1] == '8') || (startPos[1] == '2' && endPos[1] == '1')) {
                                    char promotionType;
                                    if (!(issGame >> promotionType)) {
                                        cerr << "Invalid input: must enter the correct piece type for pawn promotion" << endl;
                                        continue;
                                    }
                                    board->promotion(promotionType, startPos, endPos);
                                    continue;
                                }
                                // enpassant
                                //catching and moving
                            }
                            // castling
                            if((whosTurn == "White" && (whiteP->getLevel() == 0))) {
                                if (startPos == "e1" && endPos == "g1") {
                                    if(board->getBoard()[0][4].getPieceType() == pieceType::King){
                                        if(board->getBoard()[0][5].getPieceType() == pieceType::Nothing 
                                        && board->getBoard()[0][6].getPieceType() == pieceType::Nothing
                                        && board->getBoard()[0][7].getPieceType() == pieceType::Rook){
                                            board->getBoard()[0][5].addPiece(pieceType::Rook, Colour::White);
                                            board->getBoard()[0][6].addPiece(pieceType::King, Colour::White);
                                            board->setWhiteK(0, 6);
                                            board->getBoard()[0][4].removePiece();
                                            board->getBoard()[0][7].removePiece();
                                        }
                                    } else {
                                        cerr << "Invalid move" << endl;
                                    }
                                } else if(startPos == "e1" && endPos == "c1"){
                                    if(board->getBoard()[0][4].getPieceType() == pieceType::King){
                                        if(board->getBoard()[0][3].getPieceType() == pieceType::Nothing 
                                        && board->getBoard()[0][2].getPieceType() == pieceType::Nothing
                                        && board->getBoard()[0][1].getPieceType() == pieceType::Nothing
                                        && board->getBoard()[0][0].getPieceType() == pieceType::Rook){
                                            board->getBoard()[0][3].addPiece(pieceType::Rook, Colour::White);
                                            board->getBoard()[0][2].addPiece(pieceType::King, Colour::White);
                                            board->setWhiteK(0, 2);
                                            board->getBoard()[0][4].removePiece();
                                            board->getBoard()[0][0].removePiece();
                                        }
                                    } else {
                                        cerr << "Invalid move" << endl;
                                    }
                                } else {
                                    whiteP->move(startPos, endPos, board);
                                }
                            } else if(whosTurn == "Black" && (blackP->getLevel() == 0)) {
                                if (startPos == "e8" && endPos == "g8") {
                                    if(board->getBoard()[0][4].getPieceType() == pieceType::King){
                                        if(board->getBoard()[7][5].getPieceType() == pieceType::Nothing 
                                        && board->getBoard()[7][6].getPieceType() == pieceType::Nothing
                                        && board->getBoard()[7][7].getPieceType() == pieceType::Rook){
                                            board->getBoard()[7][5].addPiece(pieceType::Rook, Colour::White);
                                            board->getBoard()[7][6].addPiece(pieceType::King, Colour::White);
                                            board->setWhiteK(7, 6);
                                            board->getBoard()[7][4].removePiece();
                                            board->getBoard()[7][7].removePiece();
                                        }
                                    } else {
                                        cerr << "Invalid move" << endl;
                                    }
                                } else if(startPos == "e8" && endPos == "c8"){
                                    if(board->getBoard()[0][4].getPieceType() == pieceType::King){
                                        if(board->getBoard()[7][3].getPieceType() == pieceType::Nothing 
                                        && board->getBoard()[7][2].getPieceType() == pieceType::Nothing
                                        && board->getBoard()[7][1].getPieceType() == pieceType::Nothing
                                        && board->getBoard()[7][0].getPieceType() == pieceType::Rook){
                                            board->getBoard()[7][3].addPiece(pieceType::Rook, Colour::Black);
                                            board->getBoard()[7][2].addPiece(pieceType::King, Colour::Black);
                                            board->setWhiteK(7, 2);
                                            board->getBoard()[7][4].removePiece();
                                            board->getBoard()[7][0].removePiece();
                                        }
                                    } else {
                                        cerr << "Invalid move" << endl;
                                    }
                                } else {
                                    blackP->move(startPos, endPos, board);
                                }
                            }
                        }
                        if(game->isWhiteInCheckmate()){
                            cout << "Checkmate! Black wins!" << endl;
                            whiteP->~Player();
                            blackP->~Player();
                            game->setIsFinished();
                            game->addScore("Black");
                            delete board;
                        } else if(game->isBlackInCheckmate()){
                            cout << "Checkmate! White wins!" << endl;
                            whiteP->~Player();
                            blackP->~Player();
                            game->addScore("White");
                            delete board;
                        } else {
                            if(game->isInCheck() == "white"){
                                cout << "White is in check." << endl;
                            } else if(game->isInCheck() == "black"){
                                cout << "Black is in check." << endl;
                            } else if(game->isInCheck() == "both"){
                                cout << "White is in check." << endl;
                                cout << "Black is in check." << endl;
                            } else {
                                if(board->isStalemate()){ 
                                game->setIsFinished();
                                cout << "Stalemate!" << endl;
                                whiteP->~Player();
                                blackP->~Player();
                                delete board;
                                }
                            }
                        }
                        // game should be initialized after the first game is called
                        whiteScore += game->getScore("White");
                        blackScore += game->getScore("Black");

                        whosTurn = whosTurn == "Black" ? "White" : "Black";
                    }
                    else if (cmd == "undo") {
                        game->undo();
                        whosTurn = whosTurn == "Black" ? "White" : "Black";
                        board->changeTurn();
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
                cout << *board << endl;
            }
            std::cout << "Exited setup mode.\n"; // finish the setup
        } //setup
        else {
            cerr << "Invalid command" << endl;
            continue;
        }
    }
}
