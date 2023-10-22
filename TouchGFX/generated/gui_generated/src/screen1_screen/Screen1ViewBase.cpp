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

    angle_text.setXY(70, 53);
    angle_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    angle_text.setLinespacing(0);
    Unicode::snprintf(angle_textBuffer, ANGLE_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_4PYB).getText());
    angle_text.setWildcard(angle_textBuffer);
    angle_text.resizeToCurrentText();
    angle_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_R07P));
    add(angle_text);

    Radius_text.setXY(70, 97);
    Radius_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Radius_text.setLinespacing(0);
    Unicode::snprintf(Radius_textBuffer, RADIUS_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_GUNP).getText());
    Radius_text.setWildcard(Radius_textBuffer);
    Radius_text.resizeToCurrentText();
    Radius_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_ULBN));
    add(Radius_text);

    load_text.setXY(70, 147);
    load_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    load_text.setLinespacing(0);
    Unicode::snprintf(load_textBuffer, LOAD_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_NFHR).getText());
    load_text.setWildcard(load_textBuffer);
    load_text.resizeToCurrentText();
    load_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q4C2));
    add(load_text);

    SWL_text.setXY(70, 198);
    SWL_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    SWL_text.setLinespacing(0);
    Unicode::snprintf(SWL_textBuffer, SWL_TEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_OMG4).getText());
    SWL_text.setWildcard(SWL_textBuffer);
    SWL_text.resizeToCurrentText();
    SWL_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W3HT));
    add(SWL_text);

    textArea1.setXY(274, 53);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1DMU).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.resizeToCurrentText();
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_694V));
    add(textArea1);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{

}
