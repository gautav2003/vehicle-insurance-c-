
#include<iostream>
#include<windows.h>
#include<string>
#include<vector>
#include<iomanip>
#include<sstream>
#include<windows.h>
#include<filesystem>
#include<fstream>
#include<utility>
using namespace std;

bool access = false;
string currentUser = "";
bool Admin = false;

// function to read the csv file and return a vector of pairs with the vector containing the data
vector<pair<string, vector<string>>> read_csv(string filename) {
    ifstream file(filename);
    vector<pair<string, vector<string>>> result;
    string line;
    string cell;
    vector<string> values;
    while (getline(file, line)) {
        stringstream lineStream(line);
        while (getline(lineStream, cell, ',')) {
            values.push_back(cell);
        }
        result.push_back(make_pair(values.at(0), values));
        values.clear();
    }
    return result;
}

void  adminScreen() {
    string CustomerReport, WeeklyClaimReport, WeeklyRenewalReport, WeeklyNewRegistrationReport, UpdateThePolicyInformationAndPublishTheSpecialDiscounts;
    
    cout << "Customer report";
    getline(cin,CustomerReport);

    cout << "Weekly claim report";
    getline(cin,WeeklyClaimReport);

    cout << "Weekly renewal report";
    getline(cin,WeeklyRenewalReport);

    cout << "Weekly new registration report";
    getline(cin, WeeklyNewRegistrationReport);

    cout << "Update the policy information and publish the special discounts";
    getline(cin,UpdateThePolicyInformationAndPublishTheSpecialDiscounts);

}

void customerScreen() {
    string PolicyAndInsuranceApplicationProcess, Claim, Renewal, BenefitsOfNZInsurance;

    cout << "Policy And Insurance application process";
    getline(cin, PolicyAndInsuranceApplicationProcess);

    cout << "Claim";
    getline(cin, Claim);

    cout << "Renewal";
    getline(cin, Renewal);

    cout << " benefits of NZ insurance  ";
    getline(cin, BenefitsOfNZInsurance);

}

void BenefitsOfNZInsurance() {
    string NewSignUpDiscounts, MultiPolicyDiscount, RenewalDiscount, DiscountForReiewingTheInsuranceAndIntroductingFriendsorFamilyDiscount;

    cout << "New sign-up discounts";
    getline(cin, NewSignUpDiscounts);

    cout << "Multi policy disount";
    getline(cin, MultiPolicyDiscount);

    cout << "Renewal discount";
    getline(cin, RenewalDiscount);

    cout << " Discount for reiewing the insurance amd inroducting friends or family Discount";
    getline(cin, DiscountForReiewingTheInsuranceAndIntroductingFriendsorFamilyDiscount);
}
     
void insurancepolicyScreen() {
    string PolicyCategories, PolicyDescriptionTheVehicle, QuotefortheChosenPolicy, PolicyRegistration;

    cout << "Policy Categories";
    getline(cin,PolicyCategories);

    cout<<"Policy Description The Vehicle";
    getline(cin, PolicyDescriptionTheVehicle);

    cout << " Quote for the Chosen Policy";
    getline(cin, QuotefortheChosenPolicy);

    cout << "Policy Registration";
    getline(cin, PolicyRegistration);
}

void claimregistrationScreen() {
    string  PolicyNumber, FullName, Date, TimeIncidentDescription, ComplaintDetails, ContactDetails;

    cout << "Policy Number";
    getline(cin, PolicyNumber);

    cout << "Full Name";
    getline(cin, FullName);

    cout << "Date";
    getline(cin, Date);

    cout << "Time Incident Description";
    getline(cin, TimeIncidentDescription);

    cout << "Complaint Details";
    getline(cin, ComplaintDetails);

    cout << "Contact Details";
    getline(cin, ContactDetails);

}

