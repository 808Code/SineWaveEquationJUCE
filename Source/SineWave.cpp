/*
  ==============================================================================

	SineWave.cpp
	Created: 31 Oct 2022 8:50:48am
	Author:  Dell

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SineWave.h"



void SineWave::prepareToPlay(double sampleRate) {
	period = 1.0f / sampleRate;
}

float SineWave::getNextSample(float frequency) {
	if (currentTime >= 1.0f) {
		currentTime = 0.0f;
	}
	float sample = std::sin(2.0 * juce::MathConstants<float>::pi * frequency * currentTime);
	currentTime += period;
	return sample;
}


