////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012june13, creation for spisplitpatternplay
//
//
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////
#define _MIDIEVENT_H

#include <vector>
#include "portaudio.h"

class MidiEvent
{
public:
	float fTimeStamp;
	int iMessageType; //i.e. NoteOff=0, NoteOn=1
	int iChannel;
	int iValue1;
	int iValue2;

	MidiEvent();
	~MidiEvent();
	bool CreateNoteOn(std::string midifileline);
	bool CreateNoteOff(std::string midifileline);
	bool IsNoteOn();
	bool IsNoteOff();
	float GetTimeStampInMidiClockTicks();
};