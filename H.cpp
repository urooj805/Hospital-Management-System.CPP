#include <iostream>
#include <fstream>
#include <string> 
#include <cstdlib>
#include <iomanip> 

using namespace std;

// =========================================================Function prototypes
void menu();
void menuaction();
void displayAdminMenu();
void displayUserMenu();
void adminActions();
void userActions(const string &username);  // Accept username as a parameter
//to address username later on
bool readCredentials(const string &username, const string &password, string &role);
//username waghera as a refrence pass hoga ar contstant lagane ki wajhah se username ko bus fileko read krne k liye.
void saveNewUser(const string &username, const string &password, const string &role);
void signup();
bool login(string &username, string &role);
void printHeader();
void addpatient();
string getField(string record, int field);
void viewallpatient();
void viewonepatient(const string &username);
void updatePatientRecord();
void searchPatientRecord();
void updatePersonalInfo(const string &username);
void deleteUserAccount(const string &username);
void displayAvailableDoctors();
void bookAppointment(const string &username);
void viewAppointments();
void addDoctorRecord();
// Main function
int main()
{
    int choice;
    string role;
    string username;  // Declare a string to store the logged-in username

    system("cls");
    system("color 04");

    printHeader();

    while (true)
    {
        menu();  // Show the main menu
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (login(username, role))  // Pass username and role
            {
                if (role == "admin")
                {
                    adminActions();  // Admin actions
                }
                else if (role == "user")
                {
                    userActions(username);  // Pass the username to userActions
                }
                else
                {
                    cout << "Invalid role detected." << endl;
                }
            }
            break;

        case 2:
            signup();  // Call the signup function
            break;

        case 3:
            cout << "Exiting the system." << endl;
            return 0;  // Exit the program

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

void printHeader()
{
    
    cout << "\033[33m   _   _                         _           _                                                                   _       ___           _                     " << endl;
    cout << "\033[33m  ( ) ( )                     _ ( )_        (_ )    /'\\_/`\\                                                     ( )_    (  _`\\        ( )_                   " << endl;
    cout << "\033[31m  | |_| |   _     ___  _ _   (_)| ,_)   _ _  | |    |     |   _ _   ___     _ _    __    ___ ___    ___     __  | ,_)   | (_(_) _   _ | ,_)   __    ___ ___  " << endl;
    cout << "\033[31m  |  _  | /'_`\\ /',__)( '_`\\ | || |   /'_` ) | |    | (_) | /'_` )/' _ `\\ /'_` ) /'_ `\\/\\' _ ` _ `\\/\\' _ `\\ /'__`\\| |     `\\__ \\ ( ) ( )| |   /'__`\\/\\' _ ` _ `\\" << endl;
    cout << "\033[31m  | | | |( (_) )\\__, \\| (_) )| || |_ ( (_| | | |    | | | |( (_| || ( ) |( (_| |( (_) || ( ) ( ) || ( ) |(  ___/| |_    ( )_) || (_) || |_ (  ___/| ( ) ( ) |" << endl;
    cout << "\033[33m  (_) (_)`\\___/'(____/| ,__/'(_)`\\__)`\\__,_)(___)   (_) (_)`\\__,_)(_) (_)`\\__,_)`\\__  |(_) (_) (_)(_) (_)`\\____)`\\__)   `\\____)`\\__, |`\\__)`\\____)(_) (_) (_) " << endl;
    cout << "\033[33m                      | |                                                       ( )_) |                                        ( )_| |                       " << endl;
    cout << "\033[33m                      (_)                                                        \\___/'                                        `\\___/'                       " << endl;
    cout << "\033[31m";
}

void displayAdminMenu()
{
    system("cls");
    printHeader();
     cout << "\033[33m";
    cout << " **********************************************" << endl;
    cout << " *               Admin MENU                   *" << endl;
    cout << " **********************************************" << endl;
    cout << "\033[31m";
    cout << " Add New Patient......................press 1" << endl;
    cout << " View All Patients records............press 2" << endl;
    cout << " View Appointments....................press 3" << endl;
    cout << " Update record of a patient...........press 4" << endl;
    cout << " Search a Patient  Record.............press 5" << endl;
    cout << " Add Doctor Record....................press 6" << endl;
    cout << " Exit.................................press 7" << endl;
    cout << "Enter your choice: .........................";
}
void adminActions()
{
    int choice;
    while (true)
    {
        displayAdminMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            addpatient();
            break;
        case 2:
            viewallpatient();
            break;
        case 3:
            viewAppointments();
            break;
        case 4:
            updatePatientRecord();
            break;
        case 5:
            searchPatientRecord();
            break;
        case 6:
            addDoctorRecord();
            break;
        case 7:
            cout << "Exiting Admin Interface." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}


void displayUserMenu()
{
    system("cls");
    printHeader();
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[33m *                User MENU                  *" << endl;
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[31m";
    cout << " Add Personal Information.............press 1" << endl;
    cout << " View Personal Details................press 2" << endl;
    cout << " Update personal information..........press 3" << endl;
    cout << " View Available Doctor timings........press 4" << endl;
    cout << " Book an Appointment..................press 5" << endl;
    cout << " Delete your account..................press 6" << endl;
    cout << " Exit.................................press 7" << endl;
    cout << "Enter your choice: .........................";
}
void userActions(const string &username) {
    int choice;
    while (true) {
        displayUserMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            addpatient();
            break;
        case 2:
            viewonepatient(username);
            break;
        case 3:
            updatePersonalInfo(username);
            break;
        case 4:
            displayAvailableDoctors();
            break;
        case 5:
            bookAppointment(username);
            break;
        case 6:
            deleteUserAccount(username);
            return;
        case 7:
            cout << "Exiting User Interface." << endl;
            return;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

bool readCredentials(const string &username, const string &password, string &role)
{
    ifstream file("credentials.txt");
    string storedUsername, storedPassword, storedRole;

    while (file.good())
    {
        getline(file, storedUsername, ',');
        getline(file, storedPassword, ',');
        getline(file, storedRole);

        if (storedUsername == username && storedPassword == password)
        {
            role = storedRole;
            return true;
        }
    }
    return false;
}



void menu(){
    system("cls");
    printHeader();
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[33m *                   MAIN MENU                   *" << endl;
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[31m";
    cout << "1. Login\n";
    cout << "2. Sign Up\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
} 

void saveNewUser(const string &username, const string &password, const string &role)
{
    ofstream file("credentials.txt", ios::app);
    file << username << "," << password << "," << role << endl;
    cout << "Account created successfully!" << endl;
}

void signup()
{
    system("cls");
    printHeader();
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[33m *                  SIGN-UP                   *" << endl;
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[31m";
    string username, password, role;
    cout << "\nEnter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    cout << "Enter role (admin/user): ";
    cin >> role;

    if (role != "admin" && role != "user")
    {
        cout << "Invalid role. Please enter 'admin' or 'user'." << endl;
        return;
    }

    saveNewUser(username, password, role);
}

bool login(string &username, string &role)
{
    system("cls");
    printHeader();
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[33m *                   LOGIN                    *" << endl;
    cout << "\033[33m **********************************************" << endl;
    cout << "\033[31m";
    cout << "\nEnter username: ";
    cin >> username;  
    cout << "Enter password: ";
    string password;
    cin >> password; 

    if (readCredentials(username, password, role))  // Pass the username and password to verify role
    {
        return true;
    }

    cout << "Invalid username or password!" << endl;
    return false;
}

void addpatient() {
    ofstream file("patient.txt", ios::app); // Open patient.txt in append mode
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }
    int i=200;
    char username[i], name[i], gender[i], bloodGroup[i], medicalHistory[i], contactNo[i], address[i];

    cout << "Enter Username: "; cin >> username;
    cin.ignore(); // Clear input buffer
    cout << "Enter Full Name: "; cin.getline(name, i);
    cout << "Enter Gender: "; cin >> gender;
    cout << "Enter Blood Group: "; cin >> bloodGroup;
    cin.ignore();
    cout << "Enter Medical History: "; cin.getline(medicalHistory, i);
    cout << "Enter Contact Number: "; cin >> contactNo;
    cin.ignore();
    cout << "Enter Address: "; cin.getline(address, i);

    file << username << "," << name << "," << gender << "," << bloodGroup << "," 
         << medicalHistory << "," << contactNo << "," << address << "\n";

    cout << "Patient information saved to patient.txt successfully!" << endl;
    file.close();
}

string getField(string record, int field) {
    int commaCount = 1;  // Start counting from the first field
    string item = "";
    
    for (int x = 0; x < record.length(); x++) {
        if (record[x] == ',') {
            commaCount++;  // Increment when a comma is encountered
        } else if (commaCount == field) {
            item += record[x];  // Add the character to the item if it's the desired field
        }
    }
    return item;
}

void viewonepatient(const string &username)  // Accept the username as an argument
{
    system("cls");
    printHeader();
    fstream data;
    string record;
    data.open("patient.txt", ios::in);  // Open file for reading

    if (!data) {
        cout << "Error opening file!" << endl;
        return;
    }

    string uname, name, gender, bloodGroup, medicalHistory, contactNo, address;
    bool found = false;

    // Print the table header
    cout << "Username      Name           Gender    Blood Group    Medical History         Contact No     Address\n";
    cout << "-------------------------------------------------------------------------------------------------------\n";

    // Read the file and extract fields
    while (getline(data, record)) {
        uname = getField(record, 1);  // Get the username from the record

        if (uname == username) {  // If the username matches
            name = getField(record, 2);
            gender = getField(record, 3);
            bloodGroup = getField(record, 4);
            medicalHistory = getField(record, 5);
            contactNo = getField(record, 6);
            address = getField(record, 7);

            // Print the patient's information
            cout << left << setw(12) << username
                 << left << setw(20) << name
                 << left << setw(10) << gender
                 << left << setw(15) << bloodGroup
                 << left << setw(20) << medicalHistory
                 << left << setw(15) << contactNo
                 << left << setw(20) << address << endl;//used the stew function for better tabular representaion of data. the number written describes the word length . and left shows that it is alligned to left side.

            found = true;  // Mark the patient as found
            break;  
        }
    }

    if (!found) {
        cout << "\nPatient not found!" << endl;  // If no matching patient found
    }

    data.close();  // Close the file

    // Add a prompt here to pause before returning to the menu
    cout << "\nPress Enter to return to User Menu...";
    cin.ignore(); // To clear the newline left in the input buffer
    cin.get();    // Wait for the user to press Enter
}

void viewallpatient() {
    system("cls");
    printHeader();
    fstream data;
    string record;
    data.open("patient.txt", ios::in);  // Open file for reading

    if (!data) {
        cout << "Error opening file!" << endl;
        return;
    }

    string uname, name, gender, bloodGroup, medicalHistory, contactNo, address;
    bool found = false;

    // Print the table header
    cout << "Username      Name                 Gender    Blood Group    Medical History         Contact No     Address\n";
    cout << "--------------------------------------------------------------------------------------------\n";

    // Read the file and extract fields
    while (getline(data, record)) {
        uname = getField(record, 1);  // Get the username from the record
        name = getField(record, 2);
        gender = getField(record, 3);
        bloodGroup = getField(record, 4);
        medicalHistory = getField(record, 5);
        contactNo = getField(record, 6);
        address = getField(record, 7);

        // Print the patient's information
        cout << left << setw(12) << uname
             << left << setw(20) << name
             << left << setw(10) << gender
             << left << setw(15) << bloodGroup
             << left << setw(20) << medicalHistory
             << left << setw(15) << contactNo
             << left << setw(20) << address << endl;
    }

    data.close();  // Close the file
    cout << "\nPress Enter to return to Admin Menu...";
    cin.ignore(); // To clear the newline left in the input buffer
    cin.get();    // Wait for the user to press Enter
}
void updatePatientRecord() {
    system("cls");
    printHeader();
    fstream file("patient.txt", ios::in | ios::out);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    string username, record, newDetails[6];
    cout << "Enter Username of the patient to update: ";
    cin >> username;

    string tempFilename = "temp.txt";
    ofstream tempFile(tempFilename);
    bool found = false;

    while (getline(file, record)) {
        if (getField(record, 1) == username) {
            cout << "Updating details for " << username << ":\n";
            cout << "Enter New Full Name: ";
            cin.ignore(); getline(cin, newDetails[0]);
            cout << "Enter New Gender: "; cin >> newDetails[1];
            cout << "Enter New Blood Group: "; cin >> newDetails[2];
            cout << "Enter New Medical History: "; cin.ignore(); getline(cin, newDetails[3]);
            cout << "Enter New Contact Number: "; cin >> newDetails[4];
            cout << "Enter New Address: "; cin.ignore(); getline(cin, newDetails[5]);

            tempFile << username << "," << newDetails[0] << "," << newDetails[1] << "," << newDetails[2] << "," 
                     << newDetails[3] << "," << newDetails[4] << "," << newDetails[5] << "\n";
            found = true;
        } else {
            tempFile << record << "\n";
        }
    }

    file.close();
    tempFile.close();

    remove("patient.txt");
    rename("temp.txt", "patient.txt");

    if (found) cout << "Record updated successfully!\n";
    else cout << "Patient not found!\n";

    cout << "Press Enter to continue...";
    cin.ignore(); cin.get();
}
void searchPatientRecord() {
    system("cls");
    printHeader();
    fstream file("patient.txt", ios::in);
    if (!file) {
        cout<< "Error opening file!" << endl;
        return;
    }

    string username, record;
    cout << "Enter Username to search: "; cin >> username;
    bool found = false;

    while (getline(file, record)) {
        if (getField(record, 1) == username) {
            cout << "Record Found:\n";
            cout << "Full Details: " << record << endl;
            
            found = true;
            break;
        }
    }

    if (!found) cout << "No patient record found for username: " << username << endl;
    
    file.close();
    cout << "Press Enter to continue...";
    cin.ignore(); cin.get();
}
void updatePersonalInfo(const string &username) {
    updatePatientRecord();
}
void deleteUserAccount(const string &username) {
    system("cls");
    printHeader();
    ifstream file("credentials.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string record;
    bool deleted = false;
    while (getline(file, record)) {
        if (getField(record, 1) != username) {
            tempFile << record << "\n";
        } else {
            deleted = true;
        }
    }

    file.close();
    tempFile.close();

    remove("credentials.txt");
    rename("temp.txt", "credentials.txt");

    if (deleted) cout << "Account successfully deleted." << endl;
    else cout << "Account not found." << endl;

    cout << "Press Enter to continue...";
    cin.ignore(); cin.get();
}
void displayAvailableDoctors() {
    system("cls");
    printHeader();
    fstream file("doctors.txt", ios::in);
    if (!file) {
        cout << "Error opening doctors file!" << endl;
        return;
    }

    string record;
    cout << "\nAvailable Doctors:" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Doctor ID      Name                        Specialization" << endl;
    cout << "--------------------------------------------" << endl;
    while (getline(file, record)) {
        string doctorID = getField(record, 1);
        string name = getField(record, 2);
        string specialization = getField(record, 3);
        cout << left << setw(15) << doctorID
             << left << setw(30) << name
             << left << setw(25) << specialization << endl;
    }

    file.close();
    cout << "\nPress Enter to continue...";
    cin.ignore(); cin.get();
}void bookAppointment(const string &username) {
    system("cls");
    printHeader();
    displayAvailableDoctors();

    string doctorID, appointmentDate;
    cout << "\nEnter Doctor ID to book an appointment: ";
    cin >> doctorID;
    cout << "Enter Appointment Date (YYYY-MM-DD): ";
    cin >> appointmentDate;

    ofstream file("appointments.txt", ios::app);
    if (!file) {
        cout << "Error opening appointments file!" << endl;
        return;
    }

    file << username << "," << doctorID << "," << appointmentDate << "\n";
    cout << "\nAppointment booked successfully!" << endl;

    file.close();
    cout << "Press Enter to continue...";
    cin.ignore(); cin.get();
}

void viewAppointments() {
    system("cls");
    printHeader();
    fstream file("appointments.txt", ios::in);
    if (!file) {
        cout << "Error opening appointments file!" << endl;
        return;
    }

    string record;
    cout << "\nAppointments List:" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Patient Username      Doctor ID        Appointment Date" << endl;
    cout << "-----------------------------------------------------" << endl;
    while (getline(file, record)) {
        string username = getField(record, 1);
        string doctorID = getField(record, 2);
        string date = getField(record, 3);
        cout << left << setw(20) << username
             << left << setw(19) << doctorID
             << left << setw(25) << date << endl;
    }

    file.close();
    cout << "\nPress Enter to continue...";
    cin.ignore(); cin.get();
}
void addDoctorRecord() {
    system("cls");
    printHeader();
    string doctorID, name, specialization;

    cout << "Enter Doctor ID: ";
    cin >> doctorID;
    cout << "Enter Doctor Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Specialization: ";
    getline(cin, specialization);

    ofstream file("doctors.txt", ios::app);
    if (!file) {
        cout << "Error opening doctors file!" << endl;
        return;
    }

    file << doctorID << "," << name << "," << specialization << "\n";
    cout << "\nDoctor record added successfully!" << endl;

    file.close();
    cout << "Press Enter to continue...";
    cin.ignore(); cin.get();
}
