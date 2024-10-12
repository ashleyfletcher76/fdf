# FDF

FDF (Fil De Fer) is a 3D wireframe viewer project developed in **C** as part of the **42 School curriculum**. The program takes a 2D map as input and visualizes it in a 3D space using wireframe modeling, applying rotations, translations, and scaling to create an interactive visualization.

## Table of Contents
- [Project Description](#project-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)

## Project Description

FDF reads a 2D map (grid) where each point represents a height value and projects it into 3D space. The project explores basic 3D rendering principles like rotation and projection. The output is a dynamic wireframe model of the input data, allowing zoom, rotation, and translation.

## Features

- Reads 2D map files.
- Wireframe 3D visualization.
- Rotate, zoom, and translate the model in real-time.
- Basic isometric projection.

## Installation

Clone the repository and compile the project:

```bash
  git clone https://github.com/username/fdf.git
  cd fdf
  make

## Usage
./fdf test_maps/[sample_map.fdf]
