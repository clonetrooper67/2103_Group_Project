#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <string>
#include <fstream>

using namespace std;

const int easy = 1000;
const int medium = 500;
const int hard = 250;

string getFileContents(ifstream&);
string blank;
string red;
string green;
string blue;
string yellow;

char difficulty;

int main() {
//  Get the Blank Table
    ifstream Blank("blank_table.txt");
    blank = getFileContents(Blank);
//  Get the Red Table
    ifstream Red ("red_table.txt");
    red = getFileContents(Red);
//  Get the Green Table
    ifstream Green ("green_table.txt");
    green = getFileContents(Red);
//  Get the Blue Table
    ifstream Blue ("blue_table.txt");
    blue = getFileContents(Red);
//  Get the Yellow Table
    ifstream Yellow ("yellow_table.txt");
    yellow = getFileContents(Red);
//  Close all the file inputs
    Blank.close();
    Red.close();
    Green.close();
    Blue.close();
    Yellow.close();


    //    Sleep(1000);
    //    system("clear");

    return 0;
}

void printTable() {

}

void printRed(int t) {
    cout << red << endl;
}

void printGreen(int t) {
    cout << green << endl;
}

void printBlue(int t) {
    cout << blue << endl;
}

void Yellow(int t) {
    cout << yellow << endl;
}

string getFileContents(ifstream& File) {
    string Lines = ""; 

    if (File) {
        while (File.good()) {
            string TempLine; //Define the temp line
            getline(File, TempLine); // Get the temp line
            TempLine += "\n"; //Add newline

            Lines += TempLine; //Add newline
        }
        return Lines;
    } else //Return error
    {
        return "File does not exist";
    }
}