void RenewalScreen() {
    string   RenewalProcessDescription,PolicyNumber, FullName, New_Policy_Name, ContactNumber, VisaCardNumber;

    cout << " Renewal Process Description ";
    getline(cin, RenewalProcessDescription);

    cout << "Policy Number ";
    getline(cin, PolicyNumber);

    cout << "Full Name";
    getline(cin, FullName);

    cout << "New_Policy_Name";
    getline(cin, New_Policy_Name);

    cout << "Contact Number ";
    getline(cin, ContactNumber);

    cout << "Visa Card Number ";
    getline(cin, VisaCardNumber);

}



void registerUser() {
    //Get user name from user
    string RegUsername, RegPassword, FirstName, LastName, DOB, Gender, ContactNumber,Email, PhysicalAddress, VehicleRegistrationNumber;
    char AdminAccess;
    string ADM = "";
    cout << "Enter  First name:";
    cin.ignore(1000, '\n');
    cin.clear();
    getline(cin, FirstName);


    cout << "Enter Last name:";
    getline(cin, LastName);


    cout << "Enter your DOB: ";
	getline(cin, DOB);
    
    cout << "Enter your Gender: ";
    getline(cin, Gender);


    cout << "Enter your contact number: ";
    getline(cin, ContactNumber);


    cout << "Enter your email: ";
    getline(cin, Email);
    //Checking to make sure the currently entered username doesn't already exist
   /* vector<pair<string, vector<string>>> result2 = read_csv("Accounts.csv");
    for (int i = 0; i < result2.size(); i++) {
        if (result2.at(i).first == Email) {
            cout << " Email " << Email << " Already exists";
            Sleep(3000);
            system("CLS");
            return;
        }
    } */

    cout << "Enter your physical address: ";
    getline(cin, PhysicalAddress);


    cout << "Enter your Vehicle registration number: ";
    getline(cin, VehicleRegistrationNumber);

    //Checking to make sure the currently entered username doesn't already exist
   /* vector<pair<string, vector<string>>> result1 = read_csv("Accounts.csv");
    for (int i = 0; i < result1.size(); i++) {
        if (result1.at(i).first == VehicleRegistration) {
            cout << "vehicle registeration " << VehicleRegistration << " Already exists";
            Sleep(3000);
            system("CLS");
            return;
        }
    }*/



    cout << "Enter username: ";
    getline(cin, RegUsername);

    /*//Checking to make sure the currently entered username doesn't already exist
    vector<pair<string, vector<string>>> result = read_csv("Accounts.csv");
    for (int i = 0; i < result.size(); i++) {
        if (result.at(i).first == RegUsername) {
            cout << "Username " << RegUsername << " Already exists";
            Sleep(3000);
            system("CLS");
            return;
        }
    }*/
    //Getting password from the user
    cout << "Enter password: ";
    cin.clear();
    getline(cin, RegPassword);

    // Open the file in append mode
    ofstream outFile(" Customer_registration.csv", ios::app);
    if (!outFile) {
        cerr << "Error opening file for writing\n";
        return;
    }
//Asking the user if they would like admin access
if (Admin == true) {
    while (true) {
        cout << "Would you like to give this account admin access (y/n): ";
        cin >> AdminAccess;
        if (AdminAccess == 'Y' || AdminAccess == 'y') {
            ADM = "1";
            break;
        }

        else if (AdminAccess == 'N' || AdminAccess == 'n') {
            ADM = "0";
            break;
        }

        else {
            cout << "Invalid option";
        }
    }
}

else if (Admin == false) {
    ADM = "0";
}
FirstName, LastName, DOB, Gender, ContactNumber, Email, PhysicalAddress, VehicleRegistrationNumber;
//write user information to the file
outFile << RegUsername << "," << RegPassword << "," << FirstName << "," << LastName << "," << DOB << "," << Gender << "," << ContactNumber << "," << Email << "," << PhysicalAddress << "," << VehicleRegistrationNumber << ","<< ADM << "\n";

//close the file
outFile.close();

//Confirmation message
cout << "User registration successful\n";
Sleep(3000);
system("CLS");
}


