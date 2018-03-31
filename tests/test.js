"use strict";
let cnHashing = require('../build/Release/cryptonighthashing');
let fs = require('fs');
let lineReader = require('readline');

let hashes = {
    'CryptoNight': {
        'file': 'cryptonight.txt',
        'fileFormat': 'cn', // VARIANT EXPECTED HASH
        'function': cnHashing.cryptonight
    },
    'CryptoNight-Light': {
        'file': 'cryptonight_light.txt',
        'fileFormat': 'cnlight', // LIGHT VARIANT EXPECTED HASH
        'function': cnHashing.cryptonight_light
    }
};

for (let hashType in hashes){
    if (hashes.hasOwnProperty(hashType)){
        let testsFailed = 0, testsPassed = 0;
        let lr = lineReader.createInterface({
            input: fs.createReadStream(hashes[hashType].file)
        });
        lr.on('line', function (line) {
            if (hashes[hashType].fileFormat === 'cn'){
                let line_data = line.split(' ');
                let hashed_data = hashes[hashType].function(Buffer.from(line_data[2], 'hex'), parseInt(line_data[0])).toString('hex');
                if (line_data[1] !== hashed_data){
                    console.log('Expected: ' + line_data[1]);
                    console.log('Received: ' + hashed_data);
                    testsFailed += 1;
                } else {
                    testsPassed += 1;
                }
            }
            if (hashes[hashType].fileFormat === 'cnlight'){
                let line_data = line.split(' ');
                let hashed_data = hashes[hashType].function(Buffer.from(line_data[3], 'hex'), parseInt(line_data[0]), parseInt(line_data[1])).toString('hex');
                if (line_data[2] !== hashed_data){
                    console.log('Expected: ' + line_data[2]);
                    console.log('Received: ' + hashed_data);
                    testsFailed += 1;
                } else {
                    testsPassed += 1;
                }
            }
        });
        lr.on('close', function(){
            if (testsFailed > 0){
                console.log(testsFailed + '/' + (testsPassed + testsFailed) + ' tests failed on: ' + hashType);
            } else {
                console.log(testsPassed + ' tests passed on: ' +hashType);
            }
        });
    }
}

