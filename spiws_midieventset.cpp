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
#include <string>
#include <fstream>
#include <vector>

#include <iostream>
#include <sstream>
using namespace std;

//#include "portaudio.h"
#include "spiws_midievent.h"
#include "spiws_midieventset.h"

MidiEventSet::MidiEventSet(MidiEvent* pMidiEventNoteOn, MidiEvent* pMidiEventNoteOff)
{
	assert(pMidiEventNoteOn);
	assert(pMidiEventNoteOff);
	midieventvector.push_back(pMidiEventNoteOn);
	midieventvector.push_back(pMidiEventNoteOff);
}

MidiEventSet::~MidiEventSet()
{
	vector<MidiEvent*>::iterator it;
	for(it=midieventvector.begin(); it<midieventvector.end(); it++)
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
}

float MidiEventSet::GetLengthInMidiClockTicks()
{
	MidiEvent* pMidiEventNoteOn = NULL;
	MidiEvent* pMidiEventNoteOff = NULL;
	vector<MidiEvent*>::iterator it;
	for(it=midieventvector.begin(); it<midieventvector.end(); it++)
	{
		if(*it!=NULL) 
		{
			if((*it)->IsNoteOn())
			{
				assert(!pMidiEventNoteOn);
				pMidiEventNoteOn = *it;
			}
			if((*it)->IsNoteOff())
			{
				assert(!pMidiEventNoteOff);
				pMidiEventNoteOff = *it;
			}
		}
		else
		{
			assert(false);
		}
	}
	assert(pMidiEventNoteOn);
	assert(pMidiEventNoteOff);
	return pMidiEventNoteOff->GetTimeStampInMidiClockTicks()-pMidiEventNoteOn->GetTimeStampInMidiClockTicks();
}

float MidiEventSet::GetStartTimeStampInMidiClockTicks()
{
	MidiEvent* pMidiEventNoteOn = NULL;
	vector<MidiEvent*>::iterator it;
	for(it=midieventvector.begin(); it<midieventvector.end(); it++)
	{
		if(*it!=NULL) 
		{
			if((*it)->IsNoteOn())
			{
				assert(!pMidiEventNoteOn);
				pMidiEventNoteOn = *it;
				break;
			}
		}
		else
		{
			assert(false);
		}
	}
	assert(pMidiEventNoteOn);
	return pMidiEventNoteOn->GetTimeStampInMidiClockTicks();
}

float MidiEventSet::GetEndTimeStampInMidiClockTicks()
{
	MidiEvent* pMidiEventNoteOff = NULL;
	vector<MidiEvent*>::iterator it;
	for(it=midieventvector.begin(); it<midieventvector.end(); it++)
	{
		if(*it!=NULL) 
		{
			if((*it)->IsNoteOff())
			{
				assert(!pMidiEventNoteOff);
				pMidiEventNoteOff = *it;
			}
		}
		else
		{
			assert(false);
		}
	}
	assert(pMidiEventNoteOff);
	return pMidiEventNoteOff->GetTimeStampInMidiClockTicks();
}

int MidiEventSet::GetNoteNumber()
{
	MidiEvent* pMidiEvent = NULL;
	vector<MidiEvent*>::iterator it;
	for(it=midieventvector.begin(); it<midieventvector.end(); it++)
	{
		if(*it!=NULL) 
		{
			if((*it)->IsNoteOn() || (*it)->IsNoteOff())
			{
				assert(!pMidiEvent);
				pMidiEvent = *it;
				break;
			}
		}
		else
		{
			assert(false);
		}
	}
	assert(pMidiEvent);
	return pMidiEvent->iValue1;
}
