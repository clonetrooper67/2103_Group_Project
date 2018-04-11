#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

const int easy = 1000000;
const int medium = 500000;
const int hard = 250000;

int difficultyTime;
int userScore = 0;
int numRounds = 1;
int letter;

bool runAgain = true;

string getFileContents(ifstream&);
string blank;
string red;
string green;
string blue;
string yellow;
string inputedSequence;
string actualSequence;

char difficulty;

void printClear() {
    cout << blank << endl;
}

void printRed() {
    cout << red << endl;
}

void printGreen() {
    cout << green << endl;
}

void printBlue() {
    cout << blue << endl;
}

void printYellow() {
    cout << yellow << endl;
}

int main() {
    //  Get the Blank Table
    ifstream Blank("blank_table.txt");
    blank = getFileContents(Blank);
    Blank.close();
    //  Get the Red Table
    ifstream Red("red_table.txt");
    red = getFileContents(Red);
    Red.close();

    //  Get the Green Table
    ifstream Green("green_table.txt");
    green = getFileContents(Green);
    Green.close();
    //  Get the Blue Table
    ifstream Blue("blue_table.txt");
    blue = getFileContents(Blue);
    Blue.close();
    //  Get the Yellow Table
    ifstream Yellow("yellow_table.txt");
    yellow = getFileContents(Yellow);
    Yellow.close();


    //  Ask the user to input the difficult and collect the input
    cout << "Please enter your level of difficulty: " << endl;
    cout << "'e' for easy" << endl;
    cout << "'m' for medium" << endl;
    cout << "'h' for hard" << endl;
    cout << "level: ";
    cin >> difficulty;
    cout << endl;
    //  Determine the timing of the program based on the user input
    switch (difficulty) {
        case 'e':
            difficultyTime = easy;
            break;
        case 'm':
            difficultyTime = medium;
            break;
        case 'h':
            difficultyTime = hard;
            break;
        default:
            cout << "Invalid Character";
            return 0;
    }
    
    while (runAgain) {
        actualSequence = "";
        
        for (int i = 0; i < numRounds; i++) {
            //  Generate a random number
            srand(time(NULL));
            letter = rand() % 4;

            //  Choose the letter based on the random number
            switch (letter) {
                case 0:
                    printRed();
                    actualSequence.append("R");
                    break;
                case 1:
                    printGreen();
                    actualSequence.append("G");                    
                    break;
                case 2:
                    printBlue();
                    actualSequence.append("B");
                    break;
                case 3:
                    printYellow();
                    actualSequence.append("Y");
                    break;
                default:
                    cout << "Something went really wrong";
                    return 0;
            }
            //  Sleep for the proper amount of time and then clear the console
            usleep(difficultyTime);
//            system("CLS");
            system("tput clear");
            usleep(250000);
            printClear();
        }
        cout << "Please enter the character sequence you saw: ";
        cin >> inputedSequence;
        cout << endl;
        runAgain = inputedSequence == actualSequence; 
        userScore++;
        numRounds++;
    }
    cout << "The combination was incorrect, your final score is: " << userScore << endl;
    cout << "You made it to round " << numRounds << endl;
    cout << "Game Over!" << endl;
    return 0;
}

string getFileContents(ifstream& File) {
    string Lines = "";
//  Make sure the file exists
    if (File) {
        while (File.good()) {
            string TempLine; //Define the temp line
            getline(File, TempLine); // Get the temp line
            TempLine += "\n"; //Add newline

            Lines += TempLine; //Add newline
        }
        return Lines;
    } else {
        return "File does not exist";
    }
}