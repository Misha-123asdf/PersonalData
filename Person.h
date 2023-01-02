#include <string>
#include <iostream>
using namespace std;

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H


class Person {

public:

    string name;
    string surname;
    int age;
    float height;
    string education;

    Person(string name, string surname, int age, float height, string education);



    operator string() const;

    bool operator < (Person& person);

    ~Person();

protected:

private:

};


#endif //UNTITLED_PERSON_H
