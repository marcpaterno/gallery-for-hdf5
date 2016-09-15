.PHONY: all test clean

export CPPFLAGS = -I$(BOOST_INC) \
  -I$(CANVAS_INC) \
  -I$(CETLIB_INC) \
  -I$(FHICLCPP_INC) \
  -I$(GALLERY_INC) \
  -I$(LARCOREOBJ_INC) \
  -I$(LARDATAOBJ_INC) \
  -I$(NUSIMDATA_INC) \
  -I$(ROOT_INC)

export CXXFLAGS = -fPIC -std=c++14 -Wall -Werror -Wextra -pedantic
export CXX = g++
export LDFLAGS = $$(root-config --libs) \
  -L$(CANVAS_LIB) -lcanvas_Utilities -lcanvas_Persistency_Common -lcanvas_Persistency_Provenance \
  -L$(CETLIB_LIB) -lcetlib \
  -L$(GALLERY_LIB) -lgallery \
  -L$(NUSIMDATA_LIB) -lnusimdata_SimulationBase \
  -L$(LARCOREOBJ_LIB) -llarcoreobj_SummaryData \
  -L$(LARDATAOBJ_LIB) -llardataobj_RecoBase

LIB := libgallery-demo.so
OBJECTS := compare.o
EXEC := for_dana

all : $(EXEC)

$(EXEC) : % : %.cc for_each_associated.hh for_each_entry.hh compare.hh $(LIB)
	@echo Building $(@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(LIB) -o $@ $<

libgallery-demo.so: compare.o
	@echo Building $(@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -fPIC -shared -o $(@) $(^) 

clean:
	@$(MAKE) -C test clean
	-@$(RM) compare.o libgallery-demo.so $(EXEC)

test: all
	@$(MAKE) -C test
