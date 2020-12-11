===========
Conventions
===========

This sections describes the coding conventions adopted by the Code
Craftsmen project.  These standards should be respected when making
contributions to our Code Crafting tools.

Python Code
===========

.. _documenting-python-code:

Embedded Documentation
----------------------

The API documentation for our `Python <python>` packages is extracted
from `docstrings`_ embedded in the code using `Sphinx <sphinx>`.  The
docstrings are formatted according to the `Google docstring`_ style
convention with `PEP 484`_ type annotations.  The `autodoc`_,
`napoleon`_, and `sphinx_autodoc_typehints`_ Sphinx extensions are
used to extract and format the `API documentation`_.  See this `Google
docstring example`_ to get a feel for this docstring format.

.. _docstrings: https://www.python.org/dev/peps/pep-0287/
.. _Google docstring: https://google.github.io/styleguide/pyguide.html#38-comments-and-docstrings
.. _PEP 484: https://www.python.org/dev/peps/pep-0484/
.. _autodoc:
   https://www.sphinx-doc.org/en/master/usage/extensions/autodoc.html
.. _napoleon:
   https://www.sphinx-doc.org/en/master/usage/extensions/napoleon.html
.. _sphinx_autodoc_typehints:
   https://pypi.org/project/sphinx-autodoc-typehints/
.. _API documentation:
   https://www.sphinx-doc.org/en/master/usage/quickstart.html#autodoc
.. _Google docstring example:
   https://www.sphinx-doc.org/en/master/usage/extensions/example_google.html#example-google
