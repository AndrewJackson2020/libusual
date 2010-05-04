/*
 * Pool for shared strings.
 *
 * Copyright (c) 2010  Marko Kreen, Skype Technologies OÜ
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _USUAL_STRPOOL_H_
#define _USUAL_STRPOOL_H_

#include <usual/base.h>

struct StrPool;

/* Pooled String */
struct PStr {
	struct StrPool *pool;
	int refcnt;
	int len;
	char str[];
};


struct StrPool *strpool_create(void);
void strpool_free(struct StrPool *sp);

struct PStr *strpool_get(struct StrPool *sp, const char *str, int len);

void strpool_incref(struct PStr *str);
void strpool_decref(struct PStr *str);

int strpool_total(struct StrPool *sp);

#endif

