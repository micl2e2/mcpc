ifneq (,$(and $(isnot_done_ccdefs),$(is_mingw)))
    is_unix = xxx
    CFLAGS += -Dis_mingw
    CFLAGS += -Dis_win  # winapi?

    wherecl = $(shell where cl)
    ifneq (,$(wherecl))
        found_cl = xxx
    endif

    # Use cl whenever possible
    ifneq (,$(and $(found_cl),$(is_indirsh)))
      CC = cl
      is_cllike = xxx
      is_winlib = xxx
    else
      # To find any other cc

      # gh win2019 patch, intentionally to use gcc
      ifneq (,$(is_win2019))
          CC = gcc
      endif
      # GH win2022 patch, intentionally to use gcc
      ifneq (,$(is_win2022))
          CC = gcc
      endif

      cc_ver = $(shell $(CC) --version)
      ifneq (,$(findstring Free Software Foundation,$(cc_ver)))
          found_gcc = xxx
      endif
      ifneq (,$(found_gcc))
          is_gcc = xxx
          is_gcclike = xxx
          is_unixar = xxx
          is_winld = xxx
          gcc_ver = $(shell $(CC) --version)
          is_gcc8 = $(findstring 8.,$(gcc_ver))
          is_gcc12 = $(findstring 12.,$(gcc_ver))
          is_gcc13 = $(findstring 13.,$(gcc_ver))
          is_gcc14 = $(findstring 14.,$(gcc_ver))
      endif
      ifneq (,$(found_clang))
          is_clang = xxx
          is_gcclike = xxx
          is_unixar = xxx
          is_winld = xxx
          clang_ver = $(shell $(CC) --version)
          is_clang18 = $(findstring 18.,$(clang_ver))
          is_clang19 = $(findstring 19.,$(clang_ver))
      endif
    endif

    ifeq (1,2)
    else ifneq (,$(is_cllike))
        CFLAGS += /Dis_win
        CFLAGS += /Dis_wincl
        CFLAGS += /nologo
        CFLAGS += /std:c17
        CFLAGS += /DMCPC_C23PTCH_KW1
        CFLAGS += /DMCPC_C23PTCH_CKD1
        CFLAGS += /DMCPC_C23PTCH_UCHAR1
        CFLAGS += /DMCPC_C23GIVUP_FIXENUM
        LDFLAGS += /nologo
        is_cllike = xxx
        is_winlib = xxx
        is_cl = xxx
        isnot_done_ccdefs = 
    else ifneq (,$(and $(is_gcc8)))
        CFLAGS += -std=c11
        CFLAGS += -DMCPC_C23PTCH_KW1
        CFLAGS += -DMCPC_C23PTCH_CKD1
        CFLAGS += -DMCPC_C23PTCH_UCHAR1
        CFLAGS += -DMCPC_C23GIVUP_FIXENUM
        isnot_done_ccdefs = 
    else ifneq (,$(and $(is_gcc12)))
        CFLAGS += -std=c17
        CFLAGS += -DMCPC_C23PTCH_KW1
        CFLAGS += -DMCPC_C23PTCH_CKD1
        CFLAGS += -DMCPC_C23PTCH_UCHAR1
        CFLAGS += -DMCPC_C23GIVUP_FIXENUM
        isnot_done_ccdefs = 
    else ifneq (,$(and $(is_gcc14)))
        # fc41
        CFLAGS += -std=c23
        CFLAGS += -DMCPC_C23PTCH_UCHAR2
        isnot_done_ccdefs = 
    endif
endif
