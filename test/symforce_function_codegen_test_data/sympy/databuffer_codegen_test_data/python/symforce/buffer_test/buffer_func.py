# -----------------------------------------------------------------------------
# This file was autogenerated by symforce from template:
#     python_templates/function/FUNCTION.py.jinja
# Do NOT modify by hand.
# -----------------------------------------------------------------------------

import math  # pylint: disable=unused-import
import numpy  # pylint: disable=unused-import
import typing as T  # pylint: disable=unused-import

import sym  # pylint: disable=unused-import


# pylint: disable=too-many-locals,too-many-lines,too-many-statements,unused-argument


def buffer_func(buffer, a, b):
    # type: (numpy.ndarray, float, float) -> float
    """
    This function was autogenerated. Do not modify by hand.

    Args:
        buffer: DataBuffer
        a: Scalar
        b: Scalar

    Outputs:
        result: Scalar
    """

    # Total ops: 9

    # Input arrays

    # Intermediate terms (0)

    # Output terms
    _result = a + b + buffer[int((-a + b) * (a + b))] + buffer[int(-(a ** 2) + b ** 2)]
    return _result
