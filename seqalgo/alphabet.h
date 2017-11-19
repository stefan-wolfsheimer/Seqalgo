#pragma once
#include <utility>

namespace Seqalgo
{

  class IAlphabet
  {
  public:
    using LetterCodeType = std::size_t;
    virtual IAlphabet(){}
  };

  class Alphabet : public IAlphabet
  {
  };

}
