=======
Xenomai
=======

`Xenomai <xenomai>` is a free software project focused on building a
real-time framework for the :ref:`Linux <Linux>` platform.
  
External Documentation
======================

- `Xenomai Web Site <xenomai-site_>`_
- `Official Instructions for Building Xenomai Debian Packages <xenomai-debian-build_>`_

Installation Notes
==================

Ubuntu 18.04
------------

Download xenomai-3.1.tar.bz2 from:

  https://xenomai.org/downloads/xenomai/stable/

and extract the archive::

  mkdir ~/xeno-builds/4.19.94-cip18-xenomai-3.1
  cd  ~/xeno-builds/4.19.94-cip18-xenomai-3.1
  tar -xvf xenomai-3.1.tar.bz2

Alternatively, check out the desired Xenomai version from git::

  mkdir ~/xeno-builds/4.19.94-cip18-xenomai-3.1
  cd  ~/xeno-builds/4.19.94-cip18-xenomai-3.1
  GIT_SSL_NO_VERIFY=1 git clone git://git.xenomai.org/xenomai-3.git
  cd xenomai-3
  git checkout stable/v3.0.x

Install the required packages for building the userspace library (once)::

  sudo apt-get install devscripts debhelper dh-kpatches findutils

Build and install the Xenomai userspace library packages::

  cd ~/xeno-builds/4.19.94-cip18-xenomai-3.1/xenomai-3.1
  DEBEMAIL="your@email" DEBFULLNAME="Your Name" debchange -v 3.1 Release 3.1
  debuild -uc -us
  cd ..
  sudo dpkg -i libxenomai-dev_3.1_amd64.deb  \
               libxenomai1_3.1_amd64.deb  \
               xenomai-kernel-source_3.1_all.deb  \
               xenomai-runtime_3.1_amd64.deb

Install the required packages for building the kernel (once)::

  sudo apt-get install kernel-package libncurses-dev fakeroot zlib1g-dev bison flex libssl-dev

Download the CIP long-term support kernel from:

  https://git.kernel.org/pub/scm/linux/kernel/git/cip/linux-cip.git/tag/?h=v4.19.94-cip18

and extract the archive::

  tar -xvf linux-cip-4.19.94-cip18.tar.gz

Alternatively, download the linux kernel source from the mainline tree:

  https://mirrors.edge.kernel.org/pub/linux/kernel/v4.x/linux-4.9.38.tar.xz

and extract the archive::

  tar -xvf linux-4.19.84.tar.xz
  
Download a matching ipipe patch from here:

  https://xenomai.org/downloads/ipipe/v4.x/x86/
  (e.g. ipipe-core-4.19.94-cip18-x86-10.patch)

Apply the ipipe patch and set up the Xenomai cobalt kernel support::

  cd linux-cip-4.19.94-cip18
  /usr/src/xenomai-kernel-source/scripts/prepare-kernel.sh \
    --arch=x86 --linux=. --adeos=../ipipe-core-4.19.94-cip18-x86-10.patch \
    --outpatch=../xenomai-kernel.patch
  patch -p1 < ../xenomai-kernel.patch
  cd ..
  
Start with the kernel configuration from the standard Ubuntu kernel::

  cd linux-cip-4.19.94-cip18
  cp /boot/config-4.15.0-70-generic .config
  make olddefconfig
  make menuconfig

Note that if you import the config from a previously built
xenomai/ipipe-patched kernel instead of the "standard" Ubuntu kernel config
mentioned above, the configuration options below should already be selected.

Adjust the following kernel configuration options:

.. code-block:: none

  4.4.199-cip39, 4.19.94-cip18 Config
 
   General Setup
     Local version: -xenomai-3.1
   Processor type and features
     Multi-core scheduler support
       CPU core priorities scheduler support -> [n] (on newer kernels)
   Memory Management Options (or Processor type and features on older kernels)
     Transparent Hugepage Support -> [n]
     Allow for memory compaction -> [n]
     Contiguous Memory Allocator -> [n]
     Page migration -> [n]
   Power management and ACPI options
     CPU Frequency scaling
       CPU Frequency scaling -> [n]
     ACPI Support
       Processor -> [n]
     CPU Idle
       CPU idle PM support -> [n]
   Device Drivers
     Input device support
       Miscellaneous devices
         PC Speaker support -> [n]
     Character devices
       Serial Drivers
         8250/16550 and compatible serial support -> [m]
     Microsoft Hyper-V guest support -> [n]
     Staging drivers -> [n]
   Kernel hacking
     KGDB -> [n]
   Xenomai/cobalt
     Core features
       Shared interrupts -> [y]
     Drivers
       Serial Drivers
         16550A UART driver -> [m]
           Hardware access mode
             Any access mode -> [y]
         PCI board support -> [y]
       RTnet
         RTnet, TCP/IP socket interface -> [m]
           Protocol Stack
             Real-Time IPv4
               TCP support -> [m]
             RTmac Layer
               NoMAC discipline for RTmac -> [m]
         Drivers
           New Intel(R) PRO/1000 (Gigabit) -> [m] 
         Add-Ons
           Real-Time Capturing Support -> [m]
           IP protocol proxy for Linux -> [m]
             Enable ARP handling via protocol proxy -> [y]
       Real-time IPC drivers
         RTIPC protocol family -> [y]
       UDD support
         User-space device driver framework -> [m]

Save the kernel configuration to ``.config`` and exit the configuration tool.

Build the debian (Ubuntu) kernel packages::

  time make -j `getconf _NPROCESSORS_ONLN` deb-pkg

