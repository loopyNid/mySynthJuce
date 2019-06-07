/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"
#include "Envelope.h"

//==============================================================================
/**
*/
class FirstPlugin2AudioProcessorEditor  : public AudioProcessorEditor
{
public:
    FirstPlugin2AudioProcessorEditor (FirstPlugin2AudioProcessor&);
    ~FirstPlugin2AudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;



private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FirstPlugin2AudioProcessor& processor;

    Oscillator oscGui;
    Envelope envGui;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FirstPlugin2AudioProcessorEditor)
};
