/* oshmem/include/shmem.h.  Generated from shmem.h.in by configure.  */
/*
 * Copyright (c) 2014-2015 Mellanox Technologies, Inc.
 *                         All rights reserved.
 * Copyright (c) 2014      Intel, Inc. All rights reserved
 * $COPYRIGHT$
 *
 * Additional copyrights may follow
 *
 * $HEADER$
 */

#ifndef OSHMEM_SHMEM_H
#define OSHMEM_SHMEM_H


#include <stddef.h>     /* include for ptrdiff_t */
#include <stdint.h>     /* include for fixed width types */
#if defined(c_plusplus) || defined(__cplusplus)
#    include <complex>
#    define OSHMEM_COMPLEX_TYPE(type)    std::complex<type>
#else
#    include <complex.h>
#    define OSHMEM_COMPLEX_TYPE(type)    type complex
#endif


/*
 * SHMEM version
 */
#define OSHMEM_MAJOR_VERSION 1
#define OSHMEM_MINOR_VERSION 10
#define OSHMEM_RELEASE_VERSION 5


#ifndef OSHMEM_DECLSPEC
#  if defined(OPAL_C_HAVE_VISIBILITY) && (OPAL_C_HAVE_VISIBILITY == 1)
#     define OSHMEM_DECLSPEC __attribute__((visibility("default")))
#  else
#     define OSHMEM_DECLSPEC
#  endif
#endif

#ifndef OSHMEM_DESTRUCTOR
#    if defined(OPAL_C_HAVE_VISIBILITY) && (OPAL_C_HAVE_VISIBILITY == 1)
#       define OSHMEM_DESTRUCTOR  __attribute__((__destructor__))
#    else
#       define OSHMEM_DESTRUCTOR
#    endif
#endif

#include <shmem-compat.h>

