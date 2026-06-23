#pragma once
#include <string>
#include <list>

class Section;
class ScheduleOfClasses;

class Course{
private:
    std::string courseNo;
    std::string courseName;
    int credits;
    std::list<Course*> prerequisites;
    std::list<Section*> sections;   
public:
    void setCourseNo(std::string courseNo);
    void setCourseName(std::string courseName);
    void setCredits(int cred);
    Course();
    Course(std::string courseNo, std::string courseName, int cred);
    ~Course();
    std::string getCourseNo();
    std::string getCourseName();
    int getCredits();
    const std::list<Course*>& getPrerequisites(); // & là trả về tham chiếu, không cần phải sao chép tốn bộ nhớ
    const std::list<Section*>& getSections(); // const nghĩa là chỉ cho đọc, không cho ghi đè
    Section* scheduleSection(std::string sectionNo, std::string dayOfWeek, std::string timeOfDay, std:: string room, int seatingCapacity);
    void addPrerequisites(Course* course); // hàm này sẽ cần một class CourseDatabase bên ngoài nếu muốn add bằng CourseNo
    bool hasPrerequisites();
    void addSection(Section* section);
};