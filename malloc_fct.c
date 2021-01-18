/*
** EPITECH PROJECT, 2019
** CPE_malloc_2019
** File description:
** __DESCRIPTION__
*/

#include "include/my.h"

mall_s *init_map(size_t size)
{
    mall_s *map_tmp = sbrk(size + sizeof(mall_s));

    if (map_tmp != (void*)-1) {
        map_tmp->next = NULL;
        map_tmp->prev = NULL;
        map_tmp->size = size;
        map_tmp->free = false;
        map_tmp->limit = map_tmp + 1;
        return (map_tmp);
    }
    return (NULL);
}

void split(mall_s *tmp, size_t size)
{
    mall_s *tt = NULL;

    if (size == tmp->size) {
            return;
    }
    tt = (mall_s *)((void *)tmp + size + sizeof(mall_s));
    tt->size = tmp->size - (size + sizeof(mall_s));
    tt->next = tmp->next;
    tt->prev = tmp;
    tt->free = true;
    tt->limit = tt + 1;
    if (tt->next)
        tt->next->prev = tt;
    tmp->size = size;
    tmp->free = false;
    tmp->next = tt;
}

mall_s *searchfree(size_t size, mall_s *tmp)
{
    if (!tmp)
        return (NULL);
    for (; tmp; tmp = tmp->next)
        if (tmp->free == true) {
            if (tmp->size == size) {
                tmp->free = false;
                return tmp;
            }
            else if (size + sizeof(mall_s) < tmp->size) {
                split(tmp, size);
                return (tmp);
            }
        }
    return (NULL);
}

mall_s *createmem(size_t size, mall_s *tmp)
{
    mall_s *init_tmp = init_map(size);

    if (init_tmp != (void*)-1) {
        for(; tmp && tmp->next != NULL; tmp = tmp->next);
        init_tmp->prev = tmp;
        tmp->next = init_tmp;
        return (tmp->next);
    }
    return (NULL);
}

void *malloc_fct(size_t size)
{
    mall_s *isfree = searchfree(size, map);

    if (map == NULL) {
        map = init_map(size);
        return (map ? map->limit : NULL);
    }
    if (isfree) {
        return (isfree->limit);
    }
    isfree = createmem(size, map);
    if (!isfree)
        return (NULL);
    return (isfree->limit);
}