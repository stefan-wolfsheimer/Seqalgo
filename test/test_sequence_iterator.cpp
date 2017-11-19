/*******************************************************************************
The MIT License (MIT)

Copyright (c) 2017 stefan-wolfsheimer

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*******************************************************************************/

#include <catch.hpp>
#include "sequence_iterator.h"

template<typename I>
void sequenceIteratorTests(I itr)
{
  auto i0 = itr;
  auto i1 = itr + 1;
  auto i2 = itr + 2;
  auto i3 = itr + 3;

  REQUIRE(*itr == 0);
  REQUIRE(*++itr == 1);
  REQUIRE(*(itr++) == 1);
  REQUIRE(itr == i2);
  REQUIRE(*--itr == 1);
  REQUIRE(*(itr--) == 1);
  REQUIRE(*itr == 0);
  REQUIRE((itr+=3) == i3);
  REQUIRE((itr-=2) == i1);
  REQUIRE(i2 == i2);
  REQUIRE(i2 != i0);
  REQUIRE(i2 < i3);
  REQUIRE(i2 <= i3);
  REQUIRE(i2 <= i2);
  REQUIRE(i2 > i1);
  REQUIRE(i2 >= i1);
  REQUIRE(i2 >= i2);
  REQUIRE(i0 + 2 == i2);
  REQUIRE(i3 - 2 == i1);

  REQUIRE(i1[-1] == 0);
  REQUIRE(i1[0] == 1);
  REQUIRE(i1[1] == 2);
}

TEST_CASE("SequenceIterator", "[SequenceIterator]")
{
  std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
  using BaseIterator = std::vector<int>::iterator;
  using SequenceIterator = Seqalgo::Impl::SequenceIterator<BaseIterator>;
  sequenceIteratorTests<SequenceIterator>(SequenceIterator(v.begin()));
}

TEST_CASE("ConstSequenceIterator", "[SequenceIterator]")
{
  std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
  using BaseIterator = std::vector<int>::const_iterator;
  using SequenceIterator = Seqalgo::Impl::SequenceIterator<BaseIterator>;
  sequenceIteratorTests<SequenceIterator>(SequenceIterator(v.begin()));
}


TEST_CASE("ReverseSequenceIterator", "[SequenceIterator]")
{
  std::vector<int> v{9,8,7,6,5,4,3,2,1,0};
  using BaseIterator = std::vector<int>::reverse_iterator;
  using SequenceIterator = Seqalgo::Impl::SequenceIterator<BaseIterator>;
  sequenceIteratorTests<SequenceIterator>(SequenceIterator(v.rbegin()));
}

TEST_CASE("ConstReverseSequenceIterator", "[SequenceIterator]")
{
  std::vector<int> v{9,8,7,6,5,4,3,2,1,0};
  using BaseIterator = std::vector<int>::const_reverse_iterator;
  using SequenceIterator = Seqalgo::Impl::SequenceIterator<BaseIterator>;
  sequenceIteratorTests<SequenceIterator>(SequenceIterator(v.rbegin()));
}
