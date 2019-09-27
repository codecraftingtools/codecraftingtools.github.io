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
considerations that influence the development of our code crafting
tools.

Application Domains
-------------------

Our tools support the development of software for a wide variety of
application domains, including, but not limited to:

- Embedded systems
- Hard and soft real-time systems
- Open and closed-loop control systems
- Hardware testing
- Data acquisition
- Simulation
- Data processing
- Data display
- Desktop applications

Obviously, the code development cycle for some of these domains
(e.g. embedded, real-time, and closed-loop systems) is much more
cumbersome than for others (e.g. non-real-time simulation).  Because
of this, it would be advantageous to develop and test as much code as
possible in the simplified domains before moving into the more complex
ones.

Application Structure
---------------------

In order to maximize both our productivity and the quality of our
software, our tools facilitate the development of code that can be
used (and reused) in a wide variety of application domains without
alteration.  The following application structure helps us achieve this
goal by separating the domain-independent code from the
domain-specific code:

Components
  Well-defined software blocks which can, ideally, be used in a
  variety of application domains without alteration.  Components
  communicate with other components and interact with their
  environment through a standardized, domain-independent interface.
  It is important to note that when the Code Craftsmen use the term
  *component*, it is rarely in the general sense, but almost always
  refers a software block that conforms to a very specific interface.
  
Run-Time Environment
  Provides components with a standardized interface to run-time
  functionality, such as inter-component communication, scheduling,
  timing, and logging.  The underlying implementation may tailored to
  a specific application domain or operating system.
  
Hierarchic Design
  Multiple components can be instantiated and connected together in
  the context of a specific run-time environment to construct
  higher-level components and applications.

Application Executive
  Common application-level functionality, such as command-line option
  and input-file processing, component configuration and
  initialization, and application termination may be handled by a
  generalized or domain-specific application executive.
  
Utility Libraries
  Traditional procedural routines or object-oriented class libraries
  may be used within the implementation of a particular component,
  run-time environment, or application executive, but do not factor
  into the interface between these code segments.

Hardware Architectures
----------------------

Although there are significant differences between some of the
relevant hardware platfoms, our tools enable developers to design
software components that can be deployed on any supported hardware
architecture without source code changes, regardless of the target
instruction set, byte order, or bit width.  This means that any
platform-specific code is either pushed down into the run-time
environment, handled by lower-level hardware abstraction layers, or
strategically isolated in a few components with abstracted interfaces.
Although we desire to support a broad range of hardware architectures,
the current priority is support for **64-bit x86** and **32-bit ARM**
systems.

Operating Systems
-----------------

The write-once, run-everywhere philosophy of our tool set also extends
to operating systems, providing a way to develop software components
that are not tied to a particular host OS, but are instead portable to
any supported real-time or non-real-time operating environment without
modification.  Although future possibilities are endless, the current
focus is on providing support for:

- Standard desktop and embedded Linux
- Real-time Linux (PREEMPT_RT)
- Real-time Linux (Xenomai/cobalt)
- RTEMS

Programming Language Support
----------------------------

At a fundamental level, we require all software components to interact
with their run-time environment via a standardized programming
interface based on C function calls.  Our tools provide a set of
higher-level language-specific bindings, built on top of this C API,
that allow components to be implemented in a way that conforms to the
conventions of each programming language.  This approach allows
software components written in various programming languages to
interoperate with one another in the same run-time environment.  Our
current priority is the development of bindings for **C++** and
**Python**, but we hope to eventually support a host of other
programming languages.

Inter-Component Communication Methodology
-----------------------------------------

..
  The primary function of a software component is to receive data from
  other components, perform some operations in reponse to that data, and
  then send data to other components.

For the many reasons described elsewhere in this documentation, our
design approach requires components to communicate with one another in
a standardized way.  There are many mechanisms that could be used to
transfer data between components, each with their own advantages and
disadvantages:

- Method calls
- Shared memory
- Message passing

In light of our goals and application domains, the versatility of the
message-passing approach has proven to be a good choice for
standardization.

..
  Primary focus is on message passing, with some limited support for
  object-oriented component operation.

..
  Run-time Environments
  ---------------------

  - Messaging framework / run-time environment
  - Object oriented API
  - Single/multi-threaded

..
  Component Environment Interface
  -------------------------------

  - Abstract interface to main application and messaging framework
  - Properties

..
  Standardized Component Interfaces
  ---------------------------------

  Allows for interchanging of components with similar interfaces at
  instantiation or compile-time.

..
  File Formats
  ------------

  - Support for arbitrary metadata embedding
  - Code generation
  - Parameterization

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

  Source vs binary compatibility
  
  Threading / concurrent / parallel execution
  
  Our tools are designed/support/be applicable/enable/deliver/transition
  
  real-time concerns Input/Output, logging, timing/scheduling

  app executive / embedding in other applications / python scripting / OO API
  
  blocking/non-blocking components
  
.. _Don't repeat yourself:
   https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
