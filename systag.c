/* $Id$ */

#include <stdio.h>
#include <sysexits.h>

#include "systag.h"
#include "lbuf.h"

static void shell(FILE *, int);
static void usage(int) __attribute__((__noreturn__));

static char *prompt = "systag> ";

int
main(int argc, char *argv[])
{
	int ch, interactive = 1;

	while ((ch = getopt(argc, argv, "e:h")) != -1) {
		switch (ch) {
		case 'e':
			parsecmd(optarg);
			interactive = 0;
			break;
		case 'h':
			usage(EXIT_SUCCESS);
			/* NOTREACHED */
		case 'f':
			readcmdfile(optarg);
			interactive = 0;
			break;
		default:
			usage(EX_USAGE);
			/* NOTREACHED */
		}
	}
	if (interactive)
		shell();
	exit(EXIT_SUCCESS);
}

static void
usage(int status)
{
	extern char *__progname;

	(void)fprintf(stderr, "usage: %s\n", __progname);
	exit(status);
}

static void
readcmdfile(char *file)
{
	struct lbuf lb;
	FILE *fp;
	char c;

	LBUF_INIT(lb);
	if ((fp = fopen(file, "r")) == NULL)
		err(EX_NOINPUT, "%s", file);
	while ((c = fgetc(fp)) != EOF) {
		if (c == '\n') {
			parsecmd(LBUF_GET(lb));
			LBUF_RESET(lb);
		} else
			LBUF_PUSH(lb, c);
	}
	(void)fclose(fp);
	LBUF_FREE(lb);
}
