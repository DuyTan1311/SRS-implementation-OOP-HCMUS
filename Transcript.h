#pragma once
#include <string>
#include <list>

class TranscriptEntry;
class Student;
class Section;

class Transcript{
private:
    std::list<TranscriptEntry*> entries; //tra cứu bằng courseNo
    Student* student;
public:
    void addTranscriptEntry(Section* section, int grade);
    int getGrade(std::string courseNo);
    ~Transcript();

};