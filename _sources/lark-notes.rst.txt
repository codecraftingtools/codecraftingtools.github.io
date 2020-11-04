====
Lark
====

`Lark <lark>` is a parsing toolkit for `Python <python>`.

External Documentation
======================

- `Lark Web Site <lark-site_>`_
- `Lark Documentation <lark-docs_>`_

.. _lark-install:

Installation Notes
==================

Before proceeding, make sure that you have created and activated the
``codecraftsmen`` virtual Python environment as described `here
<virtualenvwrapper-install>`.

At the time of this writing (November 2020), the latest release of
Lark (0.10.0) has a bug that affects the operation of our tools.  This
`issue <https://github.com/lark-parser/lark/issues/616>`_ has been
fixed in the master branch of the Lark source repository.  Until
another release is made, a manual checkout from the source repository
is required.

Make sure that `Git <git-install>` is installed and then pull down a
copy of the Lark repository::
 
  mkdir -p ~/git
  cd ~/git
  git clone https://github.com/lark-parser/lark.git
  
The following commands will checkout the exact commit we are using
(Sun Nov 1, 2020)::

  cd lark
  git checkout 0aac2760c86cc69ea499266bc9036af18e6b195e

This checkout of the Lark repository can be installed in the
``codecraftsmen`` virtual environment like this::

  cd ~/git
  workon codecraftsmen
  pip install -e lark

Once a new version of Lark has been released, you will be able to
install it directly using `pip <pip>` like this::

  workon codecraftsmen
  pip install lark-parser

.. _lark-site: https://github.com/lark-parser/lark
.. _lark-docs: https://lark-parser.readthedocs.io
