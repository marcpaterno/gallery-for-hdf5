#include "compare.hh"

#include "lardataobj/RecoBase/Vertex.h"
#include "lardataobj/RecoBase/Cluster.h"

bool
recob::operator == (recob::Vertex const & left,
                    recob::Vertex const & right)
{
  using std::CBEGIN;
  using std::CEND;
  return left.ID() == right.ID() &&
    [&]() { double l[3], r[3];
            left.XYZ(l);
            right.XYZ(r);
            return std::equal(CBEGIN(l), CEND(l), CBEGIN(r));
          }();
}

// Note this tests for equality, not equivalence or identity.
bool
recob::operator == (recob::Cluster const & left,
                    recob::Cluster const & right)
{
  return left.ID() == right.ID() &&
    left.NHits() == right.NHits() &&
    left.StartWire() == right.StartWire() &&
    left.StartTick() == right.StartTick() &&
    left.SigmaStartWire() == right.SigmaStartWire() &&
    left.SigmaStartTick() == right.SigmaStartTick() &&
    left.EndWire() == right.EndWire() &&
    left.EndTick() == right.EndTick() &&
    left.SigmaEndWire() == right.SigmaEndWire() &&
    left.SigmaEndTick() == right.SigmaEndTick() &&
    left.StartCharge() == right.StartCharge() &&
    left.StartAngle() == right.StartAngle() &&
    left.StartOpeningAngle() == right.StartOpeningAngle() &&
    left.EndCharge() == right.EndCharge() &&
    left.EndAngle() == right.EndAngle() &&
    left.EndOpeningAngle() == right.EndOpeningAngle() &&
    left.Integral() == right.Integral() &&
    left.IntegralStdDev() == right.IntegralStdDev() &&
    left.IntegralAverage() == right.IntegralAverage() &&
    left.SummedADC() == right.SummedADC() &&
    left.SummedADCstdDev() == right.SummedADCstdDev() &&
    left.SummedADCaverage() == right.SummedADCaverage() &&
    left.MultipleHitDensity() == right.MultipleHitDensity() &&
    left.Width() == right.Width() &&
    left.View() == right.View() &&
    left.Plane() == right.Plane();
}
