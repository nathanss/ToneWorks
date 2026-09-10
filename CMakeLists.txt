cmake_minimum_required(VERSION 3.22)

project(ToneWorks VERSION 1.0.0)

add_subdirectory(JUCE)

juce_add_plugin(ToneWorks
    COMPANY_NAME "BrendanLynskey"
    PLUGIN_MANUFACTURER_CODE Blyn
    PLUGIN_CODE Tnwk
    FORMATS VST3 Standalone
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD FALSE
    PRODUCT_NAME "ToneWorks")

juce_generate_juce_header(ToneWorks)

target_sources(ToneWorks PRIVATE
    Source/PluginEditor.cpp
    Source/PluginEditor.h
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h)

target_compile_features(ToneWorks PRIVATE cxx_std_17)

target_compile_definitions(ToneWorks PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(ToneWorks PRIVATE
    juce::juce_audio_utils
    juce::juce_dsp
    juce::juce_recommended_config_flags
    juce::juce_recommended_warning_flags)
