=====
RTEMS
=====

`RTEMS <rtems>` is an embedded, open-source, real-time operating system.
  
External Documentation
======================

- `RTEMS Web Site <rtems-site_>`_
- `RTEMS Raspberry Pi Info <rtems-rpi_>`_
- `RTEMS Debugging Example <rtems-dbg_>`_
- `More RTEMS Debugging Info <rtems-dbg2_>`_

.. _rtems-site: https://www.rtems.org
.. _rtems-rpi:
   https://docs.rtems.org/branches/master/user/bsps/arm/raspberrypi.html
.. _rtems-dbg:
   https://docs.adacore.com/gnat_ugx-docs/html/gnat_ugx/gnat_ugx/rtems_topics.html
.. _rtems-dbg2:
   https://lists.rtems.org/pipermail/users/2020-April/067600.html

Installation Notes (Ubuntu 18.04)
=================================

Build the RSB Tools
-------------------

The first step is to build a suitable cross-compiler toolchain for the target
CPU architectures.  This is done using the ``rtems-source-builder`` tool.

First, install the system packages required to build the cross compiler::

  sudo apt-get install build-essential g++ gdb git unzip pax bison flex libpython-dev libncurses5-dev zlib1g-dev

Now pull down the Python-based ``rtems-source-builder`` project and
(optionally) check out the specific revision that was used when writing these
notes::
  
  git clone git://git.rtems.org/rtems-source-builder.git
  cd rtems-source-builder/rtems
  git checkout f0e34ea

These are some optional, but useful commands you can run at this point::
  
  ../source-builder/sb-check
  ../source-builder/sb-set-builder --list-bsets

Then build the 32-bit ARM toolchain::

  $ DOCBOOK_TO_MAN="xmlto man --skip-validation" \
    ../source-builder/sb-set-builder --without-rtems \
    --prefix=/opt/rsb-tools-rtems-6-f0e34ea 6/rtems-arm

and/or the 64-bit ARM toolchain::
  
  $ DOCBOOK_TO_MAN="xmlto man --skip-validation" \
    ../source-builder/sb-set-builder --without-rtems \
    --prefix=/opt/rsb-tools-rtems-6-f0e34ea 6/rtems-aarch64

Build the Desired RTEMS BSPs
----------------------------

First, pull down the ``rtems`` source repository and (optionally) check out
the specific revision that was used when writing these notes::
  
  git clone git://git.rtems.org/rtems.git
  cd rtems
  git checkout acf4eb2

Now make sure that the ``rtems-source-builder`` tools are in your path::

  export PATH="/opt/rsb-tools-rtems-6-f0e34ea/bin:$PATH"

These are some optional, but useful commands you can run at this point::
  
  ./waf bsplist
  ./waf bsplist --rtems-bsps='arm/.*zynq.*'
  ./waf bsplist --rtems-bsps='aarch64/xilinx_zynqmp.*'
  ./waf bspdefaults --rtems-bsps='aarch64/xilinx_zynqmp_lp64_zu3eg'

Now create a sample configuration file for the BSP to build.  The following
is suitable for use with an UltraZed board::
  
  echo -e "[aarch64/xilinx_zynqmp_lp64_zu3eg]" > config.ini
  echo -e "BUILD_SAMPLES = False" >> config.ini
  echo -e "RTEMS_POSIX_API = True" >> config.ini
  echo -e "BSP_RESET_BOARD_AT_EXIT = 0" >> config.ini

The following is suitable for use with a MicroZed or ZedBoard::
  
  echo -e "[arm/xilinx_zynq_zedboard]" > config.ini
  echo -e "BUILD_SAMPLES = False" >> config.ini
  echo -e "RTEMS_POSIX_API = True" >> config.ini
  echo -e "BSP_RESET_BOARD_AT_EXIT = 0" >> config.ini
  echo -e "BSP_ARM_A9MPCORE_PERIPHCLK = 333333333" >> config.ini
  echo -e "ZYNQ_RAM_LENGTH = 0x40000000" >> config.ini

The following is suitable for use with a Zynq7000 QEMU setup::

  echo -e "[arm/xilinx_zynq_a9_qemu]" > config.ini
  echo -e "BUILD_SAMPLES = False" >> config.ini
  echo -e "RTEMS_POSIX_API = True" >> config.ini
  echo -e "BSP_RESET_BOARD_AT_EXIT = 0" >> config.ini

