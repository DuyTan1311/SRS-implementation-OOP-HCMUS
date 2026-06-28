#pragma once
#include<string>
#include<list>

class Section;

class ScheduleOfClasses{
private:
    std::string semester;
    std::list<Section*> sections;
public:
    void setSemester(std::string sem);
    void addSection(Section* section);
    void dropSection(Section* section);
    Section* findSection(std::string sectionNo);
    ScheduleOfClasses();
    ScheduleOfClasses(std::string semester);
    ~ScheduleOfClasses();
    std::string getSemester();
    const std::list<Section*>& getSections();
};