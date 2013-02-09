This directory contains third-party dependencies used by QtxJson.

## HIDAPI

#### Source Code

The source code of HIDAPI has been added to this repository using `git subtree`:

    $ git subtree add -P vendor/src/hidapi --squash git://github.com/signal11/hidapi.git hidapi-0.7.0

To subsequently update to a newer version of yajl, pull the code:

    $ git subtree pull -P vendor/src/hidapi --squash git://github.com/signal11/hidapi.git <version>

#### Compiling

##### Mac OS X

Commands executed when building hidapi 0.7.0:

    $ cd vendor/src/yajl
    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

Build output is located in "vendor/src/yajl/yajl-2.0.4".  For convienience, the
output has been copied into "vendor/bin", "vendor/lib", etc.

Refer to "vendor/yajl/BUILDING" for further information.

#### References

[HID API for Linux, Mac OS X, and Windows](http://www.signal11.us/oss/hidapi/)
[GitHub](https://github.com/signal11/hidapi)
