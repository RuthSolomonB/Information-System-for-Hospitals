//
//  main.cpp
//  Patient
//
//  Created by Shaylee Broadfoot on 2023-03-04.
//
#include "Patient.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <cctype>
#include <fstream>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
using namespace std;

string ExcelLocation = "D:\\TRUE\\SENG1210\\Patient Profiles.csv";

//Default constructor
Patient::Patient()
{
    name = "New Patient";
    birthdate = "MM/DD/YYYY";
    healthId = -1;
    phone = -1;
    address = "No Address";
}

//Parameterized constructor
Patient::Patient(string newName, string newBirthdate, int newhealthId, unsigned long newPhone, string newAddress)
{
    name = newName;
    birthdate = newBirthdate;
    healthId = newhealthId;
    phone = newPhone;
    address = newAddress;
}

//Changes patient's name
void Patient::setName(string newName)
{
    name = newName;
}

//Changes patient's birthdate
void Patient::setBirthdate(string newBirthdate)
{
    birthdate = newBirthdate;
}

//Changes patient's health ID #
void Patient::setHealthId(int newHealthId)
{
    healthId = newHealthId;
}

//Changes patient's phone number
void Patient::setPhone(long newPhone)
{
    phone = newPhone;
}

//Changes patient's address
void Patient::setAddress(string newAddress)
{
    address = newAddress;
}

//Add's a new patient allergy
void Patient::setAllergy(string newAllergy)
{
    allergies.push_back(newAllergy);
}

//Add's a new patient medication
void Patient::setMedication(string newMedication)
{
    medications.push_back(newMedication);
}

//Accesses patient's name
string Patient::getName()
{
    return name;
}

//Accesses patient's birthdate
string Patient::getBirthdate()
{
    return birthdate;
}

//Accesses patient's health ID #
int Patient::getHealthId()
{
    return healthId;
}

//Accesses patient's phone number
unsigned long Patient::getPhone()
{
    return phone;
}

//Accesses patient's address
string Patient::getAddress()
{
    return address;
}

//Accesses patient's allergies
void Patient::getAllergies()
{
    for (int i = 0; i < allergies.size(); i++)
    {
        cout << allergies[i] << ", ";
    }
}

//Accessess patient's medications
void Patient::getMedications()
{
    for (int i = 0; i < medications.size(); i++)
    {
        cout << medications[i] << ", ";
    }
}

//Removes an allergy from patient's list
void Patient::removeAllergy(string oldAllergy)
{
    for (int i = 0; i < allergies.size(); i++)
    {
        if (oldAllergy == allergies[i])
        {
            allergies.erase(allergies.begin() + i);
            break;
        }
    }
}

//Removes a medication from patient's list
void Patient::removeMedication(string oldMedication)
{
    for (int i = 0; i < medications.size(); i++)
    {
        if (oldMedication == medications[i])
        {
            medications.erase(medications.begin() + i);
            break;
        }
    }
}

//Display's all of patient's data field's
void Patient::display()
{
    cout << "Full name: " << name << "\nBirth Date (MM/DD/YYYY): " << birthdate << "\nHealth Care Number: " << healthId << "\nPhone Number: " << phone << "\nAddress: " << address << endl;

    cout << "Allergies: ";
    for (int i = 0; i < allergies.size(); i++)
    {
        if (i == allergies.size() - 1)
            cout << allergies[i] << ".";

        else
            cout << allergies[i] << ", ";
    }

    cout << "\nMedications: ";
    for (int i = 0; i < medications.size(); i++)
    {
        if (i == medications.size() - 1)
            cout << medications[i] << ".";

        else
            cout << medications[i] << ", ";
    }
    cout << endl;
}

char* ultostr(unsigned long value, char* ptr, int base)
{
    unsigned long t = 0, res = 0;
    unsigned long tmp = value;
    int count = 0;

    if (NULL == ptr)
    {
        return NULL;
    }

    if (tmp == 0)
    {
        count++;
    }

    while (tmp > 0)
    {
        tmp = tmp / base;
        count++;
    }

    ptr += count;

    *ptr = '\0';

    do
    {
        res = value - base * (t = value / base);
        if (res < 10)
        {
            *--ptr = '0' + res;
        }
        else if ((res >= 10) && (res < 16))
        {
            *--ptr = 'A' - 10 + res;
        }
    } while ((value = t) != 0);

    return(ptr);
}

