//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ShuffleIterator Iter>
//   Iter rotate(Iter first, Iter middle, Iter last); // constexpr since C++20

#include <algorithm>
#include <cassert>
#include <memory>
#include <type_traits>
#include <vector>

#include "test_macros.h"
#include "test_iterators.h"
#include "type_algorithms.h"

struct TestIter {
  template <class Iter>
  TEST_CONSTEXPR_CXX20 void operator()() const {
    int ia[]     = {0};
    const int sa = static_cast<int>(sizeof(ia) / sizeof(ia[0]));
    Iter r       = std::rotate(Iter(ia), Iter(ia), Iter(ia));
    assert(base(r) == ia);
    assert(ia[0] == 0);
    r = std::rotate(Iter(ia), Iter(ia), Iter(ia + sa));
    assert(base(r) == ia + sa);
    assert(ia[0] == 0);
    r = std::rotate(Iter(ia), Iter(ia + sa), Iter(ia + sa));
    assert(base(r) == ia);
    assert(ia[0] == 0);

    int ib[]     = {0, 1};
    const int sb = static_cast<int>(sizeof(ib) / sizeof(ib[0]));
    r            = std::rotate(Iter(ib), Iter(ib), Iter(ib + sb));
    assert(base(r) == ib + sb);
    assert(ib[0] == 0);
    assert(ib[1] == 1);
    r = std::rotate(Iter(ib), Iter(ib + 1), Iter(ib + sb));
    assert(base(r) == ib + 1);
    assert(ib[0] == 1);
    assert(ib[1] == 0);
    r = std::rotate(Iter(ib), Iter(ib + sb), Iter(ib + sb));
    assert(base(r) == ib);
    assert(ib[0] == 1);
    assert(ib[1] == 0);

    int ic[]     = {0, 1, 2};
    const int sc = static_cast<int>(sizeof(ic) / sizeof(ic[0]));
    r            = std::rotate(Iter(ic), Iter(ic), Iter(ic + sc));
    assert(base(r) == ic + sc);
    assert(ic[0] == 0);
    assert(ic[1] == 1);
    assert(ic[2] == 2);
    r = std::rotate(Iter(ic), Iter(ic + 1), Iter(ic + sc));
    assert(base(r) == ic + 2);
    assert(ic[0] == 1);
    assert(ic[1] == 2);
    assert(ic[2] == 0);
    r = std::rotate(Iter(ic), Iter(ic + 2), Iter(ic + sc));
    assert(base(r) == ic + 1);
    assert(ic[0] == 0);
    assert(ic[1] == 1);
    assert(ic[2] == 2);
    r = std::rotate(Iter(ic), Iter(ic + sc), Iter(ic + sc));
    assert(base(r) == ic);
    assert(ic[0] == 0);
    assert(ic[1] == 1);
    assert(ic[2] == 2);

    int id[]     = {0, 1, 2, 3};
    const int sd = static_cast<int>(sizeof(id) / sizeof(id[0]));
    r            = std::rotate(Iter(id), Iter(id), Iter(id + sd));
    assert(base(r) == id + sd);
    assert(id[0] == 0);
    assert(id[1] == 1);
    assert(id[2] == 2);
    assert(id[3] == 3);
    r = std::rotate(Iter(id), Iter(id + 1), Iter(id + sd));
    assert(base(r) == id + 3);
    assert(id[0] == 1);
    assert(id[1] == 2);
    assert(id[2] == 3);
    assert(id[3] == 0);
    r = std::rotate(Iter(id), Iter(id + 2), Iter(id + sd));
    assert(base(r) == id + 2);
    assert(id[0] == 3);
    assert(id[1] == 0);
    assert(id[2] == 1);
    assert(id[3] == 2);
    r = std::rotate(Iter(id), Iter(id + 3), Iter(id + sd));
    assert(base(r) == id + 1);
    assert(id[0] == 2);
    assert(id[1] == 3);
    assert(id[2] == 0);
    assert(id[3] == 1);
    r = std::rotate(Iter(id), Iter(id + sd), Iter(id + sd));
    assert(base(r) == id);
    assert(id[0] == 2);
    assert(id[1] == 3);
    assert(id[2] == 0);
    assert(id[3] == 1);

    int ie[]     = {0, 1, 2, 3, 4};
    const int se = static_cast<int>(sizeof(ie) / sizeof(ie[0]));
    r            = std::rotate(Iter(ie), Iter(ie), Iter(ie + se));
    assert(base(r) == ie + se);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 2);
    assert(ie[3] == 3);
    assert(ie[4] == 4);
    r = std::rotate(Iter(ie), Iter(ie + 1), Iter(ie + se));
    assert(base(r) == ie + 4);
    assert(ie[0] == 1);
    assert(ie[1] == 2);
    assert(ie[2] == 3);
    assert(ie[3] == 4);
    assert(ie[4] == 0);
    r = std::rotate(Iter(ie), Iter(ie + 2), Iter(ie + se));
    assert(base(r) == ie + 3);
    assert(ie[0] == 3);
    assert(ie[1] == 4);
    assert(ie[2] == 0);
    assert(ie[3] == 1);
    assert(ie[4] == 2);
    r = std::rotate(Iter(ie), Iter(ie + 3), Iter(ie + se));
    assert(base(r) == ie + 2);
    assert(ie[0] == 1);
    assert(ie[1] == 2);
    assert(ie[2] == 3);
    assert(ie[3] == 4);
    assert(ie[4] == 0);
    r = std::rotate(Iter(ie), Iter(ie + 4), Iter(ie + se));
    assert(base(r) == ie + 1);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 2);
    assert(ie[3] == 3);
    assert(ie[4] == 4);
    r = std::rotate(Iter(ie), Iter(ie + se), Iter(ie + se));
    assert(base(r) == ie);
    assert(ie[0] == 0);
    assert(ie[1] == 1);
    assert(ie[2] == 2);
    assert(ie[3] == 3);
    assert(ie[4] == 4);

    int ig[]     = {0, 1, 2, 3, 4, 5};
    const int sg = static_cast<int>(sizeof(ig) / sizeof(ig[0]));
    r            = std::rotate(Iter(ig), Iter(ig), Iter(ig + sg));
    assert(base(r) == ig + sg);
    assert(ig[0] == 0);
    assert(ig[1] == 1);
    assert(ig[2] == 2);
    assert(ig[3] == 3);
    assert(ig[4] == 4);
    assert(ig[5] == 5);
    r = std::rotate(Iter(ig), Iter(ig + 1), Iter(ig + sg));
    assert(base(r) == ig + 5);
    assert(ig[0] == 1);
    assert(ig[1] == 2);
    assert(ig[2] == 3);
    assert(ig[3] == 4);
    assert(ig[4] == 5);
    assert(ig[5] == 0);
    r = std::rotate(Iter(ig), Iter(ig + 2), Iter(ig + sg));
    assert(base(r) == ig + 4);
    assert(ig[0] == 3);
    assert(ig[1] == 4);
    assert(ig[2] == 5);
    assert(ig[3] == 0);
    assert(ig[4] == 1);
    assert(ig[5] == 2);
    r = std::rotate(Iter(ig), Iter(ig + 3), Iter(ig + sg));
    assert(base(r) == ig + 3);
    assert(ig[0] == 0);
    assert(ig[1] == 1);
    assert(ig[2] == 2);
    assert(ig[3] == 3);
    assert(ig[4] == 4);
    assert(ig[5] == 5);
    r = std::rotate(Iter(ig), Iter(ig + 4), Iter(ig + sg));
    assert(base(r) == ig + 2);
    assert(ig[0] == 4);
    assert(ig[1] == 5);
    assert(ig[2] == 0);
    assert(ig[3] == 1);
    assert(ig[4] == 2);
    assert(ig[5] == 3);
    r = std::rotate(Iter(ig), Iter(ig + 5), Iter(ig + sg));
    assert(base(r) == ig + 1);
    assert(ig[0] == 3);
    assert(ig[1] == 4);
    assert(ig[2] == 5);
    assert(ig[3] == 0);
    assert(ig[4] == 1);
    assert(ig[5] == 2);
    r = std::rotate(Iter(ig), Iter(ig + sg), Iter(ig + sg));
    assert(base(r) == ig);
    assert(ig[0] == 3);
    assert(ig[1] == 4);
    assert(ig[2] == 5);
    assert(ig[3] == 0);
    assert(ig[4] == 1);
    assert(ig[5] == 2);
  }
};

