#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

int main() {
    string cmd;
    Board b;

    while(true) {
        cin >> cmd;
        if(cin.fail()) break;
        if(cmd == "game") {
            string whiteP;
            string blackP;
            cin >> whiteP;
            cin >> blackP;

            b.init();
            b.defBoard();
            ...

            cout << b; // print the board
        } else if(cmd == "resign") {
            if(b.IsWhite) {
                cout << "Black Wins!" << endl;
            } else {
                cout << "White Wins!" << endl;
            }
        } else if(cmd == "setup") {
            string setupCmd;

            while(cin >> setupCmd == "done") {
                cin >> setupCmd;

                if(setupCmd == "+") {
                    ...
                }else if(setupCmd == "-") {
                    ...
                } else if(setupCmd == "=") {
                    ...
                } else {
                    ... // Do we need to consider when the user use invalide command for setup? (e.g. other than +, -, =, and done)
                }
            }
        } else if(cmd == "move") {
            string from;
            string to;
            cin >> from;
            cin >> to;
            
            ...
        }
    }
}
