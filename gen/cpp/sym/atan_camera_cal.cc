//  -----------------------------------------------------------------------------
// This file was autogenerated by symforce. Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include "./atan_camera_cal.h"

// Camera operation implementations
namespace sym {

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::FocalLength() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _focal_length;

  _focal_length(0, 0) = _self[0];
  _focal_length(1, 0) = _self[1];

  return _focal_length;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::PrincipalPoint() const {
  // Total ops: 0

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (0)

  // Output terms (1)
  Eigen::Matrix<Scalar, 2, 1> _principal_point;

  _principal_point(0, 0) = _self[2];
  _principal_point(1, 0) = _self[3];

  return _principal_point;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> ATANCameraCal<Scalar>::PixelFromCameraPoint(
    const Eigen::Matrix<Scalar, 3, 1>& point, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 29

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (4)
  const Scalar _tmp0 = std::max<Scalar>(epsilon, std::fabs(point(2, 0)));
  const Scalar _tmp1 = std::pow(_tmp0, Scalar(-2));
  const Scalar _tmp2 = std::sqrt(_tmp1 * std::pow(point(0, 0), Scalar(2)) +
                                 _tmp1 * std::pow(point(1, 0), Scalar(2)) + epsilon);
  const Scalar _tmp3 =
      std::atan(2 * _tmp2 * std::tan(Scalar(0.5) * _self[4])) / (_self[4] * _tmp0 * _tmp2);

  // Output terms (2)
  Eigen::Matrix<Scalar, 2, 1> _pixel;

  _pixel(0, 0) = _self[0] * _tmp3 * point(0, 0) + _self[2];
  _pixel(1, 0) = _self[1] * _tmp3 * point(1, 0) + _self[3];

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(0, (((point(2, 0)) > 0) - ((point(2, 0)) < 0)));
  }

  return _pixel;
}

template <typename Scalar>
Eigen::Matrix<Scalar, 3, 1> ATANCameraCal<Scalar>::CameraRayFromPixel(
    const Eigen::Matrix<Scalar, 2, 1>& pixel, const Scalar epsilon, Scalar* const is_valid) const {
  // Total ops: 34

  // Input arrays
  const Eigen::Matrix<Scalar, 5, 1>& _self = Data();

  // Intermediate terms (5)
  const Scalar _tmp0 = -_self[2] + pixel(0, 0);
  const Scalar _tmp1 = -_self[3] + pixel(1, 0);
  const Scalar _tmp2 =
      std::sqrt(epsilon + std::pow(_tmp1, Scalar(2)) / std::pow(_self[1], Scalar(2)) +
                std::pow(_tmp0, Scalar(2)) / std::pow(_self[0], Scalar(2)));
  const Scalar _tmp3 = _self[4] * _tmp2;
  const Scalar _tmp4 =
      (Scalar(1) / Scalar(2)) * std::tan(_tmp3) / (_tmp2 * std::tan(Scalar(0.5) * _self[4]));

  // Output terms (2)
  Eigen::Matrix<Scalar, 3, 1> _camera_ray;

  _camera_ray(0, 0) = _tmp0 * _tmp4 / _self[0];
  _camera_ray(1, 0) = _tmp1 * _tmp4 / _self[1];
  _camera_ray(2, 0) = 1;

  if (is_valid != nullptr) {
    Scalar& _is_valid = (*is_valid);

    _is_valid = std::max<Scalar>(
        0, (((-std::fabs(_tmp3) + M_PI_2) > 0) - ((-std::fabs(_tmp3) + M_PI_2) < 0)));
  }

  return _camera_ray;
}

}  // namespace sym

// Print implementations
std::ostream& operator<<(std::ostream& os, const sym::ATANCameraCald& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<ATANCameraCald " << a.Data().transpose().format(fmt) << ">";
  return os;
}
std::ostream& operator<<(std::ostream& os, const sym::ATANCameraCalf& a) {
  const Eigen::IOFormat fmt(Eigen::StreamPrecision, Eigen::DontAlignCols, ", ", "\n", "[", "]");
  os << "<ATANCameraCalf " << a.Data().transpose().format(fmt) << ">";
  return os;
}

// Concept implementations for this class
#include "./ops/atan_camera_cal/storage_ops.cc"

// Explicit instantiation
template class sym::ATANCameraCal<double>;
template class sym::ATANCameraCal<float>;
