#include<iostream>
#include<string>
#include<list>
#include "Person.h"
#include "Section.h"
#include "Transcript.h"

using namespace std;

// Class Person
void Person :: setSsn(string ssn){
    this->ssn = ssn;
}
void Person :: setName(string name){
    this->name = name;
}

Person :: Person(){
    this->setSsn("none");
    this->setName("none");
}
Person :: Person(string ssn, string name){
    this->setSsn(ssn);
    this->setName(name);
}

string Person :: getSsn(){
    return this->ssn;
}
string Person :: getName(){
    return this->name;
}

// Class Student
void Student :: setMajor(string major){
    this->major = major;
}
void Student :: setDegree(string degree){
    this->degree = degree;
}

void Student :: setTranscript(Transcript* transcript){
    if(this->transcript != nullptr) return;
    this->transcript = transcript;
}

Student :: Student() : Person(){
    this->setMajor("none");
    this->setDegree("none");
}
Student :: Student(string ssn, string name, string major, string degree) : Person(ssn, name){
    this->setMajor(major);
    this->setDegree(degree);
}

string Student :: getMajor(){
    return this->major;
}
string Student :: getDegree(){
    return this->degree;
}
Transcript* Student :: getTranscript(){
    return this->transcript;
}

const list<Section*>& Student :: isEnrolledIn(){
    return this->sections;
}

void Student :: addSection(Section* section){
    for(Section* sec : this->isEnrolledIn()){
        if(sec == section){
            return;
        }
    }
    this->sections.push_back(section);
}
void Student :: dropSection(Section* section){
    this->sections.remove(section);
}

Student :: ~Student(){
    this->sections.clear();
}

void Student :: display(){
    //implement sau
}