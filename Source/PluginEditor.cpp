#include "PluginEditor.h"

ToneWorksAudioProcessorEditor::ToneWorksAudioProcessorEditor(
    ToneWorksAudioProcessor& processor)
    : AudioProcessorEditor(&processor)
{
    title.setText("ToneWorks", juce::dontSendNotification);
    title.setFont(juce::FontOptions(32.0f, juce::Font::bold));
    title.setJustificationType(juce::Justification::centred);
    title.setColour(juce::Label::textColourId, juce::Colours::white);
    addAndMakeVisible(title);

    setSize(640, 360);
}

void ToneWorksAudioProcessorEditor::paint(juce::Graphics& graphics)
{
    graphics.fillAll(juce::Colour::fromRGB(28, 30, 34));
}

void ToneWorksAudioProcessorEditor::resized()
{
    title.setBounds(getLocalBounds());
}
