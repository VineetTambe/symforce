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
 *     cross_D_a: (3x3) jacobian of cross (3) wrt arg a (3)
 *     cross_D_b: (3x3) jacobian of cross (3) wrt arg b (3)
 *     cross_D_epsilon: (3x1) jacobian of cross (3) wrt arg epsilon (1)
 *     distance_D_a: (1x3) jacobian of distance (1) wrt arg a (3)
 *     distance_D_b: (1x3) jacobian of distance (1) wrt arg b (3)
 *     distance_D_epsilon: (1x1) jacobian of distance (1) wrt arg epsilon (1)
 */
template <typename Scalar>
void CrossAndDistanceBothJacobians(
    const Eigen::Matrix<Scalar, 3, 1>& a, const Eigen::Matrix<Scalar, 3, 1>& b,
    const Scalar epsilon, Eigen::Matrix<Scalar, 3, 3>* const cross_D_a = nullptr,
    Eigen::Matrix<Scalar, 3, 3>* const cross_D_b = nullptr,
    Eigen::Matrix<Scalar, 3, 1>* const cross_D_epsilon = nullptr,
    Eigen::Matrix<Scalar, 1, 3>* const distance_D_a = nullptr,
    Eigen::Matrix<Scalar, 1, 3>* const distance_D_b = nullptr,
    Eigen::Matrix<Scalar, 1, 1>* const distance_D_epsilon = nullptr) {
  // Total ops: 23

  // Input arrays

  // Intermediate terms (10)
  const Scalar _tmp0 = -b(1, 0);
  const Scalar _tmp1 = -b(2, 0);
  const Scalar _tmp2 = -b(0, 0);
  const Scalar _tmp3 = _tmp2 + a(0, 0);
  const Scalar _tmp4 = _tmp0 + a(1, 0);
  const Scalar _tmp5 = _tmp1 + a(2, 0);
  const Scalar _tmp6 = std::pow(Scalar(std::pow(_tmp3, Scalar(2)) + std::pow(_tmp4, Scalar(2)) +
                                       std::pow(_tmp5, Scalar(2)) + epsilon),
                                Scalar(Scalar(-1) / Scalar(2)));
  const Scalar _tmp7 = _tmp3 * _tmp6;
  const Scalar _tmp8 = _tmp4 * _tmp6;
  const Scalar _tmp9 = _tmp5 * _tmp6;

  // Output terms (6)
  if (cross_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _cross_D_a = (*cross_D_a);

    _cross_D_a(0, 0) = 0;
    _cross_D_a(0, 1) = b(2, 0);
    _cross_D_a(0, 2) = _tmp0;
    _cross_D_a(1, 0) = _tmp1;
    _cross_D_a(1, 1) = 0;
    _cross_D_a(1, 2) = b(0, 0);
    _cross_D_a(2, 0) = b(1, 0);
    _cross_D_a(2, 1) = _tmp2;
    _cross_D_a(2, 2) = 0;
  }

  if (cross_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _cross_D_b = (*cross_D_b);

    _cross_D_b(0, 0) = 0;
    _cross_D_b(0, 1) = -a(2, 0);
    _cross_D_b(0, 2) = a(1, 0);
    _cross_D_b(1, 0) = a(2, 0);
    _cross_D_b(1, 1) = 0;
    _cross_D_b(1, 2) = -a(0, 0);
    _cross_D_b(2, 0) = -a(1, 0);
    _cross_D_b(2, 1) = a(0, 0);
    _cross_D_b(2, 2) = 0;
  }

  if (cross_D_epsilon != nullptr) {
    Eigen::Matrix<Scalar, 3, 1>& _cross_D_epsilon = (*cross_D_epsilon);

    _cross_D_epsilon(0, 0) = 0;
    _cross_D_epsilon(1, 0) = 0;
    _cross_D_epsilon(2, 0) = 0;
  }

  if (distance_D_a != nullptr) {
    Eigen::Matrix<Scalar, 1, 3>& _distance_D_a = (*distance_D_a);

    _distance_D_a(0, 0) = _tmp7;
    _distance_D_a(0, 1) = _tmp8;
    _distance_D_a(0, 2) = _tmp9;
  }

  if (distance_D_b != nullptr) {
    Eigen::Matrix<Scalar, 1, 3>& _distance_D_b = (*distance_D_b);

    _distance_D_b(0, 0) = -_tmp7;
    _distance_D_b(0, 1) = -_tmp8;
    _distance_D_b(0, 2) = -_tmp9;
  }

  if (distance_D_epsilon != nullptr) {
    Eigen::Matrix<Scalar, 1, 1>& _distance_D_epsilon = (*distance_D_epsilon);

    _distance_D_epsilon(0, 0) = (Scalar(1) / Scalar(2)) * _tmp6;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