#if TEST_STD_VER >= 11

struct TestUniquePtr {
  template <class Iter>
  TEST_CONSTEXPR_CXX23 void operator()() const {
    std::unique_ptr<int> ia[1];
    const int sa = static_cast<int>(sizeof(ia) / sizeof(ia[0]));
    for (int i = 0; i < sa; ++i)
      ia[i].reset(new int(i));
    Iter r = std::rotate(Iter(ia), Iter(ia), Iter(ia));
    assert(base(r) == ia);
    assert(*ia[0] == 0);
    r = std::rotate(Iter(ia), Iter(ia), Iter(ia + sa));
    assert(base(r) == ia + sa);
    assert(*ia[0] == 0);
    r = std::rotate(Iter(ia), Iter(ia + sa), Iter(ia + sa));
    assert(base(r) == ia);
    assert(*ia[0] == 0);

    std::unique_ptr<int> ib[2];
    const int sb = static_cast<int>(sizeof(ib) / sizeof(ib[0]));
    for (int i = 0; i < sb; ++i)
      ib[i].reset(new int(i));
    r = std::rotate(Iter(ib), Iter(ib), Iter(ib + sb));
    assert(base(r) == ib + sb);
    assert(*ib[0] == 0);
    assert(*ib[1] == 1);
    r = std::rotate(Iter(ib), Iter(ib + 1), Iter(ib + sb));
    assert(base(r) == ib + 1);
    assert(*ib[0] == 1);
    assert(*ib[1] == 0);
    r = std::rotate(Iter(ib), Iter(ib + sb), Iter(ib + sb));
    assert(base(r) == ib);
    assert(*ib[0] == 1);
    assert(*ib[1] == 0);

    std::unique_ptr<int> ic[3];
    const int sc = static_cast<int>(sizeof(ic) / sizeof(ic[0]));
    for (int i = 0; i < sc; ++i)
      ic[i].reset(new int(i));
    r = std::rotate(Iter(ic), Iter(ic), Iter(ic + sc));
    assert(base(r) == ic + sc);
    assert(*ic[0] == 0);
    assert(*ic[1] == 1);
    assert(*ic[2] == 2);
    r = std::rotate(Iter(ic), Iter(ic + 1), Iter(ic + sc));
    assert(base(r) == ic + 2);
    assert(*ic[0] == 1);
    assert(*ic[1] == 2);
    assert(*ic[2] == 0);
    r = std::rotate(Iter(ic), Iter(ic + 2), Iter(ic + sc));
    assert(base(r) == ic + 1);
    assert(*ic[0] == 0);
    assert(*ic[1] == 1);
    assert(*ic[2] == 2);
    r = std::rotate(Iter(ic), Iter(ic + sc), Iter(ic + sc));
    assert(base(r) == ic);
    assert(*ic[0] == 0);
    assert(*ic[1] == 1);
    assert(*ic[2] == 2);

    std::unique_ptr<int> id[4];
    const int sd = static_cast<int>(sizeof(id) / sizeof(id[0]));
    for (int i = 0; i < sd; ++i)
      id[i].reset(new int(i));
    r = std::rotate(Iter(id), Iter(id), Iter(id + sd));
    assert(base(r) == id + sd);
    assert(*id[0] == 0);
    assert(*id[1] == 1);
    assert(*id[2] == 2);
    assert(*id[3] == 3);
    r = std::rotate(Iter(id), Iter(id + 1), Iter(id + sd));
    assert(base(r) == id + 3);
    assert(*id[0] == 1);
    assert(*id[1] == 2);
    assert(*id[2] == 3);
    assert(*id[3] == 0);
    r = std::rotate(Iter(id), Iter(id + 2), Iter(id + sd));
    assert(base(r) == id + 2);
    assert(*id[0] == 3);
    assert(*id[1] == 0);
    assert(*id[2] == 1);
    assert(*id[3] == 2);
    r = std::rotate(Iter(id), Iter(id + 3), Iter(id + sd));
    assert(base(r) == id + 1);
    assert(*id[0] == 2);
    assert(*id[1] == 3);
    assert(*id[2] == 0);
    assert(*id[3] == 1);
    r = std::rotate(Iter(id), Iter(id + sd), Iter(id + sd));
    assert(base(r) == id);
    assert(*id[0] == 2);
    assert(*id[1] == 3);
    assert(*id[2] == 0);
    assert(*id[3] == 1);

    std::unique_ptr<int> ie[5];
    const int se = static_cast<int>(sizeof(ie) / sizeof(ie[0]));
    for (int i = 0; i < se; ++i)
      ie[i].reset(new int(i));
    r = std::rotate(Iter(ie), Iter(ie), Iter(ie + se));
    assert(base(r) == ie + se);
    assert(*ie[0] == 0);
    assert(*ie[1] == 1);
    assert(*ie[2] == 2);
    assert(*ie[3] == 3);
    assert(*ie[4] == 4);
    r = std::rotate(Iter(ie), Iter(ie + 1), Iter(ie + se));
    assert(base(r) == ie + 4);
    assert(*ie[0] == 1);
    assert(*ie[1] == 2);
    assert(*ie[2] == 3);
    assert(*ie[3] == 4);
    assert(*ie[4] == 0);
    r = std::rotate(Iter(ie), Iter(ie + 2), Iter(ie + se));
    assert(base(r) == ie + 3);
    assert(*ie[0] == 3);
    assert(*ie[1] == 4);
    assert(*ie[2] == 0);
    assert(*ie[3] == 1);
    assert(*ie[4] == 2);
    r = std::rotate(Iter(ie), Iter(ie + 3), Iter(ie + se));
    assert(base(r) == ie + 2);
    assert(*ie[0] == 1);
    assert(*ie[1] == 2);
    assert(*ie[2] == 3);
    assert(*ie[3] == 4);
    assert(*ie[4] == 0);
    r = std::rotate(Iter(ie), Iter(ie + 4), Iter(ie + se));
    assert(base(r) == ie + 1);
    assert(*ie[0] == 0);
    assert(*ie[1] == 1);
    assert(*ie[2] == 2);
    assert(*ie[3] == 3);
    assert(*ie[4] == 4);
    r = std::rotate(Iter(ie), Iter(ie + se), Iter(ie + se));
    assert(base(r) == ie);
    assert(*ie[0] == 0);
    assert(*ie[1] == 1);
    assert(*ie[2] == 2);
    assert(*ie[3] == 3);
    assert(*ie[4] == 4);

    std::unique_ptr<int> ig[6];
    const int sg = static_cast<int>(sizeof(ig) / sizeof(ig[0]));
    for (int i = 0; i < sg; ++i)
      ig[i].reset(new int(i));
    r = std::rotate(Iter(ig), Iter(ig), Iter(ig + sg));
    assert(base(r) == ig + sg);
    assert(*ig[0] == 0);
    assert(*ig[1] == 1);
    assert(*ig[2] == 2);
    assert(*ig[3] == 3);
    assert(*ig[4] == 4);
    assert(*ig[5] == 5);
    r = std::rotate(Iter(ig), Iter(ig + 1), Iter(ig + sg));
    assert(base(r) == ig + 5);
    assert(*ig[0] == 1);
    assert(*ig[1] == 2);
    assert(*ig[2] == 3);
    assert(*ig[3] == 4);
    assert(*ig[4] == 5);
    assert(*ig[5] == 0);
    r = std::rotate(Iter(ig), Iter(ig + 2), Iter(ig + sg));
    assert(base(r) == ig + 4);
    assert(*ig[0] == 3);
    assert(*ig[1] == 4);
    assert(*ig[2] == 5);
    assert(*ig[3] == 0);
    assert(*ig[4] == 1);
    assert(*ig[5] == 2);
    r = std::rotate(Iter(ig), Iter(ig + 3), Iter(ig + sg));
    assert(base(r) == ig + 3);
    assert(*ig[0] == 0);
    assert(*ig[1] == 1);
    assert(*ig[2] == 2);
    assert(*ig[3] == 3);
    assert(*ig[4] == 4);
    assert(*ig[5] == 5);
    r = std::rotate(Iter(ig), Iter(ig + 4), Iter(ig + sg));
    assert(base(r) == ig + 2);
    assert(*ig[0] == 4);
    assert(*ig[1] == 5);
    assert(*ig[2] == 0);
    assert(*ig[3] == 1);
    assert(*ig[4] == 2);
    assert(*ig[5] == 3);
    r = std::rotate(Iter(ig), Iter(ig + 5), Iter(ig + sg));
    assert(base(r) == ig + 1);
    assert(*ig[0] == 3);
    assert(*ig[1] == 4);
    assert(*ig[2] == 5);
    assert(*ig[3] == 0);
    assert(*ig[4] == 1);
    assert(*ig[5] == 2);
    r = std::rotate(Iter(ig), Iter(ig + sg), Iter(ig + sg));
    assert(base(r) == ig);
    assert(*ig[0] == 3);
    assert(*ig[1] == 4);
    assert(*ig[2] == 5);
    assert(*ig[3] == 0);
    assert(*ig[4] == 1);
    assert(*ig[5] == 2);
  }
};

