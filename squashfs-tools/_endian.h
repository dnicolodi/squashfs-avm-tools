#ifndef SQUASHFS_ENDIAN_H
#define SQUASHFS_ENDIAN_H

#define SQUASHFS4_LE 0
#define SQUASHFS4_BE 1

#ifndef linux
#define __BYTE_ORDER BYTE_ORDER
#define __BIG_ENDIAN BIG_ENDIAN
#define __LITTLE_ENDIAN LITTLE_ENDIAN
#else
#include <endian.h>
#endif

#if   defined(TARGET_FORMAT) && TARGET_FORMAT == SQUASHFS4_LE
#define TARGET_FORMAT_BYTE_ORDER __LITTLE_ENDIAN
#elif defined(TARGET_FORMAT) && TARGET_FORMAT == SQUASHFS4_BE
#define TARGET_FORMAT_BYTE_ORDER __BIG_ENDIAN
#else
#error "Invalid or no TARGET_FORMAT defined, it's expected to be either SQUASHFS4_LE (for little-endian) or SQUASHFS4_BE (for big-endian)"
#endif

#if !(defined(TARGET_FORMAT_BYTE_ORDER) && (TARGET_FORMAT_BYTE_ORDER == __LITTLE_ENDIAN || TARGET_FORMAT_BYTE_ORDER == __BIG_ENDIAN))
#error "Invalid or no TARGET_FORMAT_BYTE_ORDER defined, it's expected to be either __LITTLE_ENDIAN or __BIG_ENDIAN"
#endif

#endif /* SQUASHFS_ENDIAN_H */
