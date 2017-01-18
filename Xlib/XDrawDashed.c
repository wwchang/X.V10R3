#include <X/mit-copyright.h>

/* $Header: XDrawDashed.c,v 10.5 86/02/01 15:32:23 tony Rel $ */
/* Copyright    Massachusetts Institute of Technology    1985	*/

#include "XlibInternal.h"
XDrawDashed (w, vlist, vcount, width, height, pixel, pattern, func, planes)
	Window w;
	int func;
	int pixel, planes, height, width, vcount;
	Pattern pattern;
	Vertex *vlist;
{
	register Display *dpy;
	register XReq *req;
	int nbytes;

	GetReq(X_Draw, w);
	dpy->lastdraw = (caddr_t) req;
	req->func = func;
	req->mask = planes;
	req->param.s[0] = vcount;
	req->param.u[1] = pixel;
	req->param.b[4] = height;
	req->param.b[5] = width;
	req->param.s[3] = DrawDashedLine;
	req->param.s[5] = pattern & 0xffff;  /* pattern string */
	req->param.s[6] = ((pattern & 0xf0000) >> 16) + 1;  /* pattern length */
	req->param.s[7] = (pattern & 0xf00000) >> 20;  /* pattern multiplier */
	nbytes = vcount*sizeof(Vertex);
	Data(dpy, (char *) vlist, nbytes);
}

