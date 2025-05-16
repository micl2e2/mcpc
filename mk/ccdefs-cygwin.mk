ifneq (,$(and $(isnot_done_ccdefs),$(is_cygwin)))
  is_unix = xxx
  is_unixar = xxx
  is_winld = xxx

  # currently we enforce gcc on cygwin
  CC = gcc
  CFLAGS += -Dis_unix
  CFLAGS += -Dis_cygwin
  is_gcc = xxx
  is_gcclike = xxx
  gcc_ver = $(shell $(CC) --version)
  is_gcc12 = $(findstring 12.,$(gcc_ver))
  is_gcc13 = $(findstring 13.,$(gcc_ver))
  is_gcc14 = $(findstring 14.,$(gcc_ver))

  ifeq (1,2)
  else ifneq (,$(and $(is_gcc12)))
    # deb12
    CFLAGS += -std=c17
    CFLAGS += -DMCPC_C23PTCH_KW1
    CFLAGS += -DMCPC_C23PTCH_CKD1
    CFLAGS += -DMCPC_C23PTCH_UCHAR1
    isnot_done_ccdefs = 
  else ifneq (,$(and $(is_gcc14)))
    # fc41
    CFLAGS += -std=c23
    CFLAGS += -DMCPC_C23PTCH_UCHAR2
    isnot_done_ccdefs = 
  endif



endif
