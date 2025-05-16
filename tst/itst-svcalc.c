
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <mcpc/_c23_keywords.h>
#include <mcpc/mcpc.h>

#include <ext_string.h>

typedef int8_t i8_t;
typedef uint8_t u8_t;
typedef int16_t i16_t;
typedef uint16_t u16_t;
typedef int32_t i32_t;
typedef uint32_t u32_t;
typedef int64_t i64_t;
typedef uint64_t u64_t;

static void
cb_calc (const mcpc_tool_t *tool, mcpc_ucbr_t *ucbr)
{
  i32_t a = 0;
  i32_t b = 0;
  char8_t op[64];
  i32_t res = 0;

  assert (0 == mcpc_tool_get_tpropval_i32 (tool, u8c1 ("a"), &a));
  assert (0 == mcpc_tool_get_tpropval_i32 (tool, u8c1 ("b"), &b));
  assert (0 == mcpc_tool_get_tpropval_u8str (tool, u8c1 ("op"), op, sizeof (op), nullptr));

  if (false)
    ;
  else if (u8streq (op, u8c1 ("+")))
    {
      res = a + b;
    }
  else if (u8streq (op, u8c1 ("＋")))
    {
      res = a + b;
    }
  else if (u8streq (op, u8c1 ("-")))
    {
      res = a - b;
    }
  else if (u8streq (op, u8c1 ("*")))
    {
      res = a * b;
    }
  else if (u8streq (op, u8c1 ("times")))
    {
      res = a * b;
    }
  else if (u8streq (op, u8c1 ("/")))
    {
      res = a / b;
    }
  else if (u8streq (op, u8c1 ("div")))
    {
      res = a / b;
    }
  else
    {
      mcpc_ucbr_toolcall_add_errmsg_printf8 (ucbr, u8c1 ("not matching \"any\" operator:%s"), op);
      return;
    }

  mcpc_ucbr_toolcall_add_text_printf8 (ucbr, u8c1 ("%d"), res);
}

mcpc_tool_t *
new_tool_calc ()
{
  const char8_t *name = u8c1 ("calc");
  const char8_t *desc = u8c1 ("simple calculator");
  mcpc_tool_t *tool = mcpc_tool_new2 (name, desc);

  {
    const char8_t *name = u8c1 ("a");
    const mcpc_anytype_t type = MCPC_I32;
    const char8_t *desc = u8c1 ("the first number(\"a\") to calculate");
    mcpc_toolprop_t *prop = mcpc_toolprop_new2 (name, desc, type);
    mcpc_tool_add_toolprop (tool, prop);
  }
  {
    const char8_t *name = u8c1 ("b");
    const mcpc_anytype_t type = MCPC_I32;
    const char8_t *desc = u8c1 ("the second number to calculate");
    mcpc_toolprop_t *prop = mcpc_toolprop_new2 (name, desc, type);
    mcpc_tool_add_toolprop (tool, prop);
  }
  {
    const char8_t *name = u8c1 ("op");
    const mcpc_anytype_t type = MCPC_U8STR;
    const char8_t *desc =	//
      u8c1 ("the calculating operator, available values " "are: \"+\",'-',\"*\",'/'");
    mcpc_toolprop_t *prop = mcpc_toolprop_new2 (name, desc, type);
    mcpc_tool_add_toolprop (tool, prop);
  }

  mcpc_tool_set_call_cb (tool, &cb_calc);

  return tool;
}

int
main_iostrm (int argc, const char *argv[])
{
  u8_t in_src = 0;		// 1stdin 2file
  char in_fpath[100];

  for (int i = 2; i < argc; i++)
    {
      const char8_t *curr_arg = (const char8_t *) argv[i];
      const char8_t *nex_arg = nullptr;
      if (i < argc - 1)
	nex_arg = (const char8_t *) argv[i + 1];
      if (nex_arg != nullptr)
	{
	  if (u8streq (curr_arg, u8c1 ("-i")))
	    {
	      if (u8streq (nex_arg, u8c1 ("-")))
		{
		  in_src = 1;
		}
	      else if (beg_with_alph ((const char8_t *) nex_arg))
		{
		  // TODO nonascii filename?
		  /* memcpy (in_fpath, nex_arg, strlen (nex_arg)); */
		  strcpy (in_fpath, (const char *) nex_arg);
		  in_src = 2;
		}
	    }
	}
    }

  assert (in_src);

  FILE *in_stream = nullptr;
  switch (in_src)
    {
    case 1:
      in_stream = stdin;
      break;
    case 2:
      in_stream = fopen (in_fpath, "r");
      if (!in_stream)
	{
	  fprintf (stdout, "file:%s, err:%s", in_fpath, strerror (errno));
	}
      break;
    }
  assert (in_stream);

  mcpc_server_t *server = mcpc_server_new_iostrm (in_stream, stdout);
  mcpc_server_capa_enable_prmt (server);
  mcpc_server_capa_enable_tool (server);
  mcpc_server_capa_enable_rsc (server);
  mcpc_server_capa_enable_complt (server);

  mcpc_tool_t *tool = new_tool_calc ();
  assert (0 == mcpc_server_add_tool (server, tool));

  mcpc_errcode_t ec = mcpc_server_start (server);

  mcpc_server_close (server);
  fclose (in_stream);

  return ec;
}

int
main_tcp (int argc, const char *argv[])
{
  mcpc_server_t *server = mcpc_server_new_tcp ();
  mcpc_server_capa_enable_prmt (server);
  mcpc_server_capa_enable_tool (server);
  mcpc_server_capa_enable_rsc (server);
  mcpc_server_capa_enable_complt (server);

  mcpc_tool_t *tool = new_tool_calc ();
  assert (0 == mcpc_server_add_tool (server, tool));

  mcpc_errcode_t ec = mcpc_server_start (server);

  mcpc_server_close (server);
  return ec;
}

int
main (int argc, const char *argv[])
{
  assert (argc >= 2);
  bool as_iostrm = strcmp (argv[1], "iostrm") == 0;
  bool as_tcp = strcmp (argv[1], "tcp") == 0;
  assert (as_iostrm || as_tcp);
  // bool as_iostrm = false;
  // bool as_tcp = true;
  if (as_tcp)
    return main_tcp (argc, argv);
  if (as_iostrm)
    return main_iostrm (argc, argv);
}
