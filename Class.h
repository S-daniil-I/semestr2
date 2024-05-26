#pragma once
#include <iostream>
#include <string>

using namespace std;

class Control {
public:
    Control(int x, int y, int width, int height);
    virtual void draw() const = 0;
    virtual bool isVisible() const;
    virtual void setVisible(bool value);

protected:
    int xPos, yPos;
    int width, height;
    bool visible = true;
};

class Ellipse : public Control {
public:
    Ellipse(int x, int y, int width, int height, int fillColor, int borderColor);
    void draw() const override;
private:
    int fill, border;
};

class HyperlinkLabel : public Control {
public:
    HyperlinkLabel(int x, int y, int width, int height, const string& url);
    void draw() const override;
private:
    string url;
};

class TextBox : public Control {
public:
    TextBox(int x, int y, int width, int height, const string& text, int color);
    void draw() const override;
    string getText() const;
    void setText(const string& newText);
private:
    string textBoxText;
    int textColor;
};

class Button : public Control {
public:
    Button(int x, int y, int width, int height, const string& toolTipText);
    void draw() const override;
private:
    string buttonToolTip;
};

