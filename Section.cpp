#include"Section.h"
#include <iostream>
#include <string>
#include<list>
#include "Course.h"
#include "ScheduleOfClasses.h"
#include "Person.h"
#include "Transcript.h"
#include "TranscriptEntry.h"

using namespace std;

void Section :: setSectionNo(string no){
    this->sectionNo = no;
}
void Section :: setDayOfWeek(string day){
    this->dayOfWeek = day;
}
void Section :: setTimeOfDay(string time){
    this->timeOfDay = time;
}
void Section :: setRoom(string room){
    this->room = room;
}
void Section :: setSeatingCapacity(int capacity){
    this->seatingCapacity = capacity;
}
void Section :: setCourse(Course* course){
    this->course = course;
}
void Section :: setScheduleOfClasses(ScheduleOfClasses* schedule){
    this->scheduleOfClasses = schedule;
}

Section :: Section(){
    this->setSectionNo("none");
    this->setDayOfWeek("none");
    this->setTimeOfDay("none");
    this->setRoom("none");
    this->setSeatingCapacity(-1);
}
Section :: Section(string sectionNo, string dayOfWeek, string timeOfDay, string room, int seatingCapacity){
    this->setSectionNo(sectionNo);
    this->setDayOfWeek(dayOfWeek);
    this->setTimeOfDay(timeOfDay);
    this->setRoom(room);
    this->setSeatingCapacity(seatingCapacity);
}

string Section :: getSectionNo(){
    return this->sectionNo;
}
string Section :: getDayOfWeek(){
    return this->dayOfWeek;
}
string Section :: getTimeOfDay(){
    return this->timeOfDay;
}
string Section :: getRoom(){
    return this->room;
}
int Section :: getSeatingCapacity(){
    return this->seatingCapacity;
}
Course* Section :: getCourse(){
    return this->course;
}

const list<Student*>& Section :: getStudents(){
    return this->students;
}

void Section :: addStudent(Student* student){
    for(Student* stu : this->getStudents()){
        if(stu == student){
            return;
        }
    }
    this->students.push_back(student);
}

void Section :: drop(Student* student){
    this->students.remove(student);
}

bool Section :: confirmSeatAvailability(){
    return this->students.size() < this->getSeatingCapacity();
}

bool Section :: enroll(Student* student){
    list<TranscriptEntry*> studentEntries = student->getTranscript()->getEntries();
    list<Course*> prerequisites = this->getCourse()->getPrerequisites();

    if(!this->confirmSeatAvailability()){
        cout << "Out of slots - Enroll failed." << endl;
        return false;
    }
    
    for(Course* course : prerequisites){
        TranscriptEntry* foundEntry = nullptr;
        for(TranscriptEntry* entry : studentEntries){
            if(entry->getSection()->getCourse() == course){
                foundEntry = entry;
                break;
            }
        }
        if(foundEntry == nullptr){
            cout << "Missing course in prerequisites - Enroll failed." << endl;;
            return false;
        }
        if(foundEntry->getGrade() < 5){
            cout << "Entry doesn't meet requirements - Enroll failed." << endl;
            return false;
        }
        cout << course->getCourseName() << " passed." << endl;
    }

    list<Section*> studentSections = student->isEnrolledIn();
    for(Section* sec : studentSections){
        if(sec == this){
            cout << "Student already enrolled this section - Enroll failed." << endl;
            return false;
        }
    }

    this->addStudent(student);
    student->addSection(this);
    cout << "Enroll successfully." << endl;
    return true;
}

bool Section :: postGrade(Student* student, int grade){
    Student* foundStudent = nullptr;
    for(Student* stu : this->getStudents()){
        if(stu == student){
            foundStudent = stu;
        }
    }
    if(foundStudent == nullptr){
        cout << "Student didn't attend this class or didn't exist - Post grade failed." << endl;
        return false; 
    }

    // student có tồn tại trong section tức là đã có đăng ký môn này, không cần check nữa

    Transcript* studentTranscript = foundStudent->getTranscript();
    studentTranscript->addTranscriptEntry(this, grade);
    cout << "Post grade successfully." << endl;
    return true;
}