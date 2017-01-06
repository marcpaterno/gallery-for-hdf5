# gallery-demo

This is the demonstration repository for `gallery`, a package for the reading of `art/ROOT` data files. Please see http://art.fnal.gov/gallery for an overview of `gallery`.


## When to use `gallery`

`gallery` provides library (as opposed to framework) facilities for reading (not writing) event data from _art_/ROOT data files. As such, it is suitable for making programs that perform tasks that do not require the full set of features of the _art_ framework. Such tasks include things like reading event data to create histograms or ntuples.

Because it allows use of your experiment's event data product classes, you can use `gallery` to write code that is easy to move into your experiment's code base. The access to event data in `gallery` is very similar to that in _art_. The `gallery::Event` interface provides the same `getByLabel`, _etc_., as is present in the `art::Event` class.

However, `gallery` is not a full-featured framework. In fact, it is not a framework at all. Thus is it not appropriate for tasks that require framework facilities, including:
* access to non-event data,
* writing of _art_/ROOT data files, and
* use of "services" that are framework-dependent.

## Running the demonstrations

There are three different demonstration codes:

1. `demo.cc` is a C++ main program which processes an input file and creates a ROOT histogram file. The provided `makefile` can be used to build the executable `demo` from `demo.cc`
2. `demo.C` is a ROOT macro intended to be invoked within an interactive ROOT session, and which creates a few histograms in memory.
3. `demo.py` is a PyROOT program that processes an input file and creates a ROOT histogram file. It can be run with `python demo.py`
