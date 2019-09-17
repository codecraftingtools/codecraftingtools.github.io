.. _design:

======
Design
======

Goals
=====

In the Code Craftsmen's view, writing software is currently much more
difficult than it needs to be.  Our hope, and our primary goal, is to
**restore the joy in programming** by developing code crafting tools
that make software:

- Easier to read
- Easier to write
- Easier to maintain
- Easier to reuse

Principles
==========

There are a few key principles that support these goals and drive our
design strategy, such as:

- `Don't repeat yourself`_
- Design for testability
- Documentation is important
- Don't repeat yourself (unless it's worth saying twice)

Although there are surely some other principles worth adding to this
list, the ones listed here play a major role in many of our design
decisions.

Considerations
==============

In this section, we will briefly walk through a number of design
considerations that have influenced the development of our code
crafting tools.

Application Domains
--------------------

Our tools should support the development of software applications in a
wide variety of domains, including, but not limited to:

- Embedded systems
- Hard and soft real-time systems
- Open and closed-loop control systems
- Hardware testing
- Data acquisition
- Simulation
- Data processing
- Data display
- Desktop applications

Application Structure
---------------------

- Reusable software components
- Hierarchic component design
- Abstracted run-time environment
- Abstracted application executive
- Scripting interface
  
Hardware Architectures
----------------------

Wherever possible, our tools should allow software components to be
compiled for any supported hardware architecture with minimal (ideally
zero) code changes.  Currently, the priority is support for 64-bit x86
and 32-bit ARM systems.

Operating Systems
-----------------

Similarly, software components should be able to be used on any
supported operating system without modifications to the source code.
Hopefully, the operating system choices will expand in the future, but
our initial focus will be:

- Standard GNU/Linux
- Real-time GNU/Linux (PREEMPT_RT)
- Real-time GNU/Linux (Xenomai/cobalt)
- RTEMS

Programming Language Support
----------------------------

- Inter-language operation
- Component implementations
  
  - C++
  - Python
    
- Python scripting

Inter-Component Communication Methodology
-----------------------------------------

Trade-offs of how to pass data between software components.

- Method calls
- Shared memory
- Message passing

Primary focus is on message passing, with some limited support for
object-oriented componet operation.

Run-time Environments
---------------------

- Messaging framework / run-time environment
- Object oriented API
- Single/multi-threaded

Component Environment Interface
-------------------------------

- Abstract interface to main application and messaging framework
- Properties

Standardized Component Interfaces
---------------------------------

Allows for interchanging of components with similar interfaces at
instantiation or compile-time.

File Formats
------------

- Support for arbitrary metadata embedding
- Code generation
- Parameterization

.. _Don't repeat yourself:
   https://en.wikipedia.org/wiki/Don%27t_repeat_yourself

..
  Comment section for ideas
  
  A fully-featured application executive leverages standardized
  component configuration and operation mechanisms to minimize
  application-level boilerplate and code duplication.

  This is achieved by employing...
  
  Code reuse is maximized / code duplication is minimized

  Generation of boilerplate/glue code
   
  Corollaries
   
  - Break software into reusable components

   Some domains of interest are: of We desire
  our tools and our so Laboratory and prototyping -- reconfigurability.

