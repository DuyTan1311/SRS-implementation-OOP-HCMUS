#include "Course.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

void Course :: setCourseNo(string courseNo){
    this->courseNo = courseNo;
}

void Course :: setCourseName(string courseName){
    this->courseName = courseName;
}

void Course :: setCredits(int cred){
    this->credits = cred;
}

Course :: Course(){
    this->setCourseNo("none");
    this->setCourseName("none");
    this->setCredits(-1);
}

Course :: Course(string courseNo, string courseName, int cred){
    this->setCourseNo(courseNo);
    this->setCourseName(courseName);
    this->setCredits(cred);
}

string Course :: getCourseNo(){
    return this->courseNo;
}

string Course :: getCourseName(){
    return this->courseName;
}

int Course :: getCredits(){
    return this->credits;
}

const list<Course*>& Course :: getPrerequisites(){
    return this->prerequisites;
}

const list<Section*>& Course :: getSections(){
    return this->sections;
}

void Course :: addPrerequisites(Course* course){
    this->prerequisites.push_back(course);
}

bool Course :: hasPrerequisites(){
    return !this->prerequisites.empty();
}

void Course :: addSection(Section* section){
    this->sections.push_back(section);
}

Section* Course :: scheduleSection(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity){
    Section* newSection = new Section(sectionNo, dayOfWeek, timeOfDay, room, seatingCapacity);
    newSection->setCourse(this);
    this->addSection(newSection);
    return newSection;
}

Course :: ~Course(){
    for(Section* sec : this->getSections()){
        delete sec;
    }
    sections.clear();
    prerequisites.clear();
}