#include <stdio.h>
void reset_terminal()
{
	printf("\033c");
}
void clear_input_buffer()
{
	for (char clr_in; (clr_in = getchar()) != '\n' && clr_in != EOF;) {
	}
}
