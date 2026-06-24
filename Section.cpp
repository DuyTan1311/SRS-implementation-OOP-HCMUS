#include"Section.h"
#include <string>
#include<list>
#include "Course.h"
#include "ScheduleOfClasses.h"
#include "Person.h"

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