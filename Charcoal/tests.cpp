#include <cmath>  // Include for math functions
#include <cstdint>
#include <iostream>
#include <vector>

#include "../Chalk/Chalk.hpp"
#include "Color.hpp"

/*
// Function to print a gradient between two colors with optional spin
void printGradient(const Color& color1, const Color& color2, int numSteps,
                   double spin = 0.0) {
    for (int i = 0; i < numSteps; ++i) {
        double t = static_cast<double>(i) / static_cast<double>(numSteps - 1);
        if (spin != 0.0) {
            double angle = 2 * M_PI * spin * t;
            // Rotate the hue by the specified angle
            double hue =
                atan2(color2.getG() - color1.getG(), color2.getR() - color1.getR());
            hue += angle;
            // Ensure hue is within [0, 2*pi]
            while (hue < 0) {
                hue += 2 * M_PI;
            }
            while (hue >= 2 * M_PI) {
                hue -= 2 * M_PI;
            }
            t = hue / (2 * M_PI);
        }
        Color interpolatedColor = Color::interpolate(color1, color2, t);
        std::cout << Chalk{}.rgb(interpolatedColor.getRGBA()).str("█");
    }
    std::cout << std::endl;
}
*/

int amain() {
    // Color color1(0xFF0000FF);  // Red
    // Color color2(0x000FF1FF);  // Blue

    uint32_t x = 0x123456;
    uint8_t y = 0xa;

    std::cout << std::to_string((int)y) << '\n';
    printf("%08X\n", x);

    // Print a gradient between red and blue
    // printGradient(color1, color2, 120);

    // Print a gradient between red and blue with a spin
    // printGradient(color1, color2, 120, 1.5);

    return 0;
}
