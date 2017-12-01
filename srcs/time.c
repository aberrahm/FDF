# include "../includes/fdf.h"

int    temp_quit(void *data)
{
    static int  i;

    if (i <= 2000000)
        i++;
    else
        exit(0);
        return((int)data);
}
