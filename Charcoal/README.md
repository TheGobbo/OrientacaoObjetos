# Charcoal

TODO
- Map functionality
- Fix toHex to apply the rgba, not only the rgb
- How to modify rgba to rgb (255,0,0,0.5) -> (128,0,0)
- toHsl translate rgba to hsla?
- Truecolor ansi16m (low priority)


https://github.com/bgrins/TinyColor
https://en.wikipedia.org/wiki/RGBA_color_model
USING THE RGBA8888 FORMAT & A uint16_t for auxiliar functions;

Modifiers:
lighten, brighten, darken, desaturate, saturate
greyscale, spin (!!!),

Combinations:
analogous, monochromatic, splitcomplement, triad,
tetrad, complement

Utilities:
random, Readability, clone(?)


### Color Modification Functions 
- Takes in as argument a value from 0 to 100 (except spin, which is from -360 to 360)

desaturate(amount)
saturate(amount)
greyscale(amount)
lighten(amount)
brighten(amount)
darken(amount)
spin(amount)

