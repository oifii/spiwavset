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
using namespace std;

#define MIDIEVENT_NOTEOFF	0
#define MIDIEVENT_NOTEON	1

MidiEvent::MidiEvent()
{
	fTimeStamp = -1.0;
	iMessageType = -1; //i.e. NoteOff=0, NoteOn=1
	iChannel = -1;
	iValue1 = -1;
	iValue2 = -1;
}

MidiEvent::~MidiEvent()
{
}

bool MidiEvent::CreateNoteOn(string midifileline)
{
	fTimeStamp = -1.0;
	iMessageType = MIDIEVENT_NOTEON; //i.e. NoteOff=0, NoteOn=1
	iChannel = -1;
	iValue1 = -1;
	iValue2 = -1;
	size_t found = midifileline.find("On ch=");
	if (found!=string::npos)
	{
		string mystring = midifileline.substr(0, found);
		fTimeStamp = atof(mystring.c_str()); 
		size_t found2 = midifileline.find("n=");
		if (found2!=string::npos)
		{
			mystring = midifileline.substr(found+6, found2);
			iChannel = atoi(mystring.c_str());
			size_t found3 = midifileline.find("v=");
			if (found3!=string::npos)
			{
				mystring = midifileline.substr(found2+2, found3);
				iValue1 = atoi(mystring.c_str());
				mystring = midifileline.substr(found3+2, midifileline.size());
				iValue2 = atoi(mystring.c_str());
			}
		}
		return true;
	}
	return false;
}

bool MidiEvent::CreateNoteOff(string midifileline)
{
	fTimeStamp = -1.0;
	iMessageType = MIDIEVENT_NOTEOFF; //i.e. NoteOff=0, NoteOn=1
	iChannel = -1;
	iValue1 = -1;
	iValue2 = -1;

	string mystring;
	size_t found0 = midifileline.find("On ch=");
	size_t found = midifileline.find("Off ch=");
	if (found0!=string::npos)
	{
		mystring = midifileline.substr(0, found0);
	}
	if (found!=string::npos)
	{
		mystring = midifileline.substr(0, found);
	}
	if(found0!=string::npos || found!=string::npos)
	{
		fTimeStamp = atof(mystring.c_str()); 
		size_t found1 = midifileline.find("ch=");
		size_t found2 = midifileline.find("n=");
		size_t found3 = midifileline.find("v=");
		if (found1!=string::npos && found2!=string::npos && found3!=string::npos)
		{
			mystring = midifileline.substr(found1+3, found2-(found1+3));
			iChannel = atoi(mystring.c_str());
			mystring = midifileline.substr(found2+2, found3);
			iValue1 = atoi(mystring.c_str());
			mystring = midifileline.substr(found3+2, midifileline.size());
			iValue2 = atoi(mystring.c_str());
			
		}
		return true;
	}
	assert(false);
	return false;
}

bool MidiEvent::IsNoteOn()
{
	if(iMessageType==MIDIEVENT_NOTEON) return true;
	return false;
}

bool MidiEvent::IsNoteOff()
{
	if(iMessageType==MIDIEVENT_NOTEOFF) return true;
	return false;
}

float MidiEvent::GetTimeStampInMidiClockTicks()
{
	return fTimeStamp;
}
