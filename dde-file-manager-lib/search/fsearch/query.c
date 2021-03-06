/**
 * Copyright (C) 2017 Uniontech Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/
#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "query.h"

FsearchQuery *
fsearch_query_new (const char *query,
                   void (*callback)(void *, void *),
                   void *callback_data,
                   void *sender,
                   bool match_case,
                   bool enable_regex,
                   bool auto_search_in_path,
                   bool search_in_path)
{
    FsearchQuery *q = calloc (1, sizeof (FsearchQuery));
    assert (q != NULL);
    if (query) {
        q->query = strdup (query);
    }
    q->callback = callback;
    q->callback_data = callback_data;
    q->sender = sender;
    q->match_case = match_case;
    q->enable_regex = enable_regex;
    q->auto_search_in_path = auto_search_in_path;
    q->search_in_path = search_in_path;
    return q;
}

void
fsearch_query_free (FsearchQuery *query)
{
    assert (query != NULL);
    if (query->query) {
        free (query->query);
        query->query = NULL;
    }
    free (query);
    query = NULL;
}
