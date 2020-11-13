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

This should be sufficient for building the HTML documentation.  If you
want to build PDF output, you will need to install these additional
packages on Ubuntu 20.04/18.04::

  sudo apt-get install latexmk texlive-latex-extra texlive-latex-recommended

Miscellaneous Notes
===================

- Official `Sphinx Quickstart`_

- `Read the Docs Sphinx Quickstart`_
- How to install the `Read the Docs Sphinx Theme`_
- How to `include parts of README.rst`_ in your sphinx docs
- How to embed `Clickable SVG Files`_
- How to `conditionally include block based on documentation type`_
- Extracting `API documentation`_ from Python doc strings
- Documentation on the `autodoc extension`_
- Documentation on other Sphinx `extensions`_

.. _sphinx-site: https://www.sphinx-doc.org
.. _sphinx-docs: https://www.sphinx-doc.org/en/master/contents.html
.. _Read the Docs Sphinx Quickstart:
   https://docs.readthedocs.io/en/stable/intro/getting-started-with-sphinx.html
.. _Sphinx Quickstart:
   https://www.sphinx-doc.org/en/master/usage/quickstart.html
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
