========
Software
========

Overview
========

The following `code crafting tools <code-crafting-tools-org_>`_ are
(or will be) provided as `Git <git>` repositories hosted on `GitHub
<github>`:

.. _chimps:

`Chimps <chimps-docs_>`_
  Concurrent hierarchic message-based programming system.  Chimps is a
  framework for building software by implementing and connecting
  message-passing software components.  It provides a standardized
  run-time environment for inter-component communication, scheduling,
  timing, and logging functionality, as well as a set of generalized
  application executives.  Component messaging interfaces and
  hierarchic structures are defined and generated using `Smidgen
  <smidgen>` and `Finch <finch>`, respectively.

.. _hildegard:

`Hildegard <hildegard-docs_>`_
  Hierarchic layout and design environment for generating applications
  and rendering diagrams.  This is a graphical application for drawing
  block diagrams that describe the hierarchic structure and flow of
  data between the subcomponents of a system.  This tool can be used
  to graphically construct `Chimps <chimps>` or `Shasam <shasam>`
  applications.
  
.. _shasam:
	      
`Shasam <shasam-docs_>`_
  Standardized hierarchic architecture for simulation and modeling.
  This is a component-based 6-DOF simulation framework with Monte
  Carlo capability that is built on top of `Chimps <chimps>`.
  
.. _finch:

`Finch <finch-docs_>`_
  Format for specifying interconnections and component hierarchies.
  This project provides a language for making input/output connections
  between components and defining hierarchic component structures,
  along with a set of utilities to generate code and documentation
  from these definitions.  Component input/output interfaces are defined
  using `Smidgen <smidgen>`.

.. _smidgen:

`Smidgen <smidgen-docs_>`_
  Syntax for messaging interface definition and generation.  This
  project provides a language for defining component input/output
  messaging interfaces and a set of utilities to generate code and
  documentation from these definitions.  The structure of input and
  output data is defined using `Tydl <tydl>`.

.. _tydl:

`Tydl <tydl-docs_>`_
  Type definition language for specifying the structure, layout, and
  semantic attributes of data types.  The syntax is based on `Wumps
  <wumps>`.  This project also provides a set of tools that can be
  used to generate documentation or high-level code from type
  specifications.

.. _bt:

Bt
  Build tool that manages the dependencies between software projects
  and automates the retrieval, configuration, and building of
  prerequisite software repositories.
  
.. _wumps:

`Wumps <wumps-docs_>`_
  Widely useful macro programming syntax that serves as a foundation
  for building domain-specific languages such as `Tydl <tydl>`,
  `Smidgen <smidgen>`, and `Finch <finch>`.

.. _flopi:

`Flopi <flopi-docs_>`_
  Fine-grained logging and output Python interface for displaying and
  recording status, event, debugging, warning, and error information.
  Flopi can operate as a pure Python module, or in conjunction with
  `Flout <flout>` when `extending or embedding`_ the Python
  interpreter.

.. _turtal:

`Turtal <turtal-docs_>`_
  The underlying run-time abstraction layer that isolates high-level
  code from the details related to a specific operating system,
  hardware, or message-passing framework implementation.  This library
  provides a set of uniform programming interfaces for constructs like
  message queues, threads, file input/output, timers, and schedulers.

.. _ranger:

Ranger
  Random number generation routines.  This library provides routines
  for generating pseudo-random number streams and transforming the
  draws from these streams into random variables that exhibit specific
  probability distributions.
  
.. _todes:

Todes
  Time-stepping ordinary differential equation solver.  This library
  provides an engine for the numerical solution of differential
  equations.
  
.. _caveman:

Caveman
  Common API for vector and matrix numerical operations.  This library
  provides standardized matrix and vector class interfaces to avoid
  explicit dependencies on lower-level matrix libraries.
  
.. _flout:

`Flout <flout-docs_>`_
  Fine-grained logging and output library that provides a standardized
  programming interface for the display and recording of status,
  event, debugging, warning, and error information.

.. _cuddl:

`Cuddl <cuddl-docs_>`_
  Cross-platform user-space device driver layer that provides a common API
  for writing user-space device drivers that works under `Linux <linux>`,
  `Xenomai <xenomai>`, and `RTEMS <rtems>`.

.. _development-tools:

Development Tools
=================

Software Stack for Application Development (Simplified)
-------------------------------------------------------

The following diagram illustrates how our `code crafting tools
<software>` work together with `external open-source software
<foundation>` to form a software stack for application development.

.. only:: html

   Clicking on the title of a particular block in the diagram will
   take you to a description of the associated software.

.. raw:: html
	    
   <!-- special case code for clickable svg files -->
   <object data="_images/simplified_devel_sw_stack.svg"
           width=60% type="image/svg+xml">
   </object>

.. only:: latex
	  
   .. image:: images/simplified_devel_sw_stack.*
      :align: center
      :scale: 60%

Software Stack for Application Development (Detailed)
-----------------------------------------------------

An expanded, more detailed version of this diagram shows the
dependencies between the various software projects more explicitly.

.. raw:: html
	    
   <!-- special case code for clickable svg files -->
   <object data="_images/detailed_devel_sw_stack.svg"
           width=60% type="image/svg+xml">
   </object>

.. only:: latex
	  
   .. image:: images/detailed_devel_sw_stack.*
      :align: center
      :scale: 60%

.. _run-time-software:
   
Run-Time Software
=================

Run-Time Software Stack (Simplified)
------------------------------------

The following diagram describes the structure and run-time software
dependencies for a typical application developed using our code
crafting tools.  It shows how in-house (application developer) code
interacts with 3rd-party code, the code generated by our tools, the
`libraries we provide <software>`, and `external open-source software
<foundation>`.  It also illustrates how an *alternative
object-oriented main program* can leverage component libraries outside
of the Code Craftsmen run-time framework.

.. only:: html

   Clicking on the title of a particular block in the diagram will
   take you to a description of the associated software.

.. raw:: html
	    
   <!-- special case code for clickable svg files -->
   <object data="_images/simplified_run_time_sw_stack.svg"
           width=80% type="image/svg+xml">
   </object>

.. only:: latex
	  
   .. image:: images/simplified_run_time_sw_stack.*
      :align: center
      :scale: 45%

Run-Time Software Stack (Detailed)
----------------------------------

An expanded, more detailed version of this diagram shows the
dependencies between the various software projects more explicitly.

.. raw:: html
	    
   <!-- special case code for clickable svg files -->
   <object data="_images/detailed_run_time_sw_stack.svg"
           width=80% type="image/svg+xml">
   </object>

.. only:: latex
	  
   .. image:: images/detailed_run_time_sw_stack.*
      :align: center
      :scale: 45%
	    
.. _code-crafting-tools-org: https://github.com/codecraftingtools
.. _chimps-docs: https://chimps.readthedocs.io
.. _hildegard-docs: https://hildegard.readthedocs.io
.. _shasam-docs: https://shasam.readthedocs.io
.. _finch-docs: http://finch-format.readthedocs.io
.. _smidgen-docs: http://smidgen.readthedocs.io
.. _tydl-docs: http://tydl.readthedocs.io
.. _wumps-docs: http://wumps.readthedocs.io
.. _flopi-docs: http://flopi.readthedocs.io
.. _turtal-docs: http://turtal.readthedocs.io
.. _flout-docs: http://flout.readthedocs.io
.. _cuddl-docs: http://cuddl.readthedocs.io
.. _extending or embedding: https://docs.python.org/3/extending
