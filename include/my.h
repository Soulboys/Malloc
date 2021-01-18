/*
** EPITECH PROJECT, 2019
** CPE_malloc_2019
** File description:
** __DESCRIPTION__
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


typedef struct mall_t {
    struct mall_t *next; 
    struct mall_t *prev;
    bool free;
    void *limit;
    size_t size;
} mall_s;

extern mall_s *map;

void *malloc(size_t size);
void display();
void free(void *ptr);
void *malloc_fct(size_t size);
mall_s *init_map(size_t size);
void *calloc(size_t nmemb, size_t size);
mall_s *searchfree(size_t size, mall_s *tmp);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
void the_free(mall_s *map, void *ptr);
mall_s *createmem(size_t size, mall_s *tmp);
void free_block(mall_s *tmp);
#endif