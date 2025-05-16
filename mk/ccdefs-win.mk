ifneq (,$(and $(isnot_done_ccdefs),$(is_win)))

    ifdef USE_WINCLANG
      CC = clang-cl
      CFLAGS += /Dis_win
      is_cllike = xxx
      is_clang = xxx
      is_winclang = xxx
      clang_ver = $(shell $(CC) --version)
      is_clang14 = $(findstring 14.,$(clang_ver))
      is_clang16 = $(findstring 16.,$(clang_ver))
      is_clang19 = $(findstring 19.,$(clang_ver))

      ifeq (1,2)
      else ifneq (,$(and $(is_clang14)))
        CFLAGS += /std:c17
        CFLAGS += -DMCPC_C23PTCH_KW1
        CFLAGS += -DMCPC_C23PTCH_CKD1
        CFLAGS += -DMCPC_C23PTCH_UCHAR1
      else ifneq (,$(and $(is_clang16)))
        CFLAGS += /std:c17
        CFLAGS += -DMCPC_C23PTCH_KW1
        CFLAGS += -DMCPC_C23PTCH_CKD1
        CFLAGS += -DMCPC_C23PTCH_UCHAR1
      else ifneq (,$(and $(is_clang19)))
        CFLAGS += /std:c17
        CFLAGS += -DMCPC_C23PTCH_KW1
        CFLAGS += -DMCPC_C23PTCH_CKD1
        CFLAGS += -DMCPC_C23PTCH_UCHAR1
      endif

    else

        ifneq (,$(found_cl))
            CC = cl
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
        else
            cc_ver = $(shell $(CC) --version)
            ifneq (,$(findstring Free Software Foundation,$(ccver)))
                is_gcc = xxx
                is_gcclike = xxx
                is_unixar = xxx
                is_winld = xxx
            endif
        endif
    endif

endif
