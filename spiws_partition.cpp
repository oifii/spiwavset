////////////////////////////////////////////////////////////////
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
//
//
//2012june13, creation for spisplitpatternplay
//
//
//nakedsoftware.org, spi@oifii.org or stephane.poirier@oifii.org
////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include <assert.h>
#include <vector>
//#include "portaudio.h"
#include "spiws_midievent.h"
#include "spiws_midieventset.h"
#include "spiws_wavset.h"
#include "spiws_partition.h"
using namespace std;
#include <string.h>

Partition::Partition()
{
	miditrackname = "";
	pWavSet = NULL;
}
Partition::~Partition()
{
	vector<MidiEventSet*>::iterator it;
	for(it=midieventsetvector.begin(); it<midieventsetvector.end(); it++)
	{
		if(*it!=NULL) 
		{
			delete *it;
		}
		else
		{
			assert(false);
		}
	}
	if(pWavSet) delete pWavSet;
}

float Partition::GetLengthInMidiClockTicks()
{
	vector<MidiEventSet*>::iterator it;
	//*it = midieventsetvector.back();
	it = midieventsetvector.end();
	it--;
	if(*it!=NULL) 
	{
		return (*it)->GetEndTimeStampInMidiClockTicks();
	}
	assert(false);
	return 0.0f;
}

void Partition::Play(PaStreamParameters* pPaStreamParameters)
{
	if(pWavSet)
	{
		pWavSet->Play(pPaStreamParameters);
	}
}

void Partition::LaunchScheduledPlay(int playerflag)
{
	char charBuffer2[WAVSET_CHARNAME_MAXLENGTH];
	char charBuffer3[WAVSET_CHARNAME_MAXLENGTH];
	char charBuffer5[10]={"/b"}; //release runs start with /b option which stands for background
	char charBuffer6[10]={"-q"}; //release runs sox.exe with -q option which stands for quiet
	#ifdef _DEBUG
			sprintf_s(charBuffer5,10-1,""); //debug runs start without /b option which stands for background
			sprintf_s(charBuffer6,10-1,""); //debug runs sox.exe without -q option which stands for quiet
	#endif //_DEBUG
	string filename = "temp_";
	filename += "partition_";
	filename += partitionname;
	filename += ".wav";
	pWavSet->WriteWavFile(filename.c_str());
	float numberofsecondsinplayback = pWavSet->GetWavSetLength();
	if(playerflag==USING_SOX)
	{
		////////////////////////////////////////
		// play partition wavset as is using sox 
		////////////////////////////////////////
		//int numRepeat = numberofsecondsinplayback/pWavSet->GetWavSetLength();
		int numRepeat = 1;
		//sprintf_s(charBuffer3,WAVSET_CHARNAME_MAXLENGTH-1,"start %s C:\\sox-14-3-2\\sox %s \"%s\" -d repeat %d",charBuffer5,charBuffer6,filename.c_str(),numRepeat);
		sprintf_s(charBuffer3,WAVSET_CHARNAME_MAXLENGTH-1,"start %s C:\\app-bin\\sox\\sox.exe %s \"%s\" -d repeat %d",charBuffer5,charBuffer6,filename.c_str(),numRepeat);
		system(charBuffer3);
	}
	else if(playerflag==USING_SPIPLAY)
	{
		////////////////////////////////////////////
		// play partition wavset as is using spiplay 
		////////////////////////////////////////////
		//sprintf_s(charBuffer3,WAVSET_CHARNAME_MAXLENGTH-1,"start %s C:\\spoirier\\oifii-org\\httpdocs\\ns-org\\nsd\\ar\\cp\\audio_spi\\spiplay\\Release\\spiplay.exe \"%s\" %f",charBuffer5,filename.c_str(),numberofsecondsinplayback);
		sprintf_s(charBuffer3,WAVSET_CHARNAME_MAXLENGTH-1,"start %s C:\\app-bin\\spiplay\\spiplay.exe \"%s\" %f",charBuffer5,filename.c_str(),numberofsecondsinplayback);
		system(charBuffer3);
	}
	else
	{
		assert(false);
	}
}

