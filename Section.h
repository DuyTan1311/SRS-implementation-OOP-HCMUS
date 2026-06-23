#pragma once
#include <string>


class Course;
class ScheduleOfClasses;

class Section{
private:
    std::string sectionNo;
    std::string dayOfWeek;
    std::string timeOfDay;
    std::string room;
    int seatingCapacity;
    Course* course;
    ScheduleOfClasses* scheduleOfClasses;
    //list<Student*> students;
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
    std::string getSectionNo();
    std::string getDayOfWeek();
    std::string getTimeOfDay();
    std::string getRoom();
    Course* getCourse();
    int getSeatingCapacity();
    // void addStudent();
    // bool enroll(); // hàm này cần class student để đăng ký, cần class transcript để check bảng điểm và môn tiên quyết
    // void postGrade(); // hàm này cần class student và transcript và transcriptEntry để thêm điểm môn vào bảng điểm sinh viên
    // void drop();
    // void confirmSeatAvailability(); // kiểm tra xem số sinh viên hiện tại của lớp đã vượt quá capacity chưa
};