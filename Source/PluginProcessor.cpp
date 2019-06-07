/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FirstPlugin2AudioProcessor::FirstPlugin2AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
       attackTime(0.1f),
       tree(*this, nullptr)
#endif
{
    NormalisableRange<float> attackParam (0.1f, 5000.0f);
    NormalisableRange<float> releaseParam (0.1f, 5000.0f);
    NormalisableRange<float> sustainParam (0.0f, 1.0f);
    NormalisableRange<float> decayParam (1.0f, 2000.0f);
    NormalisableRange<float> wavetypeParam (0, 2);

    tree.createAndAddParameter("attack", "Attack", "Attack", attackParam, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("release", "Release", "Release", releaseParam, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("sustain", "Sustain", "Sustain", releaseParam, 0.1f, nullptr, nullptr);
    tree.createAndAddParameter("decay", "Decay", "Decay", releaseParam, 1.0f, nullptr, nullptr);
    tree.createAndAddParameter("wavetype", "WaveType", "wavetype", wavetypeParam, 0, nullptr, nullptr);
    mySynth.clearVoices();
    // 5 voice synth
    for (int i = 0; i < 5; i++)
    {
        mySynth.addVoice (new SynthVoice());
    }
    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
}

FirstPlugin2AudioProcessor::~FirstPlugin2AudioProcessor()
{
}

//==============================================================================
const String FirstPlugin2AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FirstPlugin2AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FirstPlugin2AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FirstPlugin2AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FirstPlugin2AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FirstPlugin2AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FirstPlugin2AudioProcessor::getCurrentProgram()
{
    return 0;
}

void FirstPlugin2AudioProcessor::setCurrentProgram (int index)
{
}

const String FirstPlugin2AudioProcessor::getProgramName (int index)
{
    return {};
}

void FirstPlugin2AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FirstPlugin2AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    ignoreUnused(samplesPerBlock);
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void FirstPlugin2AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FirstPlugin2AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FirstPlugin2AudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    for (int i = 0; i < mySynth.getNumVoices(); i++)
    {
        if (myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i)))
        {
            myVoice->getParam(tree.getRawParameterValue("attack"), tree.getRawParameterValue("release"), tree.getRawParameterValue("sustain"), tree.getRawParameterValue("decay"));
            myVoice->getOscType(tree.getRawParameterValue("wavetype"));
        }
    }

    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool FirstPlugin2AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FirstPlugin2AudioProcessor::createEditor()
{
    return new FirstPlugin2AudioProcessorEditor (*this);
}

//==============================================================================
void FirstPlugin2AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FirstPlugin2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FirstPlugin2AudioProcessor();
}