The following is suitable for use with a Raspberry Pi::

  echo -e "[arm/raspberrypi]" > config.ini
  echo -e "BUILD_SAMPLES = False" >> config.ini
  echo -e "RTEMS_POSIX_API = True" >> config.ini
  echo -e "BSP_RESET_BOARD_AT_EXIT = 0" >> config.ini
  
Once you have a config file, you can build an RTEMS BSP like this::

  ./waf configure --prefix=/opt/rsb-tools-rtems-6-f0e34ea
  ./waf
  ./waf install

Note that appropriate compiler/linker flags for each BPS can be found in the
associated ``.pc`` files found here::
  
  /opt/rsb-tools-rtems-6-f0e34ea/lib/pkgconfig/


.. note::

  With the appropriate options, the RTEMS BSPs can alternatively be built from
  an "out-of-tree" build directory.  e.g. ::
    
    /path/to/rtems/waf --out=$PWD/build --top=/path/to/rtems --no-lock-in-top --no-lock-in-run --prefix=/opt/rsb-tools-rtems-6-f0e34ea configure --rtems-config $PWD/config.ini
     
    /path/to/rtems/waf --out=$PWD/build --top=/path/to/rtems --no-lock-in-top --no-lock-in-run --prefix=/opt/rsb-tools-rtems-6-f0e34ea
     
    /path/to/rtems/waf --out=$PWD/build --top=/path/to/rtems --no-lock-in-top --no-lock-in-run --prefix=/opt/rsb-tools-rtems-6-f0e34ea install

Compile a Hello World Application
---------------------------------

Create a file called ``hello.c`` containing:

.. code-block:: c

  #include <stdio.h>
   
  void *POSIX_Init()
  {
      puts("Hello World");
      return NULL;
  }
   
  #define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
  #define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
  #define CONFIGURE_POSIX_INIT_THREAD_TABLE
  #define CONFIGURE_INIT
  #define CONFIGURE_UNLIMITED_OBJECTS
  #define CONFIGURE_UNIFIED_WORK_AREAS
  #include <rtems/confdefs.h>

Then compile it, using any required flags found in the ``.pc`` file mentioned
above::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6-gcc -c -o hello.o -I/opt/rsb-tools-rtems-6-f0e34ea/arm-rtems6/raspberrypi/lib/include -mcpu=arm1176jzf-s -ffunction-sections -fdata-sections hello.c
  /opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6-gcc -o hello.elf -mcpu=arm1176jzf-s -B/opt/rsb-tools-rtems-6-f0e34ea/arm-rtems6/raspberrypi/lib -qrtems -Wl,--gc-sections hello.o

Build the bootgen tool (Zynq/ZynqMP Targets)
--------------------------------------------

First, pull down the ``bootgen`` source repository and (optionally) check out
the specific revision that was used when writing these notes::

  git clone https://github.com/Xilinx/bootgen.git
  cd bootgen
  git checkout xilinx_v2021.1

Now make sure that you have the ``libssl-dev`` package required in order to compile ``bootgen``::

  sudo apt-get install libssl-dev

Now you can build ``bootgen``:

  make

This should generate the ``bootgen`` executable.

Note that later releases of this tool seem to generate warning messages for
the Zynq 7000 target when both an FSBL and bitstream are specified in a
``.bif`` file.

Building the ARM Trusted Firmware for ZynqMP Targets
----------------------------------------------------

First, pull down the source code::

  git clone https://github.com/Xilinx/arm-trusted-firmware
  cd arm-trusted-firmware

Now build it::
  
  CROSS_COMPILE=aarch64-rtems6- make PLAT=zynqmp RESET_TO_BL31=1

If you run into trouble, you can build with with debug output::
  
  CROSS_COMPILE=aarch64-none-elf- make PLAT=zynqmp RESET_TO_BL31=1 LOG_LEVEL=50 ZYNQMP_ATF_MEM_BASE=0x12000000 ZYNQMP_ATF_MEM_SIZE=0x00100000

This yields a ``bl31.elf`` file that is used with ``bootgen``.

