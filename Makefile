# $Id$

PROG = systag
SRCS = systag.c shell.c
CFLAGS = -Wall -g -I../lbuf
LDFLAGS = -leditline -lcurses -ll

.include <bsd.prog.mk>
