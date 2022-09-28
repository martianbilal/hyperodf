/*
 * Copyright (c) 2014-2016 Dmitry V. Levin <ldv@strace.io>
 * Copyright (c) 2016-2021 The strace developers.
 * All rights reserved.
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */

#include "defs.h"


#include "asm_stat.h"

#if defined MPERS_IS_m32
# undef HAVE_STRUCT_STAT
# undef HAVE_STRUCT_STAT_ST_MTIME_NSEC
# ifdef HAVE_M32_STRUCT_STAT
#  define HAVE_STRUCT_STAT 1
#  ifdef HAVE_M32_STRUCT_STAT_ST_MTIME_NSEC
#   define HAVE_STRUCT_STAT_ST_MTIME_NSEC 1
#  endif /* HAVE_M32_STRUCT_STAT_ST_MTIME_NSEC */
# endif /* HAVE_M32_STRUCT_STAT */
#elif defined MPERS_IS_mx32
# undef HAVE_STRUCT_STAT
# undef HAVE_STRUCT_STAT_ST_MTIME_NSEC
# ifdef HAVE_MX32_STRUCT_STAT
#  define HAVE_STRUCT_STAT 1
#  ifdef HAVE_MX32_STRUCT_STAT_ST_MTIME_NSEC
#   define HAVE_STRUCT_STAT_ST_MTIME_NSEC 1
#  endif /* HAVE_MX32_STRUCT_STAT_ST_MTIME_NSEC */
# endif /* HAVE_MX32_STRUCT_STAT */
#else /* !MPERS_IS_m32 && !MPERS_IS_mx32 */
# define HAVE_STRUCT_STAT 1
#endif

#ifndef HAVE_STRUCT_STAT
struct stat {};
#endif

typedef struct stat struct_stat;

struct_stat mpers_target_var;
