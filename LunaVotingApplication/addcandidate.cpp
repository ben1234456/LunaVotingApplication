// addcandidate.cpp : A Voting Application that allows the user to add and view candidates
// Created at: 28/7/2021
// hello world

#include <string> 
#include <iostream>
#include <fstream>

using namespace std;

void addCandidate(int &ID) {
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

    // Create text file (Albert)
    fstream myFile;
    myFile.open("candidate.txt", ios::app);
    if (myFile.is_open())
    {
        myFile.close();
    }

    // Perform validation to check whether the user has entered a same candidate. (Albert)         
    string newLine = "Candidate Name: " + candidateName; // A variable that stores the string which matches with the format of the line of text in the text file.
    string line; // A variable that stores each line of text of the text file for each loop.
    //Open and reopen the file to read the file again for a certain time to check whether the user still enters a repeated candidate's name.
    for (int counter = 1; counter < 500; counter++)
    {
        myFile.open("candidate.txt", ios::in); // Open the text file in order to read the text file.
        while (myFile.is_open()) // Check whether the text file is opened successfully.
        {
            while (getline(myFile, line)) // Use a while loop to access every single line of text of the text file and store the text into the string variable called line.
            {
                while (line == newLine) // To search whether the string that contains the input name is the same as any line of text in the text file.
                {
                    cout << "Candidate already exists. Please enter a new candidate name" << endl;
                    cin >> candidateName;
                    newLine = "Candidate Name: " + candidateName; // Update the string that stored in variable newLine after the user types in different name.
                }
            }
            myFile.close(); // After finished to read the file, close the file.
        }
    }

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
    string string_ID;
    ID++;
    if (ID <= 9) {
        string_ID = "0" + to_string(ID);
    } else { string_ID = to_string(ID);}
    candidateID = firstThreeLetterParty + string_ID;

    //Save candidate’s information into the text file.(Albert)
    myFile.open("candidate.txt", ios::app); // Open the file in order to append new information to text file.
    if (myFile.is_open()) //Check whether the file has been opened successfully.
    {
        myFile << "Candidate ID: " << candidateID << endl;  // Store the candidate’s information into the text file.
        myFile << "Candidate Name: " << candidateName << endl;
        myFile << "Candidate Party: " << candidateParty << endl;
        myFile << "Candidate Division: " << candidateDivsion << endl;
        myFile << "Candidate Vote Count: " << candidateVoteCount << endl;
        myFile << "\n";
        myFile.close(); //Close the file after finished to append.
    }

    //print out candidate infromation
    cout << "Candidate Information:" << endl;
    cout << "Candidate ID: " << candidateID << endl;
    cout << "Candidate Name: " << candidateName << endl;
    cout << "Candidate Party: " << candidateParty << endl;
    cout << "Candidate Division: " << candidateDivsion << endl;
    cout << "Candidate Vote Count: " << candidateVoteCount << endl;
}

void display_ID (){
    fstream myFile;

    myFile.open("candidate.txt", ios::in);
    string line;

    while (getline(myFile, line)) {
        cout << line << endl;
    }
    myFile.close(); // After finished to read the file, close the file.
    }

int main()
{
    int ID = 0;//a variable for candidate ID
    int selection = 0; //a variable to store the user selection
    cout << "Welcome to Luna Voting Application" << endl;
    while (selection != 3) {
        //print out the menu details
        if (ID != 0) {
            cout << endl << "Please enter again" << endl;
        }
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
            addCandidate(ID);
            break;

            //View Candidates
        case 2:
            display_ID();
            break;

            //Exit
        case 3:
            cout << "Thanks for using Luna Voting Application! Have a great day!";
            break;

        default:
            cout << "Something went wrong! Please Try Again";
        }
    }

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
