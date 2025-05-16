#ifndef h_commtst
#define h_commtst


// clang-format off
#ifdef is_unix
#define _POSIX_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <spawn.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#endif

#ifdef is_win

/* #  define _WINSOCKAPI_ */
#include <fcntl.h>
#include <stdio.h>
#include <winsock2.h>
/* #  include <windows.h> */
#include <io.h>
#include <ws2tcpip.h>
#include "commtst.h"

#endif
// clang-format on

#include <mcpc/_c23_keywords.h>
#include <mcpc/_c23_uchar.h>
#include <ext_string.h>
#include <ext_stdint.h>

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ass0(f)                                                                \
  do {                                                                         \
    int ec = (f);                                                              \
    if (0 != ec) {                                                             \
      fprintf(stderr,                                                          \
              "%s:%d,ec:%d syserr:%s\n",                                       \
              __FILE__,                                                        \
              __LINE__,                                                        \
              ec,                                                              \
              strerror(errno));                                                \
      abort();                                                                 \
    }                                                                          \
  } while (0)

#define assT(f)                                                                \
  do {                                                                         \
    if (!(f)) {                                                                \
      fprintf(stderr,                                                          \
              "abort@%s:%d,syserr:%s\n",                                       \
              __FILE__,                                                        \
              __LINE__,                                                        \
              strerror(errno));                                                \
      abort();                                                                 \
    }                                                                          \
  } while (0)

#define assF(f)                                                                \
  do {                                                                         \
    if ((f)) {                                                                 \
      fprintf(stderr,                                                          \
              "abort@%s:%d,syserr:%s\n",                                       \
              __FILE__,                                                        \
              __LINE__,                                                        \
              strerror(errno));                                                \
      abort();                                                                 \
    }                                                                          \
  } while (0)

#define assTcb(f, cb)                                                          \
  do {                                                                         \
    if (!(f)) {                                                                \
      { cb };                                                                  \
      fprintf(stderr, "abort@%s:%d\n", __FILE__, __LINE__);                    \
      abort();                                                                 \
    }                                                                          \
  } while (0)

#define BUFCAP 1024
#define PORT 8080

typedef int8_t i8_t;
typedef uint8_t u8_t;
typedef int16_t i16_t;
typedef uint16_t u16_t;
typedef int32_t i32_t;
typedef uint32_t u32_t;
typedef int64_t i64_t;
typedef uint64_t u64_t;

typedef char8_t ch8_t;

typedef size_t sz_t;

#ifdef is_win
typedef SSIZE_T ssize_t;
#endif

void read_atmost (void *src, char *rbuf, const size_t nexact, size_t *nread);

void recv_atmost (
#ifdef is_unix
		   int csock,
#elif defined(is_win)
		   SOCKET cosck,
#endif
		   char *rbuf, const size_t nmost, size_t *nread);

int32_t read_u8str (const char8_t * const filename, char8_t * const destbuf);

int32_t read_u8str_sz (const char8_t * const filename, char8_t * const destbuf, size_t *nread);

void zero_trailing_white_char (char8_t * buf, const size_t len);

void zero_trailing_white_char2 (char8_t * buf, size_t *len);


#ifdef is_unix
FILE *unix_fd2strm_r (int fd);
#endif

#ifdef is_win
FILE *win_handle2strm (HANDLE h);
#endif

#ifdef is_win
int win_handle2fd (HANDLE h);
#endif


#endif
