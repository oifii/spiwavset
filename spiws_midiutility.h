#ifndef _MIDIUTILITY_H
#define _MIDIUTILITY_H

//midi note range from 0 to 127, from C -1 to G9
extern const char* notename[132]; //we use 132 to complete 9th octave
extern const float notefreq[132]; //we use 132 to complete 9th octave

int  GetMidiNoteNumberFromString(const char* pstring);
float GetFrequencyFromMidiNoteNumber(int midinotenumber);
int GetMidiNoteNumberFromFrequency(float frequency_hz);
#endif //_MIDIUTILITY_H