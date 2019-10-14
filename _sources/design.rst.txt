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
  timing, and logging.  The underlying implementation may be
  general-purpose or tailored to a specific application domain or
  operating system.
  
Hierarchic Design
  Multiple components can be instantiated and connected together in
  the context of a specific run-time environment to construct
  higher-level components and applications.

Application Executive
  Common application-level functionality, such as command-line option
  and input-file processing, component configuration and
  initialization, and application termination may be handled by a
  generalized or domain-specific application executive.

Hardware and Operating System Abstraction Layer
  Provides a uniform, hardware-independent programming interface to
  standard operating system functionality.

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
platform-specific code must be incorporated into a lower-level
abstraction layer, handled by the run-time environment, or
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
modification.  In order to achieve this, any OS-specific code must be
incorporated into a lower-level abstraction layer or handled by the
run-time environment.  Although future possibilities are endless, the
current focus is on providing support for:

- Standard desktop and embedded Linux
- Real-time Linux (PREEMPT_RT)
- Real-time Linux (Xenomai/cobalt)
- RTEMS

Concurrent and Parallel Processing
----------------------------------

Many of our application domains require support for independent
software components executing concurrently, or even simultaneously (in
parallel).  There are several categories of concurrency that we must
consider:

Preemptive Multitasking
  Execution of a task may be forcibly suspended by the operating
  system in order to give another task a turn.  Many real-time
  systems, for example, have long-running lower-priority tasks that
  must be preempted by high-priority short-duration tasks in order to
  meet real-time deadlines.  This is typically achieved by creating a
  separate operating-system thread or process for each task.  In many
  real-time systems, these threads and processes can be assigned
  priority values to ensure that high-priority tasks take precedence
  over low-priority ones.

Cooperative Multitasking
  Tasks may voluntarily yield execution to other tasks at specific
  points in time.  One example of this type of concurrency is a
  physics simulation involving several models, where each of these
  models must be updated at each time step.

Parallel Processing
  Tasks execute simultaneously on different processors.  Parallel
  processing is often used to speed up program execution or perform
  several unrelated tasks at once.  In many general-purpose
  parallel-processing systems, several operating-system threads or
  processes can be executed in parallel.

Our code crafting tools are designed to allow software components to
execute concurrently in all of these environments with minimal effort.
This is critical for real-time applications, but is also useful for
speeding up non-real-time applications by breaking up software into
independent pieces that can run in parallel on separate processors.
Most software components should not need to know anything about
threads, processes, scheduling policies, or priorities.  Our tools
allow these details to be easily specified when low-level components
are instantiated and combined together into a higher-level component
or application.

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

For the many reasons described elsewhere in this documentation, our
design approach requires components to communicate with one another in
a standardized way.  There are many mechanisms that could be used to
transfer data between components, each with their own advantages and
disadvantages:

Method Calls
  In object-oriented programming languages, data is typically
  transferred between objects by having one object pass data to (or
  receive data from) another object using method calls (member
  functions).  This approach is simple and well understood, but has
  many drawbacks:

  - Passing data between objects using method calls is not
    thread-safe, so data transfer between objects in different threads
    typically requires manual, error-prone synchronization.
    
  - Objects typically have no way to "send out" information.
    Typically, the outputs of an object must be retrieved by a
    higher-level object.

  - Custom top-level glue code must often be written to extract data from
    one component and pass it into another.
    
  - In languages with strict typing, it is difficult to "connect" objects
    that were not designed specifically to work together.
    
  - Inter-language operation is usually possible, but tedious to
    implement.

Callback Functions
  In some object-oriented architectures, objects do attempt to "send
  out" data by storing a pointer to an output object and calling a
  member-function of that object to send data to that object.  This
  approach still has many issues:

  - Manual checks may have to be performed to see if a destination
    object has been "connected".

  - Multiple destination objects are usually not a possibility.

  - Callback loops can cause issues with non-reentrant code.

