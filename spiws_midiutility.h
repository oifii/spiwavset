/*
 * Copyright (c) 2010-2016 Stephane Poirier
 *
 * stephane.poirier@oifii.org
 *
 * Stephane Poirier
 * 3532 rue Ste-Famille, #3
 * Montreal, QC, H2X 2L1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef _MIDIUTILITY_H
#define _MIDIUTILITY_H

//midi note range from 0 to 127, from C -1 to G9
extern const char* notename[132]; //we use 132 to complete 9th octave
extern const float notefreq[132]; //we use 132 to complete 9th octave

int  GetMidiNoteNumberFromString(const char* pstring);
float GetFrequencyFromMidiNoteNumber(int midinotenumber);
int GetMidiNoteNumberFromFrequency(float frequency_hz);
#endif //_MIDIUTILITY_H