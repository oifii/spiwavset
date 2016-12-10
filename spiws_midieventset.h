////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012june13, creation for spisplitpatternplay
//
//
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////
#define _MIDIEVENTSET_H

class MidiEventSet
{
public:
	std::vector<class MidiEvent*> midieventvector;
	MidiEventSet(class MidiEvent* pMidiEventNoteOn, class MidiEvent* pMidiEventNoteOff);
	~MidiEventSet();
	float GetLengthInMidiClockTicks();
	float GetStartTimeStampInMidiClockTicks();
	float GetEndTimeStampInMidiClockTicks();
	int GetNoteNumber();
};