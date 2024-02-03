#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {

public:
    Employee(); // default constructor
    Employee(string);
    //~Employee();
    Employee(string, string, string, string, string, string); // default constructor with argument

    void setname(string); // mutator functions
    void setbirthd(string);
    void setaddress(string);
    void setposition(string);
    void setid(string);
    void setphone_n(string);
    void display_all();
    void display_names();
    void display();
    void new_Employee();
    void update_info(string, int);
    void delete_line_by_name();
    void uptae_file();
    void one_line(string name);

    string getname(); // accessor functions
    string getbirthd();
    string getaddress();
    string getposition();
    string getId();
    string getphone_n();
private:

    friend class EmployeeHandler;
    string name; // variable names
    string birthday;
    string address;
    string position;
    string Id;
    string Phonenumber;

};


class EmployeeHandler 
{
public:
    EmployeeHandler(std::string path) {
        employeeFilePath = path;
        loadEmployees();
    }

    bool loadEmployees() {
        ifstream input;
        // opens the file to be appended (data added to the last line)
        std::string line;
        input.open(employeeFilePath, ios::app);
        while (std::getline(input, line))
        {
            std::stringstream lineSS;
            lineSS << line;
            std::string item;
            std::vector<std::string> itemList;
            while (std::getline(lineSS, item, ',')) {
                itemList.push_back(item);
            }

            Employee e1;
            e1.name = itemList[0];
            e1.birthday = itemList[1];
            e1.address = itemList[2];
            e1.position = itemList[3];
            e1.Id = itemList[4];
            e1.Phonenumber = itemList[5];

            employeeList.push_back(e1);
        }
        input.close();
        return true;
    }
    bool saveEmployees() {
        ofstream output;
        output.open(employeeFilePath);//, std::ofstream::out | std::ofstream::trunc);

        for (int i = 0; i < employeeList.size(); i++) {
            output << employeeList[i].name << "," << employeeList[i].birthday << "," << employeeList[i].address << "," << employeeList[i].position << "," << employeeList[i].Id << "," << employeeList[i].Phonenumber << "\n";         
        }
        cout << "The database is updated with the new employee." << endl << endl;
        output.close();
        return true;
    }
    void getEmployeeList(std::vector<Employee>& Emp_list) { 
        employeeList.clear();
        loadEmployees();
        Emp_list = employeeList; 
    }
    void changeEmployeeName(string n_name, int position) {
        employeeList[position].name = n_name;
    }
    void changeEmployeeBday(string b_day, int position) {
        employeeList[position].birthday = b_day;
    }
    void changeEmployeeAddress(string n_address, int position) {
        employeeList[position].address = n_address;
    }
    void changeEmployeePosition(string n_pos, int position) {
        employeeList[position].position = n_pos;
    }
    void changeEmployeeId(string n_Id, int position) {
        employeeList[position].Id = n_Id;
    }
    void changeEmployeePhone(string n_phone, int position) {
        employeeList[position].Phonenumber = n_phone;
    }

private:

    std::string employeeFilePath;
    std::vector<Employee> employeeList;

};


#endif
