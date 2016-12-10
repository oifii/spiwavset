////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012june11, creation for spisplitpatternplay
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////
#define _INSTRUMENTSET_H

class InstrumentSet
{
public:
	std::vector<class Instrument*> instrumentvector;
	InstrumentSet();
	~InstrumentSet();
	void Populate(const char* wavfilesfolder, int iflag_subfolders=1);
	void Populate(std::vector<string>* wavfilenames);
	std::string GetFilenamePattern(const char* filename);
	bool IsNewFilenamePattern(const char* prevfilename, const char* newfilename);
	bool HasOneInstrument();
	int GetNumberOfInstrument();
	class Instrument* GetInstrumentFromID(int idinstrument);
	class Instrument* GetInstrumentRandomly();
	class Instrument* GetInstrumentFromMidiTrackName(class Partition* pPartition);
	void Play(struct PaStreamParameters* pPaStreamParameters,  float numberofsecondsinplayback, int numberofinstrumentsinplayback,  int iCONCATENATEATTACKSflag=1);
	bool OpenAllStreams(PaStreamParameters* pPaStreamInputParameters, PaStreamParameters* pPaStreamOutputParameters, PaStreamCallback* pPaStreamCallback);
	bool CloseAllStreams();
};