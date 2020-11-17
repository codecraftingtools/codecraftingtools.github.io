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

You may also need to install the `sphinx_autodoc_typehints`_ Sphinx
extension that is used to format the Python API documentation for some
of our projects::

  pip install sphinx_autodoc_typehints
  
This should be sufficient for building the HTML documentation.  If you
want to build PDF output, you will need to install these additional
packages on Ubuntu 20.04/18.04::

  sudo apt-get install latexmk texlive-latex-extra texlive-latex-recommended

Extra Setup for Projects Using Read the Docs
============================================

For Python projects that require prerequisite packages to build the
documentation, a `requirements.txt`_ file needs to be added to the
project's documentation directory to allow the build to succeed on the
`Read the Docs <read-the-docs>` site.

.. _documenting-python-code:

Documenting Python Code
=======================

The API documentation for our Python packages is extracted from
`docstrings`_ embedded in the code.  The docstrings are formatted
according to the `Google docstring`_ style convention with `PEP 484`_
type annotations.  The `napoleon`_ and `sphinx_autodoc_typehints`_
Sphinx extensions are used to extract and format the API
documentation.  See this `Google docstring example`_ to get a feel for
this docstring format.

Miscellaneous Notes
===================

- Official `Sphinx Quickstart`_
- `Read the Docs Sphinx Quickstart`_
- How to install the `Read the Docs Sphinx Theme`_
- How to `include parts of README.rst`_ in your sphinx docs
- How to embed `Clickable SVG Files`_
- How to `conditionally include block based on documentation type`_
- Python `docstrings`_
- Extracting `API documentation`_ from Python docstrings
- Documentation on the `autodoc extension`_
- Documentation on the `napoleon`_ extension
- Documentation on other Sphinx `extensions`_

.. _sphinx-site: https://www.sphinx-doc.org
.. _sphinx-docs: https://www.sphinx-doc.org/en/master/contents.html
.. _sphinx_autodoc_typehints:
   https://pypi.org/project/sphinx-autodoc-typehints/
.. _requirements.txt:
   https://docs.readthedocs.io/en/stable/guides/specifying-dependencies.html
.. _docstrings: https://www.python.org/dev/peps/pep-0287/
.. _Google docstring: https://google.github.io/styleguide/pyguide.html#Comments
.. _PEP 484: https://www.python.org/dev/peps/pep-0484/
.. _napoleon:
   https://www.sphinx-doc.org/en/master/usage/extensions/napoleon.html
.. _Google docstring example:
   https://www.sphinx-doc.org/en/master/usage/extensions/example_google.html#example-google
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
.. _API documentation:
   https://www.sphinx-doc.org/en/master/usage/quickstart.html#autodoc
.. _autodoc extension:
   https://www.sphinx-doc.org/en/master/usage/extensions/autodoc.html
.. _extensions:
   https://www.sphinx-doc.org/en/master/usage/extensions/index.html