#endif // TEST_STD_VER >= 11

template <std::size_t N>
TEST_CONSTEXPR_CXX20 bool test_vector_bool() {
  for (int offset = -4; offset <= 4; ++offset) {
    std::vector<bool> a(N, false);
    std::size_t mid = N / 2 + offset;
    for (std::size_t i = mid; i < N; ++i)
      a[i] = true;
    std::rotate(a.begin(), a.begin() + mid, a.end());
    for (std::size_t i = 0; i < N; ++i)
      assert(a[i] == (i < N - mid));
  }
  return true;
};

TEST_CONSTEXPR_CXX20 bool test() {
  types::for_each(types::forward_iterator_list<int*>(), TestIter());

#if TEST_STD_VER >= 11
  if (TEST_STD_VER >= 23 || !TEST_IS_CONSTANT_EVALUATED)
    types::for_each(types::forward_iterator_list<std::unique_ptr<int>*>(), TestUniquePtr());
#endif

  test_vector_bool<8>();
  test_vector_bool<19>();
  test_vector_bool<32>();
  test_vector_bool<49>();
  test_vector_bool<64>();
  test_vector_bool<199>();
  test_vector_bool<256>();

  return true;
}

int main(int, char**) {
  test();
#if TEST_STD_VER >= 20
  static_assert(test());
#endif

  return 0;
}
