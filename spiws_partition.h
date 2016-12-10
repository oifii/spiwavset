////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012june13, creation for spisplitpatternplay
//
//
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////
#define _PARTITION_H

#include <vector>

#define USING_SOX		1
#define USING_SPIPLAY	2

class Partition
{
public:
	std::string miditrackname;
	std::string partitionname;
	std::vector<class MidiEventSet*> midieventsetvector;
	class WavSet* pWavSet;
	Partition();
	~Partition();
	float GetLengthInMidiClockTicks();
	bool CreateWavSet(class Instrument* pInstrument);
	//void Play(struct PaStreamParameters* pPaStreamParameters, class Instrument* pInstrument, float numberofsecondsinplayback);
	void Play(struct PaStreamParameters* pPaStreamParameters);
	void LaunchScheduledPlay(int usingflag);
};