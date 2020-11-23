========
Workflow
========

Let us walk through a simple example to demonstrate how our code
crafting tools can be leveraged in bottom-up or top-down software
development workflows.

Bottom-Up
=========

Message Definition
------------------

The first step in a bottom-up workflow is to define the data content
and format of each message that is passed between software components
in the application.  This is accomplished by writing suitable data
structure declarations in `Tydl <tydl>`, our custom type definition
language.

.. highlight:: none

.. literalinclude:: HVAC/Temperature.tyd
   :caption:

Component Interface Definition
------------------------------

The next step is to define the messaging interface for each software
component in the application.  Components have input ports for
receiving messages from other components and output ports for sending
messages to other components.  Each port has a name and an associated
data type that defines the message format.  Component messaging
interfaces are defined using the `Smidgen <smidgen>` syntax, which
builds on `Tydl <tydl>`.

.. table::
   :widths: 15 10
   :width: 100%

   +--------------------------------+------------------------------+
   |                                | .. only:: latex              |
   |                                |                              |
   | .. literalinclude::            |      .                       |
   |    HVAC/Temperature/Sensor.cmi |                              |
   |    :caption:                   | .. image:: sensor_cmi.*      |
   +--------------------------------+------------------------------+

.. table::
   :widths: 15 10
   :width: 100%
	   
   +-----------------------------+------------------------------+
   |                             | .. only:: latex              |
   |                             |                              |
   | .. literalinclude::         |      .                       |
   |    HVAC/Heating/Element.cmi |                              |
   |    :caption:                | .. image:: element_cmi.*     |
   +-----------------------------+------------------------------+

Primitive Component Declaration
--------------------------------

Stay tuned...

Primitive Component Implementation
----------------------------------

Stay tuned...
