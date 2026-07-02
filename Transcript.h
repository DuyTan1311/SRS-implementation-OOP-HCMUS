#pragma once
#include <string>
#include <list>

class TranscriptEntry;
class Student;
class Section;
class Course;

class Transcript{
private:
    std::list<TranscriptEntry*> entries; //tra cứu bằng courseNo
    Student* student = nullptr;
public:
    void addTranscriptEntry(Section* section, int grade);
    void addStudent(Student* student);
    int getGrade(std::string courseNo);
    Student* getStudent();
    const std::list<TranscriptEntry*>& getEntries();
    void detachStudent();
    ~Transcript();
    void display();
};