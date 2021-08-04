//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./lie_group_ops.h"

#include <algorithm>
#include <cmath>

#include <sym/rot2.h>

namespace sym {
namespace rot2 {

template <typename Scalar>
sym::Rot2<Scalar> LieGroupOps<Scalar>::FromTangent(const Eigen::Matrix<Scalar, 1, 1>& vec,
                                                   const Scalar epsilon) {
  // Total ops: 2

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = std::cos(vec(0, 0));
  _res[1] = std::sin(vec(0, 0));

  return sym::Rot2<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 1, 1> LieGroupOps<Scalar>::ToTangent(const sym::Rot2<Scalar>& a,
                                                           const Scalar epsilon) {
  // Total ops: 1

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 1, 1> _res;

  _res(0, 0) = std::atan2(_a[1], _a[0]);

  return _res;
}

template <typename Scalar>
sym::Rot2<Scalar> LieGroupOps<Scalar>::Retract(const sym::Rot2<Scalar>& a,
                                               const Eigen::Matrix<Scalar, 1, 1>& vec,
                                               const Scalar epsilon) {
  // Total ops: 9

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();

  // Intermediate terms (2)
  const Scalar _tmp0 = std::sin(vec(0, 0));
  const Scalar _tmp1 = std::cos(vec(0, 0));

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _res;

  _res[0] = _a[0] * _tmp1 - _a[1] * _tmp0;
  _res[1] = _a[0] * _tmp0 + _a[1] * _tmp1;

  return sym::Rot2<Scalar>(_res);
}

template <typename Scalar>
Eigen::Matrix<Scalar, 1, 1> LieGroupOps<Scalar>::LocalCoordinates(const sym::Rot2<Scalar>& a,
                                                                  const sym::Rot2<Scalar>& b,
                                                                  const Scalar epsilon) {
  // Total ops: 14

  // Input arrays
  const Eigen::Matrix<Scalar, 2, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 2, 1>& _b = b.Data();

  // Intermediate terms (3)
  const Scalar _tmp0 = Scalar(1.0) / (std::pow(_a[0], Scalar(2)) + std::pow(_a[1], Scalar(2)));
  const Scalar _tmp1 = _a[0] * _tmp0;
  const Scalar _tmp2 = _a[1] * _tmp0;

  // Output terms (1)
  Eigen::Matrix<Scalar, 1, 1> _res;

  _res(0, 0) = std::atan2(-_b[0] * _tmp2 + _b[1] * _tmp1, _b[0] * _tmp1 + _b[1] * _tmp2);

  return _res;
}

}  // namespace rot2
}  // namespace sym

// Explicit instantiation
template struct sym::rot2::LieGroupOps<double>;
template struct sym::rot2::LieGroupOps<float>;
