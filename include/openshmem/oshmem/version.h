/*
 * Copyright (c) 2013      Mellanox Technologies, Inc.
 *                         All rights reserved.
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 *
 * This file should be included by any file that needs full
 * version information for the OSHMEM project
 */

#ifndef OSHMEM_VERSIONS_H
#define OSHMEM_VERSIONS_H

#define OSHMEM_MAJOR_VERSION 1
#define OSHMEM_MINOR_VERSION 10
#define OSHMEM_RELEASE_VERSION 5
#define OSHMEM_GREEK_VERSION ""
#define OSHMEM_WANT_REPO_REV @OSHMEM_WANT_REPO_REV@
#define OSHMEM_REPO_REV "v1.10.4-72-gfda17f8"
#ifdef OSHMEM_VERSION
/* If we included version.h, we want the real version, not the
   stripped (no-r number) version */
#undef OSHMEM_VERSION
#endif
#define OSHMEM_VERSION "1.10.5"

#endif
