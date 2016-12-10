////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012june13, creation for spisplitpatternplay
//
//
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////
#define _PARTITIONSET_H

class PartitionSet
{
public:
	int mfile_format;
	int mfile_ntrks;
	int mfile_division;
	int timesig_numerator;
	int timesig_denominator;
	int timesig_midiclockspermetronomeclick;
	int timesig_numberofnotated32ndnotesperquaternote;
	float tempo_microsecondsperquaternote;
	std::vector<class Partition*> partitionvector;
	std::vector<class MidiEvent*> tempmidieventvector;
	PartitionSet();
	~PartitionSet();
	bool Populate(const char* midifile);
	bool IsStandardMidiFile(const char* filename);
	bool IsStandardMidiFileTxt(const char* filename);
	bool HasChannelNumber(string midifileline);
	bool HasNonZeroTimeStamp(string midifileline);
	bool IsTimeSig(string midifileline);
	bool IsTempo(string midifileline);
	bool IsMetaTrkName(string midifileline);
	bool IsNoteOn(string midifileline);
	bool IsNoteOff(string midifileline);
	class MidiEvent* CreateMidiEventNoteOn(string midifileline);
	class MidiEvent* CreateMidiEventNoteOff(string midifileline);
	void StoreNoteOn(class MidiEvent* pMidiEventNoteOn);
	class MidiEvent* RetreiveNoteOn(class MidiEvent* pMidiEventNoteOff);
	bool CreateWavSetForPartition(class Partition* pPartition, class Instrument* pInstrument, float numberofsecondsinplayback);
	void Play(struct PaStreamParameters* pPaStreamParameters, class InstrumentSet* pInstrumentSet, float numberofsecondsinplayback);
	float GetTempoInBPM();
	float GetLengthInSeconds();
	float ConvertMidiClockTicksToSeconds(int midiclockticks);
	float GetLengthInSeconds(class Partition* pPartition);
	float GetLengthInSeconds(class MidiEventSet* pMidiEventSet);
	float GetStartTimeStampInSeconds(class MidiEventSet* pMidiEventSet);
	float GetEndTimeStampInSeconds(class MidiEventSet* pMidiEventSet);
	bool HasOnePartition();
};