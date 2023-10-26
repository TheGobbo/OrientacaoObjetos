#include "Color.hpp"

void Color::toHSL(double& hue, double& saturation, double& lightness) const {
    // Normalize RGBA values to the range [0, 1]
    ColorComponents color;
    double r = color.r / 255.0;
    double g = color.g / 255.0;
    double b = color.b / 255.0;

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

uint32_t Color::m_seed = time(nullptr);

Color::Color() : m_model{ColorModel::RGBA} {
    this->m_color.r = 0;
    this->m_color.g = 0;
    this->m_color.b = 0;
    this->m_color.a = 0;
}

Color::Color(uint32_t rgba) : m_model{ColorModel::RGBA} { this->setRgb(rgba); }

/* --------------------------------------------------------------------------------
 * GETTERS
 * -------------------------------------------------------------------------------- */

// can also return rgba values
uint32_t Color::getRgb() const {
    assert(this->m_model == ColorModel::RGBA || this->m_model == ColorModel::RGB);
    // reassign later

    int rgba = 0;
    if (this->m_model == ColorModel::RGBA) {
        rgba += this->m_color.a;
    }

    rgba += (this->m_color.r << 24);
    rgba += (this->m_color.g << 16);
    rgba += (this->m_color.b << 8);

    return rgba;
}

// can also return hsla values
ColorComponents Color::getHsl() const {
    assert(this->m_model == ColorModel::HSLA || this->m_model == ColorModel::HSL);
    // translate later

    return this->m_color;
}

std::string Color::toStr() const {
    if (this->m_model == ColorModel::RGBA) {
        std::string result = "RGBA: ";
        char buffer[9];
        std::sprintf(buffer, "%08X", this->getRgb());
        return result + buffer;
    } else {
        std::string result = "HSL : ";
        ColorComponents hsl = this->getHsl();
        result += std::to_string(hsl.h) + ", ";
        result += std::to_string(hsl.s / 255.0) + ", ";
        result += std::to_string(hsl.l / 255.0);
        return result;
    }
}

/* --------------------------------------------------------------------------------
 * SETTERS
 * -------------------------------------------------------------------------------- */

Color& Color::setRgb(uint32_t rgba) {
    this->m_model = ColorModel::RGBA;

    this->m_color.r = (uint8_t)((rgba >> 24) & 0xFF);
    this->m_color.g = (uint8_t)((rgba >> 16) & 0xFF);
    this->m_color.b = (uint8_t)((rgba >> 8) & 0xFF);
    this->m_color.a = (uint8_t)(rgba & 0xFF);

    return *this;
}

// to use with rgb, set a = 0xff or 255
Color& Color::setRgba(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    this->m_model = ColorModel::RGBA;

    this->m_color.r = r;
    this->m_color.g = g;
    this->m_color.b = b;
    this->m_color.a = a;

    return *this;
}

// to use with hsl, set a = 0xff or 255;
Color& Color::setHsla(uint16_t h, uint8_t l, uint8_t s, uint8_t a) {
    this->m_model = ColorModel::HSLA;

    this->m_color.h = h;
    this->m_color.l = l;
    this->m_color.s = s;
    this->m_color.alpha = a;

    return *this;
}

Color& Color::setHsla(double h, double s, double l, double a) {
    this->m_model = ColorModel::HSLA;

    // Ensure s, l, and a are in the [0, 1] range
    s = std::max(0.0, std::min(1.0, s));
    l = std::max(0.0, std::min(1.0, l));
    a = std::max(0.0, std::min(1.0, a));

    // this->m_color.h = (uint16_t)(h * 65535.0 / 360.0);
    this->m_color.h = static_cast<uint16_t>(h) % 360;
    this->m_color.s = static_cast<uint8_t>(s * 255);
    this->m_color.l = static_cast<uint8_t>(l * 255);
    this->m_color.alpha = static_cast<uint8_t>(a * 255);

    return *this;
}

/* --------------------------------------------------------------------------------
 * CONVERSIONS
 * -------------------------------------------------------------------------------- */

Color& Color::toRgb() {
    if (this->m_model == ColorModel::RGB) {
        return *this;
    }

    double chroma = (1 - std::abs(2 * this->m_color.l - 1)) * this->m_color.s;
    double huePrime = this->m_color.h / 60.0;
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

    double lightnessAdjustment = this->m_color.l - chroma / 2.0;
    red += lightnessAdjustment;
    green += lightnessAdjustment;
    blue += lightnessAdjustment;

    uint8_t r = static_cast<uint8_t>(std::round(red * 255.0));
    uint8_t g = static_cast<uint8_t>(std::round(green * 255.0));
    uint8_t b = static_cast<uint8_t>(std::round(blue * 255.0));

    setRgba(r, g, b, 0xff);

    return *this;
}

Color& Color::toHsl() {
    if (this->m_model == ColorModel::HSL || this->m_model == ColorModel::HSLA) {
        return *this;
    }
    this->m_model = ColorModel::HSL;

    // Normalize RGBA values to the range [0, 1]
    double r = this->m_color.r / 255.0;
    double g = this->m_color.g / 255.0;
    double b = this->m_color.b / 255.0;
    // double a = this->m_color.a / 255.0;

    double maxVal = std::max(std::max(r, g), b);
    double minVal = std::min(std::min(r, g), b);

    double delta = maxVal - minVal;

    double hue, saturation, lightness;

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

    setHsla(hue, saturation, lightness, 1);

    return *this;
}

/* --------------------------------------------------------------------------------
 * UTILITIES
 * -------------------------------------------------------------------------------- */

Color Color::random() { return Color(Color::pcg_hash()); }

// PRIVATE
uint32_t Color::pcg_hash() {
    uint32_t state = Color::m_seed * 747796405u + 2891336453u;
    uint32_t word = ((state >> ((state >> 28u) + 4u)) ^ state) * 277803737u;
    Color::m_seed = (word >> 22u) ^ word;
    return Color::m_seed;
}

// Color& Color::setHsl(ColorComponents color) {
//     this->m_model = ColorModel::HSL;

// }

/*
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
    /*
   --------------------------------------------------------------------------------
     * MODIFIERS
     * -------------------------------------------------------------------------------- /

    // Spin takes a positive or negative amount within [-360, 360] indicating the
   change
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

    /*
   --------------------------------------------------------------------------------
     * CONVERSIONS
     * -------------------------------------------------------------------------------- /

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

    /*
   --------------------------------------------------------------------------------
     * COMBINATIONS
     * -------------------------------------------------------------------------------- /

    /*
   --------------------------------------------------------------------------------
     * UTILITIES
     * -------------------------------------------------------------------------------- /

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
    */