#include "map.h"
#include <stdio.h>

void init(MAP *map)
{
    map->size = 0;
    return;
}

int associate(MAP *map, KEY key, VALUE value)
{
    if(map->size == MAPSIZE) return -1;
    map->key[ map->size ] = key;
    map->value[ map->size ] = value;
    map->size++;
    return 1;
}

int map(MAP *map, KEY key, VALUE *value)
{
    int i = 0;
    for(i = 0 ; i < map->size ; i++) if(key == map->key[i]) break;
    if(i == map->size) return -1;
    *value = map->value[i];
    return 1;
}

int isEmpty(MAP *map)
{
    if(map->size == 0) return 1;
    return 0;
}

