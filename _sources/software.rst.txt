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

.. _Chimps:

Chimps
  Component-based hierarchic message-passing system.  Chimps is a
  framework for building software by implementing and connecting
  message-passing software components.  It provides a standardized
  run-time environment for inter-component communication, scheduling,
  timing, and logging functionality, as well as a set of generalized
  application executives.  Component messaging interfaces and
  hierarchic structures are defined and generated using `Smidgen`_ and
  and `Finch`_, respectively.

.. _Shasam:

Shasam
  Standardized hierarchic architecture for simulation and modeling.
  This is a component-based 6-DOF simulation framework with Monte
  Carlo capability that is built on top of `Chimps`_.
  
.. _Hildegard:

`Hildegard <Hildegard docs_>`_
  Hierarchic layout and design environment for generating applications
  and rendering diagrams.  This is a graphical application for drawing
  block diagrams that describe the hierarchic structure and flow of
  data between the subcomponents of a system.  This tool can be used
  to graphically construct `Chimps`_ or `Shasam`_ applications.
  
.. _Finch:

Finch
  Format for specifying interconnections and component hierarchies.
  This project provides a language for making input/output connections
  between components and defining hierarchic component structures,
  along with a set of utilities to generate code and documentation
  from these definitions.  Component input/output interfaces are defined
  using `Smidgen`_.

.. _Smidgen:

Smidgen
  Syntax for messaging interface definition and generation.  This
  project provides a language for defining component input/output
  messaging interfaces and a set of utilities to generate code and
  documentation from these definitions.  The structure of input and
  output data is defined using `Tydl`_.

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
  `Smidgen`_.

.. _Flopi:

Flopi
  Fine-grained logging and output Python interface for displaying and
  recording status, event, debugging, warning, and error information.
  Flopi can operate as a pure Python module, or in conjunction with
  `Flout`_ when `extending or embedding`_ the Python interpreter.

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

.. _Ranger:

Ranger
  Random number generation routines.  This library provides routines
  for generating pseudo-random number streams and transforming the
  draws from these streams into random variables that exhibit specific
  probability distributions.
  
.. _Todes:

Todes
  Time-stepping ordinary differential equation solver.  This library
  provides an engine for the numerical solution of differential
  equations.
  
.. _Caveman:

Caveman
  Common API for vector and matrix numerical operations.  This library
  provides standardized matrix and vector class interfaces to avoid
  explicit dependencies on lower-level matrix libraries.
  
Development Tools
=================

The following diagram illustrates how our :ref:`code crafting
tools<code crafting tools>` work together with :ref:`external
open-source software<Foundation>` to form a software stack for
application development.

.. figure:: images/simplified_devel_sw_stack.*

   Software Stack for Application Development (Simplified)

An expanded, more detailed version of this diagram shows the
dependencies between the various software projects more explicitly.

.. figure:: images/detailed_devel_sw_stack.*

   Software Stack for Application Development (Detailed)
	    
Run-Time Software
=================

The following diagram describes the structure and run-time software
dependencies for a typical application developed using our code
crafting tools.  They show how in-house (application developer) code
interacts with 3rd-party code, the code generated by our tools, the
:ref:`libraries we provide <code crafting tools>`, and :ref:`external
open-source software<Foundation>`.

.. figure:: images/simplified_run_time_sw_stack.*

   Run-Time Software Stack (Simplified)
	    
An expanded, more detailed version of this diagram shows the
dependencies between the various software projects more explicitly.

.. figure:: images/detailed_run_time_sw_stack.*

   Run-Time Software Stack (Detailed)
	    
.. _code crafting tools organization: https://github.com/codecraftingtools
.. _Hildegard docs: https://github.com/codecraftingtools/hildegard
.. _Wumps docs: http://wumps.readthedocs.io
.. _extending or embedding: https://docs.python.org/3/extending
