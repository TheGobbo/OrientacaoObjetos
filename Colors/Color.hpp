#if !defined(COLOR_HPP)
#define COLOR_HPP

#include <cmath>
#include <cstdint>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>

// Format conversions:
// RGB, RGBA
// HSL, HSLA
// HSV, HSVA

// Modifiers:
// lighten, brighten, darken, desaturate, saturate
//  greyscale, spin (!!!),

// Combinations:
// analogous, monochromatic, splitcomplement, triad,
// tetrad, complement

// Utilities:
// random, Readability, clone(?)

// https://github.com/bgrins/TinyColor
// https://en.wikipedia.org/wiki/RGBA_color_model
// USING THE RGBA8888 FORMAT

/* TODO
- Fix toHex to apply the rgba, not only the rgb
- How to modify rgba to rgb (255,0,0,0.5) -> (128,0,0)

*/

class Color {
   public:
    Color() : rgba{0} {}
    // Constructor that accepts RGB format
    Color(uint8_t r, uint8_t g, uint8_t b) { setRGB(r, g, b); }
    // Constructor that accespts RGBA values
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) { setRGBA(r, g, b, a); }
    // Constructor that accepts an integer in hexadecimal format
    Color(uint32_t hexValue) {
        uint8_t r = static_cast<uint8_t>((hexValue >> 24) & 0xFF);
        uint8_t g = static_cast<uint8_t>((hexValue >> 16) & 0xFF);
        uint8_t b = static_cast<uint8_t>((hexValue >> 8) & 0xFF);
        uint8_t a = static_cast<uint8_t>(hexValue & 0xFF);

        setRGBA(r, g, b, a);
    }

    ~Color() = default;

    // Getter functions
    uint32_t getRGBA() const { return this->rgba; }
    uint8_t getR() const { return (this->rgba >> 24) & 0xFF; }
    uint8_t getG() const { return (this->rgba >> 16) & 0xFF; }
    uint8_t getB() const { return (this->rgba >> 8) & 0xFF; }
    uint8_t getA() const { return this->rgba & 0xFF; }

    void setRGB(uint8_t r, uint8_t g, uint8_t b) {
        this->rgba = r << 24 | g << 16 | b << 8;
    }
    void setRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
        this->rgba = r << 24 | g << 16 | b << 8 | a;
    }
    /* --------------------------------------------------------------------------------
     * MODIFIERS
     * -------------------------------------------------------------------------------- */

    // Spin takes a positive or negative amount within [-360, 360] indicating the change
    // of hue. Values outside of this range will be wrapped into this range. function
    // _spin(color, amount) {
    //     var hsl = tinycolor(color).toHsl();
    //     var hue = (hsl.h + amount) % 360;
    //     hsl.h = hue < 0 ? 360 + hue : hue;
    //     return tinycolor(hsl);
    // }
    // Function to adjust hue (spin)
    void spinHue(int degrees) {
        double hue, saturation, lightness;
        this->toHSL(hue, saturation, lightness);

        // Adjust the hue within the range [0, 360)
        hue += degrees;
        hue = fmod(hue, 360.0);
        if (hue < 0) {
            hue += 360.0;
        }

        // Update the RGBA color with the new HSL values
        hslToRGBA(hue, saturation, lightness);
    }

    /* --------------------------------------------------------------------------------
     * CONVERSIONS
     * -------------------------------------------------------------------------------- */

    std::string toHex() const {
        char hexString[8];  // 8 characters for RGBA + null terminator
        snprintf(hexString, sizeof(hexString), "#%02X%02X%02X", this->getR(),
                 this->getG(), this->getB());
        return std::string(hexString);
    }

    // Color toHsl() {}
    // Conversion function to get HSL values
    void toHSL(double& hue, double& saturation, double& lightness) const {
        // Normalize RGBA values to the range [0, 1]
        double r = this->getR() / 255.0;
        double g = this->getG() / 255.0;
        double b = this->getB() / 255.0;

        double maxVal = std::max(std::max(r, g), b);
        double minVal = std::min(std::min(r, g), b);

        double delta = maxVal - minVal;

        // Calculate lightness
        lightness = (maxVal + minVal) / 2.0;

        // Calculate saturation
        if (delta == 0.0) {
            saturation = 0.0;
        } else {
            saturation = delta / (1 - std::abs(2 * lightness - 1));
        }

        // Calculate hue
        if (delta == 0.0) {
            hue = 0.0;  // Undefined, but we can set it to 0.
        } else if (maxVal == r) {
            hue = 60.0 * fmod(((g - b) / delta + 6.0), 6.0);
        } else if (maxVal == g) {
            hue = 60.0 * (((b - r) / delta) + 2.0);
        } else {
            hue = 60.0 * (((r - g) / delta) + 4.0);
        }
    }

    // Conversion function to update RGBA from HSL
    void hslToRGBA(double hue, double saturation, double lightness) {
        double chroma = (1 - std::abs(2 * lightness - 1)) * saturation;
        double huePrime = hue / 60.0;
        double secondComponent = chroma * (1 - std::abs(fmod(huePrime, 2) - 1));
        double red, green, blue;

        if (huePrime >= 0 && huePrime < 1) {
            red = chroma;
            green = secondComponent;
            blue = 0;
        } else if (huePrime >= 1 && huePrime < 2) {
            red = secondComponent;
            green = chroma;
            blue = 0;
        } else if (huePrime >= 2 && huePrime < 3) {
            red = 0;
            green = chroma;
            blue = secondComponent;
        } else if (huePrime >= 3 && huePrime < 4) {
            red = 0;
            green = secondComponent;
            blue = chroma;
        } else if (huePrime >= 4 && huePrime < 5) {
            red = secondComponent;
            green = 0;
            blue = chroma;
        } else {
            red = chroma;
            green = 0;
            blue = secondComponent;
        }

        double lightnessAdjustment = lightness - chroma / 2.0;
        red += lightnessAdjustment;
        green += lightnessAdjustment;
        blue += lightnessAdjustment;

        uint8_t r = static_cast<uint8_t>(std::round(red * 255.0));
        uint8_t g = static_cast<uint8_t>(std::round(green * 255.0));
        uint8_t b = static_cast<uint8_t>(std::round(blue * 255.0));

        setRGB(r, g, b);
    }

    // Function to translate RGBA to RGB based on a background color
    void rgbaToRGB(uint8_t& red, uint8_t& green, uint8_t& blue) {
        red = static_cast<uint8_t>((1 - getA()) * getR() + getA() * getR());
        green = static_cast<uint8_t>((1 - getA()) * getG() + getA() * getG());
        blue = static_cast<uint8_t>((1 - getA()) * getB() + getA() * getB());
    }

    /* --------------------------------------------------------------------------------
     * COMBINATIONS
     * -------------------------------------------------------------------------------- */

    /* --------------------------------------------------------------------------------
     * UTILITIES
     * -------------------------------------------------------------------------------- */

    // Returns a new random Color, uses the pcg_hash as pseudo-random function
    static Color random() {
        return Color(Color::pcg_hash(), Color::pcg_hash(), Color::pcg_hash());
    }

    // Function to interpolate between two colors
    static Color interpolate(const Color& color1, const Color& color2, double t) {
        uint8_t red =
            static_cast<uint8_t>(color1.getR() + t * (color2.getR() - color1.getR()));
        uint8_t green =
            static_cast<uint8_t>(color1.getG() + t * (color2.getG() - color1.getG()));
        uint8_t blue =
            static_cast<uint8_t>(color1.getB() + t * (color2.getB() - color1.getB()));
        uint8_t alpha =
            static_cast<uint8_t>(color1.getA() + t * (color2.getA() - color1.getA()));
        return Color(red, green, blue, alpha);
    }

    // returns a gradient of colors
    // std::list<Color> gradient();

   private:
    static uint8_t seed;
    uint32_t rgba;
    // + (bit 0) Red|Green|Blue|Alpha (bit 32)

    static uint8_t pcg_hash() {
        uint8_t state = Color::seed * 747796405u + 2891336453u;
        uint8_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
        Color::seed = (word >> 22u) ^ word;
        return Color::seed;
    }
};

uint8_t Color::seed = time(nullptr);

#endif  // COLOR_HPP