Building the PMU Firmware for ZynqMP
------------------------------------

In Vivado SDK, perform the following steps:
  
- File->New->Application Project
- Project name: pmu
- Processor: psu_pmu_0
- Next, PSU PMU Firmware, Finish
- Yields pmu.elf

Build a Boot Image for Zynq Targets
-----------------------------------

Create a file called ``hello.bif`` containing::

  the_ROM_image:
  {
    [bootloader]fsbl.elf
    system_wrapper.bit
    hello.elf
  }

The ``fsbl.elf`` and ``system_wrapper.bit`` files are generated in Vivado.

Now generate a bootable image for the "Hello World" application::

  /path/to/bootgen -arch zynq -image hello.bif -o hello.bin

Build a Boot Image for ZynqMP Targets
-------------------------------------

Create a file called ``hello.bif`` containing::

  the_ROM_image:
  {
          //[pmufw_image]pmu.elf // pmu fw loaded by boot rom
          [bootloader, destination_cpu=a53-0]fsbl.elf
          [destination_cpu=pmu]pmu.elf // pmu fw loaded by fsbl
          [destination_device=pl]system_wrapper.bit // optional
          [destination_cpu=a53-0, exception_level=el-3, trustzone]bl31.elf
          [destination_cpu=a53-0, exception_level=el-2]hello.elf
  }

The ``fsbl.elf``, ``pmu.elf`` and ``system_wrapper.bit`` files are generated
in Vivado.

Now generate a bootable image for the "Hello World" application::

  /path/to/bootgen -arch zynqmp -image hello.bif -o hello.bin

Raspberry Pi Setup
------------------

The following instructions were tested with a first-generation Raspberry Pi.

First, configure an SD card for booting the Raspberry Pi using the standard
process, but choose one of the minimal images.  On Ubuntu, this is best done
via::

  sudo apt-get install rpi-imager
  rpi-imager

Choose the ``Raspberry Pi OS Lite (Legacy/Buster)`` image and write it to an
SD card.

The default configuration should have the serial boot console enabled.
Connect up something like the `FTDI TTL-232R-3V3 cable
<https://www.ftdichip.com/Support/Documents/DataSheets/Cables/DS_TTL-232R_CABLES.pdf>`_
to your PC.  With this cable, the yellow PC-RXD pin connects to the PI-TXD
(P1-PIN8), the black PC-GND pin connects to the PI-GND (P1-PIN6), and the
orange PC-TXD pin connects to the PI-RXD (P1-PIN10) as shown `here
<https://www.raspberrypi.com/documentation/computers/raspberry-pi.html>`_.

Now run the following command in a terminal window and power up the Pi with
the SD card inserted::

  sudo picocom /dev/ttyUSB0 --b 115200 --d 8 --p n --f

You should see kernel boot output.  Now type <ctrl-a><ctrl-q> to quit
picocom.

Booting RTEMS currently requires an older version of the Pi firmware to be
installed on the SD card, so download a zip file with the required firmware
from `this link <https://github.com/raspberrypi/firmware/tree/1.20200601>`_.
Checking out the whole Git repo takes a very long time.

