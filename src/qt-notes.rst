====
Qt 5
====

`Qt <qt>` is a cross-platform C++ library for constructing graphical
user interfaces.

External Documentation
======================

- `Qt Web Site <qt-site_>`_
- `Qt Documentation <qt-docs_>`_

Supported Versions
==================

The following versions of Qt are regularly tested with our code
crafting tools:

- libqt5 5.9.5 (Ubuntu 18.04)
- libqt5 5.12.8 (Ubuntu 20.04)

.. _qt-install:

Installation Notes
==================

The required Qt 5 C++ libraries can be installed on Ubuntu 20.04/18.04
using the following command::

  sudo apt-get install qt5-default

Although these packages should be sufficient for running C++ Qt
programs, some additional setup is required to support Python Qt
applications.  First, create a ``codecraftsmen`` virtual Python
environment as described `here <virtualenvwrapper-install>`.  Next,
activate this environment and install the Python language bindings for
Qt::

  workon codecraftsmen
  pip install PyQt5
  pip install qtpy

The following program can be used to test your PyQt5 installation:

.. code-block:: python

    import sys
    from qtpy.QtWidgets import QApplication, QLabel
     
    app = QApplication(sys.argv)
    label = QLabel("Hello World")
    label.show()
    app.exec_()

If the code shown above is saved in a file named :file:`hello.py`, you
can run it in the ``codecraftsmen`` virtual Python environment like
this::

  workon codecraftsmen
  python hello.py

.. _qt-site: https://www.qt.io/
.. _qt-docs: https://doc.qt.io/
