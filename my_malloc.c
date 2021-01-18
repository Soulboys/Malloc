/*
** EPITECH PROJECT, 2019
** CPE_malloc_2019
** File description:
** __DESCRIPTION__
*/

#include "include/my.h"

mall_s *map;

void *malloc(size_t size)
{
    size_t i = 1;

    for(; size % 4 != 0; size++);
    if (size == 0 || size < 0) {
        return (NULL);
    }
    return (malloc_fct(size));
}

void free(void *ptr)
{
    mall_s *tmp = map;

    if (!ptr)
        return;
    if ((map && !map->next && map->free == true) || !map) {
        map = NULL;
        return;
    }
    for (; tmp; tmp = tmp->next) {
        if (tmp->limit == ptr) {
            free_block(tmp);
        }
    }
    return;
}

void *calloc(size_t nmemb, size_t size)
{
    void *mal = malloc(size * nmemb);
    memset(mal, 0, size*nmemb);
    return (mal);
}

void *realloc(void *ptr, size_t size)
{
    void *tmp;
    if (ptr && size) {
        tmp = malloc(size);
        memcpy(tmp, ptr, size);
        free(ptr);
        return (tmp);
    }
    return (malloc(size));
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    return (realloc(ptr, nmemb * size));
}
