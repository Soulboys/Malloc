/*
** EPITECH PROJECT, 2019
** CPE_malloc_2019
** File description:
** __DESCRIPTION__
*/

#include "include/my.h"

void free_merge(mall_s *tmp)
{
    if (tmp->next && tmp->free && tmp->next->free) {
        tmp->size += tmp->next->size + sizeof(mall_s);
        tmp->next = tmp->next->next;
        if (tmp->next)
            tmp->next->prev = tmp;
    }
}

void free_block(mall_s *tmp)
{
    tmp->free = true;
    free_merge(tmp);
    if (tmp->prev)
        free_merge(tmp->prev);
}