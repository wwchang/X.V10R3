#ifndef lint
static char *rcsid_Raise_c = "$Header: Raise.c,v 10.3 86/02/01 16:23:38 tony Rel $";
#endif	lint

/************************************************************************
 *									*
 *			Copyright (c) 1986 by				*
 *		Digital Equipment Corporation, Maynard, MA		*
 *		         All Rights Reserved.				*
 *									*
 *	Permission to use, copy, modify, and distribute this software	*
 *	and its documentation is hereby granted only to licensees of 	*
 *	The Regents of the University of California pursuant to their	*
 *	license agreement for the Berkeley Software Distribution 	*
 *	provided that the following appears on all copies.		*
 *									*
 *            "LICENSED FROM DIGITAL EQUIPMENT CORPORATION		*
 *                      COPYRIGHT (C) 1986				*	
 *                 DIGITAL EQUIPMENT CORPORATION			*
 *                         MAYNARD, MA					*
 *                     ALL RIGHTS RESERVED.				*
 *									*
 *      THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT	* 
 *	NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL	*
 *	EQUIPMENT CORPORATION.  DIGITAL MAKES NO REPRESENTATIONS	*
 *	ABOUT SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE. IT IS	*
 *	SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.		*
 *									*	
 * 	IF THE UNIVERSITY OF CALIFORNIA OR ITS LICENSEES MODIFY 	*	
 *	THE SOFTWARE IN A MANNER CREATING DERIVATIVE COPYRIGHT 		*	
 *	RIGHTS APPROPRIATE COPYRIGHT LEGENDS MAY BE PLACED ON THE	*
 *	DERIVATIVE WORK IN ADDITION TO THAT SET FORTH ABOVE."		*	
 *									*
 ************************************************************************/
 

/*
 * MODIFICATION HISTORY
 *
 * 000 -- M. Gancarz, DEC Ultrix Engineering Group
 */

#ifndef lint
static char *sccsid = "@(#)Raise.c	3.8	1/24/86";
#endif

#include "uwm.h"

Bool Raise(window, mask, button, x, y)
Window window;                          /* Event window. */
int mask;                               /* Button/key mask. */
short button;                           /* Button event detail. */
int x, y;                               /* Event mouse position. */
{
    /*
     * If the window is not the root window, raise the window and return.
     */
    if (window != RootWindow)
        XRaiseWindow(window);
    return(FALSE);
}
