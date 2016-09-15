TESTS := compare_assns_t
.PHONY: test clean $(foreach t,$(TESTS),test-$(t))

CPPFLAGS += -I..

test: $(foreach t,$(TESTS),test-$(t))

$(foreach t,$(TESTS),test-$(t)) : test-% : %
	LD_LIBRARY_PATH=.:..$${LD_LIBRARY_PATH:+:$${LD_LIBRARY_PATH}} $(^)

compare_assns_t: compare_assns_t.cc ../compare.hh ../libgallery-demo.so libtest_dict.so
	@echo Building $(@)
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o $@ $< ../libgallery-demo.so libtest_dict.so

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
          libtest_dict.so compare_assns_t
