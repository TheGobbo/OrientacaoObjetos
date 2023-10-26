#include <cmath>
#include <iostream>
#include <list>

#include "../Chalk/Chalk.hpp"
#include "Color.hpp"

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
        std::cout << chalk.rgb(c.getRgb()).str("█");
        // std::cout << c.toHex() << '\n';
        // std::cout << chalk.hex(c.toHex()).str("█");
    }
    std::cout << std::endl;
}

// Function to print a rainbow in the terminal
void printRainbow(int numColumns) {
    const int numColors = numColumns;  // Number of colors in the rainbow

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
/*
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
*/
using namespace std;

int main() {
    // printRainbow(120);

    // int n = 120;  // Number of columns for the gradient
    Chalk st = Chalk{}.bold().save();

    Color c1{0xfcba03};  // orange  (hsl: 44°, 98%, 50%)
    Color c2{0x1fad87};  // blue    (hsl: 164°, 70%, 40%)
    Color c3{0xe32b81};  // pink    (hsl: 332°, 77%, 53%)

    cout << hex << c1.toStr() << '\n';
    cout << hex << c2.toStr() << '\n';
    cout << hex << c3.toStr() << '\n';

    cout << c1.toHsl().toStr() << '\n';
    cout << c2.toHsl().toStr() << '\n';
    cout << c3.toHsl().toStr() << '\n';

    cout << hex << c1.toRgb().toStr() << '\n';
    cout << hex << c2.toRgb().toStr() << '\n';
    cout << hex << c3.toRgb().toStr() << '\n';

    // block(st.rgb(c1.getRgb()));
    // block(st.rgb(c1.getRgb()));
    // block(st.rgb(c1.getRgb()));

    return 0;
}