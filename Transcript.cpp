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

Transcript :: ~Transcript(){
    for(TranscriptEntry* entry : this->getEntries()){
        delete entry;
    }
    this->entries.clear();
}