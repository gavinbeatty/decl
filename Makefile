SHELL = /bin/sh
.SUFFIXES:

.PHONY: help all configure config conf confclean install
help:
	@echo "Targets: help all configure confclean install"

PROJECT_NAME = decl
HOMEPAGE = http://github.com/gavinbeatty/decl
DESCRIPTION = Compiler declarations (such as declspec for MSVC) for C/C++.
PREFIX = /usr/local
VERSION_MAJOR := 1
VERSION_MINOR := 5
VERSION_PATCH := 0
VERSION := $(VERSION_MAJOR).$(VERSION_MINOR).$(VERSION_PATCH)

SED ?= sed
RM ?= rm
INSTALL ?= install
INSTALL_DIR ?= $(INSTALL) -d
INSTALL_DATA ?= $(INSTALL) -m 0644

gen_p = @echo '    GEN       ' $@;

all: configure

decl.pc: decl.pc.in
	$(gen_p)$(SED) \
		-e 's#@PROJECT_NAME@#$(PROJECT_NAME)#g' \
		-e 's#@VERSION@#$(VERSION)#g' \
		-e 's#@DESCRIPTION@#$(DESCRIPTION)#g' \
		-e 's#@HOMEPAGE@#$(HOMEPAGE)#g' \
		-e 's#@PREFIX@#$(PREFIX)#g' \
		decl.pc.in > decl.pc

src/decl/config.h: src/decl/config.h.in
	$(gen_p)$(SED) \
		-e 's#@VERSION_MAJOR@#$(VERSION_MAJOR)#g' \
		-e 's#@VERSION_MINOR@#$(VERSION_MINOR)#g' \
		-e 's#@VERSION_PATCH@#$(VERSION_PATCH)#g' \
		-e 's#@VERSION@#$(VERSION)#g' \
		src/decl/config.h.in > src/decl/config.h
configure: src/decl/config.h decl.pc
config: configure
conf: configure

confclean:
	$(RM) src/decl/config.h decl.pc

install: configure
	$(INSTALL_DIR) $(DESTROOT)$(PREFIX)/include/decl
	$(INSTALL_DATA) $(wildcard src/decl/*.h) $(DESTROOT)$(PREFIX)/include/decl/
	$(INSTALL_DIR) $(DESTROOT)$(PREFIX)/include/decl/cc
	$(INSTALL_DATA) $(wildcard src/decl/cc/*.h) $(DESTROOT)$(PREFIX)/include/decl/cc/
