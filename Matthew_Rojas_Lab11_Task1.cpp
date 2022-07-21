//This is a C++ program
/* Matthew Rojas
   UIN: 01128932
   Date:11/18/2019
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

char examGrade (int score);

int main ()
{

    int i;
    char ch;
    int score;
    int len;
    int noOfQuestions = 20; // num of question
    char ID[9]; //array to hold ID

    char *keyString; // char pointer for anser
    char *answerString; //char student answer

    ifstream inFile;

    inFile.open("input.txt");
    if(!inFile)
    {
        cout << "Cannot open input file!!!. " << endl << "Program TERMINATED!!!!" << endl;
        return 1;
    }

    // Dynamic arrays
    //The first is for the answer key
    //the second is for the inputted answers
    keyString = new char[noOfQuestions + 1];
    answerString  = new char[noOfQuestions + 1];

    //Read the answer key
    cout << "Proccessing Data" << endl;
    inFile.get(keyString, noOfQuestions + 1);


    //output the answers
    cout << "Key: " << keyString << endl << endl;

    //Formatting
    cout << left << setw(15) << "Student ID" << setw(25)
         << "Student Answers" << setw(10) << "Score" << setw(10) << "Grade" << endl;

    inFile >> ID;
    inFile.get(ch); //includes whitespaces

    inFile.get(answerString, noOfQuestions + 1); //puts answers in the array

    while (inFile)
    {
        len = strlen(answerString);


        for (i = len; i < noOfQuestions; i++)
            answerString[i] = ' ';

        answerString[noOfQuestions] = '\0';

        score = 0;

        for (i = 0; i < noOfQuestions; i++)
            if (answerString[i] != ' ')
            {
                if (answerString[i] == keyString[i])
                {
                    score = score + 2;
                }
                else
                {
                    score = score - 1;
                }
            }

        cout << left << setw(15) << ID << setw(25)<< answerString
             << setw(10) << score << setw(10) << examGrade(score) << endl;

        inFile >> ID;
        inFile.get(ch);
        inFile.get(answerString, noOfQuestions + 1);
    }
    cout << endl;

    inFile.close();

    delete [] keyString;
    delete [] answerString;

    return 0;
}

char examGrade(int score)
{
    switch (static_cast<int>(score / 40.0 * 10))
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return 'F';
        case 6:
            return 'D';
        case 7:
            return 'C';
        case 8:
            return 'B';
        case 9:
        case 10:
            return 'A';
        default:
            return 'F';
    }
}
