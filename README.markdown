decl
====
Gavin Beatty <gavinbeatty@gmail.com>

decl: Compiler declarations (such as declspec for MSVC) for C/C++.

License
-------
Copyright (c) 2010 Gavin Beatty <gavinbeatty@gmail.com>.
All rights reserved.

New BSD License. Found in LICENSE.txt.

Install
-------
Configure:
    mkdir build
    cd build
    cmake ../

Select your own prefix:
    cmake -DCMAKE_INSTALL_PREFIX=~/.local/usr ../

Build:
    make

Default prefix is `/usr/local`:
    sudo make install

