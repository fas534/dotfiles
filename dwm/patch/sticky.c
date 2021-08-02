/* Project Name   - sticky.c */
/* Created On     - 07/31/21, 06:29:41 PM */
/* Author Name    - MD. Fahim Abrar Saikat */
/* Author E-mail  - saikat.cucse.52@gmail.com */
/* Author Github  - https://github.com/FA-Saikat */

/* -#define ISVISIBLE(C)            ((C->tags & C->mon->tagset[C->mon->seltags])) */
/* -	int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen; */


void
togglesticky(const Arg *arg)
{
	if (!selmon->sel)
		return;
	selmon->sel->issticky = !selmon->sel->issticky;
	arrange(selmon);
}

