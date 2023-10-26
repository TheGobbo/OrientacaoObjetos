// Load the tinycolor library
const tinycolor = require('./tinycolors.js');

// Your code here

// For example, you can create a tinycolor object and use its functionality
const color = tinycolor("#f01");
console.log('Original color:', color.toHexString());

// for (let index = 0; index < 20; index++) {
//     color.spin(0.1);
//     console.log(color.toHexString());
// }

console.log('\nFinal color hex : ' + color.toHex());
console.log('Final color hex : ' + color.toHex8());
console.log('Final color hsl: ' , color.toHsl());
console.log('Final color hsv: ' , color.toHsv());