/*
  ==============================================================================

    Oscillator.cpp
    Created: 6 Jun 2019 4:50:31pm
    Author:  budos

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(FirstPlugin2AudioProcessor& p) :
    processor(p)
{
    setSize(200,200);
    oscMenu.addItem("Sine", 1);
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);
    oscMenu.setJustificationType(Justification::centred);

    oscLabel.setText("Osc", dontSendNotification);
    oscLabel.attachToComponent(&oscMenu, true);
    oscLabel.setColour (Label::textColourId, Colours::black);
    oscLabel.setJustificationType (Justification::top);
    addAndMakeVisible(&oscLabel);

    waveSelection= new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{

}

void Oscillator::resized()
{
    Rectangle<int> area = getLocalBounds().reduced(40);

    oscMenu.setBounds(area.removeFromTop(20));

}

void Oscillator::comboBoxChanged(ComboBox* box)
{

}