Shared Memory
  The use of shared memory is a simple, commonly-used, and very
  efficient, method of passing data between software components.  In
  this scheme, components read input data from and write data to
  predetermined shared memory locations.  There are, however, several
  major drawbacks to this approach:
  
  - Passing data between components using shared memory is not
    thread-safe, so data transfer between components in different
    threads typically requires manual, error-prone synchronization.
    
  - Memory usage may be high.
    
  - If pointers are used to specify the location of input or output
    variables, manual checks may be required to make sure these
    pointers have been initialized.
    
  - Some shared memory communication schemes use global variable
    locations, which introduces a host of well-known issues.
  
Message Passing
  In message-passing systems, information is transmitted by passing
  data structures from one software component to another through some
  sort of message delivery framework.  The messaging framework
  typically employs some form of message queues to synchronize the
  data transmission.  Depending on the design of the system, data may
  be passed by reference or by value. Message-passing systems have a
  number of benefits:

  - Many implementations support the transmission of messages between
    threads, or even processes, without any manual synchronization.

  - Multiple messaging system implementations can be supported with no
    changes to the software components.  The messaging system
    implementation can be chosen at compile, link or run time.
    
  - The message sender does not need to know anything about the
    receiver.  Zero, one, or more message receivers can be connected
    to a single sender.

  - The message sender and receiver only need to agree on the format
    of the data structure being passed, not the class hierarchy.

  - The amount of custom top-level glue code required to transfer data
    between components is minimal.
    
  - The message-passing concept maps naturally to many communication
    channels, such as network sockets, file I/O, serial and block
    device I/O, UNIX pipes, Qt signals and slots, event-driven
    systems, function calls, and message queues.
    
  - Many real-time operating systems offer native support for message
    queues.

  - Inter-language operation is straightforward to implement.

Although message-passing systems can be more complex and slower than
some of the alternatives, the versatility offered by this approach
makes it a great choice, given our design goals and application
domains.  For this reason, we haven chosen to use **message passing as
the standard means of inter-component communication** in our software.

Standardized Component Interfaces
---------------------------------

In order for two components to communicate via message passing, the
message sender and receiver must agree on the content and structure of
the messages passed between them.  When designing sofware components,
developers should give careful consideration to the format of the
messages sent between components in order to make sure that components
use compatible message types wherever possible.  Although not strictly
required, the use of compatible message types reduces the amount of
glue code required to connect components together.  In the cases where
two components with incompatible message types must be connected,
hand-coded or auto-generated message converter components must be
employed.

Careful thought should also be given to a component's *interface*, or
set of input/output message names and types.  If two components share
the same interface, then these components can be interchanged at
compile time, or even run time, without changing the application
structure.  Although interface compatibility is highly desirable, it
is not absolutely critical.  Unlike many object-oriented schemes,
interfaces are not required to match in order for components to be
used together, but it does make things easier.

Configuration
-------------

Since all but the simplest of software components require some type of
configuration, our tools provide built-in support for this operation.
In our system, software components are merely responsible for
declaring the names, types, and default values of their configurable
properties.  The actual assignment of these properties is handled by
the run-time environment or application executive.  This approach
allows all of the software components in an application to be
configured in a uniform way, and the configuration code can be
leveraged across many applications.

Because message-passing was chosen as the standardized means of
inter-component communication, it follows that components should be
configured by sending them messages.  Under the hood, a configuration
property is simply a member variable whose value can be set via an
input message.  Typically, components also send an output message when
the value of a property changes so that the value of one property can
by tied to the value of another.

In our system, components delegate the configuration process to the
outside world, so configuration may be handled in various ways,
depending on the application.  For embedded applications with no user
interface or filesystem, configuration may be reduced to simply
specifying property values at compile-time.  This can be done by
instantiating derived components that override default property values
or by making connections that tie the value of one property to
another.  In other applications, software components may be configured
through the use of command-line options, input files, or a GUI dialog
box.  Since component properties are all defined in a uniform way, the
code that handles the configuration does not need to be hand-coded for
each application.

