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

    $ cd vendor/src/hidapi/mac
    $ make

This simply builds an object file, "hid.o", which can be linked with an
executable.

Refer to "vendor/src/hidapi/README.txt" for further information.

#### References

[HID API for Linux, Mac OS X, and Windows](http://www.signal11.us/oss/hidapi/)
[GitHub](https://github.com/signal11/hidapi)