Now mount the SD card boot partition and move all the files in that boot
directory into a subdirectory (except for ``config.txt``), as they will be
replaced.  Now copy all the files from the boot directory of the zip file you
just downloaded onto the boot partition of the SD card::

  mkdir /media/user/boot/backup
  mv /media/user/boot/* /media/user/boot/backup
  mv /media/user/boot/backup/config.txt /media/user/boot
  cp -r firmware-1.20200601/boot/* /media/user/boot

We also need to add the following lines to the end of ``config.txt``::

  dtoverlay=disable-bt
  kernel_address=0x200000
  kernel=kernel.img

You can test the booting of this configuration once more to make sure you
still see serial output.

Building a Raspberry Pi Kernel Image
------------------------------------

In order to create a bootable image for use on the Raspberry Pi, you must run
the following command::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6-objcopy -Obinary hello.elf kernel.img

Booting a Raspberry Pi Kernel Image
-----------------------------------

You can now copy the ``kernel.img`` file you created previously onto the boot
partition of the Raspberry Pi SD card (overwriting the existing one) and
power up the board::

  cp kernel.img /media/user/boot/

You should text see output appear in the ``picocom`` terminal window that you
set up previously.

Booting a MicroZed BOOT.BIN Image
---------------------------------

Now copy the ``hello.bin`` file (generated via ``bootgen``) into the root
directory of a MicroZed's SD card, renaming it ``BOOT.BIN``.

Now put the SD card into the MicroZed and boot it up.

Before turning on power to the development board, connect up the USB UART
cable to your workstation and run this command in a terminal window::

  picocom /dev/ttyUSB0 --b 115200 --d 8 --p n --f n

Now type <ctrl-a><ctrl-q> to quit picocom.

Booting an UltraZed BOOT.BIN Image
----------------------------------

Now copy the ``hello.bin`` file (generated via ``bootgen``) into the root
directory of an UltaZed's SD card, renaming it ``BOOT.BIN``.

Now put the SD card into the UltraZed and boot it up.

Before turning on power to the development board, connect up the USB UART
cable to your workstation and run this command in a terminal window::

  picocom /dev/ttyUSB1 --b 115200 --d 8 --p n --f n

Now type <ctrl-a><ctrl-q> to quit picocom.

Build libbsd for RTEMS (Optional)
---------------------------------

If you want extra features like networking and SD card drivers, you will also
need to build ``libbsd``.

In order to do this, first pull down the ``rtems-libbsd`` source repository
and (optionally) check out the required branch that works with RTEMS (commit
``ac4cf946a28329cc65cbc0c30ec1ed0d6449d7cc`` was used when writing these
notes)::
  
  git clone git://git.rtems.org/rtems-libbsd.git
  cd rtems-libbsd
  git checkout 6-freebsd-12
  git submodule init
  git submodule update rtems_waf
  ./waf configure --prefix=/opt/rsb-tools-rtems-6-f0e34ea \
    --rtems-bsps="aarch64/xilinx_zynqmp_lp64_zu3eg" \
    --buildset=buildset/default.ini
  ./waf
  ./waf install

.. note::

  With the appropriate command-line options, libbsd can alternatively be built
  from an "out-of-tree" build directory::
    
    /path/to/libbsd/waf --prefix=/opt/rsb-tools-rtems-6-f0e34ea --rtems-bsps="aarch64/xilinx_zynqmp_lp64_zu3eg" --buildset=buildset/default.ini --out=$PWD/build --top=/path/to/libbsd configure
   
    /path/to/libbsd/waf --prefix=/opt/rsb-tools-rtems-6-f0e34ea --rtems-bsps="aarch64/xilinx_zynqmp_lp64_zu3eg" --buildset=buildset/default.ini --out=$PWD/build --top=/path/to/libbsd
   
    /path/to/libbsd/waf --prefix=/opt/rsb-tools-rtems-6-f0e34ea --rtems-bsps="aarch64/xilinx_zynqmp_lp64_zu3eg" --buildset=buildset/default.ini --out=$PWD/build --top=/path/to/libbsd install

  Please note that (unlike the RTEMS out-of-tree build) the
  ``--no-lock-in-top`` and ``--no-lock-in-run`` options cannot be specified
  because the waf configuration is loaded from the lock files during the
  "build" phase.

An Application to Test libbsd
-----------------------------

In order to test ``libbsd``, you can create a file called ``netcon.c``
containing:

.. code-block:: c

  #include <stdio.h>
  #include <rtems/shell.h>
  #include <rtems/bsd/bsd.h>
  #include <machine/rtems-bsd-rc-conf.h>
   
  #define BOARD_ETH_IFC "cgem0" // microzed and ultrazed
   
  static const char* rc_conf_text = \
    "hostname=\"rtems\"\n" \
    "ifconfig_" BOARD_ETH_IFC "=\"inet 172.18.14.227 netmask 255.255.0.0\"\n" \
    "\n";
   
  void *POSIX_Init(void * arg)
  {
      rtems_status_code sc;
      
      sc = rtems_bsd_initialize();
      if (sc != RTEMS_SUCCESSFUL)
          printf ("rtems_bsd_initialize error: %s (%d)\n",
                  rtems_status_text (sc), sc);
   
      sc = rtems_bsd_run_rc_conf_script("internal", rc_conf_text, 10, true);
      if (sc != RTEMS_SUCCESSFUL)
          printf ("rtems_bsd_run_rc_conf_script error: %s (%d)\n",
                  rtems_status_text (sc), sc);
      
      sc = rtems_task_wake_after(100);
      if (sc != RTEMS_SUCCESSFUL)
          printf ("rtems_task_wake_after error: %s (%d)\n",
                  rtems_status_text (sc), sc);
   
      sc = rtems_shell_init(
          "net_shell", 60 * 1024, 150, "/dev/console", 0, 1, NULL);
      if (sc != RTEMS_SUCCESSFUL)
          printf ("rtems_shell_init error: %s (%d)\n",
                  rtems_status_text (sc), sc);
   
      return NULL;
  }
   
  #define RTEMS_BSD_CONFIG_BSP_CONFIG
  #define RTEMS_BSD_CONFIG_INIT
  #include <machine/rtems-bsd-config.h>
   
  #include <rtems/netcmds-config.h>
  #define CONFIGURE_SHELL_USER_COMMANDS \
    &rtems_shell_ARP_Command, \
    &rtems_shell_HOSTNAME_Command, \
    &rtems_shell_PING_Command, \
    &rtems_shell_ROUTE_Command, \
    &rtems_shell_NETSTAT_Command, \
    &rtems_shell_IFCONFIG_Command
  #define CONFIGURE_SHELL_COMMANDS_ALL
  #define CONFIGURE_SHELL_COMMANDS_INIT
  #include <rtems/shellconfig.h>
   
  #define CONFIGURE_APPLICATION_NEEDS_CONSOLE_DRIVER
  #define CONFIGURE_APPLICATION_NEEDS_CLOCK_DRIVER
  #define CONFIGURE_POSIX_INIT_THREAD_TABLE
  #define CONFIGURE_INIT
  #define CONFIGURE_UNLIMITED_OBJECTS
  #define CONFIGURE_UNIFIED_WORK_AREAS
  #define CONFIGURE_MAXIMUM_FILE_DESCRIPTORS 80
  #define CONFIGURE_APPLICATION_NEEDS_LIBBLOCK
  #define CONFIGURE_MAXIMUM_USER_EXTENSIONS 1
  #include <rtems/confdefs.h>

And then compile it as before, but link in ``libbsd`` and ``libm``::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6-gcc -c -o netcon.o -I/opt/rsb-tools-rtems-6-f0e34ea/arm-rtems6/raspberrypi/lib/include -mcpu=arm1176jzf-s -ffunction-sections -fdata-sections netcon.c
  /opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6-gcc -o netcon.elf -mcpu=arm1176jzf-s -B/opt/rsb-tools-rtems-6-f0e34ea/arm-rtems6/raspberrypi/lib -qrtems -Wl,--gc-sections netcon.o -lbsd -lm

Note that ethernet does not currently work for the Raspberry Pi, but does for
the MicroZed and UltraZed.

Tools for Examining Executables
-------------------------------

Print the size of an executable::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/aarch64-rtems6-size bin/hello.elf

To see the memory layout of an executable::
  
  /opt/rsb-tools-rtems-6-f0e34ea/bin/aarch64-rtems6-readelf -S bin/hello.elf

Building U-Boot (Optional)
--------------------------

If you have a need for a more sophisticated bootloader, you can set up
U-Boot.

In order to do this, first pull down the ``u-boot`` source repository and
(optionally) check out the commit that was used when writing these notes)::
  
  git clone https://github.com/Xilinx/u-boot-xlnx.git
  cd u-boot-xlnx
  git checkout xilinx-v2022.2

The (forked) URL/commit above is applicable to the Xilinx Zynq and ZynqMP
boards.  For other targets (like the Raspberry Pi), the master repository
should be used::

  git clone https://github.com/u-boot/u-boot.git
  cd u-boot

You can see the available boards and device trees in places like these::

  ls configs/xilinx_zynq_virt_defconfig
  ls arch/arm/dts/zynq-microzed.dts
  
  ls configs/rpi_defconfig
  ls arch/arm/dts/bcm2835-rpi-b.dts

To configure for the MicroZed board, issue these commands::

  export CROSS_COMPILE=/opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6- 
  export DEVICE_TREE=zynq-microzed
  make xilinx_zynq_virt_defconfig

For the UltraZed, issue these commands instead::

  export CROSS_COMPILE=/opt/rsb-tools-rtems-6-f0e34ea/bin/aarch64-rtems6-
  export DEVICE_TREE=avnet-ultrazedev-cc-v1.0-ultrazedev-som-v1.0
  make avnet_ultrazedev_cc_v1_0_ultrazedev_som_v1_0_defconfig

You will also need to follow these steps for the UltraZed:

* Run ``make menuconfig``
* Select ``Device Drivers``
* Then select ``SOC specific Drivers``
* Then select ``Enable SOC Device ID driver for Xilinx ZynqMP``
* Save and exit

For the UltraZed ethernet to work, you must also change ``reg = <0>`` to
``reg = <9>`` in ``arch/arm/dts/avnet-ultrazedev-som-v1.0.dtsi``.

If you want to use TFTP boot with a non-privileged server port, you will need
to remove this ``#ifdef`` line (and the corresponding ``#endif`` line) in
``net/tftp.c``::

  #ifdef CONFIG_TFTP_PORT

To kick off the build do::
  
  make -j

This build process should result in a ``u-boot.elf`` in the top-level
directory.  For Zynq/ZynqMP targets a ``BOOT.BIN`` file can be created using
``bootgen`` following the previous instructions and replacing ``hello.elf``
with ``u-boot.elf``.  The resulting BOOT.BIN should be able to boot on the
target board.  For the the Raspberry Pi, the ``u-boot.elf`` file can be used
to create a ``kernel.img`` in the same way that was done for ``hello.elf``.

If you want to clean everything up to build for another board, run::

  make distclean

Basic U-Boot Configuration for the MicroZed (Optional)
------------------------------------------------------

You can add a ``boot.scr`` file to the root SD card partition to customize
what u-boot does when it boots up.  As an example, create a text file named
``boot.txt`` containing the following text::

  fatload mmc 0 0x104000 hello.img
  echo "Booting hello.img from SD card..."
  bootm 0x104000
  
These commands instruct u-boot to look for a file named ``hello.img`` on the
SD card, load it into memory at the specified address, and then run it.

Now we need to convert this text file to an ``.scr`` script image::

  u-boot-xlnx/tools/mkimage -A arm -T script -C none -n "Boot Script" -d boot.txt boot.scr

The resulting ``boot.scr`` file can then be copied into the root directory of
the SD card.

Now we need to convert our ``hello.elf`` file into a binary image::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/arm-rtems6-objcopy -R -S -Obinary hello.elf hello.binary

Now we need to make a ``u-boot`` image from the binary image::
  
  u-boot-xlnx/tools/mkimage -A arm -O rtems -T kernel -C none -a 0x104000 -e 0x104000 -n "Hello World" -d hello.binary hello.img

Now copy the resulting ``hello.img`` output file onto the root partition of
the SD card and boot up the board.

Basic U-Boot Configuration for the UltraZed (Optional)
------------------------------------------------------

You can add a ``boot.scr`` file to the root SD card partition to customize
what u-boot does when it boots up.  As an example, create a text file named
``boot.txt`` containing the following text::

  fatload mmc 1 0x10000000 hello.img
  echo "Booting hello.img from SD card..."
  bootm 0x10000000
  
These commands instruct u-boot to look for a file named ``hello.img`` on the
SD card, load it into memory at the specified address, and then run it.

Now we need to convert this text file to an ``.scr`` script image::

  u-boot-xlnx/tools/mkimage -A arm64 -T script -C none -n "Boot Script" -d boot.txt boot.scr

The resulting ``boot.scr`` file can then be copied into the root directory of
the SD card.

Now we need to convert our ``hello.elf`` file into a binary image::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/aarch64-rtems6-objcopy -R -S -Obinary hello.elf hello.binary

Now we need to make a ``u-boot`` image from the binary image::
  
  u-boot-xlnx/tools/mkimage -A arm64 -O rtems -T kernel -C none -a 0x10000000 -e 0x10000000 -n "Hello World" -d hello.binary hello.img

Now copy the resulting ``hello.img`` output file onto the root partition of
the SD card and boot up the board.

TFTP Boot on the MicroZed (Optional)
------------------------------------

If we want to boot the MicroZed via TFTP, we can update the ``boot.txt`` as
follows, re-generate ``boot.scr`` and copy that to the SD card as before::

  env set tftpdstp 54321
  env set serverip 192.168.1.222
  env set ipaddr 192.168.1.111
  env set netmask 255.255.0.0
  echo "Starting application from tftp..."
  ping 192.168.1.222
  tftpboot 0x104000 hello.img
  bootm 0x104000

Just replace the network addresses/netmask with something applicable to your
setup.

Before powering up the target board, run the following command on your
development host machine from the directory containing ``hello.img``::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/rtems-tftp-server -P 54321 -v --trace-packets

If you want to change the name of the image being loaded without updating
``boot.scr`` on the target system, you can do something like this::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/rtems-tftp-server -P 54321 -F net_shell.img

TFTP Boot on the UltraZed (Optional)
------------------------------------

If we want to boot the UltraZed via TFTP, we can update the ``boot.txt`` as
follows, re-generate ``boot.scr`` and copy that to the SD card as before::

  env set tftpdstp 54321
  env set serverip 192.168.1.222
  env set ipaddr 192.168.1.111
  env set netmask 255.255.0.0
  echo "Starting application from tftp..."
  ping 192.168.1.222
  tftpboot 0x10000000 hello.img
  bootm 0x10000000

Just replace the network addresses/netmask with something applicable to your
setup.

Before powering up the target board, run the following command on your
development host machine from the directory containing ``hello.img``::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/rtems-tftp-server -P 54321 -v --trace-packets

If you want to change the name of the image being loaded without updating
``boot.scr`` on the target system, you can do something like this::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/rtems-tftp-server -P 54321 -F net_shell.img

Alternative U-Boot Boot Commands
--------------------------------

If you want to boot a "binary" file (like ``hello.binary`` mentioned
previously) without having to convert it to a ``u-boot`` image file
(i.e. ``hello.img``), you can do this by using ``go`` to execute the program
instead of ``bootm``::

  tftpboot 0x10000000 hello.binary
  go 0x10000000

You can also go a step further and directly boot the ``.elf`` file.  The
caveat here is that you must load the ``.elf`` file into a different,
non-overlapping memory area rather than the program start address that we
have been using up until now::

  tftpboot 0x20000000 hello.elf
  bootelf 0x20000000

This approach applies to both the SD card and TFTP boot methods.

Using a Remote Debugger with the MicroZed/UltraZed
--------------------------------------------------

If you want to do remote debugging over ethernet, you need to set up
``libdebugger`` in your application.  Start with the ``libbsd`` test
application shown previously and add the following ``#include`` directives::

  #include <rtems/rtems-debugger.h>
  #include <rtems/rtems-debugger-remote-tcp.h>

then add the following static declaration::

  static rtems_printer printer;

Now add the following lines before you initialize the shell in
``POSIX_Init()``::

    printf ("registering rtems debugger tcp remote...\n\n");
    sc = rtems_debugger_register_tcp_remote();
    if (sc != RTEMS_SUCCESSFUL)
        printf ("error in  rtems_debugger_register_tcp_remote()\n");
    
    printf ("starting rtems debugger...\n\n");
    sc = rtems_debugger_start("tcp", "1222", 3, 1, &printer);
    if (sc != RTEMS_SUCCESSFUL)
        printf ("error in  rtems_debugger_start()\n");

    rtems_debugger_break(1); // Wait here until debugger connects

You will also need to link the application with ``-ldebugger``.

Now when you boot up the target system with this application, it should wait
for a remote debugger connection before starting the shell.  You should be
able to connect to the target system by executing these commands on your host
development system::

  /opt/rsb-tools-rtems-6-f0e34ea/bin/aarch64-rtems6-gdb dbg_test.elf
  (gdb) target remote 192.168.1.111:1222
  (gdb) up
  (gdb) up
  (gdb) up
  (gdb) up
  (gdb) up
  (gdb) up
  (gdb) list
  (gdb) quit

After quitting the remote debugger, execution should continue on the target
system.
