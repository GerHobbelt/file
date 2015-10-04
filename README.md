file-win32
===========
[![Windows CI](https://ci.appveyor.com/api/projects/status/0ddmnhnua4lkoh7i/branch/master?svg=true)](https://ci.appveyor.com/project/alberthdev/file-win32/branch/master)

Win32 native port of file by Albert Huang ([@alberthdev])

Original file tool and libmagic by Ian F. Darwin and others;
maintained 1995-present by Christos Zoulas and others.

About
------
file-win32 is a dirty (but "native") win32 port of the original file
tool (from http://www.darwinsys.com/file/) and corresponding libmagic
library.

This port specifically allows for building natively on Visual Studio,
removing the requirement for installing Cygwin or MinGW to build
Windows binaries.

This port was created out of frustration for finding the latest file
magic DLL (`magic1.dll`) for [python-magic][4]. The old `magic1.dll`,
found on the GNUWin32 project website, is several versions behind. It
also doesn't support detecting newer Microsoft Office 2007+ files,
which was necessary for my application. MinGW/MSYS2/Cygwin is rather
unstable on my computer, with a lot of strange memory errors. Thus,
the motivation for creating a "native", Visual Studio-compatible
version of file!

This port is a "dirty" port due to its extensive use of *nix shims and
its inclusion of development libraries, which allow this tool to be
successfully built. In the future, we hope to improve and clean up the
port in the future so that it may one day be an official part of the
original file codebase.

Download
---------
Binaries and source code are available on the [release page][2].

A binary release includes the file tool executable, the libmagic DLL
library, and the development files needed to link with the libmagic
library.

The library included with the binary release will work with
[python-magic][4] - just drop the `magic1.dll` file into your script
directory or your Python installation directory, and it should work.

The latest source code from git can either be cloned via git, or
downloaded [here][3].

Requirements
-------------
**Visual Studio 2010** or higher is needed to build this port. It may
also build on Visual Studio 2008 (or earlier), but this has not been
tested. If you are able to build this solution on earlier versions,
please file an [issue][1] to let us know!

Building
---------
Simply open up win32\file.sln and build your preferred target(s)!
Available targets are:

 * Release - file executable, no debugging symbols.
 * Debug - file executable, with debugging symbols
 * Release DLL - libmagic DLL, no debugging symbols
 * Debug DLL - libmagic DLL, with debugging symbols

Note that `file.exe` (the file tool executable) does NOT require
libmagic. You do not need to compile and include libmagic
(`magic1.dll`) - the library is already embedded inside the tool.

The resulting binaries (both `file.exe` and `magic1.dll`) require two
DLLs: `regex2.dll` and `zlib1.dll`.

Once you have finished building, you should copy those DLLs from the
`win32\*-lib` directories to the `Release*\` and/or `Debug*\`
directories, as well as any other directories containing file-win32
binaries.

These binaries and support files are provided for your convenience.
You may also build your own version of these support libraries and
link them with file-win32. Make sure to replace the target paths if
you decide to do so.

We may remove these binaries in the future, in favor of developers
providing their own binaries. Stay tuned...

Finally, `magic.mgc` is not creatable on Windows at the moment. You
need to build the source from a Linux machine to create this file.
This file is required for the tool to work. For convenience, a
pre-generated file is available on the [release page][2].

Issues
-------
If you have problems building file-win32, have a suggestion, etc., we
welcome you to file an [issue][1]! Remember to be as specific as
possible about your problem or request.

License
--------
As with the original tool, the license is the BSD 2-clause license.

    Copyright (c) Ian F. Darwin 1986-1995.
    Software written by Ian F. Darwin and others;
    maintained 1995-present by Christos Zoulas and others;
    win32 native (Visual Studio-compatible) port by Albert Huang and others.
    
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:
    1. Redistributions of source code must retain the above copyright
       notice immediately at the beginning of the file, without modification,
       this list of conditions, and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
     
    THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.

[1]: https://github.com/alberthdev/file-win32/issues
[2]: https://github.com/alberthdev/file-win32/releases/
[3]: https://github.com/alberthdev/file-win32/archive/master.zip
[4]: https://github.com/ahupp/python-magic