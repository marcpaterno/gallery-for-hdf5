#ifndef COMPARE_HH
#define COMPARE_HH

#include "canvas/Persistency/Common/Assns.h"
#include "cetlib/compiler_macros.h"

#include <algorithm>
#include <iterator>
#include <type_traits>

#ifdef CET_NO_STD_CBEGIN_CEND
#define CBEGIN begin
#define CEND end
#else
#define CBEGIN cbegin
#define CEND cend
#endif

namespace art {
  template <typename A, typename B>
  inline
  bool operator == (Assns<A, B> const & left,
                    Assns<A, B> const & right)
  {
    using std::CBEGIN;
    using std::CEND;
    return left.size() == right.size() &&
      std::equal(CBEGIN(left), CEND(left), CBEGIN(right));
  }

  template <typename A, typename B>
  inline
  bool operator != (Assns<A, B> const & left,
                    Assns<A, B> const & right)
  {
    return !(left == right);
  }

  template <typename A, typename B, typename D>
  inline
  typename std::enable_if<!std::is_void<D>::value, bool>::type
  operator == (Assns<A, B, D> const & left,
               Assns<A, B, D> const & right)
  {
    if (left.size() != right.size()) return false;
    for (auto i = 0UL, sz = left.size(); i != sz; ++i) {
      if (!(left.data(i) == right.data(i) &&
            left[i] == right[i])) {
        return false;
      }
    }
    return true;
  }

  template <typename A, typename B, typename D>
  inline
  typename std::enable_if<!std::is_void<D>::value, bool>::type
  operator != (Assns<A, B, D> const & left,
               Assns<A, B, D> const & right)
  {
    return !(left == right);
  }
}

namespace recob {
  class Vertex;
  class Cluster;

  // Note this tests for equality, not equivalence or identity,.
  bool
  operator == (recob::Vertex const & left,
               recob::Vertex const & right);

  inline
  bool
  operator != (recob::Vertex const & left,
               recob::Vertex const & right)
  {
    return !(left == right);
  }

  // Note this tests for equality, not equivalence or identity,.
  bool
  operator == (recob::Cluster const & left,
               recob::Cluster const & right);

  inline
  bool
  operator != (recob::Cluster const & left,
               recob::Cluster const & right)

  {
    return !(left == right);
  }
}

#endif /* COMPARE_HH */
