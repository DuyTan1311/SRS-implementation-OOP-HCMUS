#include <iostream>
#include <string>
#include <list>
#include "Transcript.h"
#include "TranscriptEntry.h"
#include "Person.h"
#include "Section.h"

void Transcript :: addTranscriptEntry(Section* section, int grade){
    TranscriptEntry* newEntry = new TranscriptEntry(grade, section);
    this->entries.push_back(newEntry);
}

