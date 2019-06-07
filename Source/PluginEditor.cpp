/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FirstPlugin2AudioProcessorEditor::FirstPlugin2AudioProcessorEditor (FirstPlugin2AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), oscGui (p), envGui (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (440, 200);

    addAndMakeVisible(&oscGui);
    addAndMakeVisible(&envGui);

}

FirstPlugin2AudioProcessorEditor::~FirstPlugin2AudioProcessorEditor()
{
}

//==============================================================================
void FirstPlugin2AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    // fill the whole window white
    g.fillAll (Colours::white);
    // set the current drawing colour to black
    g.setColour (Colours::black);
    // set the font size and draw text to the screen
}

void FirstPlugin2AudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();

    const int componentWidth = 200;
    const int componentHeight = 200;

    oscGui.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    envGui.setBounds(area.removeFromLeft(componentWidth +40).removeFromTop(componentHeight));


    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
