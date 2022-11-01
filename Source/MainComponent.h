#pragma once

#include <JuceHeader.h>
#include "SineWave.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::AudioAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;

    //==============================================================================
    void paint (juce::Graphics& g) override;
    void resized() override;
    void setFrequency(float frequency);
    float getFrequency();

private:
    static constexpr int outputs{ 2 };
    SineWave sineWave[outputs];
    juce::Slider frequencySlider;
    juce::Slider levelSlider;
    juce::Label  frequencyLabel;
    juce::Label  levelLabel;
    float frequency{ 0.0f };
   

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
