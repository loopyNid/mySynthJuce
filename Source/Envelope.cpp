/*
  ==============================================================================

    Envelope.cpp
    Created: 6 Jun 2019 9:04:03pm
    Author:  budos

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(FirstPlugin2AudioProcessor& p) :
    processor(p)
{
    setSize(240, 200);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    // these define the parameters of our slider object
    attackSlider.setSliderStyle (Slider::LinearBarVertical);
    attackSlider.setRange(0.1f, 5000.0f);
    attackSlider.setValue(0.1f);
    attackSlider.addListener(this);
    addAndMakeVisible (&attackSlider);

    attackLabel.setText("A", dontSendNotification);
    attackLabel.attachToComponent(&attackSlider, true);
    attackLabel.setColour (Label::textColourId, Colours::orange);
    attackLabel.setJustificationType (Justification::bottom);
    addAndMakeVisible(&attackLabel);

    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.addListener(this);
    addAndMakeVisible(&releaseSlider);

    releaseLabel.setText("R", dontSendNotification);
    releaseLabel.attachToComponent(&releaseSlider, true);
    releaseLabel.setColour (Label::textColourId, Colours::black);
    releaseLabel.setJustificationType (Justification::bottom);
    addAndMakeVisible(&releaseLabel);

    decaySlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
    decaySlider.setRange(1.0f, 2000.0f);
    decaySlider.setValue(1.0f);
    decaySlider.addListener(this);
    addAndMakeVisible(&decaySlider);

    decayLabel.setText("D", dontSendNotification);
    decayLabel.attachToComponent(&decaySlider, true);
    decayLabel.setColour (Label::textColourId, Colours::purple);
    decayLabel.setJustificationType (Justification::bottom);
    addAndMakeVisible(&decayLabel);

    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearBarVertical);
    sustainSlider.setRange(0.0f, 1.0f);
    sustainSlider.setValue(0.0f);
    sustainSlider.addListener(this);
    addAndMakeVisible(&sustainSlider);

    sustainLabel.setText("S", dontSendNotification);
    sustainLabel.attachToComponent(&sustainSlider, true);
    sustainLabel.setColour (Label::textColourId, Colours::blue);
    sustainLabel.setJustificationType (Justification::bottom);
    addAndMakeVisible(&sustainLabel);

    attackTree = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "attack", attackSlider);
    releaseTree = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "release", releaseSlider);
    sustainTree = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "sustain", sustainSlider);
    decayTree = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "decay", decaySlider);

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    g.fillAll(Colours::white);

    g.setFont (15.0f);
    g.drawFittedText ("Envelope", 0, 0, getWidth(), 30, Justification::centred, 1);

}

void Envelope::resized()
{
    Rectangle<int> area = getLocalBounds();
    // This method is where you should set the bounds of any child
    // components that your component contains..
    attackSlider.setBounds (40, 30, 20, getHeight() - 60);
    decaySlider.setBounds (90, 30, 20, getHeight() - 60);
    sustainSlider.setBounds (140, 30, 20, getHeight() - 60);
    releaseSlider.setBounds (190, 30, 20, getHeight() - 60);
}

void  Envelope::sliderValueChanged(Slider* slider)
{
    // if (slider == &attackSlider)
    // {
    //     processor.attackTime = attackSlider.getValue();
    // }

    // if (slider == &releaseSlider)
    // {
    //     processor.releaseTime = releaseSlider.getValue();
    // }
    // if (slider == &sustainSlider)
    // {
    //     processor.sustainTime = sustainSlider.getValue();
    // }
    // if (slider == &decaySlider)
    // {
    //     processor.decayTime = decaySlider.getValue();
    // }
}
