TESTS := compare_assns_t compare_vertex_t compare_cluster_t

.PHONY: test clean $(foreach t,$(TESTS),test-$(t))

CPPFLAGS += -I..

test: $(foreach t,$(TESTS),test-$(t))

$(foreach t,$(TESTS),test-$(t)) : test-% : %
	@printf "Testing $(@) ... "
	@LD_LIBRARY_PATH=.:..$${LD_LIBRARY_PATH:+:$${LD_LIBRARY_PATH}} $(^) && \
     echo "OK" || { echo "FAILED!"; false; }

compare_assns_t.o : ../compare.hh compare_assns_t.hh

compare_vertex_t.o : ../compare.hh

compare_cluster_t.o : ../compare.hh

$(TESTS): % : %.o ../libgallery-demo.so libtest_dict.so
	@echo Building $(@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $(^)

libtest_dict.so: test_dict.o
	@echo Building $(@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -fPIC -shared -o $@ $< ../libgallery-demo.so

test_dict.cpp: classes.h classes_def.xml
	@echo Generating $(@)
	genreflex $(^) --noIncludePaths -I. $(filter -I% -D%,$(CPPFLAGS)) \
   -l libtest_dict.so --rootmap-lib=libtest_dict.so --rootmap=libtest_dict.rootmap \
   -o $(@)

clean:
	-@$(RM) libtest_dict_rdict.pcm test_dict.cpp test_dict.o libtest_dict.so libtest_dict.rootmap \
          libtest_dict.so compare_assns_t.o compare_assns_t
