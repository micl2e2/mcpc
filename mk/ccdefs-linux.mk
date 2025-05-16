ifneq (,$(and $(isnot_done_ccdefs),$(is_linux)))
  is_unix = xxx
  is_unixar = xxx
  CFLAGS += -Dis_unix

  cc_ver = $(shell $(CC) --version)
  ifneq (,$(findstring Free Software Foundation,$(cc_ver)))
      found_gcc = xxx
  endif
  ifneq (,$(findstring clang,$(cc_ver)))
      found_clang = xxx
  endif

  ifneq (,$(found_gcc))
    is_gcc = xxx
    is_gcclike = xxx
    gcc_ver = $(shell $(CC) --version)
    is_gcc12 = $(findstring 12.,$(gcc_ver))
    is_gcc13 = $(findstring 13.,$(gcc_ver))
    is_gcc14 = $(findstring 14.,$(gcc_ver))
  else ifneq (,$(found_clang))
    is_clang = xxx
    is_gcclike = xxx
    clang_ver = $(shell $(CC) --version)
    is_clang18 = $(findstring 18.,$(clang_ver))
    is_clang19 = $(findstring 19.,$(clang_ver))
  endif

  ldd_ver = $(shell ldd --version)
  is_glibc236 = $(and $(findstring GLIBC,$(ldd_ver)),$(findstring 2.36,$(ldd_ver)))
  is_gnu240 = $(and $(findstring GNU,$(ldd_ver)),$(findstring 2.40,$(ldd_ver)))
  is_cygwin = $(and $(findstring cygwin,$(ldd_ver)))

  ifeq (1,2)
  else ifneq (,$(and $(is_gcc12),$(is_glibc236)))
    # deb12
    CFLAGS += -std=c17
    CFLAGS += -DMCPC_C23PTCH_KW1
    CFLAGS += -DMCPC_C23PTCH_CKD1
    CFLAGS += -DMCPC_C23PTCH_UCHAR1
    CFLAGS += -DMCPC_C23GIVUP_FIXENUM
    isnot_done_ccdefs = 
  else ifneq (,$(and $(is_gcc14),$(is_cygwin)))
    # fc41
    CFLAGS += -std=c23
    CFLAGS += -DMCPC_C23PTCH_UCHAR1
    isnot_done_ccdefs = 
  else ifneq (,$(and $(is_gcc14),$(is_mingw)))
    # fc41
    CFLAGS += -std=c233
    isnot_done_ccdefs = 
  else ifneq (,$(and $(is_gcc14),$(is_gnu240)))
    # fc41
    CFLAGS += -std=c23
    isnot_done_ccdefs = 
  else ifneq (,$(and $(is_clang18),$(is_gnu240)))
    # fc41
    CFLAGS += -std=c23
    isnot_done_ccdefs = 
  else ifneq (,$(and $(is_clang19),$(is_gnu240)))
    # fc41
    CFLAGS += -std=c23
    isnot_done_ccdefs = 
  endif



endif
