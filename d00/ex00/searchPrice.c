#include "header.h"

int searchPrice(struct s_art **arts, char *name)
{
    if ((*arts)->name && name)
        while (*arts != NULL)
        {
            if (strcmp(name, (*arts)->name) == 0)
                return ( (*arts)->price );
            arts++;
        }
    return (-1);
}
