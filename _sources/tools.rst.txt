.. _tools:

=====	     
Tools
=====

Overview
========

The following code crafting tools are (or will be) available on
`GitHub`_:

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

`Wumps <Wumps-site_>`_
  Widely useful macro programming syntax.  This general-purpose syntax
  is a foundation for building domain-specific languages such as
  `Tydl`_ and `Pidgen`_.

.. only:: website_hide_for_now

  Dependencies
  ============

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

.. _GitHub: https://github.com/codecraftingtools
.. _Wumps-site: http://wumps.codecraftsmen.org
