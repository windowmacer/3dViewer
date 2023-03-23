# 3DViewer 1.0

## Project features 

- GUI
- Loading of a wireframe model from an .obj file (supports only a list of vertices and surfaces)
- Moving the model by a specified distance relative to the X, Y, Z axes
- Rotating the model by a given angle relative to its X, Y, Z axes
- Scaling the model by a given value
- Selection of a projection type (parallel or central)
- Choosing the way the edges are displayed (solid or dotted)
- Choosing the way to display vertices (circle, square or not displayed)
- Changing the thickness of the edges
- Changing the size of the vertices
- Changing the color of the background, edges and vertices
- Saving the model image in .jpeg and .bmp format
- Saving a GIF image of the model in .gif format (640x480, 10fps, 5s)


## Dependencies

Make sure you have the following packages installed:

- 'GCC'
- 'G++'
- 'MAKE'
- 'CMAKE'
- 'QT5' and later

## Installation

- From src folder, run the following command (executable file will be located in the src folder)

```sh
make install
```

## Launch

- From src folder, run the following command or click 2 times on the 3DViewer executable file

```sh
make launch_app
```

## File compression

- From src folder, run the following command (the archive will be located in the src folder)

```sh
make dist
```

## Uninstallation

- From src folder, run the following command

```sh
make uninstall
```