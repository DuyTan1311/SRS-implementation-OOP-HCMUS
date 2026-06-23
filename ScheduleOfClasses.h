#pragma once
#include<string>
#include<list>
#include "Section.h"

class ScheduleOfClasses{
private:
    std::string semester;
    std::list<Section*> sections;
public:
    void setSemester(std::string sem);
    void addSection(Section* section);
    Section* findSection(std::string sectionNo);
    ScheduleOfClasses();
    ScheduleOfClasses(std::string semester);
    ~ScheduleOfClasses();
    std::string getSemester();
    const std::list<Section*>& getSections();
};