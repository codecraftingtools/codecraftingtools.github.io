========
Workflow
========

Let us walk through a simple (but complete) example to demonstrate how
our code crafting tools can be leveraged in bottom-up or top-down
software development workflows.

Bottom-Up
=========

Define Message Data Structures
------------------------------

The first step in a bottom-up workflow is to define the data content
and format of each message that is passed between software components
in the application.  This is accomplished by writing suitable data
structure declarations in `Tydl <tydl>`, our custom type definition
language.

.. highlight:: none

.. literalinclude:: HVAC/Temperature.td
   :caption:

Define Component Messaging Interfaces
-------------------------------------

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
	   
   +-----------------------------------+------------------------------+
   |                                   | .. only:: latex              |
   |                                   |                              |
   | .. literalinclude::               |      .                       |
   |    HVAC/Heating/Element.mi        |                              |
   |    :caption:                      | .. image:: element_mi.*      |
   +-----------------------------------+------------------------------+

.. table::
   :widths: 15 10
   :width: 100%

   +-----------------------------------+------------------------------+
   |                                   | .. only:: latex	      |
   |				       |			      |
   | .. literalinclude::	       |      .			      |
   |	HVAC/Temperature/Controller.mi |			      |
   |	:caption:		       | .. image:: controller_mi.*   |
   +-----------------------------------+------------------------------+

.. table::
   :widths: 15 10
   :width: 100%

   +-----------------------------------+------------------------------+
   |                                   | .. only:: latex              |
   |                                   |                              |
   | .. literalinclude::               |      .                       |
   |    HVAC/Temperature/Sensor.mi     |                              |
   |    :caption:                      | .. image:: sensor_mi.*       |
   +-----------------------------------+------------------------------+

.. table::
   :widths: 15 10
   :width: 100%
	   
   +-----------------------------------+------------------------------+
   |                                   | .. only:: latex              |
   |                                   |                              |
   | .. literalinclude::               |      .                       |
   |    HVAC/Thermostat.mi             |                              |
   |    :caption:                      | .. image:: thermostat_mi.*   |
   +-----------------------------------+------------------------------+

Declare Primitive Components
----------------------------

After defining the component messaging interfaces, the next step is to
provide declarations for each primitive C++ component.

.. literalinclude:: HVAC/Heating/Element.pi
   :caption:

.. literalinclude:: HVAC/Temperature/Controller.pi
   :caption:

.. literalinclude:: HVAC/Temperature/Sensor.pi
   :caption:

Implement Primitive Components
------------------------------

Primitive C++ components are implemented by suppling header and source
files that provide conforming class declarations and definitions.

.. highlight:: C++

.. literalinclude:: HVAC/Heating/Element.hpp
   :caption:

.. literalinclude:: HVAC/Heating/Element.cpp
   :caption:

.. literalinclude:: HVAC/Temperature/Controller.hpp
   :caption:

.. literalinclude:: HVAC/Temperature/Controller.cpp
   :caption:

.. literalinclude:: HVAC/Temperature/Sensor.hpp
   :caption:

.. literalinclude:: HVAC/Temperature/Sensor.cpp
   :caption:

.. highlight:: none

Define the Component Hierarchy
------------------------------

Once the primitive components have been implemented, they can be
combined and connected to form composite components that build on one
another in a hierarchic fashion.

.. table::
   :widths: 13 10
   :width: 100%
	   
   +-----------------------------------+------------------------------+
   |                                   | .. only:: latex              |
   |                                   |                              |
   | .. literalinclude::               |      .                       |
   |    HVAC/Thermostat.hi             |                              |
   |    :caption:                      | .. image:: thermostat_hi.*   |
   +-----------------------------------+------------------------------+

.. table::
   :widths: 13 10
   :width: 100%
	   
   +-----------------------------------+------------------------------+
   |                                   | .. only:: latex              |
   |                                   |                              |
   | .. literalinclude::               |      .                       |
   |    HVAC/Heater.hi                 |                              |
   |    :caption:                      | .. image:: heater_hi.*       |
   +-----------------------------------+------------------------------+

Define the Application
----------------------

.. literalinclude:: HVAC/Heater.ha
   :caption:

Build the Executable
--------------------

We now have the following directory structure::
  
  HVAC/
  ├── Heater.ha
  ├── Heater.hi
  ├── Heating
  │   ├── Element.cpp
  │   ├── Element.hpp
  │   ├── Element.mi
  │   └── Element.pi
  ├── Temperature
  │   ├── Controller.cpp
  │   ├── Controller.hpp
  │   ├── Controller.mi
  │   ├── Controller.pi
  │   ├── Sensor.cpp
  │   ├── Sensor.hpp
  │   ├── Sensor.mi
  │   └── Sensor.pi
  ├── Temperature.td
  ├── Thermostat.hi
  └── Thermostat.mi

From the parent directory, the application executable can be built
like this::

  chimps --build=app --all HVAC

The previous command performs the following individual steps, which
have been broken out for instructional purposes::

  chimps --generate=type --entity=HVAC.Temperature.Measurement HVAC
  chimps --compile=type  --entity=HVAC.Temperature.Measurement HVAC
  chimps --generate=impl --entity=HVAC.Heating.Element.Impl \
                         --entity=HVAC.Temperature.Controller.Impl \
                         --entity=HVAC.Temperature.Sensor.Impl \
                         --entity=HVAC.Thermostat.Impl \
                         --entity=HVAC.Heater.Impl HVAC
  chimps --compile=impl  --entity=HVAC.Heating.Element.Impl \
                         --entity=HVAC.Temperature.Controller.Impl \
                         --entity=HVAC.Temperature.Sensor.Impl \
                         --entity=HVAC.Thermostat.Impl \
                         --entity=HVAC.Heater.Impl HVAC
  chimps --generate=app  --entity=HVAC.Heater.App HVAC
  chimps --compile=app   --entity=HVAC.Heater.App HVAC
