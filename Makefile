include mk/step0.mk

subdirs =
subdirs += src
subdirs2 =
subdirs2 += tst

default: link

clean:
	$(if $(is_sh),@for el in $(subdirs); do $(MAKE) -C $$el $@; done)
	$(if $(is_sh),@for el in $(subdirs2); do $(MAKE) -C $$el $@; done)
	$(if $(is_cmd),@for %%e in ($(subdirs)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) $@)
	$(if $(is_cmd),@for %%e in ($(subdirs2)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) $@)

link:
	$(if $(is_sh),@for el in $(subdirs); do $(MAKE) -C $$el $@; done)
	$(if $(is_cmd),@for %%e in ($(subdirs)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) $@)

tstcomp: link
	$(if $(is_sh),@for el in $(subdirs2); do $(MAKE) -C $$el comp; done)
	$(if $(is_cmd),@for %%e in ($(subdirs2)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) comp)

tstlink: link
	$(if $(is_sh),@for el in $(subdirs2); do $(MAKE) -C $$el link; done)
	$(if $(is_cmd),@for %%e in ($(subdirs2)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) link)

utst: link
	$(if $(is_sh),@for el in $(subdirs2); do $(MAKE) -C $$el $@; done)
	$(if $(is_cmd),@for %%e in ($(subdirs2)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) $@)

itst: link
	$(if $(is_sh),@for el in $(subdirs2); do $(MAKE) -C $$el $@; done)
	$(if $(is_cmd),@for %%e in ($(subdirs2)) do $(MAKE) -C %%e -f $(firstword $(MAKEFILE_LIST)) $@)

tst: utst itst

PREFIX ?= /usr/local
INC_DIR = $(PREFIX)/include
LIB_DIR = $(PREFIX)/lib
PC_DIR = $(LIB_DIR)/pkgconfig
VER = $(shell cat src/ver.txt)

install: tst
	$(if $(is_sh), install -d $(INC_DIR)/mcpc $(LIB_DIR) $(PC_DIR) )
	$(if $(is_sh), install -m 644 mcpc/* $(INC_DIR)/mcpc )
	$(if $(is_sh), install -m 644 src/libmcpc.a $(LIB_DIR) )
	$(if $(is_sh), install -m 755 src/libmcpc.so $(LIB_DIR)/libmcpc.so.$(VER) )
	$(if $(is_sh), install -m 644 src/mcpc.pc $(PC_DIR) )
	$(if $(is_sh), ln -sf $(LIB_DIR)/libmcpc.so.$(VER) $(LIB_DIR)/libmcpc.so )
	$(if $(is_cmd), echo Automatic installation not supported on this platform )
