# RUN: llvm-mc %s -triple=riscv32 -mattr=+zawrs -M no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=+zawrs -M no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zawrs < %s \
# RUN:     | llvm-objdump --mattr=+zawrs -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+zawrs < %s \
# RUN:     | llvm-objdump --mattr=+zawrs -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: wrs.nto
# CHECK-ASM: encoding: [0x73,0x00,0xd0,0x00]
wrs.nto

# CHECK-ASM-AND-OBJ: wrs.sto
# CHECK-ASM: encoding: [0x73,0x00,0xd0,0x01]
wrs.sto
