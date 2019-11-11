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
  Component-based hierarchic programming system.  This is a framework
  for building software by implementing and connecting message-passing
  software components.  Chierps provides a standardized run-time
  environment for inter-component communication, scheduling, timing,
  and logging functionality, as well as a set of generalized
  application executives.  Component messaging interfaces and
  hierarchic component structures are defined and generated using
  `Pidgen`_.
  
.. _Pidgen:

Pidgen
  Programming interface definition and generation tool set.  This
  project provides a language for describing component input/output
  interfaces and hierarchic component structures, along with a set of
  tools to generate code and documentation from these descriptions.
  The structure of input and output data is defined using `Tydl`_.

.. _Tydl:

Tydl
  Type definition language.  This language is used to define the
  structure and layout of data types.  Type definitions can be used to
  generate documentation or high-level code for manipulating messages
  in various programming languages.
  
.. _Wumps:

`Wumps <Wumps docs_>`_
  Widely useful macro programming syntax.  This general-purpose syntax
  serves as a foundation for building domain-specific languages such
  as `Tydl`_ and `Pidgen`_.

Development Tools
=================

.. figure:: images/devel_sw_stack.*

   Development Tool Software Stack
	    
.. only:: website_hide_for_now
	  
  +----------------------+
  | Gsd                  |
  +----------------------+
  | Chierps              |
  +-------------+--------+
  | Pidgen      | Turtal |
  +-------------+--------+
  | Tydl        | Flout  |
  +-------------+--------+
  | Bt                   |
  +----------------------+
  | Wumps                |
  +----------------------+
  | Flopi                |
  +----------------------+

Run-Time Software
=================

.. figure:: images/run_time_sw_stack.*

   Typical Run-Time Software Stack
	    
.. _code crafting tools organization: https://github.com/codecraftingtools
.. _Wumps docs: http://wumps.readthedocs.io
