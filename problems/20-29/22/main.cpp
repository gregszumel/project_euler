#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;


int nameVal(string name) {
    int namevalue = 0;
    for (int i = 0; i < name.size(); i++) {
        int lettervalue = int(name[i]) - int('A') + 1;
        // cout << name[i] << ": " << lettervalue << endl;
        namevalue += lettervalue;
    }
    return namevalue;
}


int main() {
    list<string> names;
    ifstream f;
    f.open("0022_names.txt", ios::in); //open a file to perform read operation using file object

    if (f.is_open()){ //checking whether the file is open
        string name;
        while(getline(f, name, ',')){ //read data from file object and put it into string.
            //  cout << name.substr(1, name.size()-2) << "\n"; //print the data of the string
            names.push_back(name.substr(1, name.size()- 2));
        }
        f.close(); //close the file object.
    }

    names.sort();
    int counter = 1;

    int valuecounter = 1;
    int total_sum = 0;
    for (string name: names) {
        total_sum += valuecounter * nameVal(name);
        valuecounter++;
    }
    cout << total_sum << endl; // 871198282
}