#ifndef __CVECTOR_TEST_H__
#define __CVECTOR_TEST_H__

// defaule cmocka includes
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../cvector_macros.h"

#define UNUSED(x) ((void)x)

typedef struct {
    int ia, ib;
    float fa, fb;
    char* pca;

    struct {
        int ia, ib;
        float fa, fb;
        char* pca;
    } struct_inner;
} struct_foo;

cvectorm_declare(int);
cvectorm_declare(struct_foo);

#endif /* __CVECTOR_TEST_H__ */
