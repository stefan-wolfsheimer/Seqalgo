#pragma once
#include <utilty>
#include <vector>
#include "ialphabet.h"

namespace Seqalgo
{
  class Sequence
  {
  public:
    using LetterCodeType =
      IAlphabet::LetterCodeType;
    using ContainerType =
      std::vector<LetterCodeType>;
    using iterator =
      Impl::SequenceIterator<ContainerType::iterator>;
    using const_iterator =
      Impl::SequenceIterator<ContainerType::const_iterator>;
    using reverse_iterator =
      Impl::SequenceIterator<ContainerType::reverse_iterator>;
    using const_reverse_iterator =
      Impl::SequenceIterator<ContainerType::const_reverse_iterator>;
    Sequence(std::shared_ptr<Alphabet> alphabet);
  private:
    std::vector<LetterCodeType> data;
  };
}

Seqalgo::Sequence::Sequence(std::shared_ptr<Alphabet> alphabet)
{
}
