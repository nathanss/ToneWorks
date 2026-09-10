#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class ToneWorksAudioProcessorEditor final : public juce::AudioProcessorEditor
{
public:
    explicit ToneWorksAudioProcessorEditor(ToneWorksAudioProcessor&);
    ~ToneWorksAudioProcessorEditor() override = default;

    void paint(juce::Graphics& graphics) override;
    void resized() override;

private:
    juce::Label title;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToneWorksAudioProcessorEditor)
};
