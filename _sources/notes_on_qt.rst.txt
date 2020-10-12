.. _Qt notes:

====
Qt 5
====

Qt is a cross-platform C++ library for constructing graphical user
interfaces.

External Documentation
======================

- `Qt Web Site <Qt site_>`_
- `Qt Documentation <Qt docs_>`_

Installation Notes
==================

The required Qt 5 C++ libraries can be installed on Ubuntu 20.04/18.04
using the following command::

  sudo apt-get install qt5-default

Although these packages should be sufficient for running C++ Qt
programs, some additional setup is required to support Python Qt
applications.  First, create a `codecraftsmen` virtual Python
environment as described :ref:`here <virtualenvwrapper notes>`.  Next,
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

If the code shown above is saved in a file named ``hello.py``, you can
run it in the `codecraftsmen` virtual Python environment like this::

  workon codecraftsmen
  python hello.py

.. _Qt site: https://www.qt.io/
.. _Qt docs: https://doc.qt.io/
