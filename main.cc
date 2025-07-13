#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

int main() {
    string cmd;
    Board b;
    bool isSetup = 0;

    while(true) {
        cin >> cmd;
        if(cin.fail()) break;
        if(cmd == "game") {
            string whiteP;
            string blackP;
            cin >> whiteP;
            cin >> blackP;

            b.init();
            if(isSetup){

            } else {
                b.defBoard();
            }

            cout << b; // print the board
        } else if(cmd == "resign") {
            if(b.IsWhite) {
                cout << "Black Wins!" << endl;
            } else {
                cout << "White Wins!" << endl;
            }
        } else if(cmd == "setup") {
            string setupCmd;

            while(cin >> setupCmd != "done") {
                cin >> setupCmd;

                if(setupCmd == "+") { // 
                    ...
                }else if(setupCmd == "-") { // setup command is -, which is remove the piece at the board
                    ...
                } else if(setupCmd == "=") { // setup command is =, which is change the turn
                    ...
                } else {
                    ... // Do we need to consider when the user use invalide command for setup? (e.g. other than +, -, =, and done)
                }
            }
            isSetup += 1;
        } else if(cmd == "move") {
            string from;
            string to;
            cin >> from;
            cin >> to;
            
            ...
        }
    }
}