bool login() {
    string username, password;
    int attempts = 0;
    const int max_attempts = 3;

    while (attempts < max_attempts) {
        cin.ignore(1000, '/n');
        cin.clear();
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter Password: ";
        getline(cin, password);


        vector<pair<string, vector<string>>>result = read_csv("Customer_registration.csv");
        bool login_success = false;


        for (const auto& customer : result) {
            if (customer.first == username && customer.second[8] == username && customer.second[9] == password) {//Assuming username and password are at positions 8 and 9
                cout << "Login successful!" << endl;
                currentUser = username;
                access = true;
                return true;
            }
        }
        attempts++;
        if (attempts < max_attempts) {
            cout << "invalid credentials. Please try again." << endl;
        }
    
        cout << "Maximum login attempts reached. Please try again later." << endl;
        return false;
    }
    //Get user name from user
    cin.ignore(1000, '\n');
    cin.clear();
    cout << "Enter username: ";
    cin.clear();
    getline(cin, username);
    //Getting password from the user
    cout << "Enter password: ";
    cin.clear();
    getline(cin, password);

    cin.clear();

    //uses readcsv function to read the csv file
    vector<pair<string, vector<string>>> result = read_csv("Customer_registration.csv");
    //loops through the vector of pairs to check if the username and password match
    string actualUsername = "";
    string actualPassword = "";
    string ActualAdmin = "";
    for (int i = 0; i < result.size(); i++) {
        if (result.at(i).first == username) {
            actualUsername = result.at(i).first;
            actualPassword = result.at(i).second.at(1);
            ActualAdmin = result.at(i).second.at(2);
        }

    }
}


void ID() {
    if (access == false) {
        cout << "You are not login \n" << endl;
    }

    else if (access == true) {
        cout << currentUser << "    ";

        if (Admin == true) {
            cout << ":    Admin" << endl;
        }

        else if (Admin == false) {
            cout << ":    Guest" << endl;
        }
    }
}
int validInput()
{
    int x;
    cin >> x;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Bad entry.  Enter a NUMBER: ";
        cin >> x;
    }
    return x;
}

void accountManage() {
    int option2;
    while (true) {
        ID();
        cout << "--- Customer login/Registration---" << endl;
        cout << "\n";
        cout << "1: login" << endl;
        cout << "2: Create account (New sign up)" << endl;
        cout << "3: log out" << endl;
        cout << "4: Exit" << endl;
        cout << "Please enter thr input for what you'd like to do:";
        cin >> option2;

        //Selecting an option

        switch (option2) {
        case 1:
            // user chooses to log in 
            if (access == false) {
                login(); 
                {
                    cout << "Access granted to the customer dashboard." << endl;
                    // Additional customer dashboard functionalities can be added here
                }
                break;
            }
            else if (access == true) {
                cout << "Already loged in";
                Sleep(3000);
                system("CLS");
                break;
            }
        case 2:
            // user chooses to create an account
            registerUser();
            break;

        case 3:
            if (access == true) {
                cout << "loged out";
                access = false;
                Sleep(3000);
                system("CLS");
                break;
            }

            else if (access == false) {
                cout << "Not currently signed in";
                Sleep(3000);
                system("CLS");
                break;
            }
        case 4:
            //User wants to exit
            system("CLS");
            return;

        default:
            cout << "invalid input";
            break;
        }
    }
}

int main() {
    int choice;
    while (true) {
        //Displaying menu options
        ID();
        cout << " Hakam & Gautav insurance company LTD \n";
        cout << " Contact information: 022456789 \n";
        cout << "\n";
        cout << "--- Vehicle Insurance Menu ---" << endl;
        cout << "\n";
        cout << "1: login/Register\n";
        cout << "2: End Function\n";

        //Asking the user for the option they want
        cout << "Please enter the number for the option you want (1, 2): ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            accountManage();
            break;

        case 2:
            system("CLS");
            adminScreen();

        case 3:
            system("CLS");
            customerScreen();

        case 4:
            system("CLS");
            insurancepolicyScreen();

        case 5:
            system("CLS");
            claimregistrationScreen();
        }

           
    }
    }

    //this is how you would call the function later
    vector<pair<string, vector<string>>> result = read_csv("Customer_registration.csv");

    //will check for a number use instead of cin
