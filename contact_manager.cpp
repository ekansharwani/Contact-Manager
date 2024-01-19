#include <iostream>
#include <fstream>
using namespace std;

class temp{
    string name, phoneNo, address, description, search;
    fstream file;
    public:
    void addContact();
    void showAll();
    void searchContact(); //search by phone number
}obj;

int main(){

    char choice;

    cout << "A. Add Contact" << endl;
    cout << "B. Show all contacts" << endl;
    cout << "C. Search for Contact" << endl;
    cout << "D. Exit" << endl;

    cout << "Please enter you choice: ";
    cin >> choice;

    switch (choice)
    {
    case 'A':
    case 'a':
        obj.addContact();
        break;
    case 'B':
    case 'b':
        obj.showAll();
        break;
    case 'C':
    case 'c':
        obj.searchContact();
        break;
    case 'D':
    case 'd':
        return 0;
        break;
    
    default:
        cout << "Invalid Choice";
        break;
    }

    return 0;
}

void temp ::addContact() {
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Phone Number: ";
    getline(cin, phoneNo);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Description: ";
    getline(cin, description);

    file.open("data.csv", ios :: out | ios :: app);
    file<< name << "," << phoneNo << "," << address << "," << description << "\n";
    file.close();
 
}


void temp ::showAll(){
    file.open("data.csv", ios :: in);

    getline(file, name, ',');
    getline(file, phoneNo, ',');   
    getline(file, address, ',');
    getline(file, description, '\n');

    while (!file.eof())
    {
        cout << "Name: " << name << endl;
        cout << "Phone Number: " << phoneNo << endl;
        cout << "Address: " << address << endl;
        cout << "Description: " << description << endl;
        cout << endl;

        getline(file, name, ',');
        getline(file, phoneNo, ',');   
        getline(file, address, ',');
        getline(file, description, '\n');
    }

    file.close();
        
}

void temp ::searchContact() {
    cout << "Enter Phone number to search: ";
    getline(cin, search);

    file.open("data.csv", ios :: in);

    getline(file, name, ',');
    getline(file, phoneNo, ',');   
    getline(file, address, ',');
    getline(file, description, '\n');

    while (!file.eof())
    {
        if (phoneNo == search) {
            cout << "Name: " << name << endl;
            cout << "Phone Number: " << phoneNo << endl;
            cout << "Address: " << address << endl;
            cout << "Description: " << description << endl;
            cout << endl;
        }
        
        getline(file, name, ',');
        getline(file, phoneNo, ',');   
        getline(file, address, ',');
        getline(file, description, '\n');
    }
}