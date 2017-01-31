# LFEV Pack Manager Main Board

## Overview

This directory contains the design of the LFEV "Packman" board. The "Packman" board, or
Pack Manager Board is responsible for monitoring the cells in the LFEV battery pack. This 
system contains a small AVR microprocessor capable of communicating high level data to the
SCADA system, while monitoring the pack for faults, managing cell charge/discharge, and tracking
the pack state of charge. This directory contains the PCB schematic and board layout
of the system.

## What's Here?

 - Kicad Project
     - Schematics
     - Board Layouts
     - Bill of Materials
 - Gerber Files
 - PDF Schematic

### Directory Structure

1. `Pacman_Rev_0_8` -- Contains versions of the finalized board layout, send these for fabrication
2. `project` -- KiCad project files... Open these to change the board design
