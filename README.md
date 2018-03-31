node-cryptonight-hashing
===============
Cryptonight hashing functions for node.js. This repo uses code that originally was [node-multi-hashing](https://github.com/zone117x/node-multi-hashing/) with all algorithms except for Cryptonight having been stripped out.

Algorithms
----------
* cryptonight
* cryptonight light

Usage
-----
Install

```bash
npm install cryptonight-hashing
```

```javascript
var cnHashing = require('crytponight-hashing');

var algorithms = ['cryptonight', 'cryptonight_light'];

var data = new Buffer("7000000001e980924e4e1109230383e66d62945ff8e749903bea4336755c00000000000051928aff1b4d72416173a8c3948159a09a73ac3bb556aa6bfbcad1a85da7f4c1d13350531e24031b939b9e2b", "hex");

var hashedData = algorithms.map(function(algo){
    return cnHashing[algo](data);
});

console.log(hashedData);
//<SlowBuffer 0b de 16 ef 2d 92 e4 35 65 c6 6c d8 92 d9 66 b4 3d 65 ..... >
```

Credits
-------
* [Snipa22](https://github.com/Snipa22/) from which portions were used
* [zone117x](https://github.com/zone117x/) from which this repo was forked from
* [NSA](http://www.nsa.gov/) and [NIST](http://www.nist.gov/) for creation or sponsoring creation of SHA2 and SHA3 algos
* [Keccak](http://en.wikipedia.org/wiki/Keccak) - Guido Bertoni, Joan Daemen, Michaël Peeters, and Gilles Van Assche
* [Skein](http://en.wikipedia.org/wiki/Skein_(hash_function)) - Bruce Schneier, Stefan Lucks, Niels Ferguson, Doug Whiting, Mihir Bellare, Tadayoshi Kohno, Jon Callas and Jesse Walker.
* [BLAKE](http://en.wikipedia.org/wiki/BLAKE_(hash_function)) - Jean-Philippe Aumasson, Luca Henzen, Willi Meier, and Raphael C.-W. Phan
* [Grøstl](http://en.wikipedia.org/wiki/Gr%C3%B8stl) - Praveen Gauravaram, Lars Knudsen, Krystian Matusiewicz, Florian Mendel, Christian Rechberger, Martin Schläffer, and Søren S. Thomsen
* [JH](http://en.wikipedia.org/wiki/JH_(hash_function)) - Hongjun Wu
* [Fugue](http://en.wikipedia.org/wiki/Fugue_(hash_function)) - Shai Halevi, William E. Hall, and Charanjit S. Jutla
* [scrypt](http://en.wikipedia.org/wiki/Scrypt) - Colin Percival
* [bcrypt](http://en.wikipedia.org/wiki/Bcrypt) - Niels Provos and David Mazières
* [X11](http://www.darkcoin.io/), [Hefty1](http://heavycoin.github.io/about.html), [Quark](http://www.qrk.cc/) creators (they just mixed together a bunch of the above algos)
* [Wolf0](https://github.com/Wolf9466)/[OhGodAGirl](https://github.com/ohgodagirl) - Rebuilding the Cryptonote functions to use AES-NI for speed purposes