#if defined(c_plusplus) || defined(__cplusplus)
extern "C" {
#endif


/*
 * OpenSHMEM API (www.openshmem.org)
 */

/*
 * Environment variables
 */

/* Following environment variables are Mellanox extension */

/* size of symmetric heap in bytes.
 * Can be qualified with the letter 'K', 'M', 'G' or 'T'
 */
#define SHMEM_HEAP_SIZE "SHMEM_SYMMETRIC_HEAP_SIZE"

/*
 * Type of allocator used by symmetric heap
 */
#define SHMEM_HEAP_TYPE "SHMEM_SYMMETRIC_HEAP_ALLOCATOR"

/*
 * Constants and definitions
 */
#define SHMEM_MAJOR_VERSION             1
#define SHMEM_MINOR_VERSION             2
#define SHMEM_VENDOR_STRING             "http://www.open-mpi.org/"
#define SHMEM_MAX_NAME_LEN              256

#ifndef OSHMEM_SPEC_VERSION
#define OSHMEM_SPEC_VERSION (SHMEM_MAJOR_VERSION * 10000 + SHMEM_MINOR_VERSION * 100)
#endif

enum shmem_wait_ops {
    SHMEM_CMP_EQ,
    SHMEM_CMP_NE,
    SHMEM_CMP_GT,
    SHMEM_CMP_LE,
    SHMEM_CMP_LT,
    SHMEM_CMP_GE
};

#define _SHMEM_BARRIER_SYNC_SIZE        (1)
#define _SHMEM_BCAST_SYNC_SIZE          (1 + _SHMEM_BARRIER_SYNC_SIZE)
#define _SHMEM_COLLECT_SYNC_SIZE        (1 + _SHMEM_BCAST_SYNC_SIZE)
#define _SHMEM_REDUCE_SYNC_SIZE         (1 + _SHMEM_BCAST_SYNC_SIZE)
#define _SHMEM_REDUCE_MIN_WRKDATA_SIZE  (1)
#define _SHMEM_SYNC_VALUE               (-1)

#define SHMEM_BARRIER_SYNC_SIZE        _SHMEM_BARRIER_SYNC_SIZE
#define SHMEM_BCAST_SYNC_SIZE          _SHMEM_BCAST_SYNC_SIZE
#define SHMEM_COLLECT_SYNC_SIZE        _SHMEM_COLLECT_SYNC_SIZE
#define SHMEM_REDUCE_SYNC_SIZE         _SHMEM_REDUCE_SYNC_SIZE
#define SHMEM_REDUCE_MIN_WRKDATA_SIZE  _SHMEM_REDUCE_MIN_WRKDATA_SIZE
#define SHMEM_SYNC_VALUE               _SHMEM_SYNC_VALUE


/*
 * Initialization routines
 */
OSHMEM_DECLSPEC  void shmem_init(void);
OSHMEM_DECLSPEC  void shmem_finalize(void) OSHMEM_DESTRUCTOR;
OSHMEM_DECLSPEC  void shmem_global_exit(int status);

/*
 * Query routines
 */
OSHMEM_DECLSPEC  int shmem_n_pes(void);
OSHMEM_DECLSPEC  int shmem_my_pe(void);

/*
 * Info routines
 */
OSHMEM_DECLSPEC void shmem_info_get_version(int *major, int *minor);
OSHMEM_DECLSPEC void shmem_info_get_name(char *name);

/*
 * Accessability routines
 */
OSHMEM_DECLSPEC int shmem_pe_accessible(int pe);
OSHMEM_DECLSPEC int shmem_addr_accessible(void *addr, int pe);

/*
 * Symmetric heap routines
 */
OSHMEM_DECLSPEC  void* shmem_malloc(size_t size);
OSHMEM_DECLSPEC  void* shmem_align(size_t align, size_t size);
OSHMEM_DECLSPEC  void* shmem_realloc(void *ptr, size_t size);
OSHMEM_DECLSPEC  void shmem_free(void* ptr);

/*
 * Remote pointer operations
 */
OSHMEM_DECLSPEC  void *shmem_ptr(void *ptr, int pe);

/*
 * Elemental put routines
 */
OSHMEM_DECLSPEC  void shmem_char_p(char* addr, char value, int pe);
OSHMEM_DECLSPEC  void shmem_short_p(short* addr, short value, int pe);
OSHMEM_DECLSPEC  void shmem_int_p(int* addr, int value, int pe);
OSHMEM_DECLSPEC  void shmem_long_p(long* addr, long value, int pe);
OSHMEM_DECLSPEC  void shmem_float_p(float* addr, float value, int pe);
OSHMEM_DECLSPEC  void shmem_double_p(double* addr, double value, int pe);
OSHMEM_DECLSPEC  void shmem_longlong_p(long long* addr, long long value, int pe);
OSHMEM_DECLSPEC  void shmem_longdouble_p(long double* addr, long double value, int pe);

/*
 * Block data put routines
 */
OSHMEM_DECLSPEC  void shmem_short_put(short *target, const short *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_int_put(int* target, const int* source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_long_put(long *target, const long *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_float_put(float *target, const float *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_double_put(double *target, const double *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_longlong_put(long long *target, const long long *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_longdouble_put(long double *target, const long double *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_put32(void *target, const void *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_put64(void *target, const void *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_put128(void *target, const void *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_putmem(void *target, const void *source, size_t len, int pe);

/*
 * Strided put routines
 */
OSHMEM_DECLSPEC void shmem_short_iput(short* target, const short* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_int_iput(int* target, const int* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_float_iput(float* target, const float* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_double_iput(double* target, const double* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_longlong_iput(long long* target, const long long* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_longdouble_iput(long double* target, const long double* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_long_iput(long* target, const long* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_iput32(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_iput64(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_iput128(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);

/*
 * Elemental get routines
 */
OSHMEM_DECLSPEC  char shmem_char_g(char* addr, int pe);
OSHMEM_DECLSPEC  short shmem_short_g(short* addr, int pe);
OSHMEM_DECLSPEC  int shmem_int_g(int* addr, int pe);
OSHMEM_DECLSPEC  long shmem_long_g(long* addr, int pe);
OSHMEM_DECLSPEC  float shmem_float_g(float* addr, int pe);
OSHMEM_DECLSPEC  double shmem_double_g(double* addr, int pe);
OSHMEM_DECLSPEC  long long shmem_longlong_g(long long* addr, int pe);
OSHMEM_DECLSPEC  long double shmem_longdouble_g(long double* addr, int pe);

/*
 * Block data get routines
 */
OSHMEM_DECLSPEC  void shmem_short_get(short *target, const short *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_int_get(int *target, const int *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_long_get(long *target, const long *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_float_get(float *target, const float *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_double_get(double *target, const double *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_longlong_get(long long *target, const long long *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_longdouble_get(long double *target, const long double *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_get32(void *target, const void *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_get64(void *target, const void *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_get128(void *target, const void *source, size_t len, int pe);
OSHMEM_DECLSPEC  void shmem_getmem(void *target, const void *source, size_t len, int pe);

/*
 * Strided get routines
 */
OSHMEM_DECLSPEC void shmem_short_iget(short* target, const short* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_int_iget(int* target, const int* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_float_iget(float* target, const float* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_double_iget(double* target, const double* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_longlong_iget(long long* target, const long long* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_longdouble_iget(long double* target, const long double* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_long_iget(long* target, const long* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_iget32(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_iget64(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);
OSHMEM_DECLSPEC void shmem_iget128(void* target, const void* source, ptrdiff_t tst, ptrdiff_t sst,size_t len, int pe);

/*
 * Atomic operations
 */
/* Atomic swap */
OSHMEM_DECLSPEC long shmem_swap(long *target, long value, int pe);
OSHMEM_DECLSPEC double shmem_double_swap(double *target, double value, int pe);
OSHMEM_DECLSPEC float shmem_float_swap(float *target, float value, int pe);
OSHMEM_DECLSPEC int shmem_int_swap(int *target, int value, int pe);
OSHMEM_DECLSPEC long shmem_long_swap(long *target, long value, int pe);
OSHMEM_DECLSPEC long long shmem_longlong_swap(long long*target, long long value, int pe);

/* Atomic conditional swap */
OSHMEM_DECLSPEC int shmem_int_cswap(int *target, int cond, int value, int pe);
OSHMEM_DECLSPEC long shmem_long_cswap(long *target, long cond, long value, int pe);
OSHMEM_DECLSPEC long long shmem_longlong_cswap(long long *target, long long cond, long long value, int pe);

/* Atomic Fetch&Add */
OSHMEM_DECLSPEC int shmem_int_fadd(int *target, int value, int pe);
OSHMEM_DECLSPEC long shmem_long_fadd(long *target, long value, int pe);
OSHMEM_DECLSPEC long long shmem_longlong_fadd(long long *target, long long value, int pe);

/* Atomic Fetch&Inc */
OSHMEM_DECLSPEC int shmem_int_finc(int *target, int pe);
OSHMEM_DECLSPEC long shmem_long_finc(long *target, int pe);
OSHMEM_DECLSPEC long long shmem_longlong_finc(long long *target, int pe);

/* Atomic Add*/
OSHMEM_DECLSPEC void shmem_int_add(int *target, int value, int pe);
OSHMEM_DECLSPEC void shmem_long_add(long *target, long value, int pe);
OSHMEM_DECLSPEC void shmem_longlong_add(long long *target, long long value, int pe);

/* Atomic Inc */
OSHMEM_DECLSPEC void shmem_int_inc(int *target, int pe);
OSHMEM_DECLSPEC void shmem_long_inc(long *target, int pe);
OSHMEM_DECLSPEC void shmem_longlong_inc(long long *target, int pe);

/*
 * Lock functions
 */
OSHMEM_DECLSPEC void shmem_set_lock(long *lock);
OSHMEM_DECLSPEC void shmem_clear_lock(long *lock);
OSHMEM_DECLSPEC int shmem_test_lock(long *lock);

/*
 * P2P sync routines
 */
OSHMEM_DECLSPEC  void shmem_short_wait(short *addr, short value);
OSHMEM_DECLSPEC  void shmem_int_wait(int *addr, int value);
OSHMEM_DECLSPEC  void shmem_long_wait(long *addr, long value);
OSHMEM_DECLSPEC  void shmem_longlong_wait(long long *addr, long long value);
OSHMEM_DECLSPEC  void shmem_wait(long *addr, long value);

OSHMEM_DECLSPEC  void shmem_short_wait_until(short *addr, int cmp, short value);
OSHMEM_DECLSPEC  void shmem_int_wait_until(int *addr, int cmp, int value);
OSHMEM_DECLSPEC  void shmem_long_wait_until(long *addr, int cmp, long value);
OSHMEM_DECLSPEC  void shmem_longlong_wait_until(long long *addr, int cmp, long long value);
OSHMEM_DECLSPEC  void shmem_wait_until(long *addr, int cmp, long value);

/*
 * Barrier sync routines
 */
OSHMEM_DECLSPEC  void shmem_barrier(int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC  void shmem_barrier_all(void);
OSHMEM_DECLSPEC  void shmem_fence(void);
OSHMEM_DECLSPEC  void shmem_quiet(void);

/*
 * Collective routines
 */
OSHMEM_DECLSPEC void shmem_broadcast32(void *target, const void *source, size_t nlong, int PE_root, int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC void shmem_broadcast64(void *target, const void *source, size_t nlong, int PE_root, int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC void shmem_broadcast(void *target, const void *source, size_t nlong, int PE_root, int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC void shmem_collect32(void *target, const void *source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC void shmem_collect64(void *target, const void *source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC void shmem_fcollect32(void *target, const void *source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long *pSync);
OSHMEM_DECLSPEC void shmem_fcollect64(void *target, const void *source, size_t nlong, int PE_start, int logPE_stride, int PE_size, long *pSync);

/*
 * Reduction routines
 */
OSHMEM_DECLSPEC void shmem_short_and_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_and_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_and_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_and_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);

OSHMEM_DECLSPEC void shmem_short_or_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_or_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_or_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_or_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);

OSHMEM_DECLSPEC void shmem_short_xor_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_xor_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_xor_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_xor_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);

OSHMEM_DECLSPEC void shmem_short_max_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_max_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_max_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_max_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_float_max_to_all(float *target, float *source, int nreduce, int PE_start, int logPE_stride, int PE_size, float *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_double_max_to_all(double *target, double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, double *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longdouble_max_to_all(long double *target, long double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double *pWrk, long *pSync);

OSHMEM_DECLSPEC void shmem_short_min_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_min_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_min_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_min_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_float_min_to_all(float *target, float *source, int nreduce, int PE_start, int logPE_stride, int PE_size, float *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_double_min_to_all(double *target, double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, double *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longdouble_min_to_all(long double *target, long double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double *pWrk, long *pSync);

OSHMEM_DECLSPEC void shmem_short_sum_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_sum_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_sum_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_sum_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_float_sum_to_all(float *target, float *source, int nreduce, int PE_start, int logPE_stride, int PE_size, float *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_double_sum_to_all(double *target, double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, double *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longdouble_sum_to_all(long double *target, long double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_complexf_sum_to_all(OSHMEM_COMPLEX_TYPE(float) *target, OSHMEM_COMPLEX_TYPE(float) *source, int nreduce, int PE_start, int logPE_stride, int PE_size, OSHMEM_COMPLEX_TYPE(float) *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_complexd_sum_to_all(OSHMEM_COMPLEX_TYPE(double) *target, OSHMEM_COMPLEX_TYPE(double) *source, int nreduce, int PE_start, int logPE_stride, int PE_size, OSHMEM_COMPLEX_TYPE(double) *pWrk, long *pSync);

OSHMEM_DECLSPEC void shmem_short_prod_to_all(short *target, short *source, int nreduce, int PE_start, int logPE_stride, int PE_size, short *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_int_prod_to_all(int *target, int *source, int nreduce, int PE_start, int logPE_stride, int PE_size, int *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_long_prod_to_all(long *target, long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longlong_prod_to_all(long long *target, long long *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long long *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_float_prod_to_all(float *target, float *source, int nreduce, int PE_start, int logPE_stride, int PE_size, float *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_double_prod_to_all(double *target, double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, double *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_longdouble_prod_to_all(long double *target, long double *source, int nreduce, int PE_start, int logPE_stride, int PE_size, long double *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_complexf_prod_to_all(OSHMEM_COMPLEX_TYPE(float) *target, OSHMEM_COMPLEX_TYPE(float) *source, int nreduce, int PE_start, int logPE_stride, int PE_size, OSHMEM_COMPLEX_TYPE(float) *pWrk, long *pSync);
OSHMEM_DECLSPEC void shmem_complexd_prod_to_all(OSHMEM_COMPLEX_TYPE(double) *target, OSHMEM_COMPLEX_TYPE(double) *source, int nreduce, int PE_start, int logPE_stride, int PE_size, OSHMEM_COMPLEX_TYPE(double) *pWrk, long *pSync);

/*
 * Platform specific cache management routines
 */
OSHMEM_DECLSPEC void shmem_udcflush(void);
OSHMEM_DECLSPEC void shmem_udcflush_line(void* target);
OSHMEM_DECLSPEC void shmem_set_cache_inv(void);
OSHMEM_DECLSPEC void shmem_set_cache_line_inv(void* target);
OSHMEM_DECLSPEC void shmem_clear_cache_inv(void);
OSHMEM_DECLSPEC void shmem_clear_cache_line_inv(void* target);

#if defined(c_plusplus) || defined(__cplusplus)
}
#endif


#endif /* OSHMEM_SHMEM_H */
