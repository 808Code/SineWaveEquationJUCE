#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    addAndMakeVisible(frequencySlider);
    frequencySlider.setRange(0, 5000.0);
    frequencySlider.setTextValueSuffix(" Hz");
    frequencySlider.onValueChange = [this] { 
       frequency = frequencySlider .getValue();
    };

    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", juce::dontSendNotification);
    frequencyLabel.attachToComponent(&frequencySlider, true);


    addAndMakeVisible(levelSlider);
    levelSlider.setRange(0, 10.0);

    addAndMakeVisible(levelLabel);
    levelLabel.setText("Noise Level", juce::dontSendNotification);
    levelLabel.attachToComponent(&levelSlider, true);

    setAudioChannels(2, 2);
    setSize (600, 400);
    
    
}

MainComponent::~MainComponent()
{
 
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    for (int i = 0; i <outputs;i++) {
        sineWave[i].prepareToPlay(sampleRate);
    }
}

void MainComponent::getNextAudioBlock (const juce::AudioSourceChannelInfo& bufferToFill)
{
    auto level = (float)levelSlider.getValue();
    auto levelScale = level * 2.0f;

    bufferToFill.clearActiveBufferRegion();
    for (int ch = 0; ch < outputs;ch++) {
        auto* outBuffer = bufferToFill.buffer->getWritePointer(ch);
        for (int s = 0; s < bufferToFill.buffer->getNumSamples();s++) {
            outBuffer[s] = sineWave[ch].getNextSample(frequency) * levelScale - level;
        }
    }
}

void MainComponent::releaseResources()
{
   
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

}

void MainComponent::resized()
{
    auto sliderLeft = 120;
    frequencySlider.setBounds(sliderLeft, 20, getWidth() - sliderLeft - 10, 20);
    levelSlider.setBounds(sliderLeft, 50, getWidth() - sliderLeft - 10, 20);
}
