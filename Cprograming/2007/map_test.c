#include <stdio.h>
#include "map.h"

int main()
{
    MAP a_map, *maptr;
    maptr = &a_map;
    VALUE c;

    init(maptr);
    if( !isEmpty(maptr))
        printf("how could this happened?\n"); 
    if( associate(maptr, 1, 'a') == -1)
        printf("insertion failed\n");
    if( associate(maptr, 2, 'b') == -1)
        printf("insertion failed\n");
    if( map(maptr, 1, &c) != -1)
        printf("The character associated with 1 is %c\n", c);
    else
        printf("There's no value associated with key 1\n");

    return 0;
}

