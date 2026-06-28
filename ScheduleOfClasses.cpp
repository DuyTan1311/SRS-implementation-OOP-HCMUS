#include "ScheduleOfClasses.h"
#include<string>
#include<list>
#include "Section.h"

using namespace std;

void ScheduleOfClasses :: setSemester(string sem){
    this->semester = sem;
}

void ScheduleOfClasses :: addSection(Section* section){
    this->sections.push_back(section);
}

void ScheduleOfClasses :: dropSection(Section* section){
    if(section == nullptr) return;
    this->sections.remove(section);
}

ScheduleOfClasses :: ScheduleOfClasses(){
    this->setSemester("none");
}
ScheduleOfClasses :: ScheduleOfClasses(string semester){
    this->setSemester(semester);
}

ScheduleOfClasses :: ~ScheduleOfClasses(){
    for(Section* sec : this->getSections()){
        if(sec != nullptr){
            sec->detachScheduleOfClasses();
        }
    }
    this->sections.clear();
}

string ScheduleOfClasses :: getSemester(){
    return this->semester;
}

const list<Section*>& ScheduleOfClasses :: getSections(){
    return this->sections;
}

Section* ScheduleOfClasses :: findSection(string sectionNo){
    for(Section* sec : this->getSections()){
        if(sec->getSectionNo() == sectionNo){
            return sec;
        }
    }
    return nullptr;
}