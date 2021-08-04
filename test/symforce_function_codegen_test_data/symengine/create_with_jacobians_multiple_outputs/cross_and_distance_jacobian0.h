// -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------
#pragma once

#include <Eigen/Dense>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: cross_and_distance
 *
 * Args:
 *     a: Matrix31
 *     b: Matrix31
 *     epsilon: Scalar
 *
 * Outputs:
 *     distance: Scalar
 *     cross_D_a: (3x3) jacobian of cross (3) wrt arg a (3)
 */
template <typename Scalar>
void CrossAndDistanceJacobian0(const Eigen::Matrix<Scalar, 3, 1>& a,
                               const Eigen::Matrix<Scalar, 3, 1>& b, const Scalar epsilon,
                               Scalar* const distance = nullptr,
                               Eigen::Matrix<Scalar, 3, 3>* const cross_D_a = nullptr) {
  // Total ops: 13

  // Input arrays

  // Intermediate terms (3)
  const Scalar _tmp0 = -b(0, 0);
  const Scalar _tmp1 = -b(1, 0);
  const Scalar _tmp2 = -b(2, 0);

  // Output terms (2)
  if (distance != nullptr) {
    Scalar& _distance = (*distance);

    _distance = std::sqrt(epsilon + std::pow(Scalar(_tmp0 + a(0, 0)), Scalar(2)) +
                          std::pow(Scalar(_tmp1 + a(1, 0)), Scalar(2)) +
                          std::pow(Scalar(_tmp2 + a(2, 0)), Scalar(2)));
  }

  if (cross_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _cross_D_a = (*cross_D_a);

    _cross_D_a(0, 0) = 0;
    _cross_D_a(0, 1) = b(2, 0);
    _cross_D_a(0, 2) = _tmp1;
    _cross_D_a(1, 0) = _tmp2;
    _cross_D_a(1, 1) = 0;
    _cross_D_a(1, 2) = b(0, 0);
    _cross_D_a(2, 0) = b(1, 0);
    _cross_D_a(2, 1) = _tmp0;
    _cross_D_a(2, 2) = 0;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
