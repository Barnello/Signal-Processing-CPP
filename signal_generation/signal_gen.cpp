#include <iostream>
#include <fftw3.h>
#include <vector>
#include <cmath>

/// @brief This function is used for the signal generation of the sine wave 
/// @param frequency 
/// @param amplitude 
/// @param phase 
/// @param duration 
/// @param sampleRate 
/// @return signal  
std::vector<double> generateSineWave(double frequency, double amplitude, double phase, double duration, double sampleRate){
    std::vector<double> signal; //initialize signal variable
    int sampleCount = duration * sampleRate;
    for (int i = 0; i < sampleCount; ++i){
        double time = i / sampleRate;
        double value = amplitude * std::sin(2 * M_PI * frequency * time + phase);
        signal.push_back(value);
    }

    return signal;
}

///
std::vector<double> generateSquareWave(double frequency, double amplitude, double dutyCycle, double duration, double sampleRate) {
    std::vector<double> signal;
    int sampleCount = duration * sampleRate;
    int samplesPerPeriod = sampleRate / frequency;
    int highSamples = samplesPerPeriod * dutyCycle;
    for (int i = 0; i < sampleCount; ++i) {
        if (i % samplesPerPeriod < highSamples) {
            signal.push_back(amplitude);
        } else {
            signal.push_back(-amplitude);
        }
    }
    return signal;
}

int main(){

    std::vector<double> signal = generateSineWave(1000, 1.0, 0.0, 1.0, 44100);
    for (int i = 0; i < 1000; ++i){
        std::cout << signal[i] << std::endl;
    }
    return 0;
}