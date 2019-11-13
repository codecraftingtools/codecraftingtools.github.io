.. _software:

========
Software
========

.. _code crafting tools:

Overview
========

The following `code crafting tools <code crafting tools
organization_>`_ are (or will be) provided as :ref:`Git<Git>`
repositories hosted on on :ref:`GitHub<GitHub>`:

.. _Chierps:

Chierps
  Component-based hierarchic programming system.  Chierps is a
  framework for building software by implementing and connecting
  message-passing software components.  It provides a standardized
  run-time environment for inter-component communication, scheduling,
  timing, and logging functionality, as well as a set of generalized
  application executives.  Component messaging interfaces and
  hierarchic structures are defined and generated using `Pidgen`_.

.. _Grasden:

Grasden
  Graphical system design environment for drawing block diagrams that
  describe the hierarchic structure and flow of data between the
  subcomponents of a system.  This tool can be used to graphically
  construct `Chierps`_ applications.
  
.. _Turtal:

Turtal
  The underlying run-time abstraction layer that isolates high-level
  code from the details related to a specific operating system,
  hardware, or message-passing framework implementation.  This library
  provides a set of uniform programming interfaces for constructs like
  message queues, threads, file input/output, timers, and schedulers.

.. _Flout:

Flout
  Fine-grained logging and output library that provides a standardized
  programming interface for the display and recording of status,
  event, debugging, warning, and error information.

.. _Pidgen:

Pidgen
  Programming interface definition and generation tool set.  This
  project provides a language for defining component input/output
  interfaces and hierarchic component structures, along with a set of
  utilities to generate code and documentation from these definitions.
  The structure of input and output data is defined using `Tydl`_.

.. _Tydl:

Tydl
  Type definition language for specifying the structure, layout, and
  semantic attributes of data types.  This project also provides a set
  of tools that can be used to generate documentation or high-level
  code from type specifications.

.. _Bt:

Bt
  Build tool that manages the dependencies between software projects
  and automates the retrieval, configuration, and building of
  prerequisite software repositories.
  
.. _Wumps:

`Wumps <Wumps docs_>`_
  Widely useful macro programming syntax that serves as a foundation
  for building domain-specific languages such as `Tydl`_ and
  `Pidgen`_.

.. _Flopi:

Flopi
  Fine-grained logging and output Python interface for displaying and
  recording status, event, debugging, warning, and error information.
  Flopi can operate as a pure Python module, or in conjunction with
  `Flout`_ when `extending or embedding`_ the Python interpreter.

Development Tools
=================

.. figure:: images/devel_sw_stack.*

   Software Stack for Application Development
	    
Run-Time Software
=================

.. figure:: images/run_time_sw_stack.*

   Run-Time Software Stack for a Typical Application
	    
.. _code crafting tools organization: https://github.com/codecraftingtools
.. _Wumps docs: http://wumps.readthedocs.io
.. _extending or embedding: https://docs.python.org/3/extending
