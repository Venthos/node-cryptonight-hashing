{
    "targets": [
        {
            "target_name": "cryptonighthashing",
            "sources": [
                "cryptonighthashing.cc",
                "crypto/oaes_lib.c",
                "crypto/keccak.c",
                "crypto/hash-extra-groestl.c",
                "crypto/groestl.c",
                "crypto/hash-extra-blake.c",
                "crypto/blake256.c",
                "crypto/hash-extra-jh.c",
                "crypto/jh.c",
                "crypto/hash-extra-skein.c",
                "crypto/skein.c",
                "crypto/hash.c",
                "cryptonight.c",
                "cryptonight_light.c"
            ],
            "include_dirs": [
                "crypto",
                "<!(node -e \"require('nan')\")",
            ],
			"cflags_c": [
				"-std=gnu11 -march=native -fPIC -m64"
			],
            "cflags_cc": [
                "-std=gnu++11 -fPIC -m64"
            ],
        }
    ]
}
