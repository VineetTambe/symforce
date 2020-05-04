/**
 * Transform a nav point into azimuth / elevation angles in the
 * camera frame.
 *
 * Args:
 *     nav_T_cam (geo.Pose3): camera pose in the world
 *     nav_t_point (geo.Matrix): nav point
 *     epsilon (Scalar): small number to avoid singularities
 *
 * Returns:
 *     geo.Matrix: (azimuth, elevation)
 */
template <typename Scalar>
Eigen::Matrix<Scalar, 2, 1> AzElFromPoint(const Pose3<Scalar>& nav_T_cam, const Eigen::Matrix<Scalar, 3, 1>& nav_t_point, const Scalar epsilon) {
    // Input arrays
    const Eigen::Matrix<Scalar, 7, 1>& _nav_T_cam = nav_T_cam.Data();

    // Output array
    Eigen::Matrix<Scalar, 2, 1> res;

    // Intermediate terms (23)
    const Scalar _tmp0 = 2*_nav_T_cam[1];
    const Scalar _tmp1 = _nav_T_cam[0]*_tmp0;
    const Scalar _tmp2 = 2*_nav_T_cam[3];
    const Scalar _tmp3 = _nav_T_cam[2]*_tmp2;
    const Scalar _tmp4 = _tmp1 - _tmp3;
    const Scalar _tmp5 = _nav_T_cam[0]*_tmp2;
    const Scalar _tmp6 = _nav_T_cam[2]*_tmp0;
    const Scalar _tmp7 = _tmp5 + _tmp6;
    const Scalar _tmp8 = -2*(_nav_T_cam[0] * _nav_T_cam[0]);
    const Scalar _tmp9 = -2*(_nav_T_cam[2] * _nav_T_cam[2]) + 1;
    const Scalar _tmp10 = _tmp8 + _tmp9;
    const Scalar _tmp11 = -_nav_T_cam[4]*_tmp4 - _nav_T_cam[5]*_tmp10 - _nav_T_cam[6]*_tmp7 + _tmp10*nav_t_point[1] + _tmp4*nav_t_point[0] + _tmp7*nav_t_point[2];
    const Scalar _tmp12 = _tmp1 + _tmp3;
    const Scalar _tmp13 = 2*_nav_T_cam[0]*_nav_T_cam[2];
    const Scalar _tmp14 = _nav_T_cam[1]*_tmp2;
    const Scalar _tmp15 = _tmp13 - _tmp14;
    const Scalar _tmp16 = -2*(_nav_T_cam[1] * _nav_T_cam[1]);
    const Scalar _tmp17 = _tmp16 + _tmp9;
    const Scalar _tmp18 = -_nav_T_cam[4]*_tmp17 - _nav_T_cam[5]*_tmp12 - _nav_T_cam[6]*_tmp15 + _tmp12*nav_t_point[1] + _tmp15*nav_t_point[2] + _tmp17*nav_t_point[0];
    const Scalar _tmp19 = _tmp13 + _tmp14;
    const Scalar _tmp20 = -_tmp5 + _tmp6;
    const Scalar _tmp21 = _tmp16 + _tmp8 + 1;
    const Scalar _tmp22 = -_nav_T_cam[4]*_tmp19 - _nav_T_cam[5]*_tmp20 - _nav_T_cam[6]*_tmp21 + _tmp19*nav_t_point[0] + _tmp20*nav_t_point[1] + _tmp21*nav_t_point[2];

    // Output terms (2)
    res[0] = std::atan2(_tmp11, _tmp18 + epsilon*((((_tmp18) > 0) - ((_tmp18) < 0)) + 0.5));
    res[1] = -std::acos(_tmp22/(epsilon + std::sqrt((_tmp11 * _tmp11) + (_tmp18 * _tmp18) + (_tmp22 * _tmp22)))) + M_PI_2;


    return Eigen::Matrix<Scalar, 2, 1>(res);
}
