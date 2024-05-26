#include "Class.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    Ellipse ellipse(10, 20, 100, 50, 255, 0); // Эллипс с красным контуром и белым заливкой
    HyperlinkLabel hyperlinkLabel(30, 70, 200, 30, "https://example.com"); 
    TextBox textBox(50, 110, 150, 60, "Hello, World!", 0); // Текстовое поле с черным текстом
    Button button(130, 140, 80, 40, "Click Me!");

    // Вызов метода draw() для каждого элемента управления
    ellipse.draw();
    hyperlinkLabel.draw();
    textBox.draw();
    button.draw();

    return 0;
}
