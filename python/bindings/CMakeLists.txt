# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND bootstrap_python_files
    python_bindings.cc)

GR_PYBIND_MAKE_OOT(bootstrap 
   ../..
   gr::bootstrap
   "${bootstrap_python_files}")

install(TARGETS bootstrap_python DESTINATION ${GR_PYTHON_DIR}/bootstrap COMPONENT pythonapi)
