ifneq (,$(and $(isnot_done_ccdefs),$(is_macos)))
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
      is_clang14 = $(findstring 14.,$(clang_ver))
      is_clang15 = $(findstring 15.,$(clang_ver))
      is_clang16 = $(findstring 16.,$(clang_ver))
    endif

    ifeq (1,2)
    else ifneq (,$(and $(is_clang14)))
      CFLAGS += -std=c17
      CFLAGS += -DMCPC_C23PTCH_KW1
      CFLAGS += -DMCPC_C23PTCH_CKD1
      CFLAGS += -DMCPC_C23PTCH_UCHAR1
      CFLAGS += -Dno_c23_n2508
      isnot_done_ccdefs = 
    else ifneq (,$(and $(is_clang15)))
      CFLAGS += -std=c17
      CFLAGS += -DMCPC_C23PTCH_KW1
      CFLAGS += -DMCPC_C23PTCH_CKD1
      CFLAGS += -DMCPC_C23PTCH_UCHAR1
      CFLAGS += -Dno_c23_n2508
      isnot_done_ccdefs = 
    else ifneq (,$(and $(is_clang16)))
      CFLAGS += -std=c17
      CFLAGS += -DMCPC_C23PTCH_KW1
      CFLAGS += -DMCPC_C23PTCH_CKD1
      CFLAGS += -DMCPC_C23PTCH_UCHAR1
      CFLAGS += -Dno_c23_n2508
      isnot_done_ccdefs = 
    endif

endif
