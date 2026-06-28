#include<iostream>
#include "TranscriptEntry.h"

using namespace std;

void TranscriptEntry :: setGrade(int grade){
    this->grade = grade;
}
void TranscriptEntry :: setSection(Section* sec){
    this->section = section;
}
void TranscriptEntry :: setTranscript(Transcript* trans){
    this->transcript = trans;
}
TranscriptEntry :: TranscriptEntry(){
    this->setGrade(-1);
    this->setSection(nullptr);
}

TranscriptEntry :: TranscriptEntry(int grade, Section* section){
    this->setGrade(grade);
    this->setSection(section);
}

int TranscriptEntry :: getGrade(){
    return this->grade;
}
Section* TranscriptEntry :: getSection(){
    return this->section;
}
Transcript* TranscriptEntry :: getTranscript(){
    return this->transcript;
}

void TranscriptEntry :: detachTranscript(){
    if(this->getTranscript() == nullptr) return;
    this->setTranscript(nullptr);
}