//Adds patient data to excel
void Patient::patientToExcel(Patient patient)
{
    ofstream excel;
    excel.open(ExcelLocation, ios::app);

    excel << "\n" << patient.getName() << "," << patient.getBirthdate() << "," << patient.getHealthId() << "," << patient.getPhone() << "," << patient.getAddress();

    excel.close();
    cout << "\nNEW PATIENT ADDED\n";
}

//...........................................................................................................
//...........................................................................................................

//Deletes patient from excel
void Patient::deletePatient(string name)
{
    vector<string> patientNames;
    string temp;
    vector<string> patientData;

    ifstream excelIn(ExcelLocation, ios::in);

    while (!excelIn.eof() && !excelIn.fail())
    {
        getline(excelIn, temp, ',');
        patientNames.push_back(temp);
        getline(excelIn, temp, '\n');
        patientData.push_back(temp);
    }

    excelIn.close();
    int count = 0;

    for (int i = 0; i < patientNames.size(); i++)
    {
        if (name == patientNames[i])
        {
            patientNames.erase(patientNames.begin() + i);
            patientData.erase(patientData.begin() + i);
            patientNames.resize(patientNames.size() - 1);
            ofstream excelOut(ExcelLocation, ios::out);

            for (int j = 0; j < patientNames.size(); j++)
            {
                if (count == 0)
                {
                    excelOut << patientNames[j] << "," << patientData[j];
                    count++;
                }
                else
                    excelOut << "\n" << patientNames[j] << "," << patientData[j];
            }

            excelOut.close();
            cout << "PATIENT REMOVAL COMPLETE\n";
            break;
        }

        else if (i == patientNames.size() - 1 && name != patientNames[i])
            cout << "PATIENT NOT FOUND.\n";
    }
}

//Creates a new patient object and writes to excel
void Patient::createNewPatient()
{
    string name, birthdate;
    string address = "";
    int healthId;
    unsigned long phone;

    cout << "Patient's full name:\n";
    cin.clear();
    cin.ignore();
    getline(cin, name);

    cout << "Patient's address:\n";
    cin.clear();
    //cin.ignore();
    getline(cin, address);

    cout << "Patient's date of birth (MM/DD/YYYY):\n";
    cin >> birthdate;

    cout << "Patient's health care number:\n";
    cin >> healthId;

    cout << "Patient's phone number:\n";
    cin >> phone;
    cin.clear();

    Patient patient(name, birthdate, healthId, phone, address);
    patient.patientToExcel(patient);
}

void sortPatients()
{
    vector<string> patientNames;
    string temp, smallest;
    vector<string> patientData;

    ifstream excelIn(ExcelLocation, ios::in);

    while (!excelIn.eof() && !excelIn.fail())
    {
        getline(excelIn, temp, ',');
        patientNames.push_back(temp);
        getline(excelIn, temp, '\n');
        patientData.push_back(temp);
    }

    excelIn.close();

    for (int i = 0; i <= patientNames.size(); i++)
    {
        for (int j = i + 1; j < patientNames.size(); j++)
        {
            if (patientNames[j] < patientNames[i])
            {
                smallest = patientNames[j];
                patientNames[j] = patientNames[i];
                patientNames[i] = smallest;

                smallest = patientData[j];
                patientData[j] = patientData[i];
                patientData[i] = smallest;
            }
        }
    }

    ofstream excelOut(ExcelLocation, ios::out);

    for (int j = 0; j < patientNames.size(); j++)
    {
        excelOut << "\n" << patientNames[j] << "," << patientData[j];
    }

    excelOut.close();
}

