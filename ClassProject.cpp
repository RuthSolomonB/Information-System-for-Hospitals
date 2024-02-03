//#include <iostream>
//#include "Employee.h"
//#include "Patient.h"
//#include <conio.h>
//
////#include "Patient.cpp"
////using namespace std;
//using std::cout;
//using std::cin;
//
//int MainMenuOption;
//int EmployeeMenuOption = 0;
//int PatientMenuOption = 0;
//
//string Excellocation = "D:\\TRUE\\SENG1210\\Passwords.csv";
//
//void MainMenu()
//{
//	MainMenuOption = 0;
//	cout << "MAIN MENU" << "\n";
//	cout << "1. Employee Profile" << "\n";
//	cout << "2. Patient Profile" << "\n";
//	cin.clear();
//	cin >> MainMenuOption;
//}
//
//// Function to read the CSV file
//vector<vector<string> > readCSV(string fileName) 
//{
//	vector<vector<string> > data;
//
//	// Open the CSV file
//	ifstream inputFile(fileName);
//
//	// Read the CSV file line by line
//	string line;
//	while (getline(inputFile, line)) {
//		vector<string> row;
//		stringstream lineStream(line);
//		string cell;
//
//		// Split the line into cells
//		while (getline(lineStream, cell, ',')) {
//			row.push_back(cell);
//		}
//
//		// Add the row to the data vector
//		data.push_back(row);
//	}
//
//	// Close the CSV file
//	inputFile.close();
//
//	return data;
//}
//
//// Function to write the CSV file
//void writeCSV(string fileName, vector<vector<string> > data) 
//{
//	// Open the CSV file
//	ofstream outputFile(fileName);
//
//	// Write the data to the CSV file
//	for (vector<string> row : data) {
//		for (int i = 0; i < row.size(); i++) {
//			outputFile << row[i];
//			if (i < row.size() - 1) {
//				outputFile << ",";
//			}
//		}
//		outputFile << endl;
//	}
//
//	// Close the CSV file
//	outputFile.close();
//}
//
//// Function to check if a username and password combination is valid
//bool checkCredentials(string username, string password) 
//{
//	// Read the user credentials from the CSV file
//	vector<vector<string> > users = readCSV(Excellocation);
//
//	// Check if the username and password combination exists in the CSV file
//	for (vector<string> user : users) {
//		if (user[0] == username && user[1] == password) {
//			return true;
//		}
//	}
//
//	return false;
//}
//
//// Function to change the password for a given username
//void changePassword(string username, string newPassword) 
//{
//	// Read the user credentials from the CSV file
//	vector<vector<string> > users = readCSV(Excellocation);
//
//	// Find the user with the given username and update their password
//	for (vector<string>& user : users) {
//		if (user[0] == username) {
//			user[1] = newPassword;
//		}
//	}
//
//	// Write the updated user credentials to the CSV file
//	writeCSV(Excellocation, users);
//}
//
//int main()
//{
//	// Get the username and password from the user
//	string username, password;
//	cout << "Enter your username: ";
//	cin >> username;
//	cout << "Enter your password: ";
//	cin >> password;
//
//	bool LoggedIn = false;
//
//	// Check if the username and password combination is valid
//	if (checkCredentials(username, password)) {
//		cout << "Login successful!" << endl;
//		LoggedIn = true;
//
//		// Ask the user if they want to change their password
//		string response;
//		cout << "Do you want to change your password? (y/n): ";
//		cin >> response;
//		if (response == "y") {
//			// Get the new password from the user
//			string newPassword;
//			cout << "Enter your new password: ";
//			cin >> newPassword;
//
//			// Change the password for the current user
//			changePassword(username, newPassword);
//
//			cout << "Password changed successfully!" << endl;
//		}
//	}
//	else 
//	{
//		cout << "Invalid username or password." << endl;
//	}
//
//	while (LoggedIn)
//	{
//		MainMenu();
//
//		switch (MainMenuOption)
//		{
//		case 1:
//			//Employee Profile Menu
//			system("cls"); // clear output screen
//			cout << "EMPLOYEE PROFILE" << "\n";
//			cout << "1. Create New Employee" << "\n";
//			cout << "2. Remove Employee" << "\n";
//			cout << "3. Employee Profile" << "\n";
//			cout << "4. Display All Employee Profiles" << "\n";
//			cout << "5. Display Employee Names" << "\n";
//			cout << "6. Update Existing Employee" << "\n";
//			cin >> EmployeeMenuOption;
//			break;
//		case 2:
//			//Patient Profile Menu
//			system("cls"); // clear output screen
//			cout << "PATIENT PROFILE" << "\n";
//			cout << "1. Display Patients Names" << "\n";
//			cout << "2. Display Patients Information" << "\n";
//			cout << "3. Edit Patient Information" << "\n";
//			cout << "4. Add New Patient" << "\n";
//			cout << "5. Delete Patient" << "\n";
//			cin >> PatientMenuOption;
//			break;
//		default:
//			break;
//		}
//
//		Employee Employee;
//		Patient Patient;
//		system("cls"); // clear output screen
//		//If Employee option selected send selection option off to Employee class. else patient class
//		if (EmployeeMenuOption != 0)
//		{
//			switch (EmployeeMenuOption)
//			{
//			case 1:
//			{
//				Employee.new_Employee();
//				cout << "New Employee Successfuly Added" << "\n";
//				break;
//			}
//			case 2:
//			{
//				string name;
//				cout << "Enter Name To Remove" << "\n";
//				cin >> name;
//				Employee.setname(name);
//				Employee.delete_line_by_name();
//				cout << "Employee deleted!!" << endl;
//
//				std::cin.clear();
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				break;
//			}
//			case 3:
//			{
//				string name;
//				cout << "Enter Name" << "\n";
//				cin >> name;
//				Employee.one_line(name);
//				break;
//			}
//			case 4:
//				Employee.display_all();
//				break;
//			case 5:
//				Employee.display_names();
//				break;
//			case 6:
//			{
//				string name;
//				int information;
//				cout << "Enter full name of person to update: ";
//				cin.ignore();
//				getline(cin, name);
//				cout << "\n\n  Update menu: \n\n1.Name\n2.Birthday\n3.Address\n4.Position\n5.Id\n6.Phone number\nChoose which informations to update:";
//				cin >> information;
//				cin.ignore();
//				Employee.update_info(name, information);
//				break;
//			}
//			default:
//				break;
//			}
//		}
//		else
//		{
//			switch (PatientMenuOption)
//			{
//			case 1:
//				Patient.readPatientNames();
//				break;
//			case 2:
//				Patient.displayAllPatientData();
//				break;
//			case 3:
//			{
//				string name;
//				cout << "Enter the patient's full name:" << "\n";
//				cin.ignore();
//				getline(cin, name);
//				Patient.EditPatientMenu(name);
//				break;
//			}
//			case 4:
//				Patient.createNewPatient();
//				break;
//			case 5:
//			{
//				string name;
//				cout << "Enter Name" << "\n";
//				cin.ignore();
//				getline(cin, name);
//				Patient.deletePatient(name);
//				break;
//			}
//			default:
//				break;
//			}
//		}
//
//		cout << "Press Enter to return to Main Menu or 0 to exit: ";
//		int input;
//		//cout << "Press Enter To Return To Main Menu" << "\n";
//#pragma warning(suppress : 4996)
//		input = getch();
//		if (input == 48)
//		{
//			LoggedIn = false;
//		}
//		system("cls"); // clear output screen
//	}
//	
//}