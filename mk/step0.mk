ifeq ($(SHELL),/bin/sh)
  is_sh = xxx
  is_dirsh = xxx
  unameall = $(shell uname -a)
  is_linux = $(findstring Linux,$(unameall))
  is_cygwin = $(findstring Cygwin,$(unameall))
  is_mingw = $(findstring MINGW64_NT,$(unameall))
  is_macos = $(findstring Darwin,$(unameall))
else ifneq (,$(findstring /sh.exe,$(SHELL)))
  # indirectly enter bash (but the only way we enter GH win)
  is_sh = xxx
  is_indirsh = xxx
  is_win = xxx
  unameall = $(shell uname -a)
  is_msys = $(findstring MSYS_NT,$(unameall))
  is_mingw = $(findstring MINGW64_NT,$(unameall))
  sysinfo = $(shell systeminfo)
  ifneq (,$(findstring Windows Server 2019,$(sysinfo)))
    is_win2019 = xxx
  endif
  ifneq (,$(findstring Windows Server 2022,$(sysinfo)))
    is_win2022 = xxx
  endif
  ifneq (,$(findstring Windows Server 2025,$(sysinfo)))
    is_win2025 = xxx
  endif
else ifneq (,$(findstring sh.exe,$(SHELL)))
  is_win = xxx
  is_cmd = xxx
endif
isnot_done_ccdefs = xxx
