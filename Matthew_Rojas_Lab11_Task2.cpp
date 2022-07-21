//This is a C++ program
/* Matthew Rojas
   UIN: 01128932
   Date: 11/18/2019
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//function prototypes
int sumVotes(int list[], int size);
int winnerIndex(int list[], int size);

int main()
{

    //declare the variables
    int numberOfCandidates;
    string *candidates;
    int *votes;
    int totalVotes;
    int i;

    //ask the user for the number of candidates
    cout << "enter number of candidates: ";
    cin >> numberOfCandidates;
    cout << endl;

    //declare dynamic arrays
    candidates = new string[numberOfCandidates];
    votes = new int[numberOfCandidates];

    //formatting
    cout << fixed << showpoint;
    cout << setprecision(2);
    //ask for the name and number of votes
    cout << "Enter candidate's name and the votes received by the candidate." << endl;

    //use a loop to store the user's input in the dynamic arrays
    for (i = 0; i < numberOfCandidates; i++)
            cin >> candidates[i] >> votes[i];

    //update total votes
    totalVotes = sumVotes(votes, numberOfCandidates);

    //table
    cout << "Candidate    votes Recieved   % of Total Votes" << endl;

    //use a similar loop to print the results
    for (i = 0; i < numberOfCandidates; i++)
    {
        cout << left << setw(10) << candidates[i]
             << right << " " << setw(10) << votes[i] << " " << setw(15)
             << (static_cast<double> (votes[i])/ static_cast<double>(totalVotes)) * 100 << endl;
    }

    //formatting
    cout << endl << endl;
    //display the total and the winner calling fro mthe array
    cout << "Total Votes: " << totalVotes << endl;

    cout << "THE WINNER IS: " << candidates[winnerIndex(votes, numberOfCandidates)] << endl;


    //delete the array
    delete [] candidates;
    delete [] votes;

    return 0;

}


//to calculate the sum
int sumVotes(int list[], int size)
{
    //declare local variable
    int sum = 0;

    //adds all components
    for (int i =0; i < size; i++)
        sum = sum + list[i];

    return sum;
}

//to calculate the winner
int winnerIndex(int list [], int size)
{
    //declare local variable
    int winInd = 0;

    //use a loop to find the winner
    for (int i = 0; i < size; i++)
    {
        if (list[i] > list[winInd])
                winInd = i;
    }
    return winInd;
}
