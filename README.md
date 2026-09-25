# ChilliSource Game Engine Particle System Study

> [!WARNING]
> Archived and no longer maintained; kept for reference. This is the LaTeX source for my 2016 master's thesis. The published version is on [ScholarWorks](https://scholarworks.umt.edu/etd/10813/).

- [ChilliSource Game Engine Particle System Study](#chillisource-game-engine-particle-system-study)
  - [Overview](#overview)
    - [How the study worked](#how-the-study-worked)
    - [Abstract](#abstract)
    - [What I found](#what-i-found)
  - [What's in here](#whats-in-here)
  - [Dataset](#dataset)
  - [Building the PDF](#building-the-pdf)

## Overview

The LaTeX source, figures, and code excerpts for my master's thesis in Computer Science at the University of Montana (2016). I stress-tested the particle system in [ChilliSource](https://github.com/ChilliWorks/ChilliSource), an open-source C++ game engine, to understand how a complex multithreaded system behaves under load and to try out ways to make it faster.

**Tech:** C++, ChilliSource, multithreading (mutexes, lock-free compare-and-swap), custom profiling, HDF5, Python, LaTeX

Related repos:

- [um-thesis-chillisource-engine](https://github.com/angiebrr/um-thesis-chillisource-engine): my fork of the engine with the profiling and metrics instrumentation (the lock-free and multiple-mutex variants are excerpted in `source/case_studies/` here)
- [um-thesis-cspong-benchmarking](https://github.com/angiebrr/um-thesis-cspong-benchmarking): the Pong game that ran the automated benchmarks
- [um-thesis-hdf5-data-packer](https://github.com/angiebrr/um-thesis-hdf5-data-packer): packs the benchmark CSVs into the HDF5 dataset


### How the study worked

- Instrumented the engine to count particles drawn, time each stage of the particle lifecycle, and track how long the background update thread waited on locks
- Wrote a small profiling system of my own, since Shiny didn't handle the multithreaded parts or Android well
- Ran automated games on Windows, iOS, and Android and compared the results
- Found a particle emission bug that ChilliSource's developers said they'd look into

### Abstract

> "The majority of modern game engines utilize intricate objects called particle systems which are a collection of many particles that together represent an object without well-defined surfaces. This thesis discusses the results of studying and stressing particle systems within ChilliSource, an open-source game engine written in C++, with the goal of understanding a complex system and exploring possible optimizations that could be made to it. The studies performed were driven by metrics generated with custom profiling classes that kept track of things like the number of particles rendered, how long the engine spent rendering particles, or even how long a background thread that updated particles waited for a locked resource to release. These metrics supported experiments that revealed the inner workings of an elaborate system and aided in the creation and dissection of optimizations. The methods and results of these studies will aide anyone interested in reducing contention in large data structures either by using multiple mutexes, data structure "sharding", or hardware-based "lock free" implementations. They are also useful to any developer in need of profiling a complex system."

### What I found

- **Lock-free helps one big shared structure.** With a single particle effect, the background thread and the renderer fought over one large particle array. Replacing the lock with a lock-free implementation cut time in `CommitParticleData` from 47 s to 15 s (68%) and from 50 s to 7 s (86%), depending on the emission pattern. Using more than one mutex helped too, but less (47 s → 24 s, 50 s → 31 s).
- **Sharding had already solved it for many effects.** With ten effects, the particles were spread across ten components and ten threads, so there was barely any contention to remove. ChilliSource's design was doing its job.
- **Background tasks aren't free.** Depending on how tasks are organized, scheduling one on a background thread can be slower than doing the work on the main thread. Many small tasks on many threads is what paid off.
- **Some effects never showed up.** A non-looping effect with lots of particles and a short duration wouldn't visually emit. Part of that was my configuration, but it's also an edge case the engine could guard against.

## What's in here

| Path | What it is |
|---|---|
| `Thesis.tex` and chapter files (`intro.tex`, `case_studies.tex`, …) | The thesis itself |
| `source/` | C++ excerpts quoted in the thesis: the particle lifecycle, the case-study changes (lock-free, multiple mutexes), metrics, and task-scheduling observations |
| `figures/` | Charts and diagrams (`png/`, plus the Photoshop sources in `psd/`) |
| `bin/Thesis.pdf` | The compiled thesis as of December 2016 |
| `build/` | Python helper scripts for building the PDF |
| `templates/` | The university's thesis templates |

## Dataset

All of the results in the thesis are in a single HDF5 file, `csgeps_angela-gross_thesis_data.hdf5` (about 540 KB). It used to live in this repo's Bitbucket downloads; it's now attached to this repo's [GitHub release](https://github.com/angiebrr/um-thesis-particle-optimization/releases). The citation inside the published PDF still points at the old Bitbucket URL.

## Building the PDF

This thesis used a template provided by Eric Spaulding, who in turn included a few packages geared toward producing theses in LaTeX.

There are "build scripts" in the `build` directory, but I mostly built it with the LaTeXTools plugin for Sublime Text 3. MiKTeX managed the LaTeX packages on Windows.

