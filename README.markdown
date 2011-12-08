decl
====
Gavin Beatty <gavinbeatty@gmail.com>

decl: Compiler declarations (such as declspec for MSVC) for C/C++.

License
-------
Copyright and license information can be found in the included LICENSE.txt.

Install
-------
To generate config.h and decl.pc, run `make configure`. The prefix in decl.pc
is determinted at this time, so do `make conf PREFIX=/your/path`.

Default install prefix is `/usr/local`. Examples for installing:

* `sudo make install`
* `make install PREFIX="${HOME}/.local"`
* `fakeroot make install PREFIX="/usr" DESTROOT=./decl-bin`

Only the headers are installed. You must install decl.pc yourself.
