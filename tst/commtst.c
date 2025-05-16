#include "commtst.h"

#include <stdint.h>

i32_t
fsize (FILE *strm)
{
  fseek (strm, 0, SEEK_SET);
  fseek (strm, 0, SEEK_END);
  long sz = ftell (strm);
  assert (sz > 0);
  fseek (strm, 0, SEEK_SET);
  return sz;
}

void
read_atmost (void *src, char *rbuf, const size_t nmost, size_t *nread)
{
#ifdef is_win
  HANDLE *hdlp = (HANDLE *) src;
#else
  int *fdp = (int *) src;
#endif
  size_t nread_accm = 0;
  size_t nleft = nmost;
  while (nleft > 0)
    {
      ssize_t nbuffered = nmost - nleft;
#ifdef is_win
      ssize_t nread_cur = 0;
      assT (ReadFile
	    (*hdlp, rbuf + nbuffered, (DWORD)nleft, (LPDWORD) (&nread_cur),
	     nullptr));
#else
      ssize_t nread_cur = read (*fdp, rbuf + nbuffered, nleft);
#endif
      if (nread_cur <= 0)
	break;
      nread_accm += nread_cur;
      nleft -= nread_cur;
    }
  *nread = nread_accm;
}

void
recv_atmost (
#if is_unix
	      int csock,
#elif is_win
	      SOCKET csock,
#endif
	      char *rbuf, const size_t nmost, size_t *nread)
{
  size_t nread_accm = 0;
  size_t nleft = nmost;
  while (nleft > 0)
    {
      ssize_t nbuffered = nmost - nleft;
      ssize_t nread_cur = recv (csock, rbuf + nbuffered, (int)nleft, 0);
      if (nread_cur <= 0)
	break;
      nread_accm += nread_cur;
      nleft -= nread_cur;
    }
  *nread = nread_accm;
}

i32_t
read_u8str (const char8_t *const filename, char8_t *const destbuf)
{
  FILE *file;

  // Open the file
#if is_win
  fopen_s (&file, (const char*) filename, "rb,ccs=UTF-8");
#else
  file = fopen ((const char*) filename, "rb");
#endif
  assert (file != nullptr);

  i32_t fsz = fsize (file);

  // Read the file content into the buffer
  size_t bytes_read = fread (destbuf, 1, fsz, file);
  assert (bytes_read > 0);

  // Null-terminate the buffer
  destbuf[bytes_read] = 0;

  // printf("File content: %s\n", destbuf);

  // Close the file
  fclose (file);

  return 0;
}

i32_t
read_u8str_sz (const char8_t *const filename, char8_t *const destbuf,
	       size_t *nread)
{
  FILE *file;

  // Open the file
#if is_win
  fopen_s (&file, (const char*) filename, "rb,ccs=UTF-8");
#else
  file = fopen ((const char*) filename, "rb");
#endif
  assTcb (file != nullptr,
	  {
	  fprintf (stderr, "filename:%s\n", filename);
	  });

  i32_t fsz = fsize (file);

  // Read the file content into the buffer
  size_t bytes_read = fread (destbuf, 1, fsz, file);
  assert (bytes_read > 0);

  // Null-terminate the buffer
  destbuf[bytes_read] = 0;
  *nread = bytes_read;
  // printf("File content: %s\n", destbuf);

  // Close the file
  fclose (file);

  return 0;
}

void
zero_trailing_white_char (char8_t *buf, const size_t len)
{
  for (size_t i = len - 1; i != 0; i--) // TODO ckd_add
    {
      if (buf[i] == '\n' || buf[i] == '\r' || buf[i] == '\t' || buf[i] == ' ')
	buf[i] = 0;
      else
	break;
    }
}

void
zero_trailing_white_char2 (char8_t *buf, size_t *len)
{
  for (size_t i = *len - 1; i != 0; i--) // TODO ckd_add
    {
      if (buf[i] == '\n' || buf[i] == '\r' || buf[i] == '\t' || buf[i] == ' ')
	{
	  buf[i] = 0;
	  *len -= 1;
	}
      else
	break;
    }
}

#ifdef is_unix
FILE *
unix_fd2strm_r (int fd)
{
  return fdopen (fd, "r");
}
#endif

#ifdef is_win
FILE *
win_handle2strm (HANDLE h)
{
  // Convert HANDLE to file descriptor
  int fd = _open_osfhandle ((intptr_t) h, _O_RDONLY);
  assT (fd > 0);

  // Convert file descriptor to FILE*
  FILE *file = _fdopen (fd, "r+");	// Use "r" or "w" as needed
  assT (file != nullptr);
  return file;
}
#endif

#ifdef is_win
int
win_handle2fd (HANDLE h)
{
  // Convert HANDLE to file descriptor
  int fd = _open_osfhandle ((intptr_t) h, _O_RDONLY);
  assT (fd > 0);
  return fd;
}
#endif
