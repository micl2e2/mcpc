
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# dbgrel

ifdef DBG
  ifeq (1,2)
  else ifneq (,$(is_gcclike))
    CFLAGS += -g -O0
    CFLAGS += -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter -Wno-unused-label
    CFLAGS += -DMCPC_DBG
    CFLAGS += -I..
  else ifneq (,$(is_cllike))
    CFLAGS += /Zi /Od /Ob0
    CFLAGS += /RTC1
    # CFLAGS += /Wall
    CFLAGS += /DMCPC_DBG
    CFLAGS += /I..
  endif
else
  ifeq (1,2)
  else ifneq (,$(is_gcclike))
    CFLAGS += -Wall -Wextra -Werror -Wno-unused-function -Wno-unused-parameter -Wno-unused-label -Wno-error=unused-variable -Wno-error=unused-but-set-variable
    CFLAGS += -O2 -Os
    CFLAGS += -I..
  else ifneq (,$(is_cllike))
    CFLAGS += /MD
    CFLAGS += /Wall
    CFLAGS += /wd4152 # okay with: nonstandard extension, function/data pointer conversion in expression
    CFLAGS += /wd4310 # okay with cast causing truncate
    CFLAGS += /wd4127 # window is wrong about sizeof(long) being constant
    CFLAGS += /wd4102 # okay to have unref label
    CFLAGS += /wd4189 # local variable is initialized but not referenced
    CFLAGS += /wd4100 # its okay not ref to param
    CFLAGS += /wd5045 # why call spectre rather than boundcheck?
    CFLAGS += /wd4005 # alloca macro redef is ok
    CFLAGS += /wd4996 # use strerror sprintf anyway
    CFLAGS += /wd4456 # no need to warn shadow decl
    CFLAGS += /wd4255 # ok for C23
    CFLAGS += /wd4668 # disb #if macro
    CFLAGS += /wd4710 # disable inline warn
    CFLAGS += /wd4820 # we know there is padding
    CFLAGS += /O2 /Ob1
    CFLAGS += /I..
  endif
endif

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# strip

ifndef DBG
  # LDFLAGS += --strip-all ld not recoginizing?
  ifneq (,$(is_linux))
    LDFLAGS += -s
  endif
  ifneq (,$(is_macos))
    LDFLAGS += -dead_strip
  endif
endif
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
# sanitizer

ifdef VALG
  which_valg = $(shell which valgrind)
  ifneq (,$(which_valg))
    is_valg = xxx
  endif
endif


# NOTE asan triggered only if ASAN=1, we use valgrind by default
ifdef ASAN
  is_asan = xxx
  is_valg =
  ifneq (,$(is_linux))
    CFLAGS += -fsanitize=address
    LDFLAGS += -lasan
  endif
  ifneq (,$(is_macos))
    CFLAGS += -fsanitize=address
    LDFLAGS += -fsanitize=address
  endif
  ifneq (,$(is_cllike))
    CFLAGS += /fsanitize=address
    LDFLAGS += /DEBUG
#    LDFLAGS += "C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\VC\\Tools\\Llvm\\lib\\clang\\19\\lib\\windows\\clang_rt.asan-i386.lib"
    LDFLAGS += /NODEFAULTLIB:libcmt.lib
    LDFLAGS += msvcrt.lib
  endif
endif


