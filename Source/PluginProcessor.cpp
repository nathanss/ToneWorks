#include "PluginProcessor.h"
#include "PluginEditor.h"

ToneWorksAudioProcessor::ToneWorksAudioProcessor()
    : AudioProcessor(BusesProperties()
                         .withInput("Input", juce::AudioChannelSet::stereo(), true)
                         .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{
}

void ToneWorksAudioProcessor::prepareToPlay(double, int)
{
}

void ToneWorksAudioProcessor::releaseResources()
{
}

bool ToneWorksAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    const auto input = layouts.getMainInputChannelSet();
    const auto output = layouts.getMainOutputChannelSet();

    return input == output
        && (output == juce::AudioChannelSet::mono()
            || output == juce::AudioChannelSet::stereo());
}

void ToneWorksAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer,
                                           juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;

    for (auto channel = getTotalNumInputChannels();
         channel < getTotalNumOutputChannels();
         ++channel)
    {
        buffer.clear(channel, 0, buffer.getNumSamples());
    }
}

juce::AudioProcessorEditor* ToneWorksAudioProcessor::createEditor()
{
    return new ToneWorksAudioProcessorEditor(*this);
}

bool ToneWorksAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String ToneWorksAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool ToneWorksAudioProcessor::acceptsMidi() const
{
    return false;
}

bool ToneWorksAudioProcessor::producesMidi() const
{
    return false;
}

bool ToneWorksAudioProcessor::isMidiEffect() const
{
    return false;
}

double ToneWorksAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int ToneWorksAudioProcessor::getNumPrograms()
{
    return 1;
}

int ToneWorksAudioProcessor::getCurrentProgram()
{
    return 0;
}

void ToneWorksAudioProcessor::setCurrentProgram(int)
{
}

const juce::String ToneWorksAudioProcessor::getProgramName(int)
{
    return {};
}

void ToneWorksAudioProcessor::changeProgramName(int, const juce::String&)
{
}

void ToneWorksAudioProcessor::getStateInformation(juce::MemoryBlock&)
{
}

void ToneWorksAudioProcessor::setStateInformation(const void*, int)
{
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new ToneWorksAudioProcessor();
}
