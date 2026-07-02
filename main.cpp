#include <iostream>
#include <string>
#include <list>
#include "Person.h"
#include "Course.h"
#include "Section.h"
#include "Transcript.h"
#include "TranscriptEntry.h"
#include "ScheduleOfClasses.h"

using namespace std;

int main(){
    Course* oop = new Course("MTH10407", "OOP", 4);
    Section* oop23_24_3 = oop->scheduleSection("MTH10407-24-25-2", "Tue", "8:00AM", "F202", 100);
    Transcript* aliceTranscript = new Transcript();
    Student* alice = new Student("001", "Alice", "Maths", "Bachelor", aliceTranscript);
    oop23_24_3->enroll(alice);
    oop23_24_3->postGrade(alice, 9);
        
    Course* dsa = new Course("MTH10405", "DSA", 4);
    Section* dsa23_24_3 = dsa->scheduleSection("MTH10405-24-25-2", "Wed", "8:00AM", "E202A", 100);
    dsa23_24_3->enroll(alice);
    dsa23_24_3->postGrade(alice, 8);     
        
    alice->displayTranscript();

    delete oop;
    delete dsa;
    delete alice;
    delete aliceTranscript;
}