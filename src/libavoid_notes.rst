.. _libavoid notes:

========
libavoid
========

`libavoid <libavoid site_>`_ is a cross-platform C++ library providing fast,
object-avoiding orthogonal and polyline connector routing for use in
interactive diagram editors

Installation
============

libavoid is part of the `adaptagrams <adaptagrams site_>`_ project.
The first step in installing *libavoid* is to check out a copy of the
*adaptagrams* git repository::

  git clone https://github.com/mjwybrow/adaptagrams.git
  
There appear to be no tags or releases yet, so this is the commit I
used for reference (Wed Mar 7, 2018)::

  git checkout 86b46ed3694b13603a6625d2d6fff0352441f846

These packages should be installed if they are not present::

  sudo apt-get install libcairo2-dev automake m4 swig
  
These commands should build the C libraries::

  cd adaptagrams/cola
  ./autogen.sh

This resulted in some test suite failures, but the *libavoid.so* library
was built correctly.  The location of the library is here::

  adaptagrams/cola/libavoid/.libs/libavoid.so

Now we need to install the python wrappers.  First, change this line
in *swig-python-setup.py* to make it work under Python 3::

  if sysconfig.get_config_vars().has_key("OPT"):
  
to::
  
  if "OPT" in sysconfig.get_config_vars():

Then build the python wrappers::
  
  workon kivy
  make -f Makefile-swig-python

Now install the python package::
  
  ln -s swig-python-setup.py setup.py
  cd ..
  pip install -e cola

Example
=======

An example program can be found `here <libavoid example_>`_.

.. _libavoid site: https://www.adaptagrams.org/documentation/libavoid.html
.. _adaptagrams site: https://www.adaptagrams.org
.. _libavoid example: https://www.adaptagrams.org/documentation/libavoid_example.html
