/* $Id$ */

#include <stdio.h>

#include <histedit.h>

#include "systag.h"

static void
shell(void)
{
	extern char *__progname;
	EditLine *el;
	char *s;
	int len;

	el = el_init(__progname, stdin, stdout, stderr);
	/* XXX: check for NULL */
	do {
		(void)printf("%s", prompt);
		s = el_gets(el, &len);

	} while (!feof(fp));
	el_end(el);
}
