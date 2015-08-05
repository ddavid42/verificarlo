/********************************************************************************
 *                                                                              *
 *  This file is part of Verificarlo.                                           *
 *                                                                              *
 *  Copyright (c) 2015                                                          *
 *     Universite de Versailles St-Quentin-en-Yvelines                          *
 *     CMLA, Ecole Normale Superieure de Cachan                                 *
 *                                                                              *
 *  Verificarlo is free software: you can redistribute it and/or modify         *
 *  it under the terms of the GNU General Public License as published by        *
 *  the Free Software Foundation, either version 3 of the License, or           *
 *  (at your option) any later version.                                         *
 *                                                                              *
 *  Verificarlo is distributed in the hope that it will be useful,              *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of              *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
 *  GNU General Public License for more details.                                *
 *                                                                              *
 *  You should have received a copy of the GNU General Public License           *
 *  along with Verificarlo.  If not, see <http://www.gnu.org/licenses/>.        *
 *                                                                              *
 ********************************************************************************/

#include<mcalib.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VERIFICARLO_PRECISION "VERIFICARLO_PRECISION"
#define VERIFICARLO_MCAMODE "VERIFICARLO_MCAMODE"
#define VERIFICARLO_PRECISION_DEFAULT 24
#define VERIFICARLO_MCAMODE_DEFAULT MCALIB_MCA

__attribute__((constructor)) void begin (void)
{
    _mca_seed();

    char * endptr;

    /* Set default values for MCALIB*/

    MCALIB_T = VERIFICARLO_PRECISION_DEFAULT;
    MCALIB_OP_TYPE = VERIFICARLO_MCAMODE_DEFAULT;

    /* If VERIFICARLO_PRECISION is set, try to parse it */
    char * precision = getenv(VERIFICARLO_PRECISION);
    if (precision != NULL) {
        errno = 0;
        int val = strtol(precision, &endptr, 10);
        if (errno != 0 || val <= 0) {
            /* Invalid value provided */
            fprintf(stderr, VERIFICARLO_PRECISION
                   " invalid value provided, defaulting to default\n");
        } else {
            MCALIB_T = val;
        }
    }

     /* If VERIFICARLO_MCAMODE is set, try to parse it */
    char * mode = getenv(VERIFICARLO_MCAMODE);
    if (mode != NULL) {
        if (strcmp("IEEE", mode) == 0) {
            MCALIB_OP_TYPE = MCALIB_IEEE;
        }
        else if (strcmp("MCA", mode) == 0) {
            MCALIB_OP_TYPE = MCALIB_MCA;
        }
        else if (strcmp("PB", mode) == 0) {
            MCALIB_OP_TYPE = MCALIB_PB;
        }
        else if (strcmp("RR", mode) == 0) {
            MCALIB_OP_TYPE = MCALIB_RR;
        } else {
            /* Invalid value provided */
            fprintf(stderr, VERIFICARLO_MCAMODE
                   " invalid value provided, defaulting to default\n");
        }
    }
}

typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double4 __attribute__((ext_vector_type(4)));
typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float4 __attribute__((ext_vector_type(4)));

double2 _2xdoubleadd(double2 a, double2 b) {
    double2 c;

    c[0] = _doubleadd(a[0],b[0]);
    c[1] = _doubleadd(a[1],b[1]);
    return c;
}

double2 _2xdoublesub(double2 a, double2 b) {
    double2 c;

    c[0] = _doublesub(a[0],b[0]);
    c[1] = _doublesub(a[1],b[1]);
    return c;
}

double2 _2xdoublemul(double2 a, double2 b) {
    double2 c;

    c[0] = _doublemul(a[0],b[0]);
    c[1] = _doublemul(a[1],b[1]);
    return c;
}

double2 _2xdoublediv(double2 a, double2 b) {
    double2 c;

    c[0] = _doublediv(a[0],b[0]);
    c[1] = _doublediv(a[1],b[1]);
    return c;
}

double4 _4xdoubleadd(double4 a, double4 b) {
    double4 c;

    c[0] = _doubleadd(a[0],b[0]);
    c[1] = _doubleadd(a[1],b[1]);
    c[2] = _doubleadd(a[2],b[2]);
    c[3] = _doubleadd(a[3],b[3]);
    return c;
}

double4 _4xdoublesub(double4 a, double4 b) {
    double4 c;

    c[0] = _doublesub(a[0],b[0]);
    c[1] = _doublesub(a[1],b[1]);
    c[2] = _doublesub(a[2],b[2]);
    c[3] = _doublesub(a[3],b[3]);
    return c;
}

double4 _4xdoublemul(double4 a, double4 b) {
    double4 c;

    c[0] = _doublemul(a[0],b[0]);
    c[1] = _doublemul(a[1],b[1]);
    c[2] = _doublemul(a[2],b[2]);
    c[3] = _doublemul(a[3],b[3]);
    return c;
}

double4 _4xdoublediv(double4 a, double4 b) {
    double4 c;

    c[0] = _doublediv(a[0],b[0]);
    c[1] = _doublediv(a[1],b[1]);
    c[2] = _doublediv(a[2],b[2]);
    c[3] = _doublediv(a[3],b[3]);
    return c;
}

float2 _2xfloatadd(float2 a, float2 b) {
    float2 c;

    c[0] = _floatadd(a[0],b[0]);
    c[1] = _floatadd(a[1],b[1]);
    return c;
}

float2 _2xfloatsub(float2 a, float2 b) {
    float2 c;

    c[0] = _floatsub(a[0],b[0]);
    c[1] = _floatsub(a[1],b[1]);
    return c;
}

float2 _2xfloatmul(float2 a, float2 b) {
    float2 c;

    c[0] = _floatmul(a[0],b[0]);
    c[1] = _floatmul(a[1],b[1]);
    return c;
}

float2 _2xfloatdiv(float2 a, float2 b) {
    float2 c;

    c[0] = _floatdiv(a[0],b[0]);
    c[1] = _floatdiv(a[1],b[1]);
    return c;
}

float4 _4xfloatadd(float4 a, float4 b) {
    float4 c;

    c[0] = _floatadd(a[0],b[0]);
    c[1] = _floatadd(a[1],b[1]);
    c[2] = _floatadd(a[2],b[2]);
    c[3] = _floatadd(a[3],b[3]);
    return c;
}

float4 _4xfloatsub(float4 a, float4 b) {
    float4 c;

    c[0] = _floatsub(a[0],b[0]);
    c[1] = _floatsub(a[1],b[1]);
    c[2] = _floatsub(a[2],b[2]);
    c[3] = _floatsub(a[3],b[3]);
    return c;
}

float4 _4xfloatmul(float4 a, float4 b) {
    float4 c;

    c[0] = _floatmul(a[0],b[0]);
    c[1] = _floatmul(a[1],b[1]);
    c[2] = _floatmul(a[2],b[2]);
    c[3] = _floatmul(a[3],b[3]);
    return c;
}

float4 _4xfloatdiv(float4 a, float4 b) {
    float4 c;

    c[0] = _floatdiv(a[0],b[0]);
    c[1] = _floatdiv(a[1],b[1]);
    c[2] = _floatdiv(a[2],b[2]);
    c[3] = _floatdiv(a[3],b[3]);
    return c;
}
