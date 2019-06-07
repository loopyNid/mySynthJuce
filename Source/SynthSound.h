/*
  ==============================================================================

    SynthSound.h
    Created: 4 Jun 2019 3:37:52pm
    Author:  budos

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int /*midiNoteNumber*/)
    {
        return true;
    }
    bool appliesToChannel (int /*midiChannel*/)
    {
        return true;
    }
};
