FROM quay.io/pypa/manylinux1_i686
COPY src/ /buildme/src
COPY doc/ /buildme/doc
COPY fuzz/ /buildme/fuzz
COPY m4/ /buildme/m4
COPY magic/ /buildme/magic
COPY python/ /buildme/python
COPY tests/ /buildme/tests
COPY NEWS /buildme
COPY README /buildme
COPY AUTHORS /buildme
COPY COPYING /buildme
COPY ChangeLog /buildme
COPY INSTALL /buildme
COPY visibility.m4 /buildme
COPY configure.ac /buildme
COPY Makefile.am /buildme
RUN cd /buildme && libtoolize && aclocal && autoheader && autoconf; exit 0
RUN cd /buildme && automake --add-missing && ./configure && make && make install
