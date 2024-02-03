#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Employee.h"
using namespace std;

string file_name = "D:\\TRUE\\SENG1210\\employees.csv";
EmployeeHandler handler = EmployeeHandler(file_name);

void Employee::display_all() { // displays all the data in the excel file
    std::vector<Employee> empList; 
    handler.getEmployeeList(empList);

    for (int i = 0; i < empList.size(); i++) {
        empList[i].display();
    }
}
void update_items(EmployeeHandler& handler, string name)
{   
    std::string update_info;
    bool state=false;
    vector<Employee> empList;
     handler.getEmployeeList(empList);

    for (int i = 0; i < empList.size(); i++) {
        if (empList[i].getname() == name)
        {
            state = true;
            empList[i].display();
            cout << "Input the information to update: ";
            getline(cin,update_info);
            handler.changeEmployeeName(update_info, i);
            break;
        }
    }
    if (!state)
    {
        std::cout << "Employee not found!" << endl;
    }
    else
    { 
        handler.saveEmployees();
    }
}
void Employee::update_info(string name, int info)
{
    std::string update_info;
    bool state = false;
    vector<Employee> empList;
    handler.getEmployeeList(empList);
    Employee eup;

    for (int i = 0; i < empList.size(); i++) {
        if (empList[i].getname() == name)
        {
            state = true; 
            cout << "\n\nPrevious information:\n ";
            empList[i].display();
            switch(info)
            {
            case 1:
                cout << "Input the updated name: ";
                getline(cin, update_info);
                handler.changeEmployeeName(update_info, i);
                break;
            case 2:
                cout << "Input the updated birthday(mm/dd/yyyy): ";
                getline(cin, update_info);
                handler.changeEmployeeBday(update_info, i);
                break;
            case 3:
                cout << "Input the updated address: ";
                getline(cin, update_info);
                handler.changeEmployeeAddress(update_info, i);
                break;
            case 4:
                cout << "Input the updated position: ";
                getline(cin, update_info);
                handler.changeEmployeePosition(update_info, i);
                break;
            case 5:
                cout << "Input the updated Id: ";
                getline(cin, update_info);
                handler.changeEmployeeId(update_info, i);
                break;
            case 6:
                cout << "Input the updated phonenumber: ";
                getline(cin, update_info);
                cin.ignore();
                handler.changeEmployeePhone(update_info, i);
                break;
            }
            break;
        }
    }
    if (!state)
    {
        std::cout << "Employee not found!" << endl;
    }
    else
    {
        handler.saveEmployees();
    }
}
void Employee::display_names() // a function to displays all the names in the excel files content
{
    string line;
    int count=0;
    ifstream myfile1(file_name);
    vector<string> data;
    while (getline(myfile1, line)) //for every line in input file
    {
        stringstream ss(line);  //copy line to stringstream
        string value;
        if (getline(ss, value, ',')) {
            data.push_back(value);
            count++;
        }
    }
    for (size_t i = 0; i < data.size(); ++i)
        cout << data[i] << '\n';
}
void Employee::one_line(string name)
{
    ifstream input(file_name);

    vector <string> lines;
    string one_line;

    while (getline(input, one_line)) { // reads line by line
        // if name is found in that line and not equal "not found"->(string::npos)
        if (one_line.find(name) != string::npos)
        {
            string field;
            stringstream ss(one_line);
            while (getline(ss, field, ',')) {
                // display based on ',' separation
                cout << field << setw(20);
            }
        }
        else // if 
            continue;
    }
    input.close();
}

