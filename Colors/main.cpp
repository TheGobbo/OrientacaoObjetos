#include <cmath>
#include <iostream>
#include <list>

#include "../Chalk/Chalk.hpp"
#include "Color.hpp"

std::vector<Color> atlas = {Color(0xfeac5e), Color(0xc779d0), Color(0x4bc0c8)};
std::vector<Color> cristal = {Color(0xbdfff3), Color(0x4ac29a)};
std::vector<Color> teen = {Color(0x77a1d3), Color(0x79cbca), Color(0xe684ae)};
std::vector<Color> mind = {Color(0x473b7b), Color(0x3584a7), Color(0x30d2be)};
std::vector<Color> morning = {Color(0xff5f6d), Color(0xffc371)};
std::vector<Color> vice = {Color(0x5ee7df), Color(0xb490ca)};
std::vector<Color> passion = {Color(0xf43b47), Color(0x453a94)};
std::vector<Color> fruit = {Color(0xff4e50), Color(0xf9d423)};
std::vector<Color> instagram = {Color(0x833ab4), Color(0xfd1d1d), Color(0xfcb045)};
std::vector<Color> retro = {Color(0x3f51b1), Color(0x5a55ae), Color(0x7b5fac),
                            Color(0x8f6aae), Color(0xa86aa4), Color(0xcc6b8e),
                            Color(0xf18271), Color(0xf3a469), Color(0xf7c978)};
std::vector<Color> summer = {Color(0xfdbb2d), Color(0x22c1c3)};
std::vector<Color> rainbow = {Color(0xff0000), Color(0xff0100)};
std::vector<Color> pastel = {Color(0x74ebd5), Color(0x74ecd5)};

void block(Chalk style) {
    std::cout << style("███████") << std::endl;
    std::cout << style("███████") << std::endl;
    std::cout << style("███████") << std::endl;
}

void grad(const std::list<Chalk>& styles) {
    for (Chalk s : styles) std::cout << s("███████") << " ";
    std::cout << '\n';
    for (Chalk s : styles) std::cout << s("███████") << " ";
    std::cout << '\n';
    for (Chalk s : styles) std::cout << s("███████") << " ";
    std::cout << '\n';
}

void randGrad(int n) {
    Color c;
    Chalk chalk;
    for (int i = 0; i < n; i++) {
        c = Color::random();
        std::cout << chalk.rgb(c.getR(), c.getG(), c.getB()).str("█");
        // std::cout << c.toHex() << '\n';
        // std::cout << chalk.hex(c.toHex()).str("█");
    }
    std::cout << std::endl;
}

// Function to print a rainbow in the terminal
void printRainbow(int numColumns) {
    const int numColors = numColumns;  // Number of colors in the rainbow
    const int numRows = 1;             // Number of rows for each color

    // Iterate through the hues for the rainbow
    for (int hue = 0; hue < 360; hue += 360 / numColors) {
        // Convert hue to RGB values
        double hueDegrees = static_cast<double>(hue);
        double red, green, blue;
        double x = 1.0 - std::abs(std::fmod(hueDegrees / 60.0, 2.0) - 1.0);

        if (hueDegrees >= 0 && hueDegrees < 60) {
            red = 1.0;
            green = x;
            blue = 0.0;
        } else if (hueDegrees >= 60 && hueDegrees < 120) {
            red = x;
            green = 1.0;
            blue = 0.0;
        } else if (hueDegrees >= 120 && hueDegrees < 180) {
            red = 0.0;
            green = 1.0;
            blue = x;
        } else if (hueDegrees >= 180 && hueDegrees < 240) {
            red = 0.0;
            green = x;
            blue = 1.0;
        } else if (hueDegrees >= 240 && hueDegrees < 300) {
            red = x;
            green = 0.0;
            blue = 1.0;
        } else {
            red = 1.0;
            green = 0.0;
            blue = x;
        }

        // Use Chalk to print colored blocks
        // for (int row = 0; row < numRows; ++row) {
        // Chalk chalk;
        std::cout << Chalk{}
                         .rgb(static_cast<int>(red * 255), static_cast<int>(green * 255),
                              static_cast<int>(blue * 255))
                         .str("█");
        // }

        // Move to the next line
    }
    std::cout << std::endl;
}

// Function to print a gradient in a single line
void printGradient(const std::vector<Color>& colors, int numColumns) {
    const int numColors = colors.size();

    // Iterate through the columns
    for (int col = 0; col < numColumns; ++col) {
        double colorIndex =
            static_cast<double>(col) / static_cast<double>(numColumns - 1);
        colorIndex *= (numColors - 1);

        int index1 = static_cast<int>(std::floor(colorIndex));
        int index2 = std::min(index1 + 1, numColors - 1);

        double fraction = colorIndex - index1;

        const Color& color1 = colors[index1];
        const Color& color2 = colors[index2];

        // Interpolate between color1 and color2
        double red = (1.0 - fraction) * color1.getR() + fraction * color2.getR();
        double green = (1.0 - fraction) * color1.getG() + fraction * color2.getG();
        double blue = (1.0 - fraction) * color1.getB() + fraction * color2.getB();

        // Use Chalk to print colored blocks
        std::cout << Chalk{}
                         .rgb(static_cast<int>(red), static_cast<int>(green),
                              static_cast<int>(blue))
                         .str("█");
    }

    // Move to the next line
    std::cout << std::endl;
}

int main() {
    int n = 120;  // Number of columns for the gradient

    Chalk name = Chalk{}.bold().save();

    std::cout << name("atlas") << "\t\t";
    printGradient(atlas, n);
    std::cout << name("cristal") << "\t\t";
    printGradient(cristal, n);
    std::cout << name("teen") << "\t\t";
    printGradient(teen, n);
    std::cout << name("mind") << "\t\t";
    printGradient(mind, n);
    std::cout << name("morning") << "\t\t";
    printGradient(morning, n);
    std::cout << name("vice") << "\t\t";
    printGradient(vice, n);
    std::cout << name("passion") << "\t\t";
    printGradient(passion, n);
    std::cout << name("fruit") << "\t\t";
    printGradient(fruit, n);
    std::cout << name("instagram") << "\t";
    printGradient(instagram, n);
    std::cout << name("retro") << "\t\t";
    printGradient(retro, n);
    std::cout << name("summer") << "\t\t";
    printGradient(summer, n);
    std::cout << name("rainbow") << "\t\t";
    printGradient(rainbow, n);
    std::cout << name("pastel") << "\t\t";
    printGradient(pastel, n);

    // printRainbow(n);
    // printGradient(rainbow, n);
    // printGradient(test, n);

    // char teste[3];  // = "AB\0";
    // snprintf(teste, sizeof(teste), "AB");

    // std::cout << teste << '\n';
    // std::cout << std::string(teste) << '\n';

    // block(t1);

    // grad(s1);

    return 0;
}