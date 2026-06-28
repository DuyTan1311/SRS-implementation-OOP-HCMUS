#pragma once
#include<string>
#include<list>

class Section;
class Transcript;

class Person{
private:
    std::string ssn;
    std::string name;
public:
    void setSsn(std::string ssn);
    void setName(std::string name);
    Person();
    Person(std::string ssn, std::string name);
    virtual ~Person(); // tránh lỗi memory leak khi dùng con trỏ class cha quản lý object con, ví dụ như Person* p = new Student()
    std::string getSsn();
    std::string getName();
    virtual void display() = 0;
};

class Student : public Person{
private:
    std::string major;
    std::string degree;
    std::list<Section*> sections;
    Transcript* transcript;
public:
    void setMajor(std::string major);
    void setDegree(std::string degree);
    void setTranscript(Transcript* transcript);
    Student();
    Student(std::string ssn, std::string name, std::string major, std::string degree);
    ~Student() override;
    std::string getMajor();
    std::string getDegree();
    Transcript* getTranscript();
    void addSection(Section* section);
    void dropSection(Section* section);
    void detachTranscript();
    const std::list<Section*>& isEnrolledIn();
    void display() override;
};