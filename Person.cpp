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

Person :: ~Person(){}

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
    this->transcript = transcript;
}

Student :: Student() : Person(){
    this->setMajor("none");
    this->setDegree("none");
    this->setTranscript(nullptr);
}
Student :: Student(string ssn, string name, string major, string degree, Transcript* transcript) : Person(ssn, name){
    this->setMajor(major);
    this->setDegree(degree);
    this->setTranscript(transcript);
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
    if(section == nullptr) return;
    this->sections.remove(section);
}

void Student :: detachTranscript(){
    if(this->getTranscript() == nullptr) return; // check null cho chắc

    this->setTranscript(nullptr);
}

Student :: ~Student(){
    for(Section* sec : this->isEnrolledIn()){
        if(sec != nullptr){
            sec->drop(this);
        }
    }
    this->sections.clear();
    Transcript* temp = this->getTranscript();
    if(temp != nullptr){ // nếu Transcript bị delete trước thì bỏ qua
        temp->detachStudent();
    }
    this->detachTranscript();
}

void Student :: display(){
    cout << "Student Name: " << this->getName() << endl;
    cout << "SSN: " << this->getSsn() << endl;
    cout << "Major: " << this->getMajor() << endl;
    cout << "Degree: " << this->getDegree() << endl;
}

void Student :: displayTranscript(){
    cout << "Student Name: " << this->getName() << endl;
    this->getTranscript()->display();
}