void Patient::readPatientNames()
{
    //sortPatients();
    vector<string> patientNames;
    string temp;
    vector<string> patientData;

    ifstream excelIn(ExcelLocation, ios::in);

    while (!excelIn.eof() && !excelIn.fail())
    {
        getline(excelIn, temp, ',');
        patientNames.push_back(temp);
        getline(excelIn, temp, '\n');
        patientData.push_back(temp);
    }

    excelIn.close();
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PATIENT NAMES~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    
    for (int i = 0; i < patientNames.size(); i++)
    {
        cout << patientNames[i] << endl;
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout << endl;
}

void Patient::displayAllPatientData()
{
    vector<string> names;
    vector<string> birthdates;
    vector<int> healthIds;
    vector<unsigned long> phones;
    vector<string> addresses;
    string temp;
    int temp1;
    unsigned long temp2;
    //sortPatients();
    string line, word;
    vector<string> row;
    vector<vector<string>> content;



    //ifstream excelIn(ExcelLocation);

    fstream file(ExcelLocation, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream ss(line);

            ss.str(line);

            while (getline(ss, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }

    file.close();

    int j = 0;
    for (size_t i = 0; i < content.size(); i++)
    {
        names.push_back(content[i][j]);
        birthdates.push_back(content[i][j + 1]);
        int string1 = stoi(content[i][j + 2]);
        unsigned long string2 = stoul(content[i][j + 3]);
        healthIds.push_back(string1);
        phones.push_back(string2);
        addresses.push_back(content[i][j + 4]);
    }

    //while (!excelIn.eof() && !excelIn.fail())
    //{
    //    getline(excelIn, temp, ',');
    //    names.push_back(temp);
    //    getline(excelIn, temp, ',');
    //    birthdates.push_back(temp);
    //    excelIn >> temp1;
    //    healthIds.push_back(temp1);
    //    excelIn >> temp2;
    //    phones.push_back(temp2);
    //    //excelIn >> temp;
    //    getline(excelIn, temp, '\n');
    //    addresses.push_back(temp);
    //}

    //excelIn.close();
    
    //std::cout << std::left << std::setw(25) << "Column 1" << std::setw(25) << "Column 2" << std::endl;
    //printf("%20s %12s %11s %12s %25s\n", "Full Name", "Birth Date", "Health ID", "Phone #", "Home Address");
    cout << "Full Name" << std::setw(26) << "Birth Date" << std::setw(11) << "Health ID" << std::setw(10) << "Phone #" << std::setw(18) << "Home Address" << "\n";
    cout << "********************************************************************************\n";

    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i].c_str() << std::setw(10 + (25 - names[i].size())) << birthdates[i].c_str() << "  " << healthIds[i] << "  " << phones[i] << "  " << addresses[i].c_str() << "\n";
    }


    cout << "***********************************************************************************\n";
    cout << endl;
}


void editPatient(string name, char dataField)
{
    vector<string> names;
    vector<string> birthdates;
    vector<int> healthIds;
    vector<long> phones;
    vector<string> addresses;
    string temp;
    int temp1;
    long temp2;
    string line, word;
    vector<string> row;
    vector<vector<string>> content;

    fstream file(ExcelLocation, ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream ss(line);

            ss.str(line);

            while (getline(ss, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }

    file.close();

    int j = 0;
    for (size_t i = 0; i < content.size(); i++)
    {
        names.push_back(content[i][j]);
        birthdates.push_back(content[i][j + 1]);
        int string1 = stoi(content[i][j + 2]);
        unsigned long string2 = stoul(content[i][j + 3]);
        healthIds.push_back(string1);
        phones.push_back(string2);
        addresses.push_back(content[i][j + 4]);
    }

    for (int i = 0; i < names.size(); i++)
    {
        if (name == names[i])
        {
            if (dataField == 'N')
            {
                cout << "Enter the patient's new name:\n";
                cin.ignore();
                getline(cin, temp);
                names[i] = temp;
            }

            else if (dataField == 'B')
            {
                cout << "Enter the patient's new birth date (MM/DD/YYYY):\n";
                cin.ignore();
                getline(cin, temp);
                birthdates[i] = temp;
            }

            else if (dataField == 'H')
            {
                cout << "Enter the patient's new health care number:\n";
                cin >> temp1;
                healthIds[i] = temp1;
            }

            else if (dataField == 'P')
            {
                cout << "Enter the patient's new phone number:\n";
                cin >> temp2;
                phones[i] = temp2;
            }

            else if (dataField == 'A')
            {
                cout << "Enter the patient's new home address:\n";
                cin.ignore();
                getline(cin, temp);
                addresses[i] = temp;
            }
        }
    }

    ofstream excelOut(ExcelLocation, ios::out);

    int count = 0;
    for (int j = 0; j < names.size(); j++)
    {
        if (count == 0)
        {
            excelOut << names[j] << "," << birthdates[j] << "," << healthIds[j] << "," << phones[j] << "," << addresses[j];
            count++;
        }
        else
            excelOut << "\n" << names[j] << "," << birthdates[j] << "," << healthIds[j] << "," << phones[j] << "," << addresses[j];
    }

    excelOut.close();

    cout << "\nUPDATE COMPLETE\n";
}

void clearScreen()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Patient::EditPatientMenu(string name)
{
    int choice;
    char field;

    //for (int i = 0; ; i++)
    //{
        cout << "............................................................................................\n";
        cout << "                                          MENU\n";
        cout << "............................................................................................\n";
        cout << "\n1: Edit Name\n\n2: Edit Birth Date\n\n3: Edit Health Care Number\n\n4: Edit Phone Number\n\n5: Edit Home Address\n\n";
        cin >> choice;
        //system("CLS");
        clearScreen();

        switch (choice)
        {
        case 1:
            field = 'N';
            editPatient(name, field);
            break;

        case 2:
            field = 'B';
            editPatient(name, field);
            break;

        case 3:
            field = 'H';
            editPatient(name, field);
            break;

        case 4:
            field = 'P';
            editPatient(name, field);
            break;

        case 5:
            field = 'A';
            editPatient(name, field);
            break;

        default:
            cout << "Please enter an option from the list:\n" << flush;
            break;
        }
    //}
}

//int main()
//{
//    string name, back;
//    int choice;
//    char cancel, field;
//
//    for (int i = 0; i < 100; i++)
//    {
//        cout << "--------------------------------------------------------------------------------------------------------------\n\n";
//        cout << "                                           PATIENT PROFILES\n";
//        cout << "--------------------------------------------------------------------------------------------------------------\n";
//        cout << "\n1: Patients\n\n2: Patient Information\n\n3: Edit Patient Information\n\n4: Add New Patient\n\n5: Delete Patient\n\n";
//        cout << "--------------------------------------------------------------------------------------------------------------\n\n";
//        cin >> choice;
//        //system("CLS");
//        clearScreen();
//
//        switch (choice)
//        {
//        case 1: //Displays patients names in alphabetical order
//            sortPatients();
//            readPatientNames();
//            printf("%-20s", "Enter 'B' to go back\n");
//            while (toupper(choice) != 'B')
//            {
//                cin >> choice;
//                clearScreen();
//            }
//
//            break;
//
//        case 2: //Displays all patient information in alphabetical order
//            displayAllPatientData();
//            printf("%-20s", "Enter 'B' to go back\n");
//            cin >> choice;
//            if (toupper(choice) == 'B')
//            {
//                clearScreen();
//                break;
//            }
//
//        case 3: //Allows you to edit a specific patient data field
//            cout << "/nEnter the patient's full name:/n";
//            getline(cin, name);
//
//            for (int i = 0; ; i++)
//            {
//                clearScreen();
//                //system("CLS");
//                cout << "............................................................................................\n";
//                cout << "                                          MENU\n";
//                cout << "............................................................................................\n";
//                cout << "\n1: Edit Name\n\n2: Edit Birth Date\n\n3: Edit Health Care Number\n\n4: Edit Phone Number\n\n5: Edit Home Address\n\n";
//                cin >> choice;
//                //system("CLS");
//                clearScreen();
//
//                switch (choice)
//                {
//                case 1:
//                    field = 'N';
//                    editPatient(name, field);
//                    break;
//
//                case 2:
//                    field = 'B';
//                    editPatient(name, field);
//                    break;
//
//                case 3:
//                    field = 'H';
//                    editPatient(name, field);
//                    break;
//
//                case 4:
//                    field = 'P';
//                    editPatient(name, field);
//                    break;
//
//                case 5:
//                    field = 'A';
//                    editPatient(name, field);
//                    break;
//
//                default:
//                    cout << "Please enter an option from the list:\n" << flush;
//                    break;
//                }
//            }
//
//        case 4: //Adds a new patient to file
//            createNewPatient();
//            break;
//
//        case 5: //Deletes a specified patient from file
//            cout << "/nEnter the patient's full name:\n";
//            getline(cin, name);
//
//            cout << "\nYou are about to permanently delete " << name << " from the system. Enter 'C' to cancel or press any key to continue:\n";
//            cin >> cancel;
//
//            if (toupper(cancel) == 'C')
//            {
//                clearScreen();
//                break;
//            }
//
//            else
//            {
//                deletePatient(name);
//                clearScreen();
//                break;
//            }
//
//        default:
//            cout << "Please enter an option from the list:\n";
//            break;
//        }
//    }
//}
