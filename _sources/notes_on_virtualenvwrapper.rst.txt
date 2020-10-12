.. _virtualenvwrapper notes:

=================
virtualenvwrapper
=================

virtualenvwrapper is a set of extensions to the
:ref:`virtualenv <virtualenv>` tool that includes wrappers for creating
and deleting virtual :ref:`Python <Python>` environments.

External Documentation
======================

- `virtualenvwrapper Web Site <virtualenvwrapper site_>`_

Installation Notes
==================

First, make sure that :ref:`Python 3 <Python notes>` is installed.

The virtualenvwrapper package can be installed on Ubuntu 20.04/18.04
using the following command::

  sudo apt-get install virtualenvwrapper
  
The next step is to decide where you want your virtual Python
environments to be stored.  By default, they will be stored here::

  ~/.virtualenvs

If you want them to be stored somewhere else, set the following
environment variable in your `~/.profile`::

  export WORKON_HOME=~/venv

Now add the following line to your `~/.bashrc` and then log out and log
back in again to set up your shell environment::
  
  source /usr/share/virtualenvwrapper/virtualenvwrapper.sh
  
Now you should be able to create a new virtual Python environment for
working with our code crafting tools::

  mkvirtualenv --python=/usr/bin/python3 codecraftsmen

After the new environment is created, it should be automatically
activated.  This should be evident by the `(codecraftsmen)` prefix
shown in your command prompt::

  (codecraftsmen) user@host:~$

The virtual environment can be deactivated like this::

  deactivate

and reactivated like this::

  workon codecraftsmen

When a virtual environment is activated, any new Python packages
installed using :ref:`pip <pip>` only apply to the active environment
and global (system) site packages are disabled.

.. _virtualenvwrapper site: https://virtualenvwrapper.readthedocs.io
