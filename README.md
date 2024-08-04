# Generic Simulation and Modelling Platform

This repository is for a proof-of-concept for a generic simulation and modelling platform.
The project was born out of frustration of spending countless hours attempting to integrate models into larger, more complicated models.
These integrations often lead to terrible 'hacks' being used to string
models together, which would then proliferate and cause further problems
down the line.

We believe integrating models together shouldn't have to be complicated.
Instead, we are trying to build a generic simulation and modelling
platform (GSMP), which takes the pain out of integrating models by:
- Being robust against any type of model, written in any type of backend,
whilst being able to link an arbitrary number of models together.
- Ensuring compatibility of model interfaces, whilst also performing automatic consolidation of those interfaces.
- Allowing users to freely select which models should be used, with the freedom of knowing any combination is automatically handled.
- Providing complete customisation of any simulation through the use of a
Simulation Scripting Engine, giving users the ability to change
parameters of any model, and even inject faults.


## High-level architecture
This project makes use of the [C4 Model](https://c4model.com/) to architect
the system diagrams (see [README.md](docs/readme.md) in `docs/` for more information).

The level 1 (context) diagram is given below.
<p align="center">
  <img src="docs/PlantUML/diagrams/out/L1_System Context Diagram - Simulation Model Platform.png "/>
</p>

Zooming into the Simulation Model Platform gives us the level 2 (container)
diagram, given below.
<p align="center">
  <img src="docs/PlantUML/diagrams/out/L2_Container Diagram - Simulation Model Platform.png "/>
</p>

## Work for the proof-of-concept
For the proof-of-concept, the bulk of work is in building the Model Manager,
defined in the level 2 diagram above.
We should be able to prove with (at least) two models, built in different
backends, that interface checking and consolidation is possible.
Once this is proven, we can add on additional functionality, i.e., the
Simulation Manager and potentially the Simulation Scripting Engine.
