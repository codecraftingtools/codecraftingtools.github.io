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
  components.  The interfaces and hierarchic descriptions for
  components are defined using `Pidgen`_.  The Chierps framework
  provides a messaging system implementation and tools to generate
  interface code from the component descriptions.

..
  Scdl: Structural component description language
  
.. _Pidgen:

Pidgen
  Programming interface definition and generation tool set.  This is a
  language for defining software component messaging interfaces and
  hierarchic component implementations.  It is a superset of `Tydl`_,
  which is used to define message content.

.. _Tydl:

Tydl
  Type definition language.  This language is used to define the
  content of messages sent between software or hardware components.
  Type definitions can be used to generate documentation or high-level
  code for manipulating messages in various programming languages.
  
.. _Wumps:

`Wumps <Wumps docs_>`_
  Widely useful macro programming syntax.  This general-purpose syntax
  is a foundation for building domain-specific languages such as
  `Tydl`_ and `Pidgen`_.

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
