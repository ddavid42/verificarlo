## Verificarlo

[![Build Status](https://travis-ci.org/verificarlo/verificarlo.svg?branch=master)](https://travis-ci.org/verificarlo/verificarlo)

A tool for automatic Montecarlo Arithmetic analysis.

### Installation

Please ensure that Verificarlo's dependencies are installed on your system:

  * mcalib, https://github.com/mfrechtling/mcalib
  * LLVM, clang and opt 3.3 or 3.4, http://clang.llvm.org/
  * gcc, gfortran and dragonegg (for Fortran support), http://dragonegg.llvm.org/
  * python, version >= 2.4
  * autotools (automake, autoconf)

Then run the following command inside verificarlo directory:

```bash
   $ ./autogen.sh
   $ ./configure
   $ make
```

If needed LLVM path, dragonegg path, and gcc path can be configured with the
following options:

```bash
   $ ./configure --with-llvm=<path to llvm install directory> \
                 --with-dragonegg=<path to dragonegg.so> \
                 CC=<gcc binary compatible with installed dragonegg>
```

Once installation is over, we recommend that you run the test suite to ensure verificarlo works as expected
on your system:

```bash
   $ make check
```


For example on an x86_64 Ubuntu 14.04 release, you should use the following
install procedure:

```bash
   # install mcalib manually following instructions at
   # https://github.com/mfrechtling/mcalib
   # ensure that the installation directory is added to your LD_LIBRARY_PATH

   $ sudo apt-get install clang-3.3 llvm3.3-dev dragonegg-4.7 gcc-4.7 \
               gfortran-4.7 autoconf automake build-essential

   $ cd verificarlo/
   $ ./autogen.sh
   $ ./configure \
       --with-dragonegg=/usr/lib/gcc/x86_64-linux-gnu/4.7/plugin/dragonegg.so \
       CC=gcc-4.7
   $ make && make check
```

### Usage

To automatically instrument a program with Verificarlo you must compile it using
the `verificarlo` command. First make sure to add the `verificarlo/` root
directory to your path with

```bash
   $ export PATH=<verificarlo path>:$PATH
```

Then you can use the `verificarlo` command to compile your programs. Either modify
your makefile to use `verificarlo` as the compiler (`CC=verificarlo` and
`FC=verificarlo` ) and linker (`LD=verificarlo`) or use the verificarlo command
directly:

```bash
   $ verificarlo *.c *.f90 -o ./program
```

### Examples

The `tests/` directory contains various examples of Verificarlo usage.