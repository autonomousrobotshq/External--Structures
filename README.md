# Structures
[![OSX Build Status](https://github.com/s-t-a-n/structures/workflows/macos/badge.svg)](https://github.com/s-t-a-n/structures/actions?workflow=macos)
[![Linux Build Status](https://github.com/s-t-a-n/structures/workflows/linux/badge.svg)](https://github.com/s-t-a-n/structures/actions?workflow=linux)
[![Windows Build status](https://github.com/s-t-a-n/structures/workflows/windows/badge.svg)](https://github.com/s-t-a-n/structures/actions?workflow=windows)  
Various structures for use in microcontrollers:  a poor man's 'dynamic' allocation. Library is formatted for Arduino but should work on any MCU.

## Goal
* Have structures like Array and Vector and Memoryblocks ready to be manipulated.
* Handle dynamic allocation by having all underlying memory allocated through memory pool.

## Quickstart
1. Run 'bundle install --path vendor/bundle' in root. This will install Arduino-CI
2. Run 'bundle exec arduino_ci.rb'. This will run the unittest.
3. Find Arduino examples in examples/

## Current Features
* Array: staticly/dynamicly allocated array with standard features.
* Vector: staticly/dynamicly allocated array with standard features.
* Vec3 & Vec2: Simple containers for various point/matrix calculations.

## Planned Features
* Memorypool layer (provide scratchpad that can be defragmented if needed or throws 'exception')
* Prioritypool layer (keep this memory alive at all costs)
* Memory exception handling
* Overload functions like malloc(), calloc(), free(), new() and delete() to use a memorypool provide adapted containers.

## Known Problems
* iterators are not mere pointer iterators, and therefore on the heavy side

## References

* [janelia-arduino/Vector](https://github.com/janelia-arduino/Vector) Inspired by
* [Arduino-CI/arduino_ci](https://github.com/Arduino-CI/arduino_ci) Unittesting framework
