/*
  ==============================================================================

    Oscillator.h
    Created: 6 Jun 2019 4:50:31pm
    Author:  budos

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Oscillator    : public Component,
                      private ComboBox::Listener
{
public:
    Oscillator(FirstPlugin2AudioProcessor&);
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;

    void comboBoxChanged(ComboBox*) override;

private:
    ComboBox oscMenu;
    Label oscLabel;

    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FirstPlugin2AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
