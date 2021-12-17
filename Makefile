TARGET	= $(STATIC) $(SHARED)
STATIC	= libarmadillo.a
SHARED	= libarmadillo.so
OBJS	= accel.o armadillo.o clcd.o d7seg.o display.o touch.o

VPATH	= src
INCLUDE	= `pkg-config --cflags freetype2`
LDFLAGS	= -pthread -lm -lfreetype -ljpeg
CFLAGS	= -O2 -Wall -fPIC $(INCLUDE) $(LDFLAGS)
CXXFLAGS= -std=gnu++0x -O2 -Wall -fPIC $(INCLUDE) $(LDFLAGS)

MKDIR	= mkdir -p
INSTALL	= install
LDCONFIG= ldconfig

HEADER_PATH	= /usr/local/include/armadillo
LIBRARY_PATH	= /usr/local/lib
LD_SO_PATH	= /etc/ld.so.conf.d/libarmadillo.conf

DEPEND	= depend.inc

all: $(DEPEND) $(TARGET)

$(STATIC): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

$(SHARED): $(OBJS)
	$(CXX) -o $@ -shared $(CXXFLAGS) $^

.PHONY: $(DEPEND)
$(DEPEND): ${OBJS:.o=.cc}
	-@ ${RM} ${DEPEND}
	-@ for i in $^; do ${CPP} ${CFLAGS} ${CXXFLAGS} -MM $$i >>$@; done
 
.PHONY: claen
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPEND)

.PHONY: install
install: all
	$(MKDIR) $(HEADER_PATH)
	$(INSTALL) -m644 src/*.hh $(HEADER_PATH)
	$(MKDIR) $(LIBRARY_PATH)
	$(INSTALL) $(SHARED) $(LIBRARY_PATH)
	$(INSTALL) -m644 $(STATIC) $(LIBRARY_PATH)
	echo "$(LIBRARY_PATH)" >$(LD_SO_PATH)
	$(LDCONFIG)

-include $(DEPEND)
