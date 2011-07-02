decl
====
Gavin Beatty <gavinbeatty@gmail.com>

decl: Compiler declarations (such as declspec for MSVC) for C/C++.

License
-------
Copyright and license information can be found in the included LICENSE.txt.

Install
-------
To configure, just run `make configure`

This is a header only library, so there is nothing to build.

The default prefix is `/usr/local`. Examples for installing:

* `sudo make install`
* `make install PREFIX="$HOME"/.local/usr`
* `fakeroot make install PREFIX=/usr DESTROOT=./decl-bin`

