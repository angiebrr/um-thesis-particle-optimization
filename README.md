# ChilliSource Game Engine Particle System Study
*Visit [https://scholarworks.umt.edu](https://scholarworks.umt.edu/etd/10813/) for the published version of the thesis.*

## Abstract

The majority of modern game engines utilize intricate objects called particle systems which are a collection of many particles that together represent an object without well-defined surfaces. This thesis discusses the results of studying and stressing particle systems within ChilliSource, an open-source game engine written in C++, with the goal of understanding a complex system and exploring possible optimizations that could be made to it. The studies performed were driven by metrics generated with custom profiling classes that kept track of things like the number of particles rendered, how long the engine spent rendering particles, or even how long a background thread that updated particles waited for a locked resource to release. These metrics supported experiments that revealed the inner workings of an elaborate system and aided in the creation and dissection of optimizations. The methods and results of these studies will aide anyone interested in reducing contention in large data structures either by using multiple mutexes, data structure "sharding", or hardware-based "lock free" implementations. They are also useful to any developer in need of profiling a complex system.

## LaTeX Info

This thesis utilized a thesis template provided by Eric Spaulding. He, in turn, included a few packages geared toward the production of theses in LaTeX. 

There are "build scripts" that can be found in the `build` directory, but a build system that utilized a Sublime Text 3 plugin, LateXTools, was primarily used. Additionally, MiKTeX was used to manage Windows LaTex packages.

## Dataset Info

The "Downloads" associated with this repository contains an HDF5 file that holds all data for all studies conducted for this thesis.
