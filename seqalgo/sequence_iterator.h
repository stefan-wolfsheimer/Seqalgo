#pragma once
#include <iterator>

namespace Seqalgo
{
  namespace Impl
  {
    template<typename I>
    class SequenceIterator
    {
    public:
      // http://anderberg.me/2016/07/04/c-custom-iterators/
      // Iterator traits, previously from std::iterator.
      using value_type = typename I::value_type;
      using difference_type = std::ptrdiff_t;
      using pointer = typename I::pointer;
      using reference = typename I::reference;
      using iterator_category = std::random_access_iterator_tag;

      // Default constructible.
      SequenceIterator() = default;
      explicit SequenceIterator(I _iter) : iter(_iter)
      {}

      // Dereferencable.
      inline reference operator*() const
      {
        return *iter;
      }

      // Pre- and post-incrementable.
      inline SequenceIterator& operator++()
      {
        ++iter;
        return *this;
      }

      inline SequenceIterator operator++(int)
      {
        return SequenceIterator(iter++);
      }

      // Pre- and post-decrementable.
      inline SequenceIterator& operator--()
      { --iter;
        return *this;
      }

      inline SequenceIterator operator--(int)
      {
        return SequenceIterator(iter--);
      }

      // Equality / inequality.
      inline bool operator==(const SequenceIterator& rhs) const
      {
        return iter == rhs.iter;
      }

      inline bool operator!=(const SequenceIterator& rhs) const
      {
        return iter != rhs.iter;
      }
      
      inline bool operator<(const SequenceIterator& rhs) const
      {
        return iter < rhs.iter;
      }
      
      inline bool operator<=(const SequenceIterator& rhs) const
      {
        return iter <= rhs.iter;
      }
      
      inline bool operator>(const SequenceIterator& rhs) const
      {
        return iter > rhs.iter;
      }

      inline bool operator>=(const SequenceIterator& rhs) const
      {
        return iter >= rhs.iter;
      }

      SequenceIterator& operator+=(difference_type d)
      {
        iter+= d;
        return *this;
      }
      
      SequenceIterator& operator-=(difference_type d)
      {
        iter-= d;
        return *this;
      }

      SequenceIterator operator+(difference_type d) const
      {
        return SequenceIterator(iter + d);
      }

      SequenceIterator operator-(difference_type d) const
      {
        return SequenceIterator(iter - d);
      }
      
      reference operator[](difference_type d) const
      {
        return iter[d];
      }
      
    private:
      I iter;
    };
  }
}
