============
vmod-flagship
============

-------------------------------
Flagship module for Varnish 
-------------------------------

:Author: Guillaume Jacquart(@guillaumejacquart)
:Date: 2022/11/30
:Version: 0.1
:Support Varnish Version: 5.0.x ~ 7.0.x

SYNOPSIS
========

import flagship;

DESCRIPTION
===========

Flagship vmod provide feature flagging & experimentation abilities at the web server level and cache server.

FUNCTIONS
=========

init
-----

Prototype
        ::

                init(
                        STRING envID,           // [your env id]
                        STRING apiKey,          // [your api key]
                        INT pollingInterval,    // [polling interval]
                        STRING logLevel,        // [log level]
                        INT trackingEnabled,    // [tracking enabled]
                )
Return value
	VOID
Description
	Initialize flagship.

Example
        ::
                import flagship;

                sub vcl_init {
                        flagship.init("FS_ENV_ID", "FS_API_KEY", 200, "debug", 0);
                }
compute_flags
-----

Prototype
        ::

                compute_flags(
                        STRING visitorID,       // [your visitor id]
                        STRING context,         // [your context]
                )
Return value
	STRING
Description
	Return flags that corresponds to the visitor id and context (flags are separated by ";").

Example
        ::
                sub vcl_hash {
                        set req.http.X-FS-FLAGVALUES = flagship.compute_flags("visitor_id", "visitor_context");
                }

get_flag_bool
-----

Prototype
        ::

                get_flag_bool(
                        STRING visitorID,       // [your visitor id]
                        STRING context,         // [your context]
                        STRING key,             // [your flag key]
                        INT defaultValue,       // [default value]
                        INT activate,           // [activate]
                )
Return value
	INT
Description
	Return flag that corresponds to the visitor id and context.

Example
        ::
                sub vcl_hash {
                        set req.http.X-FS-FLAGBOOL = flagship.get_flag_bool("visitor_id", "visitor_context", "flag_key", 0, 0);
                }

get_flag_string
-----

Prototype
        ::

                get_flag_string(
                        STRING visitorID,       // [your visitor id]
                        STRING context,         // [your context]
                        STRING key,             // [your flag key]
                        STRING defaultValue,    // [default value]
                        INT activate,           // [activate]
                )
Return value
	STRING
Description
	Return flag that corresponds to the visitor id and context.

Example
        ::
                sub vcl_hash {
                        set req.http.X-FS-FLAGSTRING = flagship.get_flag_string("visitor_id", "visitor_context", "flag_key", "default_value", 0);
                }

get_flag_number
-----

Prototype
        ::

                get_flag_number(
                        STRING visitorID,       // [your visitor id]
                        STRING context,         // [your context]
                        STRING key,             // [your flag key]
                        INT defaultValue,       // [default value]
                        INT activate,           // [activate]
                )
Return value
	STRING
Description
	Return flag that corresponds to the visitor id and context.

Example
        ::
                sub vcl_hash {
                        set req.http.X-FS-FLAGNUMBER = flagship.get_flag_string("visitor_id", "visitor_context", "flag_key", 12.0, 0);
                }

INSTALLATION
============

Before installating make sure to copy the file ``libflaship.so`` to ``/usr/lib/`` and the file ``libflagship.h`` to ``/usr/include/``

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the ``varnishtest`` tool.

Building requires the Varnish header files and uses pkg-config to find
the necessary paths.

Usage::

 ./autogen.sh
 ./configure

If you have installed Varnish to a non-standard directory, call
``autogen.sh`` and ``configure`` with ``PKG_CONFIG_PATH`` pointing to
the appropriate path. For instance, when varnishd configure was called
with ``--prefix=$PREFIX``, use

::

 export PKG_CONFIG_PATH=${PREFIX}/lib/pkgconfig
 export ACLOCAL_PATH=${PREFIX}/share/aclocal

The module will inherit its prefix from Varnish, unless you specify a
different ``--prefix`` when running the ``configure`` script for this
module.

Make targets:

* make - builds the vmod.
* make install - installs your vmod.
* make check - runs the unit tests in ``src/tests/*.vtc``.
* make distcheck - run check and prepare a tarball of the vmod.

If you build a dist tarball, you don't need any of the autotools or
pkg-config. You can build the module simply by running::

 ./configure
 make


Installation directories
------------------------

By default, the vmod ``configure`` script installs the built vmod in the
directory relevant to the prefix. The vmod installation directory can be
overridden by passing the ``vmoddir`` variable to ``make install``.


COMMON PROBLEMS
===============

* configure: error: Need varnish.m4 -- see README.rst

  Check whether ``PKG_CONFIG_PATH`` and ``ACLOCAL_PATH`` were set correctly
  before calling ``autogen.sh`` and ``configure``

* Incompatibilities with different Varnish Cache versions

  Make sure you build this vmod against its correspondent Varnish Cache version.
  For instance, to build against Varnish Cache 4.1, this vmod must be built from
  branch 4.1.

COPYRIGHT
=============

This document is licensed under the same license as the
libvmod-flagship project. See LICENSE for details.

* Copyright (c) 2020-2022 Guillaume Jacquart(@guillaumejacquart)

File layout and configuration based on libvmod-example

* Copyright (c) 2011 Varnish Software AS
* https://github.com/varnishcache/libvmod-example/
* https://github.com/varnishcache/libvmod-example/blob/master/LICENSE
