TESTS := compare_assns_t compare_vertex_t compare_cluster_t \
         compare_hit_t compare_hitcoll_t compare_trajectory_t \
         compare_particle_t compare_neutrino_t compare_truth_t

.PHONY: test clean $(foreach t,$(TESTS),test-$(t))

CPPFLAGS += -I..

test: $(foreach t,$(TESTS),test-$(t))

$(foreach t,$(TESTS),test-$(t)) : test-% : %
	@printf "Testing $(@) ... "
	@$(DYN_LIB_PATH)=.:..$${$(DYN_LIB_PATH):+:$${$(DYN_LIB_PATH)}} ./$(^) && \
     echo "OK" || { echo "FAILED!"; false; }

compare_%.o : ../compare.hh

compare_assns_t.o : compare_assns_t.hh

compare_assns_t : libtest_dict.so

$(foreach i,vertex cluster hit hitcoll trajectory particle neutrino truth,compare_$(i)_t) : ../libgallery-demo.so

$(foreach i,trajectory particle neutrino truth,compare_$(i)_t) : LDFLAGS += -L$(ROOTSYS)/lib -lPhysics

$(TESTS): LDFLAGS += -L$(ROOTSYS)/lib -lCore

$(TESTS): % : %.o
	@echo Building $(@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $(^)

libtest_dict.so: test_dict.o ../libgallery-demo.so
	@echo Building $(@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -fPIC -shared -o $@ $^ -L $(ROOTSYS)/lib -lCore -Wl,-rpath-link,..

test_dict.cpp: classes.h classes_def.xml
	@echo Generating $(@)
	genreflex $(^) --noIncludePaths -I. $(filter -I% -D%,$(CPPFLAGS)) \
   -l libtest_dict.so --rootmap-lib=libtest_dict.so --rootmap=libtest_dict.rootmap \
   -o $(@)

clean:
	-@$(RM) libtest_dict_rdict.pcm test_dict.cpp test_dict.o libtest_dict.so libtest_dict.rootmap \
          libtest_dict.so compare_assns_t.o compare_assns_t
