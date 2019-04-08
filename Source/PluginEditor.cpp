/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Maggs_a2AudioProcessorEditor::Maggs_a2AudioProcessorEditor (Maggs_a2AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setSize (400, 300);
    
    freqSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 80, 12);
    freqSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    freqSlider.setRange(20.0f, 2000.0f);
    freqSlider.setTextValueSuffix("hz");
    
    freqSlider.addListener(this);
    addAndMakeVisible(freqSlider);
    freqSlider.setValue(300.0f);
    //freqSlider.setValue(processor.freqLevel.getTargetValue());
    
   
    
    mixSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mixSlider.setRange(0, 100.0);
    mixSlider.setTextValueSuffix("%");
    mixSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::red);
    
    mixSlider.addListener(this);
    addAndMakeVisible(mixSlider);
    
    addAndMakeVisible(mixLabel);
    mixLabel.setText("Wet/Dry Mix", dontSendNotification);
    mixLabel.attachToComponent(&mixSlider, false);
    
    
    
    
    
    //setResizable(true, true);
    
}

Maggs_a2AudioProcessorEditor::~Maggs_a2AudioProcessorEditor()
{
}

//==============================================================================
void Maggs_a2AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::royalblue);

    g.setColour (Colours::lemonchiffon);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
    
    //New Line of text
    g.setColour(Colours::aquamarine);
    g.setFont(Font ("Arial", 50.0f , Font::italic));
    g.drawFittedText("RingFreq", 10, 10, getWidth(), 50, Justification::topLeft, 1);
    
    
    //Draw Rectangle
    g.setColour(Colours::black);
    g.drawRect(4, 1, 205, 70, 5);
    g.fillRect(150, 100, 100, 100);
    
    
   
    
    
}

void Maggs_a2AudioProcessorEditor::resized()
{
    
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mixSlider.setBounds(60, 100 , 200, 100);
    
    freqSlider.setBounds(250, 100, 200, 120);
    
}
void Maggs_a2AudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &mixSlider)
    {
     //get the value on our current slider, Pass that value to the audio processor
        processor.mixLevel.setTargetValue(mixSlider.getValue());
       
    } else if (slider ==&freqSlider){
        
        //get the value on our current slider, Pass that value to the audio processor
        processor.freqLevel.setTargetValue(freqSlider.getValue());
    }
  
}

