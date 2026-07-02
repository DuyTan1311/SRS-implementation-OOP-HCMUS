#include <iostream>
#include <string>
#include <list>
#include "Transcript.h"
#include "TranscriptEntry.h"
#include "Person.h"
#include "Section.h"
#include "Course.h"

using namespace std;

void Transcript :: addTranscriptEntry(Section* section, int grade){
    TranscriptEntry* newEntry = new TranscriptEntry(grade, section);
    this->entries.push_back(newEntry);
}

void Transcript :: addStudent(Student* student){
    if(this->student != nullptr) return;
    this->student = student;
}

const list<TranscriptEntry*>& Transcript :: getEntries(){
    return this->entries;
}

Student* Transcript :: getStudent(){
    return this->student;
}

int Transcript :: getGrade(string courseNo){
    for(TranscriptEntry* entry : this->getEntries()){
        if(entry->getSection()->getCourse()->getCourseNo() == courseNo){
            return entry->getGrade();
        }
    }
    return -1;
}

void Transcript :: detachStudent(){
    if(this->getStudent() == nullptr) return; // cần check null để tránh lặp vô hạn
    this->student = nullptr;
}

Transcript :: ~Transcript(){
    for(TranscriptEntry* entry : this->getEntries()){
        if(entry != nullptr){
            entry->detachTranscript();
            delete entry;
        }
    }
    this->entries.clear();
    Student* temp = this->getStudent();
    if(temp != nullptr){ // nếu Student bị delete trước rồi thì bỏ qua
        temp->detachTranscript();
    }
    this->detachStudent();
}

void Transcript :: display(){
    cout << "No\tSection\tGrade\n";
    int index = 1;
    for(TranscriptEntry* entry : this->getEntries()){
        cout << index << "\t";
        entry->display();
    }
}