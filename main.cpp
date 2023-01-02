#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <vector>
#include "Person.h"
#include <sstream>

void tokenize(string const &str, const char delim,vector<string> &out)
{
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

list <Person> makeListOfPeople()
{

    list <Person> people;
    string next;
    do {

        string name,surname;


        cout<<"Write a name\n";
        cin>>name;
        cout<<"Write a surname\n";
        cin>>surname;

        int age;
        while (true){
            cout<<"Write age\n";


            cin>>age;
            if (age<100 && age>0) {break;}
            cout<< "Age is incorrect\n";
        }

        int height;
        while (true){
            cout<<"Write height in cm\n";
            cin >>height;
            if (height<230 && height>80) {break;}
            cout<< "Height is incorrect\n";
        }

        string education;
        while (true){
            cout<<"Choose education level\n For middle school - write 1 \n For high school - write 2\n For university - write 3\n";

            cin>>education;
            if (education=="1") {education = "MS"; break;}
            if (education=="2") {education = "HS"; break;}
            if (education=="3") {education = "UN"; break;}
            cout<< "Education is incorrect\n";
        }

        Person man = Person(name, surname , age, height, education);
        cout<<string(man)<<"\n";

        people.push_back(man);

        cout<<"If you want to add a person print 'Yes'\n";
        cin>>next;

    }while(next=="Yes");

    people.sort();
    return people;

}

void printToFile(string filename, list<Person> people){

    std::ofstream file;
    file.open(filename);
    for (Person man : people) {
        file<<string(man)<<"\n";
    }
    file.close();

}

list <Person> readListOfPeople(string filename){
    list <Person> people;
    ifstream file(filename);
    string line;
    while (getline(file, line)) {

        const char delim = ' ';
        vector<string> out;
        tokenize(line, delim, out);

        string name, surname, education;
        name = out[0];
        surname = out[1];
        int age = stoi(out[2]);
        int height = stoi(out[3]);
        education = out[4];

        Person man = Person(name, surname, age, height, education);
        cout << string(man) << endl;
        people.push_back(man);
    }
    return people;


}


int main() {

    string filename="people.txt";

    list<Person> people;

    people=makeListOfPeople();

    printToFile(filename, people);

    people=readListOfPeople(filename);


    return 0;

}