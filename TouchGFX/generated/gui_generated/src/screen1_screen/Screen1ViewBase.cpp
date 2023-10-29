/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase()
{
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    textArea1.setXY(274, 53);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1DMU).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.resizeToCurrentText();
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_694V));
    add(textArea1);

    RadiusValue.setXY(157, 232);
    RadiusValue.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    RadiusValue.setLinespacing(0);
    RadiusValueBuffer[0] = 0;
    RadiusValue.setWildcard(RadiusValueBuffer);
    RadiusValue.resizeToCurrentText();
    RadiusValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ULBN));
    add(RadiusValue);

    AngleValue.setXY(75, 201);
    AngleValue.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    AngleValue.setLinespacing(0);
    AngleValueBuffer[0] = 0;
    AngleValue.setWildcard(AngleValueBuffer);
    AngleValue.resizeToCurrentText();
    AngleValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_R07P));
    add(AngleValue);

    SWLValue.setXY(342, 18);
    SWLValue.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    SWLValue.setLinespacing(0);
    SWLValueBuffer[0] = 0;
    SWLValue.setWildcard(SWLValueBuffer);
    SWLValue.resizeToCurrentText();
    SWLValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W3HT));
    add(SWLValue);

    LoadValue.setXY(195, 170);
    LoadValue.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    LoadValue.setLinespacing(0);
    LoadValueBuffer[0] = 0;
    LoadValue.setWildcard(LoadValueBuffer);
    LoadValue.resizeToCurrentText();
    LoadValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q4C2));
    add(LoadValue);

    textArea2.setXY(274, 97);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea2.setLinespacing(0);
    Unicode::snprintf(textArea2Buffer, TEXTAREA2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_BQDJ).getText());
    textArea2.setWildcard(textArea2Buffer);
    textArea2.resizeToCurrentText();
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6ZBR));
    add(textArea2);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}
