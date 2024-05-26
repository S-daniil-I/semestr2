#include "Class.h"

Control::Control(int x, int y, int width, int height) : xPos(x), yPos(y), width(width), height(height) {}

bool Control::isVisible() const { return visible; }
void Control::setVisible(bool value) { visible = value; }

Ellipse::Ellipse(int x, int y, int width, int height, int fillColor, int borderColor) :
    Control(x, y, width, height), fill(fillColor), border(borderColor) {}

void Ellipse::draw() const {
    cout << "��������� �������..." << endl;
}

HyperlinkLabel::HyperlinkLabel(int x, int y, int width, int height, const string& url) :
    Control(x, y, width, height), url(url) {}

void HyperlinkLabel::draw() const {
    cout << "��������� ����� � ������������..." << endl;
}

TextBox::TextBox(int x, int y, int width, int height, const string& text, int color) :
    Control(x, y, width, height), textBoxText(text), textColor(color) {}

void TextBox::draw() const {
    cout << "��������� ���������� ����..." << endl;
}

string TextBox::getText() const { return textBoxText; }
void TextBox::setText(const string& newText) { textBoxText = newText; }

Button::Button(int x, int y, int width, int height, const string& toolTipText) :
    Control(x, y, width, height), buttonToolTip(toolTipText) {}

void Button::draw() const {
    cout << "��������� ������..." << endl;
}