======
Sphinx
======

`Sphinx <sphinx>` is a documentation generation tool originally created
for the generating the `Python <python>` language documentation.

External Documentation
======================

- `Sphinx Web Site <sphinx-site_>`_
- `Sphinx Documentation <sphinx-docs_>`_

.. _sphinx-install:

Installation Notes
==================

Before proceeding, make sure that you have created and activated the
``codecraftsmen`` virtual Python environment as described `here
<virtualenvwrapper-install>`.

Sphinx can be installed using `pip <pip>` like this::

  workon codecraftsmen
  pip install sphinx
  pip install sphinx-rtd-theme

Some of the Code Craftsmen projects also use the `sphinx_autodoc_typehints`_
Sphinx extension to format Python API documentation.  This extension can also
be installed using `pip <pip>`::

  pip install sphinx_autodoc_typehints
  
Our C++ projects use `Doxygen <doxygen>` to extract API documentation from
C++ source files and the `breathe`_ Sphinx extension to integrate and format
that documentation using Sphinx.  These tools can be installed by running the
following commands on Ubuntu 20.04/18.04::

  sudo apt-get install doxygen
  pip install breathe

Our C projects use the `kernel-doc`_ Sphinx extension to extract API
documentation from C source files and integrate the results into Sphinx.
This extension is typically distributed as part of the `Linux kernel <linux>`
source tree, so we simplify the distribution and installation process by
including a copy of the required files under the ``doc`` directory of the
projects that require this extension.

Performing the steps listed above should be sufficient for building the HTML
documentation for most, if not all, Code Craftsmen projects.  If you want to
build PDF output, you will need to install these additional packages on
Ubuntu 20.04/18.04::

  sudo apt-get install latexmk texlive-latex-extra texlive-latex-recommended

Extra Setup for Projects Using Read the Docs
============================================

For Python projects that require prerequisite `pip <pip>` packages to build
the documentation, a `requirements.txt`_ file needs to be added to the
project's documentation directory to allow the build to succeed on the `Read
the Docs <read-the-docs>` site.

Extracting Embedded Documentation from Python Code
==================================================

- Information on Python `docstrings`_
- How to extract `API documentation`_ from Python docstrings
- Documentation for the `autodoc extension`_
- Documentation for the `napoleon`_ extension
- Documentation for the `sphinx_autodoc_typehints`_ extension
- Documentation for the `Sphinx Python domain <sphinx_python_domain_>`_
- See the `Flopi <flopi>` project's `doc <python_doc_example_>`_ directory
  for an example of how to set up Sphinx for Python API documentation.

Extracting Embedded Documentation from C++ Code
===============================================

- Documentation for the `Doxygen <doxygen>` C++ documentation generator
- Documentation for the `breathe`_ extension (integrates `Doxygen <doxygen>`
  output with Sphinx)
- Documentation for the `Sphinx C++ domain <sphinx_cpp_domain_>`_
- See the `Cuddl <cuddl>` project's `doc <cpp_doc_example_>`_ directory for
  an example of how to set up Sphinx for C++ API documentation.

Extracting Embedded Documentation from C Code
=============================================

- Documentation for the `kernel-doc`_ extension
- Documentation for the `Sphinx C domain <sphinx_c_domain_>`_
- See the `Cuddl <cuddl>` project's `doc <cpp_doc_example_>`_ directory for
  an example of how to set up Sphinx for C API documentation.

Miscellaneous Notes
===================

- Official `Sphinx Quickstart`_
- `Read the Docs Sphinx Quickstart`_
- How to install the `Read the Docs Sphinx Theme`_
- How to `include parts of README.rst`_ in your sphinx docs
- How to embed `Clickable SVG Files`_
- How to `conditionally include block based on documentation type`_
- Documentation on other Sphinx `extensions`_

.. _sphinx-site: https://www.sphinx-doc.org
.. _sphinx-docs: https://www.sphinx-doc.org/en/master/contents.html
.. _sphinx_autodoc_typehints:
   https://pypi.org/project/sphinx-autodoc-typehints/
.. _breathe:
   https://www.breathe-doc.org/
.. _kernel-doc:
   https://www.kernel.org/doc/html/latest/doc-guide/kernel-doc.html
.. _requirements.txt:
   https://docs.readthedocs.io/en/stable/guides/specifying-dependencies.html
.. _docstrings: https://www.python.org/dev/peps/pep-0287/
.. _API documentation:
   https://www.sphinx-doc.org/en/master/usage/quickstart.html#autodoc
.. _autodoc extension:
   https://www.sphinx-doc.org/en/master/usage/extensions/autodoc.html
.. _napoleon:
   https://www.sphinx-doc.org/en/master/usage/extensions/napoleon.html
.. _sphinx_python_domain:
   https://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#the-python-domain
.. _sphinx_c_domain:
   https://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#the-c-domain
.. _sphinx_cpp_domain:
   https://www.sphinx-doc.org/en/master/usage/restructuredtext/domains.html#cpp-domain
.. _python_doc_example:
   https://github.com/codecraftingtools/flopi/tree/master/doc
.. _c_doc_example:
   https://github.com/codecraftingtools/cuddl/tree/master/doc
.. _cpp_doc_example:
   https://github.com/codecraftingtools/cuddl/tree/master/doc
.. _Sphinx Quickstart:
   https://www.sphinx-doc.org/en/master/usage/quickstart.html
.. _Read the Docs Sphinx Quickstart:
   https://docs.readthedocs.io/en/stable/intro/getting-started-with-sphinx.html
.. _Read the Docs Sphinx Theme:
   https://sphinx-rtd-theme.readthedocs.io/en/latest/
.. _include parts of README.rst:
   https://muffinresearch.co.uk/selectively-including-parts-readme-rst-in-your-docs
.. _Clickable SVG Files:
   https://stackoverflow.com/questions/34777943/insert-clickable-svg-image-into-sphinx-documentation
.. _conditionally include block based on documentation type:
   https://stackoverflow.com/questions/2215518/conditional-output-in-sphinx-documentation
.. _extensions:
   https://www.sphinx-doc.org/en/master/usage/extensions/index.html
