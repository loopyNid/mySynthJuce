/*
  ==============================================================================

    Envelope.h
    Created: 6 Jun 2019 9:04:03pm
    Author:  budos

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//==============================================================================
/*
*/
class Envelope    : public Component,
                    public Slider::Listener
{
public:
    Envelope(FirstPlugin2AudioProcessor&);
    ~Envelope();

    void paint (Graphics&) override;
    void resized() override;

    void sliderValueChanged (Slider* slider) override;

private:
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> attackTree;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> releaseTree;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sustainTree;
    ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> decayTree;

    Slider attackSlider;
    Label attackLabel;
    Slider releaseSlider;
    Label releaseLabel;
    Slider sustainSlider;
    Label sustainLabel;
    Slider decaySlider;
    Label decayLabel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FirstPlugin2AudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Envelope)
};
