//===-- Implementation header for conjf16 -----------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIBC_SRC_COMPLEX_CONJF16_H
#define LLVM_LIBC_SRC_COMPLEX_CONJF16_H

#include "src/__support/macros/config.h"
#include "src/__support/macros/properties/complex_types.h"

namespace LIBC_NAMESPACE_DECL {

cfloat16 conjf16(cfloat16 x);

} // namespace LIBC_NAMESPACE_DECL

#endif // LLVM_LIBC_SRC_COMPLEX_CONJF16_H