Employee::Employee() {

}
Employee::Employee(string new_name) {
    name = new_name;
}
// default constructor with arguments setting for the parameters 
Employee::Employee(string new_name, string new_bday, string new_address, string new_posn, string new_id, string new_phone) {
    name = new_name;
    birthday = new_bday;
    address = new_address;
    position = new_posn;
    Id = new_id;
    Phonenumber = new_phone;
}
void Employee::setname(string new_name) { // mutator function for inputing employee name
    name = new_name;
}
void Employee::setbirthd(string new_bday) { // mutator function for inputing employee birthday
    birthday = new_bday;
}
void Employee::setaddress(string new_address) { // mutator function for inputing employee address
    address = new_address;
}
void Employee::setposition(string new_posn) { // mutator function for inputing employee position
    position = new_posn;
}
void Employee::setid(string new_id) {
    Id = new_id;
}
void Employee::setphone_n(string new_phone) {
    Phonenumber = new_phone;
}
string Employee::getname() { // accessor function for getting employee name
    return name;
}
string Employee::getbirthd() { // accessor function for getting employee birthdate
    return birthday;
}
string Employee::getaddress() {// accessor function for getting employee address
    return address;
}
string Employee::getposition() {// accessor function for getting employee position
    return position;
}
string Employee::getId() {
    return Id;
}
string Employee::getphone_n() {
    return Phonenumber;
}
// a function to display 1 employee's information
void Employee::display() 
{
    cout << name << setw(15 + (25 - name.size())) << birthday << setw(20) << address << setw(20) << position << setw(20) << Id << setw(20) << Phonenumber << endl; // separate the fields
}
void Employee::new_Employee()
{
    // prompts the user to input employee information

    cout << " Enter the Full name of the new employee \n ";
    cin.ignore();
    getline(cin, name);
    cout << " Enter the birthday of the new employee in (mm/dd/yy) format \n";
    cin >> birthday;
    cin.ignore();
    cout << " Enter the address of the new employee \n ";
    getline(cin, address);
    cout << "Enter the position of the new employee \n ";
    getline(cin, position);
    cout << " Enter the ID of the new employee \n ";
    getline(cin, Id);
    cout << " Enter the phone number of the new employee \n ";
    cin >> Phonenumber;
    cin.ignore(); // having this line will clear the cin statement for the next time, no need to write it repeatedly


    ofstream output;
    // opens the file to be appended (data added to the last line)
    output.open(file_name, ios::app);
    output << name << "," << birthday << "," << address << "," << position << "," << Id << "," << Phonenumber << "\n";

    output.close();
    cout << "The database is updated with teh new employee." << endl << endl;
    //display();
}

void Employee::delete_line_by_name()
{
    ifstream input(file_name); // open file as an input 

    vector <string> lines;
    string one_line;

    while (getline(input, one_line)) { // gets one line
        if (one_line.find(name) != string::npos)
        {
            // if it is the name to be deleted, don't puch back just skip it
            continue;
        }
        // push back the lines to the vector if it isn't the same name as the input
        lines.push_back(one_line);
    }
    input.close(); // close file

    //cout << "Employee deleted!!" << endl;

    ofstream output(file_name); // open file as output
    // give back the lines based on reference to the excel file
    for (const auto& n : lines)
    {
        output << n << endl;
    }
    output.close(); // close the file
}
void Employee::uptae_file() {

}



//int main() {
//
//    cout << endl << endl << endl;
//    // displays all the menu options
//    cout << " _________________________Welcome to the Royal Inland Hospital Information System_________________________" << endl << endl;;
//    cout << "Main menu \n1. Enter a new employee \n2. Remove an employee \n3. Display all employee information \n4. Display employee names ";
//    cout << "\n5. Update employee information  \n6. Display information of one employee " << endl;
//    cout << endl << endl;
//
//    EmployeeHandler employeeHandler = EmployeeHandler(file_name);
//
//    int menu_num;
//    for (;;) // infinite loop to make sure the number is between 1 and 7
//    {
//        cout << " Enter menu number here: ";
//        cin >> menu_num;
//        if (menu_num < 8 && menu_num>0) // condition to check menu number 1-7
//            break;
//        else
//            cout << "Invalid menu number, enter again." << endl;
//    }
//    cout << endl << endl;
//
//
//    switch (menu_num) {
//    case 1: //menu 1 will prompt user to enter a new employes information---------------------------DONE!!!!!!
//    {
//        Employee employee1;
//        employee1.new_Employee();
//    }
//    break;
//    case 2: //menu 2 will prompt user to input the name of an employee to be removed ---------------DONE!!!!!!
//    {
//        string del_name;
//        cout << "Enter the full name of the employee to be deleted: ";
//        cin.ignore();
//        getline(cin, del_name);
//        Employee employee2(del_name);
//        employee2.delete_line_by_name();
//        break;
//    }
// 
//    case 3:  // menu 3 will display all the information in the employee file -----------------------DONE!!!!!!!!
//        //display_all(employeeHandler);
//        break;
//    case 4: //menu 4 displays all employee names   --------------------------------------------------DONE!!!!!!!
//        //display_names();
//        break;
//    case 5: //menu 5 prompts user to enter the name of the user whose information will be updated
//    {
//        string name;
//        int information;
//        cout << "Enter name of person to update: ";
//        cin.ignore();
//        getline(cin, name);
//        cout << "\n\n  Update menu: \n\n1.Name\n2.Birthday\n3.Address\n4.Position\n5.Id\n6.Phone number\nChoose which informations to update:";
//        cin >> information;
//        cin.ignore();
//        //update_items(employeeHandler, name);
//        //update_info(employeeHandler, name, information);
//    }
//        break;
//    
//    case 6: // menu 6 displays one employee information ---------------------------------------------DONE!!!!!!!!
//        string emp_name;
//        cin.ignore();
//        cout << "Enter the name of employee whose information to display: ";
//        getline(cin, emp_name);
//        one_line(emp_name);
//        break;
//    }
//
//    cout << endl << endl << endl;
//
//    return 0;
//}
