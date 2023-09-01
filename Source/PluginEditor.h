/* JUCE Plugin Editor --- FRONT END --- */

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class MusicMagicAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        private juce::Timer,
                                        public juce::FileDragAndDropTarget,
                                        public juce::DragAndDropContainer
{
public:
    
    //constructor & destructor
    MusicMagicAudioProcessorEditor (MusicMagicAudioProcessor&);
    ~MusicMagicAudioProcessorEditor() override;
    
    //building window
    void paint (juce::Graphics&) override;
    void resized() override;
    
    //drag and drop files in:
    bool isInterestedInFileDrag (const juce::StringArray& files) override;
    void filesDropped (const juce::StringArray &files, int x, int y) override;
    
    
private:
    
    //input
    void initialiseInputComponents();
    juce::ToggleButton inputFocusButton;
    juce::TextButton input_load_box;
    juce::TextButton input_delete_button;
    void updateInputTrackDesign();
    
    //randomness
    juce::Slider RandomnessSlider;
    
    //actions
    juce::ToggleButton extendButton;
    juce::ToggleButton fillButton;
    juce::ToggleButton replaceButton;
    juce::ToggleButton generateButton;
    void toggleOn(juce::ToggleButton& onButton);
    
    //prompt
    juce::TextEditor userPrompt;
    
    //generate button
    juce::TextButton generate_music_button;
    void timerCallback() override;
    bool check_valid_request();
    void generate_request();
    void send_request(juce::String prompt, juce::String action, juce::String randomness);
    
    //output
    void initialiseOutputComponents();
    juce::ToggleButton outputFocusButton;
    juce::TextButton output_track_box;
    void mouseDrag(const juce::MouseEvent& event) override;
    juce::TextButton output_delete_button;
    void updateOutputTrackDesign();
        
    //other general
    void toggleIO(std::string IO);
    
    //XXX
    juce::TextButton selectOutput;
    
    // reference provided as quick way for editor to access processor object that created it.
    MusicMagicAudioProcessor& MusMagProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MusicMagicAudioProcessorEditor)
};