Install the kernel packages::

  cd ..
  sudo dpkg -i linux-image-4.19.94-cip18-xenomai-3.1_4.19.94-cip18-xenomai-3.1-1_amd64.deb linux-headers-4.19.94-cip18-xenomai-3.1_4.19.94-cip18-xenomai-3.1-1_amd64.deb

RHEL 8
------

First of all, make sure that you are set up to `build RPM packages
<create-rpm-spec-file_>`_ by creating a few required directories::

  mkdir -p ~/rpmbuild/BUILD
  mkdir -p ~/rpmbuild/BUILDROOT
  mkdir -p ~/rpmbuild/RPMS
  mkdir -p ~/rpmbuild/SOURCES
  mkdir -p ~/rpmbuild/SPECS
  mkdir -p ~/rpmbuild/SRPMCS
  mkdir -p ~/rpmbuild/tmp

and an ``~/.rpmmacros`` file containing::

  %packager Firstname Lastname
  %_topdir /home/username/rpmbuild
  %_tmppath /home/username/rpmbuild/tmp

Now create a file named ``xenomai3.spec`` in ``~/rpmbuild/SPECS/``
containing::

  %define _unpackaged_files_terminate_build 0
   
  Summary: Xenomai real-time system
  Name: xenomai
  Version: 3.1.3
  Release: 1
  License: GNU GPL
  Group: Development/Tools
  Source: xenomai-3.1.3.tar.gz
  URL: http://www.xenomai.org
  Buildroot: %{_tmppath}/%{name}-%{version}-root
   
  %description
  Xenomai user-space installation.  Requires a Xenomai patched kernel.
   
  %prep
  %setup -q
   
  %build
  ./scripts/bootstrap
  ./configure --prefix=/usr --sysconfdir=/etc --includedir=/usr/include/xenomai
  make -j8
   
  %install
  [ "$RPM_BUILD_ROOT" != "/" ] && rm -rf $RPM_BUILD_ROOT
  make DESTDIR=$RPM_BUILD_ROOT install
   
  %clean
  [ "${RPM_BUILD_ROOT}" != "/" ] && rm -rf ${RPM_BUILD_ROOT}
   
  %post
  if ! getent group xenomai >/dev/null; then
      groupadd --system xenomai || true
  fi
  grubby --update-kernel=/boot/vmlinuz-$(uname -r) --args=\"xenomai.allowed_group=$(getent group xenomai | cut --delimiter ':' --fields 3)\"
   
  %files
  %defattr(-,root, root)
  %dir /usr/include/xenomai
  %dir /usr/lib/xenomai
  /usr/bin/*
  /usr/demo/*
  /usr/include/xenomai/*
  /usr/lib/cobalt.wrappers
  /usr/lib/dynlist.ld
  /usr/lib/lib*
  /usr/lib/modechk.wrappers
  /usr/lib/xenomai/*
  /usr/sbin/*
  /etc/udev/rules.d/00-rtnet.rules
  /etc/udev/rules.d/rtdm.rules
  /etc/rtnet.conf
  /etc/tdma.conf

and download the associated source tarball (e.g. ``xenomai-3.1.3.tar.gz``)
from https://xenomai.org/downloads/xenomai/stable/ into
``~/rpmbuild/SOURCES``.

Now you should be able to build an RPM file containing the Xenomai user-space
support like this::

  rpmbuild -ba ~/rpmbuild/SPECS/xenomai3.spec

If all goes well, an RPM file will be generated in ``~/rpmbuild/RPMS`` that
can be installed like this::

  sudo rpm -i RPMS/x86_64/xenomai-3.1.3-1.x86_64.rpm

Building a Linux kernel with Xenomai support on RHEL 8 is very similar to the
process outlined above for Ubuntu 18.04, so most of those instructions are
applicable here.

The kernel config file from Ubuntu 18.04
(i.e. ``/boot/config-4.15.0-70-generic``) should also be a suitable starting
point for building a kernel under RHEL 8.  If you want to use the kernel
config file from RHEL 8 instead
(i.e. ``/boot/config-4.18.0-425.3.1.el8.x86_64``), you may need to disable
guest OS support (in menuconfig) to eliminate some warnings about PARAVIRT
dependencies when running the "make olddefconfig" command.

You will also want to build an RPM package instead of a Debian/Ubuntu
package, so the ``make`` command will look like this instead::

  time make -j `getconf _NPROCESSORS_ONLN` binrpm-pkg

If all goes well, this command will generate an RPM package for the new
kernel under ``~/rpmbuild/RPMS`` that can be installed using ``rpm -i``.

If you have trouble building RPMs, you can build and install everything
manually (instead of from RPM packages), but uninstalling may get messy::

  make -j 8
  sudo make modules_install -j 8
  sudo make install -j 8
  sudo update-grub

.. _xenomai-site: https://www.xenomai.org
.. _xenomai-debian-build:
   https://gitlab.denx.de/Xenomai/xenomai/wikis/Building_Debian_Packages
.. _create-rpm-spec-file:
   https://stackoverflow.com/questions/15055841/how-to-create-spec-file-rpm

Kernel Boot Parameters
======================

The following kernel boot parameters may (or may not) be useful::

  drm_kms_helper.poll=0
  nouveau.noaccel=1
  pci=routeirq
  xenomai.allowed_group=997
  acpi_irq_nobalance
  noirqbalance
  nmi_watchdog=0
  nosoftlockup
  nosmap
  nohalt
  mce=ignore_ce
  idle=poll
  intel_idle.max_cstate=0
  processor.max_cstate=0
  intel.max_cstate=0
  processor_idle.max_cstate=0

Note that kernel boot parameters can be set by adding them to the
``GRUB_CMDLINE_LINUX_DEFAULT`` string in ``/etc/default/grub`` and then
running ``sudo update-grub``.
