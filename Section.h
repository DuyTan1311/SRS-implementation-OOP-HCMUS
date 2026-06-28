#pragma once
#include <string>
#include <list>

class Course;
class ScheduleOfClasses;
class Student;

class Section{
private:
    std::string sectionNo;
    std::string dayOfWeek;
    std::string timeOfDay;
    std::string room;
    int seatingCapacity;
    Course* course;
    ScheduleOfClasses* scheduleOfClasses;
    list<Student*> students;
public:
    void setSectionNo(std::string no);
    void setDayOfWeek(std::string day);
    void setTimeOfDay(std::string time);
    void setRoom(std::string room);
    void setSeatingCapacity(int capacity);
    void setCourse(Course* course);
    void setScheduleOfClasses(ScheduleOfClasses* schedule);
    Section();
    Section(std::string sectionNo, std::string dayOfWeek, std::string timeOfDay, std::string room, int seatingCapacity);
    ~Section();
    std::string getSectionNo();
    std::string getDayOfWeek();
    std::string getTimeOfDay();
    std::string getRoom();
    Course* getCourse();
    int getSeatingCapacity();
    const std::list<Student*>& getStudents();
    ScheduleOfClasses* getScheduleOfClasses();
    void addStudent(Student* student);

    void drop(Student* student);
    void detachCourse();
    void detachScheduleOfClasses();

    bool enroll(Student* student); // hàm này cần class student để đăng ký, cần class transcript để check bảng điểm và môn tiên quyết
    bool postGrade(Student* student, int grade); // hàm này cần class student và transcript và transcriptEntry để thêm điểm môn vào bảng điểm sinh viên
    bool confirmSeatAvailability(); // kiểm tra xem số sinh viên hiện tại của lớp đã vượt quá capacity chưa
};