/* JUCE Plugin Editor --- FRONT END --- */
#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

class MusicMagicAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                        private juce::Timer,
                                        public juce::FileDragAndDropTarget,
                                        public juce::DragAndDropContainer,
                                        public juce::Slider::Listener
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
    juce::TextButton input_load_box;
    juce::TextButton input_play_button;
    juce::TextButton input_stop_button;
    juce::TextButton input_delete_button;
    void initialiseInputComponents();
    void updateInputTrackDesign();
    //second input
    bool infillMode;
    juce::TextButton sec_input_load_box;
    juce::TextButton sec_input_play_button;
    juce::TextButton sec_input_stop_button;
    juce::TextButton sec_input_delete_button;
    void updateSecInputTrackDesign();
    
    //input1 precise segment selection
    juce::Slider firstStart;
    juce::Slider firstEnd;
    juce::TextButton firstStartCover;
    juce::TextButton firstEndCover;
    void sliderValueChanged(juce::Slider* slider) override;
    //input2 precise segment selection
    juce::Slider secStart;
    juce::Slider secEnd;
    juce::TextButton secStartCover;
    juce::TextButton secEndCover;
    
    //randomness
    juce::Slider RandomnessSlider;
    
    //actions
    juce::ToggleButton extendButton;
    juce::ToggleButton fillButton;
    juce::ToggleButton replaceButton;
    juce::ToggleButton generateButton;
    void toggleOn(juce::ToggleButton& onButton, juce::String action);
    
    //cumstom controls
    juce::Slider extendSlider;
    juce::Label customSliderLabel;
    
    //extend control
    juce::ToggleButton leftExtendButton;
    juce::ToggleButton rightExtendButton;
    void toggleSide(juce::ToggleButton& onButton, juce::String sideSelected);
    juce::String side;
    
    //prompt
    juce::TextEditor userPrompt;
    
    //generate
    juce::TextButton generate_music_button;
    bool sendingRequest;
    void timerCallback() override;
    void ui_red_update(juce::String msg);
    void ui_update_request_sent();
    void ui_request_success();
    void generate_request();
    
    //output
    juce::TextButton output_track_box;
    juce::TextButton output_play_button;
    juce::TextButton output_stop_button;
    juce::TextButton output_delete_button;
    void initialiseOutputComponents();
    void mouseDrag(const juce::MouseEvent& event) override;
    void updateOutputTrackDesign();
    
    //covers
    juce::TextButton input_cover;
    juce::TextButton randomiser_cover;
    juce::TextButton custom_slider_cover;
    juce::TextButton extend_cover;
    
    //reference to call processor functions
    MusicMagicAudioProcessor& MusMagProcessor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MusicMagicAudioProcessorEditor)
};
