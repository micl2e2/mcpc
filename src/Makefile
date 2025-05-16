include ../mk/step0.mk

ifneq (,$(is_linux))
  include ../mk/ccdefs-linux.mk
endif
ifneq (,$(is_cygwin))
  include ../mk/ccdefs-cygwin.mk
endif
ifneq (,$(is_mingw))
  include ../mk/ccdefs-mingw.mk
endif
ifneq (,$(is_macos))
  include ../mk/ccdefs-macos.mk
endif
ifneq (,$(is_win))
  include ../mk/ccdefs-win.mk
endif

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

include ../mk/dbgrel.mk

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

default: link

clean:
	$(if $(is_cmd) , del *.pdb *.ilk *.o *.out *.a *.so *.dSYM *.obj *.exe *.lib *.dll *.exp )
	$(if $(is_sh) , rm -rf *.pdb *.ilk *.o *.out *.a *.so *.dSYM *.obj *.exe *.lib *.dll *.exp )

comp: libmcpc_COMP

link: libmcpc_LINKS
link: libmcpc_LINKD

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# libmcpc

libmcpc_srcs =
libmcpc_srcs += alloc.c
libmcpc_srcs += log.c
libmcpc_srcs += errcode.c
libmcpc_srcs += anydata.c
libmcpc_srcs += tool.c
libmcpc_srcs += rsc.c
libmcpc_srcs += prmpt.c
libmcpc_srcs += server.c
libmcpc_srcs += retbuf.c
libmcpc_srcs += ucbr.c
libmcpc_srcs += complt.c
libmcpc_srcs += serlz.c
libmcpc_srcs += mjson.c

libmcpc_objs =
ifneq (,$(is_gcclike))
  libmcpc_objs = $(patsubst %.c,%.o,$(libmcpc_srcs))
endif
ifneq (,$(is_cllike))
  libmcpc_objs = $(patsubst %.c,%.obj,$(libmcpc_srcs))
endif

libmcpc_cflags =
ifeq (,$(is_win))
  libmcpc_cflags += -fPIC
endif
libmcpc_clcflags =

libmcpc_ldflags =
ifneq (,$(is_unixar))
  libmcpc_ldflags += ../src/libmcpc.a
endif
ifneq (,$(is_winlib))
  libmcpc_ldflags += ws2_32.lib
endif
ifneq (,$(is_winld))
  libmcpc_ldflags += -lws2_32
endif

libmcpc_arflags =
libmcpc_arflags += rcs

libmcpc_COMP:
	$(if $(is_gcclike) , $(CC) $(CFLAGS) $(libmcpc_cflags) $(libmcpc_srcs) -c )
	$(if $(is_cllike) , $(CC) $(CFLAGS) $(libmcpc_clcflags) $(libmcpc_srcs) /c )

libmcpc_LINKS: libmcpc_COMP
	$(if $(is_gcclike) , $(AR) $(libmcpc_arflags) libmcpc.a $(libmcpc_objs) )
	$(if $(is_cllike) , lib /nologo $(libmcpc_objs) /out:mcpc.lib $(libmcpc_ldflags) )

libmcpc_LINKD: libmcpc_COMP
	$(if $(is_gcclike) , $(CC) $(LDFLAGS) -o libmcpc.so $(libmcpc_objs) -shared $(libmcpc_ldflags) )
	$(if $(is_cllike) , cl /nologo $(libmcpc_objs) /link /dll /out:mcpc.dll $(LDFLAGS) $(libmcpc_ldflags) )


