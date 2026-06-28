#pragma once

class Section;
class Transcript;

class TranscriptEntry{
private:
    int grade;
    Section* section;
    Transcript* transcript;
public:
    void setGrade(int grade);
    void setSection(Section* sec);
    void setTranscript(Transcript* trans);
    TranscriptEntry();
    TranscriptEntry(int grade, Section* section);
    ~TranscriptEntry();
    void detachTranscript();
    int getGrade();
    Transcript* getTranscript();
    Section* getSection();
};