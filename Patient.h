
//
//  Patient.h
//  Patient
//
//  Created by Shaylee Broadfoot on 2023-03-04.
//

#ifndef Patient_h
#define Patient_h
#include <string>
#include <vector>
using namespace std;

class Patient
{
public:

    //Default constructor
    Patient();

    //Parameterized constructor
    Patient(string newName, string newBirthdate, int newhealthId, unsigned long newPhone, string newAddress);

    //Changes patient's name
    void setName(string newName);

    //Changes patient's birthdate
    void setBirthdate(string newBirthdate);

    //Changes patient's health ID #
    void setHealthId(int newHealthId);

    //Changes patient's phone number
    void setPhone(long newPhone);

    //Changes patient's address
    void setAddress(string newAddress);

    //Add's a new patient allergy
    void setAllergy(string newAllergy);

    //Add's a new patient medication
    void setMedication(string newMedication);

    //Accesses patient's name
    string getName();

    //Accesses patient's birthdate
    string getBirthdate();

    //Accesses patient's health ID #
    int getHealthId();

    //Accesses patient's phone number
    unsigned long getPhone();

    //Accesses patient's address
    string getAddress();

    //Accesses patient's allergies
    void getAllergies();

    //Accessess patient's medications
    void getMedications();

    //Removes an allergy from patient's list
    void removeAllergy(string oldAllergy);

    //Removes a medication from patient's list
    void removeMedication(string oldMedication);

    //Display's all of patient's data field's
    void display();

    //Adds patient data to excel
    void patientToExcel(Patient patient);

    void readPatientNames();

    void displayAllPatientData();

    void EditPatientMenu(string name);

    void createNewPatient();

    void deletePatient(string name);
private:

    string name; //Full name of patient
    string birthdate; //Birthdate of patient
    int healthId; //Patient's health care number
    unsigned long phone; //Patient's primary phone number
    string address; //Patient's residence address
    vector<string> allergies; //Vector holding patient's allergies
    vector<string> medications; //Vector holding patient's medications
};

#endif /* Patient_h */

