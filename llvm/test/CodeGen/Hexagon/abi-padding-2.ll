; RUN: llc -mtriple=hexagon -mcpu=hexagonv65 < %s | FileCheck %s

; C file was:
; struct S { char b; long long a; };
; void foo(int x, struct S arg1);
; void bar() {
;   struct S s;
;   s.b = 'a';
;   foo(42, s);
;}

;
; Test that while passing a 7-byte struct on the stack, the
; size of the struct is 16 bytes including padding since its
; largest member is of type long long. This was being handled
; correctly but is a check against any potential future
; regressions.
;

; CHECK: memd(r{{[0-9]+}}+#8) =
; CHECK: memd(r{{[0-9]+}}+#0) =

%struct.S = type { i8, i64 }

; Function Attrs: nounwind
define dso_local void @bar() local_unnamed_addr #0 {
entry:
  %s = alloca %struct.S, align 8
  call void @llvm.lifetime.start.p0(i64 16, ptr nonnull %s) #3
  store i8 97, ptr %s, align 8
  tail call void @foo(i32 42, ptr nonnull byval(%struct.S) align 8 %s) #3
  call void @llvm.lifetime.end.p0(i64 16, ptr nonnull %s) #3
  ret void
}

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

declare dso_local void @foo(i32, ptr byval(%struct.S) align 8) local_unnamed_addr #2

; Function Attrs: argmemonly nounwind willreturn
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #1

