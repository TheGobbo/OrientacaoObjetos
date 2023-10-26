#if !defined(COLOR_HPP)
#define COLOR_HPP

#include <assert.h>

#include <cmath>
#include <cstdint>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>

// Define a common structure for color components
typedef union {
    struct {
        uint8_t r, g, b, a;  // RGBA components
    };
    struct {
        uint16_t h;           // Hue (0-359)
        uint8_t s, l, alpha;  // Saturation, Lightness, Alpha
    };
} ColorComponents;

// Enum to specify the color model
enum class ColorModel { RGB, RGBA, HSL, HSLA, HSV, HSVA };

// Defaults to RGBA format
class Color {
   public:
    Color();
    Color(uint32_t rgba);
    Color(uint8_t r, uint8_t g, uint8_t b);
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    Color(ColorComponents color, ColorModel model);

    ~Color() = default;

    // Getter functions
    uint32_t getRGBA() const;
    uint32_t getRgb() const;
    uint32_t getHex() const;
    ColorComponents getHsl() const;
    std::string toStr() const;
    // // void getHlv() const;
    // // uint8_t getR() const;
    // // uint8_t getG() const;
    // // uint8_t getB() const;
    // // uint8_t getA() const;

    // // void setRGB(uint8_t r, uint8_t g, uint8_t b);
    // // void setRGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    // // void setRGBA(uint32_t rgba);
    // // void setRGB(uint32_t rgb);

    // setters
    Color& setRgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    Color& setRgb(uint32_t rgba);

    Color& setHsla(uint16_t h, uint8_t l, uint8_t s, uint8_t a);
    Color& setHsla(double h, double s, double l, double a);
    // Color& setHsl(ColorComponents color);

    /* --------------------------------------------------------------------------------
     * MODIFICATIONS
     * --------------------------------------------------------------------------------
     */

    // Color& desaturate(uint8_t amount);
    // Color& saturate(uint8_t amount);
    // Color& greyscale(uint8_t amount);
    // Color& lighten(uint8_t amount);
    // Color& brighten(uint8_t amount);
    // Color& darken(uint8_t amount);
    // Color& spin(int16_t amount);

    /* --------------------------------------------------------------------------------
     * COMBINATIONS (low priority)
     * --------------------------------------------------------------------------------
     */

    // Color& complement();                      // complement of current color
    // array<Color> polyad(number);              // number = # of array
    // array<Color> splitcomplement();           // ???
    // array<Color> analogous(results, slices);  // results = # of array, slices = ?
    // array<Color> monochromatic(results);      // results = # of array

    /* --------------------------------------------------------------------------------
     * CONVERSIONS
     * --------------------------------------------------------------------------------
     */

    // // std::string toHex() const;
    // // void toHSL(double& hue, double& saturation, double& lightness) const;
    // // void hslToRGBA(double hue, double saturation, double lightness);
    // // void rgbaToRGB(uint8_t& red, uint8_t& green, uint8_t& blue);

    // void toModel(ColorModel model);  // any to any

    Color& toRgb();
    Color& toHsl();
    void toHSL(double& hue, double& saturation, double& lightness) const;

    // Color& toHsl(ColorComponents color);

    //  rgbToHsl(r, g, b);
    //  hslToRgb(h, s, l);
    //  hue2rgb(p, q, t);
    //  rgbToHsv(r, g, b);
    //  hsvToRgb(h, s, v);
    //  rgbToHex(r, g, b, allow3Char);
    //  rgbaToHex(r, g, b, a, allow4Char);
    //  rgbaToArgbHex(r, g, b, a);

    /* --------------------------------------------------------------------------------
     * OPERATORS
     * --------------------------------------------------------------------------------
     */

    // + - / * Override

    /* --------------------------------------------------------------------------------
     * UTILITIES
     * --------------------------------------------------------------------------------
     */

    static Color random();
    // static Color interpolate(const Color& color1, const Color& color2, double t);
    // ?? mix = function(color1, color2, amount);
    // ?? readability = function(color1, color2);
    // ?? isReadable = function(color1, color2, wcag2);
    // ?? mostReadable = function(baseColor, colorList, args);

   private:
    ColorComponents m_color;  // color values
    ColorModel m_model;       // type of color model
    static uint32_t m_seed;   // seed for random generation

    static uint32_t pcg_hash();  // random seed sampler
};

#endif  // COLOR_HPP
