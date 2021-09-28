// addcandidate.cpp : A Voting Application that allows the user to add and view candidates
// Created at: 28/7/2021
// hello world

#include <string> 
#include <iostream>

using namespace std;

void addCandidate() {
    //All candidate information
    string candidateID = ""; // a variable to store candidate's ID
    string candidateName = ""; // a variable to store candidate's name
    string candidateParty = ""; // a variable to store candidate's party
    int candidateDivsion = 0; // a variable to store candidate's division (only 1 - 4 allowed)
    int candidateVoteCount = 0; // a variable to store candidate's vote count

    //Inputs
    int partyInput = 0; // a variable to store party input
    int divisionInput = 0; // a variable to store division input

    //Others
    int counter = 1; // a variable that act as counter
    string candidateParties[3] = { "Party1", "Party2", "Party3" }; // an array to store the parties
    string firstThreeLetterParty = ""; // a variable to store the first three letter of the party

    cout << "You have selected [1] Add Candidate" << endl;
    cout << "Please enter the candidate's information" << endl;
    cout << "Please enter the candidate's name" << endl;

    //get candidate's name
    cin >> candidateName;

    //TO-DO Validate is duplicate or not

    //print out parties
    cout << "Please enter candidate's party according to the selection below" << endl;

    for (string party : candidateParties) {
        cout << "[" << counter << "] " << party << endl;
        counter++;
    }

    //get candidate's party
    cin >> partyInput;

    //perform validation, while the selection is not 0, 1, or 2, the program will display an error message again and prompt the user to enter the selection again
    while (partyInput != 1 && partyInput != 2 && partyInput != 3) {
        //clear failbit
        cin.clear();

        // remove characters that are still in the input buffer (until next end of line)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid number, please enter a valid number (1, 2, or 3)" << endl;

        cin >> partyInput;
    }

    //assign party to candidate
    candidateParty = candidateParties[partyInput - 1];

    //print out divisions
    cout << "Please enter a division (1-4)" << endl;

    cin >> divisionInput;

    //perform validation, while the selection is not 1, 2, 3 or 4 the program will display an error message again and prompt the user to enter the selection again
    while (divisionInput != 1 && divisionInput != 2 && divisionInput != 3 && divisionInput != 4) {
        //clear failbit
        cin.clear();

        // remove characters that are still in the input buffer (until next end of line)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid number, please enter a valid number (1, 2, 3 or 4)" << endl;

        cin >> divisionInput;
    }

    //assign the division to candidate's division
    candidateDivsion = divisionInput;

    //TO-DO: Softcode the id (Vendy)
    // 
    //getting candidate id
    firstThreeLetterParty = candidateParty.substr(0, 3);
    candidateID = firstThreeLetterParty + "00";

    //TO-DO: save to text file

    //print out candidate infromation
    cout << "Candidate Information:" << endl;
    cout << "Candidate ID: " << candidateID << endl;
    cout << "Candidate Name: " << candidateName << endl;
    cout << "Candidate Party: " << candidateParty << endl;
    cout << "Candidate Division: " << candidateDivsion << endl;
    cout << "Candidate Vote Count: " << candidateVoteCount << endl;

}

int main()
{
    int selection = 0; //a variable to store the user selection

    //print out the menu details
    cout << "Welcome to Luna Voting Application" << endl;
    cout << "[1] Add Candidate" << endl;
    cout << "[2] View Candidates" << endl;
    cout << "[3] Exit" << endl;
    cout << "Please select one of the numbers:" << endl;

    //get the user input
    cin >> selection;

    //perform validation, while the selection is not 1, 2, or 3, the program will display an error message again and prompt the user to enter the selection again
    while (selection != 1 && selection != 2 && selection != 3) {
        //clear failbit
        cin.clear();

        // remove characters that are still in the input buffer (until next end of line)
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Invalid number, please enter a valid number (1, 2, or 3)" << endl;

        cin >> selection;
    }

    //Menu
    //1 = Add Candidate
    //2 = View Candidates
    //3 = Exit

    switch (selection) {
        //Add Candidate
    case 1:
        addCandidate();
        break;

        //View Candidates
    case 2:
        cout << "TO-DO";
        break;

        //Exit
    case 3:
        cout << "Thanks for using Luna Voting Application! Have a great day!";
        break;

    default:
        cout << "Something went wrong! Please Try Again";
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
