CPPFLAGS=-I $(BOOST_INC) \
         -I $(CANVAS_INC) \
         -I $(CETLIB_INC) \
         -I $(FHICLCPP_INC) \
         -I $(GALLERY_INC) \
         -I $(LARCOREOBJ_INC) \
         -I $(LARDATAOBJ_INC) \
         -I $(NUSIMDATA_INC) \
         -I $(ROOT_INC)

CXXFLAGS=-std=c++14 -Wall -Werror -Wextra -pedantic
CXX=g++
LDFLAGS=$$(root-config --libs) \
        -L $(CANVAS_LIB) -l canvas_Utilities -l canvas_Persistency_Common -l canvas_Persistency_Provenance \
        -L $(CETLIB_LIB) -l cetlib \
        -L $(GALLERY_LIB) -l gallery \
        -L $(NUSIMDATA_LIB) -l nusimdata_SimulationBase \
        -L $(LARCOREOBJ_LIB) -l larcoreobj_SummaryData \
        -L $(LARDATAOBJ_LIB) -l lardataobj_RecoBase

UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
  EXEC=for_dana-osx
else
  EXEC=for_dana-linux
endif

$(EXEC): for_dana.cc for_each_associated.hh for_each_entry.hh compare.hh compare.cc
	@echo Building $(EXEC)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $< compare.cc

compare_assns_t: compare_assns_t.cc compare.hh compare.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $< compare.cc
