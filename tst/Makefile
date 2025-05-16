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


ifneq (,$(is_gcclike))
  CFLAGS += -I../src
endif
ifneq (,$(is_cllike))
  CFLAGS += /I..\src
endif


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

default: link utst

clean:
	$(if $(is_cmd) , del *.pdb *.ilk *.o *.out *.a *.so *.dSYM *.obj *.exe *.lib *.dll *.exp *.log )
	$(if $(is_sh) , rm -rf *.pdb *.ilk *.o *.out *.a *.so *.dSYM *.obj *.exe *.lib *.dll *.exp *.log )

comp: itst-svcalc_COMP

link: itst-svcalc_LINKE

utst: itst-svcalc_EXEC

itst: itst-svcalc_EXEC


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# itst-svcalc

itst-svcalc_srcs =
itst-svcalc_srcs += commtst.c
itst-svcalc_srcs += itst-svcalc.c

itst-svcalc_objs = 
ifneq (,$(is_gcclike))
  itst-svcalc_objs = $(patsubst %.c,%.o,$(itst-svcalc_srcs))
else ifneq (,$(is_cllike))
  itst-svcalc_objs = $(patsubst %.c,%.obj,$(itst-svcalc_srcs))
endif

itst-svcalc_ldflags =
ifneq (,$(is_unixar))
  itst-svcalc_ldflags += ../src/libmcpc.a
endif
ifneq (,$(is_manual_pthread))
  itst-svcalc_ldflags += -lpthread
endif
ifneq (,$(is_winlib))
  itst-svcalc_ldflags += ws2_32.lib
  itst-svcalc_ldflags += ..\src\mcpc.lib
endif
ifneq (,$(is_winld))
  itst-svcalc_ldflags += -lws2_32
endif


itst-svcalc_COMP:
	$(if $(is_gcclike) , $(CC) $(CFLAGS) $(itst-svcalc_srcs) -c )
	$(if $(is_cllike) , $(CC) $(CFLAGS) $(itst-svcalc_srcs) /c )
itst-svcalc_LINKE: itst-svcalc_COMP
	$(if $(is_gcclike) , $(CC) $(itst-svcalc_objs) $(LDFLAGS) $(itst-svcalc_ldflags) -o itst-svcalc.out )
	$(if $(is_cllike) , $(CC) $(itst-svcalc_objs) /link /out:itst-svcalc.exe $(LDFLAGS) $(itst-svcalc_ldflags))
itst-svcalc_EXEC: itst-svcalc_LINKE
	@ echo>>$@.stdout.log; echo>>$@.stderr.log;
	$(if $(is_unix) , @ date>>$@.stdout.log; date>>$@.stderr.log; )
	$(if $(is_cmd) , echo ___>>$@.stdout.log; echo ___>>$@.stderr.log; )
	$(if $(is_pkill) , pkill itst-sv || printf "" )
        # itst-svcalc
	$(if $(is_dirsh) , ./itst-svcalc.out iostrm -i itst-svcalc-req-toolslist-1.json 1>>$@.stdout.log 2>>$@.stderr.log )
	$(if $(is_cmd) , itst-svcalc.exe iostrm -i itst-svcalc-req-toolslist-1.json 1>>$@.stdout.log 2>>$@.stderr.log )
	$(if $(and $(is_indirsh),$(is_cllike)) , ./itst-svcalc.exe iostrm -i itst-svcalc-req-toolslist-1.json 1>>$@.stdout.log 2>>$@.stderr.log )
	$(if $(and $(is_indirsh),$(is_gcclike)) , ./itst-svcalc.out iostrm -i itst-svcalc-req-toolslist-1.json 1>>$@.stdout.log 2>>$@.stderr.log )
	$(if $(is_valg) , valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --error-exitcode=222 ./itst-svcalc.out iostrm -i itst-svcalc-req-toolslist-1.json 1>/dev/null 2>/dev/null )
	@echo P A S S E D : $(patsubst %_EXEC,%,$@)
