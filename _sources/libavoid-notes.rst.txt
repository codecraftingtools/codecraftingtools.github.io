========
libavoid
========

`libavoid <libavoid>` is a cross-platform C++ library providing fast,
object-avoiding orthogonal and polyline connector routing for use in
interactive diagram editors.

External Documentation
======================

- `libavoid Web Site <libavoid-site_>`_
- `Adaptagrams Project Web Site <adaptagrams-site_>`_
- `Example Program <libavoid-example_>`_

.. _libavoid-install:

Installation Notes
==================

libavoid is part of the Adaptagrams project, and is developed as part
of that Git repository.  The first step in installing libavoid is to
make sure that `Git <git-install>` is installed, and then pull down a
copy of the adaptagrams repository::

  mkdir -p ~/git
  cd ~/git
  git clone https://github.com/mjwybrow/adaptagrams.git
  
There appear to be no tags or releases yet, so this is the commit we
used for reference (Wed Mar 7, 2018)::

  cd adaptagrams
  git checkout 86b46ed3694b13603a6625d2d6fff0352441f846

On Ubuntu 20.04/18.04, these additional packages should be installed
if they are not present::

  sudo apt-get install build-essential automake libtool

The following extra package is required on Ubuntu 18.04::

  sudo apt-get install libcairo2-dev

These commands should build the C++ libraries::

  cd cola
  ./autogen.sh

This may result in a build failure, but the required :file:`libavoid.so`
library should have been built correctly.  The location of the library
is here::

  ~/git/adaptagrams/cola/libavoid/.libs/libavoid.so

Now that we have built the required C++ libraries, we need to build
and install the Python wrapper.  Under Ubuntu 20.04/18.04, these
additional packages are required::

  sudo apt-get install swig python3-dev

Before proceeding, also make sure that you have created and activated
the ``codecraftsmen`` virtual Python environment as described `here
<virtualenvwrapper-install>`.

Next, change this line in :file:`swig-python-setup.py` to make it work
under Python 3::

  if sysconfig.get_config_vars().has_key("OPT"):
  
to::
  
  if "OPT" in sysconfig.get_config_vars():

Then build the Python wrapper::
  
  workon codecraftsmen
  make -f Makefile-swig-python

Now install the Python package::
  
  ln -s swig-python-setup.py setup.py
  cd ..
  pip install -e cola

.. _libavoid-site: https://www.adaptagrams.org/documentation/libavoid.html
.. _adaptagrams-site: https://www.adaptagrams.org
.. _libavoid-example:
   https://www.adaptagrams.org/documentation/libavoid_example.html
