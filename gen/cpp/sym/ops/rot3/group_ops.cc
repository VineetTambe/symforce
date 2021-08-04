//  ----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./group_ops.h"

namespace sym {
namespace rot3 {

/**
 *
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: <lambda>
 *
 * Args:
 *
 * Outputs:
 *     res: Rot3
 *
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::Identity() {
  // Total ops: 0

  // Input arrays

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = 0;
  _res[1] = 0;
  _res[2] = 0;
  _res[3] = 1;

  return sym::Rot3<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::Inverse(const sym::Rot3<Scalar>& a) {
  // Total ops: 3

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = -_a[0];
  _res[1] = -_a[1];
  _res[2] = -_a[2];
  _res[3] = _a[3];

  return sym::Rot3<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::Compose(const sym::Rot3<Scalar>& a,
                                            const sym::Rot3<Scalar>& b) {
  // Total ops: 32

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _a[0] * _b[3] + _a[1] * _b[2] - _a[2] * _b[1] + _a[3] * _b[0];
  _res[1] = -_a[0] * _b[2] + _a[1] * _b[3] + _a[2] * _b[0] + _a[3] * _b[1];
  _res[2] = _a[0] * _b[1] - _a[1] * _b[0] + _a[2] * _b[3] + _a[3] * _b[2];
  _res[3] = -_a[0] * _b[0] - _a[1] * _b[1] - _a[2] * _b[2] + _a[3] * _b[3];

  return sym::Rot3<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply `compose(inverse(a), b)`.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::Between(const sym::Rot3<Scalar>& a,
                                            const sym::Rot3<Scalar>& b) {
  // Total ops: 38

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = -_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0];
  _res[1] = _a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1];
  _res[2] = -_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2];
  _res[3] = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3];

  return sym::Rot3<Scalar>(_res);
}

/**
 *
 * Inverse of the element a.
 *
 * Returns:
 *     Element: b such that a @ b = identity
 *     res_D_a: (3x3) jacobian of res (3) wrt arg a (3)
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::InverseWithJacobian(
    const sym::Rot3<Scalar>& a, Eigen::Matrix<Scalar, 3, 3>* const res_D_a) {
  // Total ops: 39

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();

  // Intermediate terms (13)
  const Scalar _tmp0 = std::pow(_a[2], Scalar(2));
  const Scalar _tmp1 = std::pow(_a[0], Scalar(2));
  const Scalar _tmp2 = -std::pow(_a[3], Scalar(2));
  const Scalar _tmp3 = std::pow(_a[1], Scalar(2));
  const Scalar _tmp4 = _tmp2 + _tmp3;
  const Scalar _tmp5 = 2 * _a[2];
  const Scalar _tmp6 = _a[3] * _tmp5;
  const Scalar _tmp7 = -2 * _a[0] * _a[1];
  const Scalar _tmp8 = 2 * _a[3];
  const Scalar _tmp9 = _a[1] * _tmp8;
  const Scalar _tmp10 = -_a[0] * _tmp5;
  const Scalar _tmp11 = _a[0] * _tmp8;
  const Scalar _tmp12 = -_a[1] * _tmp5;

  // Output terms (2)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = -_a[0];
  _res[1] = -_a[1];
  _res[2] = -_a[2];
  _res[3] = _a[3];

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp0 - _tmp1 + _tmp4;
    _res_D_a(0, 1) = _tmp6 + _tmp7;
    _res_D_a(0, 2) = _tmp10 - _tmp9;
    _res_D_a(1, 0) = -_tmp6 + _tmp7;
    _res_D_a(1, 1) = _tmp0 + _tmp1 + _tmp2 - _tmp3;
    _res_D_a(1, 2) = _tmp11 + _tmp12;
    _res_D_a(2, 0) = _tmp10 + _tmp9;
    _res_D_a(2, 1) = -_tmp11 + _tmp12;
    _res_D_a(2, 2) = -_tmp0 + _tmp1 + _tmp4;
  }

  return sym::Rot3<Scalar>(_res);
}

/**
 *
 * Composition of two elements in the group.
 *
 * Returns:
 *     Element: a @ b
 *     res_D_a: (3x3) jacobian of res (3) wrt arg a (3)
 *     res_D_b: (3x3) jacobian of res (3) wrt arg b (3)
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::ComposeWithJacobians(
    const sym::Rot3<Scalar>& a, const sym::Rot3<Scalar>& b,
    Eigen::Matrix<Scalar, 3, 3>* const res_D_a, Eigen::Matrix<Scalar, 3, 3>* const res_D_b) {
  // Total ops: 300

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (79)
  const Scalar _tmp0 = _a[0] * _b[3] + _a[1] * _b[2] - _a[2] * _b[1] + _a[3] * _b[0];
  const Scalar _tmp1 = -_a[0] * _b[2] + _a[1] * _b[3] + _a[2] * _b[0] + _a[3] * _b[1];
  const Scalar _tmp2 = _a[0] * _b[1] - _a[1] * _b[0] + _a[2] * _b[3] + _a[3] * _b[2];
  const Scalar _tmp3 = -_a[0] * _b[0] - _a[1] * _b[1] - _a[2] * _b[2] + _a[3] * _b[3];
  const Scalar _tmp4 = 2 * _tmp2;
  const Scalar _tmp5 = _b[3] * _tmp4;
  const Scalar _tmp6 = 2 * _tmp0;
  const Scalar _tmp7 = _b[1] * _tmp6;
  const Scalar _tmp8 = 2 * _tmp1;
  const Scalar _tmp9 = _b[0] * _tmp8;
  const Scalar _tmp10 = 2 * _tmp3;
  const Scalar _tmp11 = _b[2] * _tmp10;
  const Scalar _tmp12 = _tmp11 + _tmp5 + _tmp7 + _tmp9;
  const Scalar _tmp13 = (Scalar(1) / Scalar(2)) * _a[2];
  const Scalar _tmp14 = _b[2] * _tmp8;
  const Scalar _tmp15 = _b[0] * _tmp10;
  const Scalar _tmp16 = _b[1] * _tmp4;
  const Scalar _tmp17 = _b[3] * _tmp6;
  const Scalar _tmp18 = _tmp16 - _tmp17;
  const Scalar _tmp19 = -_tmp14 + _tmp15 + _tmp18;
  const Scalar _tmp20 = (Scalar(1) / Scalar(2)) * _a[0];
  const Scalar _tmp21 = _b[2] * _tmp4;
  const Scalar _tmp22 = -_tmp21;
  const Scalar _tmp23 = _b[0] * _tmp6;
  const Scalar _tmp24 = _b[1] * _tmp8;
  const Scalar _tmp25 = -_tmp24;
  const Scalar _tmp26 = _b[3] * _tmp10;
  const Scalar _tmp27 = _tmp22 + _tmp23 + _tmp25 + _tmp26;
  const Scalar _tmp28 = (Scalar(1) / Scalar(2)) * _a[3];
  const Scalar _tmp29 = _b[0] * _tmp4;
  const Scalar _tmp30 = _b[1] * _tmp10;
  const Scalar _tmp31 = _b[2] * _tmp6;
  const Scalar _tmp32 = _b[3] * _tmp8;
  const Scalar _tmp33 = _tmp31 - _tmp32;
  const Scalar _tmp34 = _tmp29 - _tmp30 + _tmp33;
  const Scalar _tmp35 = (Scalar(1) / Scalar(2)) * _a[1];
  const Scalar _tmp36 = -_tmp5 + _tmp9;
  const Scalar _tmp37 = -_tmp11 + _tmp36 + _tmp7;
  const Scalar _tmp38 = _tmp14 + _tmp15 + _tmp16 + _tmp17;
  const Scalar _tmp39 = -_tmp23 + _tmp26;
  const Scalar _tmp40 = _tmp22 + _tmp24 + _tmp39;
  const Scalar _tmp41 = -_tmp29 + _tmp30 + _tmp33;
  const Scalar _tmp42 = _tmp11 + _tmp36 - _tmp7;
  const Scalar _tmp43 = _tmp14 - _tmp15 + _tmp18;
  const Scalar _tmp44 = _tmp21 + _tmp25 + _tmp39;
  const Scalar _tmp45 = _tmp29 + _tmp30 + _tmp31 + _tmp32;
  const Scalar _tmp46 = _a[0] * _tmp4;
  const Scalar _tmp47 = _a[2] * _tmp6;
  const Scalar _tmp48 = _a[3] * _tmp8;
  const Scalar _tmp49 = _a[1] * _tmp10;
  const Scalar _tmp50 = -_tmp46 + _tmp47 - _tmp48 + _tmp49;
  const Scalar _tmp51 = (Scalar(1) / Scalar(2)) * _b[1];
  const Scalar _tmp52 = -_tmp50 * _tmp51;
  const Scalar _tmp53 = _a[3] * _tmp4;
  const Scalar _tmp54 = _a[1] * _tmp6;
  const Scalar _tmp55 = _a[0] * _tmp8;
  const Scalar _tmp56 = _a[2] * _tmp10;
  const Scalar _tmp57 = _tmp53 + _tmp54 - _tmp55 - _tmp56;
  const Scalar _tmp58 = (Scalar(1) / Scalar(2)) * _b[2];
  const Scalar _tmp59 = _a[0] * _tmp6 + _a[1] * _tmp8 + _a[2] * _tmp4 + _a[3] * _tmp10;
  const Scalar _tmp60 = (Scalar(1) / Scalar(2)) * _b[3];
  const Scalar _tmp61 = _tmp59 * _tmp60;
  const Scalar _tmp62 = _a[1] * _tmp4;
  const Scalar _tmp63 = _a[3] * _tmp6;
  const Scalar _tmp64 = _a[2] * _tmp8;
  const Scalar _tmp65 = _a[0] * _tmp10;
  const Scalar _tmp66 = _tmp62 - _tmp63 - _tmp64 + _tmp65;
  const Scalar _tmp67 = (Scalar(1) / Scalar(2)) * _b[0];
  const Scalar _tmp68 = _tmp61 - _tmp66 * _tmp67;
  const Scalar _tmp69 = _tmp50 * _tmp67;
  const Scalar _tmp70 = _tmp58 * _tmp59;
  const Scalar _tmp71 = _tmp51 * _tmp59;
  const Scalar _tmp72 = _tmp58 * _tmp66;
  const Scalar _tmp73 = -_tmp53 - _tmp54 + _tmp55 + _tmp56;
  const Scalar _tmp74 = -_tmp62 + _tmp63 + _tmp64 - _tmp65;
  const Scalar _tmp75 = -_tmp58 * _tmp73;
  const Scalar _tmp76 = _tmp59 * _tmp67;
  const Scalar _tmp77 = _tmp51 * _tmp73;
  const Scalar _tmp78 = _tmp46 - _tmp47 + _tmp48 - _tmp49;

  // Output terms (3)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp0;
  _res[1] = _tmp1;
  _res[2] = _tmp2;
  _res[3] = _tmp3;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp12 * _tmp13 - _tmp19 * _tmp20 + _tmp27 * _tmp28 - _tmp34 * _tmp35;
    _res_D_a(0, 1) = _tmp12 * _tmp28 - _tmp13 * _tmp27 - _tmp19 * _tmp35 + _tmp20 * _tmp34;
    _res_D_a(0, 2) = -_tmp12 * _tmp20 - _tmp13 * _tmp19 + _tmp27 * _tmp35 + _tmp28 * _tmp34;
    _res_D_a(1, 0) = _tmp13 * _tmp40 - _tmp20 * _tmp41 + _tmp28 * _tmp37 - _tmp35 * _tmp38;
    _res_D_a(1, 1) = -_tmp13 * _tmp37 + _tmp20 * _tmp38 + _tmp28 * _tmp40 - _tmp35 * _tmp41;
    _res_D_a(1, 2) = -_tmp13 * _tmp41 - _tmp20 * _tmp40 + _tmp28 * _tmp38 + _tmp35 * _tmp37;
    _res_D_a(2, 0) = _tmp13 * _tmp43 - _tmp20 * _tmp42 + _tmp28 * _tmp45 - _tmp35 * _tmp44;
    _res_D_a(2, 1) = -_tmp13 * _tmp45 + _tmp20 * _tmp44 + _tmp28 * _tmp43 - _tmp35 * _tmp42;
    _res_D_a(2, 2) = -_tmp13 * _tmp42 - _tmp20 * _tmp43 + _tmp28 * _tmp44 + _tmp35 * _tmp45;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp52 + _tmp57 * _tmp58 + _tmp68;
    _res_D_b(0, 1) = -_tmp51 * _tmp66 + _tmp57 * _tmp60 + _tmp69 - _tmp70;
    _res_D_b(0, 2) = _tmp50 * _tmp60 - _tmp57 * _tmp67 + _tmp71 - _tmp72;
    _res_D_b(1, 0) = -_tmp51 * _tmp74 + _tmp60 * _tmp73 - _tmp69 + _tmp70;
    _res_D_b(1, 1) = _tmp52 + _tmp61 + _tmp67 * _tmp74 + _tmp75;
    _res_D_b(1, 2) = -_tmp50 * _tmp58 + _tmp60 * _tmp74 - _tmp76 + _tmp77;
    _res_D_b(2, 0) = _tmp60 * _tmp78 - _tmp67 * _tmp73 - _tmp71 + _tmp72;
    _res_D_b(2, 1) = -_tmp58 * _tmp78 + _tmp60 * _tmp66 + _tmp76 - _tmp77;
    _res_D_b(2, 2) = _tmp51 * _tmp78 + _tmp68 + _tmp75;
  }

  return sym::Rot3<Scalar>(_res);
}

/**
 *
 * Returns the element that when composed with a produces b. For vector spaces it is b - a.
 *
 * Implementation is simply `compose(inverse(a), b)`.
 *
 * Returns:
 *     Element: c such that a @ c = b
 *     res_D_a: (3x3) jacobian of res (3) wrt arg a (3)
 *     res_D_b: (3x3) jacobian of res (3) wrt arg b (3)
 */
template <typename Scalar>
sym::Rot3<Scalar> GroupOps<Scalar>::BetweenWithJacobians(
    const sym::Rot3<Scalar>& a, const sym::Rot3<Scalar>& b,
    Eigen::Matrix<Scalar, 3, 3>* const res_D_a, Eigen::Matrix<Scalar, 3, 3>* const res_D_b) {
  // Total ops: 315

  // Input arrays
  const Eigen::Matrix<Scalar, 4, 1>& _a = a.Data();
  const Eigen::Matrix<Scalar, 4, 1>& _b = b.Data();

  // Intermediate terms (82)
  const Scalar _tmp0 = -_a[0] * _b[3] - _a[1] * _b[2] + _a[2] * _b[1] + _a[3] * _b[0];
  const Scalar _tmp1 = _a[0] * _b[2] - _a[1] * _b[3] - _a[2] * _b[0] + _a[3] * _b[1];
  const Scalar _tmp2 = -_a[0] * _b[1] + _a[1] * _b[0] - _a[2] * _b[3] + _a[3] * _b[2];
  const Scalar _tmp3 = _a[0] * _b[0] + _a[1] * _b[1] + _a[2] * _b[2] + _a[3] * _b[3];
  const Scalar _tmp4 = 2 * _b[2];
  const Scalar _tmp5 = _tmp2 * _tmp4;
  const Scalar _tmp6 = 2 * _tmp0;
  const Scalar _tmp7 = _b[0] * _tmp6;
  const Scalar _tmp8 = 2 * _tmp1;
  const Scalar _tmp9 = _b[1] * _tmp8;
  const Scalar _tmp10 = 2 * _tmp3;
  const Scalar _tmp11 = -_b[3] * _tmp10;
  const Scalar _tmp12 = _tmp11 + _tmp5 - _tmp7 + _tmp9;
  const Scalar _tmp13 = (Scalar(1) / Scalar(2)) * _a[3];
  const Scalar _tmp14 = 2 * _tmp2;
  const Scalar _tmp15 = _b[3] * _tmp14;
  const Scalar _tmp16 = -_tmp15;
  const Scalar _tmp17 = -_b[1] * _tmp6;
  const Scalar _tmp18 = _b[0] * _tmp8;
  const Scalar _tmp19 = -_tmp18;
  const Scalar _tmp20 = _tmp3 * _tmp4;
  const Scalar _tmp21 = _tmp16 + _tmp17 + _tmp19 - _tmp20;
  const Scalar _tmp22 = (Scalar(1) / Scalar(2)) * _a[2];
  const Scalar _tmp23 = _b[1] * _tmp14;
  const Scalar _tmp24 = _b[0] * _tmp10;
  const Scalar _tmp25 = _b[3] * _tmp6;
  const Scalar _tmp26 = -_tmp1 * _tmp4;
  const Scalar _tmp27 = -_tmp25 + _tmp26;
  const Scalar _tmp28 = _tmp23 + _tmp24 + _tmp27;
  const Scalar _tmp29 = (Scalar(1) / Scalar(2)) * _a[0];
  const Scalar _tmp30 = _b[3] * _tmp8;
  const Scalar _tmp31 = _b[1] * _tmp10;
  const Scalar _tmp32 = -_b[0] * _tmp14;
  const Scalar _tmp33 = _tmp0 * _tmp4;
  const Scalar _tmp34 = _tmp32 - _tmp33;
  const Scalar _tmp35 = _tmp30 + _tmp31 + _tmp34;
  const Scalar _tmp36 = (Scalar(1) / Scalar(2)) * _a[1];
  const Scalar _tmp37 = _tmp11 + _tmp7;
  const Scalar _tmp38 = _tmp37 + _tmp5 - _tmp9;
  const Scalar _tmp39 = _tmp17 + _tmp20;
  const Scalar _tmp40 = _tmp15 + _tmp19 + _tmp39;
  const Scalar _tmp41 = -_tmp23;
  const Scalar _tmp42 = -_tmp24 + _tmp27 + _tmp41;
  const Scalar _tmp43 = -_tmp30;
  const Scalar _tmp44 = _tmp31 + _tmp32 + _tmp33 + _tmp43;
  const Scalar _tmp45 = _tmp37 - _tmp5 + _tmp9;
  const Scalar _tmp46 = _tmp16 + _tmp18 + _tmp39;
  const Scalar _tmp47 = _tmp24 + _tmp25 + _tmp26 + _tmp41;
  const Scalar _tmp48 = -_tmp31 + _tmp34 + _tmp43;
  const Scalar _tmp49 = _a[3] * _tmp14;
  const Scalar _tmp50 = _a[1] * _tmp6;
  const Scalar _tmp51 = _a[0] * _tmp8;
  const Scalar _tmp52 = _a[2] * _tmp10;
  const Scalar _tmp53 = _tmp49 - _tmp50 + _tmp51 + _tmp52;
  const Scalar _tmp54 = (Scalar(1) / Scalar(2)) * _b[2];
  const Scalar _tmp55 = _a[0] * _tmp14;
  const Scalar _tmp56 = _a[2] * _tmp6;
  const Scalar _tmp57 = _a[3] * _tmp8;
  const Scalar _tmp58 = _a[1] * _tmp10;
  const Scalar _tmp59 = (Scalar(1) / Scalar(2)) * _tmp55 - Scalar(1) / Scalar(2) * _tmp56 -
                        Scalar(1) / Scalar(2) * _tmp57 - Scalar(1) / Scalar(2) * _tmp58;
  const Scalar _tmp60 = -_b[1] * _tmp59;
  const Scalar _tmp61 = -_a[0] * _tmp6 - _a[1] * _tmp8 - _a[2] * _tmp14 + _a[3] * _tmp10;
  const Scalar _tmp62 = (Scalar(1) / Scalar(2)) * _b[3];
  const Scalar _tmp63 = _tmp61 * _tmp62;
  const Scalar _tmp64 = _a[1] * _tmp14;
  const Scalar _tmp65 = _a[3] * _tmp6;
  const Scalar _tmp66 = _a[2] * _tmp8;
  const Scalar _tmp67 = _a[0] * _tmp10;
  const Scalar _tmp68 = -_tmp64 - _tmp65 + _tmp66 - _tmp67;
  const Scalar _tmp69 = (Scalar(1) / Scalar(2)) * _b[0];
  const Scalar _tmp70 = _tmp63 - _tmp68 * _tmp69;
  const Scalar _tmp71 = _tmp54 * _tmp61;
  const Scalar _tmp72 = (Scalar(1) / Scalar(2)) * _b[1];
  const Scalar _tmp73 = _b[0] * _tmp59;
  const Scalar _tmp74 = _tmp61 * _tmp72;
  const Scalar _tmp75 = _tmp54 * _tmp68;
  const Scalar _tmp76 = -_tmp49 + _tmp50 - _tmp51 - _tmp52;
  const Scalar _tmp77 = _tmp64 + _tmp65 - _tmp66 + _tmp67;
  const Scalar _tmp78 = -_tmp54 * _tmp76;
  const Scalar _tmp79 = _tmp61 * _tmp69;
  const Scalar _tmp80 = _tmp72 * _tmp76;
  const Scalar _tmp81 = -_tmp55 + _tmp56 + _tmp57 + _tmp58;

  // Output terms (3)
  Eigen::Matrix<Scalar, 4, 1> _res;

  _res[0] = _tmp0;
  _res[1] = _tmp1;
  _res[2] = _tmp2;
  _res[3] = _tmp3;

  if (res_D_a != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_a = (*res_D_a);

    _res_D_a(0, 0) = _tmp12 * _tmp13 + _tmp21 * _tmp22 - _tmp28 * _tmp29 - _tmp35 * _tmp36;
    _res_D_a(0, 1) = -_tmp12 * _tmp22 + _tmp13 * _tmp21 - _tmp28 * _tmp36 + _tmp29 * _tmp35;
    _res_D_a(0, 2) = _tmp12 * _tmp36 + _tmp13 * _tmp35 - _tmp21 * _tmp29 - _tmp22 * _tmp28;
    _res_D_a(1, 0) = _tmp13 * _tmp40 + _tmp22 * _tmp38 - _tmp29 * _tmp44 - _tmp36 * _tmp42;
    _res_D_a(1, 1) = _tmp13 * _tmp38 - _tmp22 * _tmp40 + _tmp29 * _tmp42 - _tmp36 * _tmp44;
    _res_D_a(1, 2) = _tmp13 * _tmp42 - _tmp22 * _tmp44 - _tmp29 * _tmp38 + _tmp36 * _tmp40;
    _res_D_a(2, 0) = _tmp13 * _tmp48 + _tmp22 * _tmp47 - _tmp29 * _tmp46 - _tmp36 * _tmp45;
    _res_D_a(2, 1) = _tmp13 * _tmp47 - _tmp22 * _tmp48 + _tmp29 * _tmp45 - _tmp36 * _tmp46;
    _res_D_a(2, 2) = _tmp13 * _tmp45 - _tmp22 * _tmp46 - _tmp29 * _tmp47 + _tmp36 * _tmp48;
  }

  if (res_D_b != nullptr) {
    Eigen::Matrix<Scalar, 3, 3>& _res_D_b = (*res_D_b);

    _res_D_b(0, 0) = _tmp53 * _tmp54 + _tmp60 + _tmp70;
    _res_D_b(0, 1) = _tmp53 * _tmp62 - _tmp68 * _tmp72 - _tmp71 + _tmp73;
    _res_D_b(0, 2) = _b[3] * _tmp59 - _tmp53 * _tmp69 + _tmp74 - _tmp75;
    _res_D_b(1, 0) = _tmp62 * _tmp76 + _tmp71 - _tmp72 * _tmp77 - _tmp73;
    _res_D_b(1, 1) = _tmp60 + _tmp63 + _tmp69 * _tmp77 + _tmp78;
    _res_D_b(1, 2) = -_b[2] * _tmp59 + _tmp62 * _tmp77 - _tmp79 + _tmp80;
    _res_D_b(2, 0) = _tmp62 * _tmp81 - _tmp69 * _tmp76 - _tmp74 + _tmp75;
    _res_D_b(2, 1) = -_tmp54 * _tmp81 + _tmp62 * _tmp68 + _tmp79 - _tmp80;
    _res_D_b(2, 2) = _tmp70 + _tmp72 * _tmp81 + _tmp78;
  }

  return sym::Rot3<Scalar>(_res);
}

}  // namespace rot3
}  // namespace sym

// Explicit instantiation
template struct sym::rot3::GroupOps<double>;
template struct sym::rot3::GroupOps<float>;