So far, we have only considered the simple assignment of properties.
In addition to the fundamental property attributes (i.e. name, type,
default value), components can also declare additional attributes to
supply information that may be useful in certain run-time
environments.  The declaration of min/max value constraints could be
used to automatically check that run-time property assignments are
within the expected range.  Unit constraints could be used to check
that the user has supplied values with the proper units or even
perform automatic conversions.  Statistical constraints, like random
distribution parameters, could be used by a simulation engine to make
Monte Carlo draws.  The possibilities are endless.

Logging and Screen Output
-------------------------

Most software components require some mechanism for conveying run-time
status information to the user.  This includes things like
informational and debug messages as well as the logging of events,
errors, and warnings.  Since the way these functions are handled
varies widely from one application domain to another, the run-time
environment provides a standardized programming interface for these
functions.

In some domains, direct screen and log file output is available.  In
other systems, screen and log file output are available, but must be
buffered due to real-time constraints.  In some embedded domains,
reporting may be very restricted (e.g. a few words of information in a
telemetry stream), so output is reduced to capturing error codes or
source file and line numbers.  The programming interface provided by
the run-time environment must take all of these cases into
consideration.

The amount of information reported by an application may also change
due to compile-time options or run-time selection.  For example, users
may choose to enable verbose or debug screen output, or record errors
and warnings in a log file.  To provide the most flexibility, logging
output levels should be selectable at component level.  This enables
debug output to be enabled for one component without enabling debug
output for all components, which would be overwhelming and
counter-productive.

Timekeeping
-----------

Many components require some information about the passage of time in
order to operate.  This might be determining the absolute time that an
event occurred, measuring the elapsed time between events, or
scheduling some processing to occur at a specific periodic frequency.
In order to support this functionality, the run-time environment
provides software components with a standardized timekeeping API that
is consistent across all application domains.

Real-Time
  In systems that must meeting timing deadlines, the run-time
  environment may deliver very precise time measurement and scheduling
  functionality.

Non-Real-Time
  In systems where timing requirements are not as demanding, the
  run-time environment may supply a less precise implementation.

Simulated-Time
  In some simulations, a software component's notion of time may not
  be tied to the passage of time in the real world at all, but is
  instead advanced by an external simulation executive.

In some systems, there may not be a single authoritative time standard
that is suitable for all purposes.  For instance, some events may be
measured in terms of system time, and others with respect to an
external timing source.  To support these use cases, the timekeeping
API also provides support for the measurement of time according to
multiple time references that may drift relative to one another, and
for converting time values from one time base to another.
  
Scheduling
----------

..
  non-blocking
  policies/priorities
  periodic, one-time, deferred
  
File / Device Input and Output
------------------------------

..
  Real-time, logging

Data Logging and Message Playback
---------------------------------

Run-time Environments
---------------------

..
  - Messaging framework / run-time environment
  - rt, msg/thread priorities, zeromq
  - Object oriented API
  - Single/multi-threaded

Application-Level Code
----------------------

..
  top-level code
  scripting
  glue
  embedding
  OO
  
File Formats
------------

..
  - Support for arbitrary metadata embedding
  - Code generation
  - Parameterization

Code Generation
---------------

..
  glue logic could be mentioned here
  
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
  
  Our tools are designed/support/be applicable/enable/deliver/transition
  
  real-time concerns Input/Output, logging, timing/scheduling

  app executive / embedding in other applications / python scripting / OO API
  
  Primary focus is on message passing, with some limited support for
  object-oriented component operation.

  blocking/non-blocking components
  
  Allows for interchanging of components with similar interfaces at
  instantiation or compile-time.  Not enforced, but enabled by tool set.
  
.. _Don't repeat yourself:
   https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
