#include "Person.h"
#include <string>
#include <utility>


Person::Person(string name, string surname, int age, float height, string education):
        name(name), surname(surname), age(age), height(height), education(education){}


Person::operator string() const {
    return name + " " + surname + " " + to_string(age) + " " + to_string(height)  + " " + education;
}

bool Person::operator < (Person& person) {
    if (surname != person.surname) {
        return surname < person.surname;
    }

    return name < person.name;
}

Person::~Person(){}