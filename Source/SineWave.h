/*
  ==============================================================================

    SineWave.h
    Created: 31 Oct 2022 9:35:03am
    Author:  Dell

  ==============================================================================
*/

#pragma once


class SineWave {
private:
    float period{ 0.0f };
    float currentTime{ 0.0f };
    
public:
    void prepareToPlay(double sampleRate);
    float getNextSample(float frequency);
   


};
