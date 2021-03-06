# dim0451_cgraphics
DIM0451 - Computer Graphics I

@author Giovanni Rosário
--------------------------------
Rastafarizer2D (2D Rasterizer Programming Project)
# 1. Introduction
A [rasterizer](https://en.wikipedia.org/wiki/Rasterisation) is a program that takes in the description of vector shapes and converts that description into a raster image, i.e. a matrix of pixels.

Rastafarizer2D receives as input a scene description file coded in JSON (https://www.json.org/) and outputs an image in PPM format that contains the rasterization of all Two-Dimensional (2D) primitives described in the input json file.

# 2. Usage
In your terminal, run make command to compile the project and run      
```
./rasta your_scene.json your_image
```

# 3. Supported Primitives
Currently the Rastafarizer2D project supports the following primitives:
1. **Line Segment** defined by two points, a color and thickness. Implemented in Bresenham Line Generation Algorithm. 
2. **Circles** defined by a center point and a radius. Implemented in the Midpoint Algorithm.
3. **Polylines** defined by a set of vertex points.
4. **Polygon** defined by a set of vertex points, stroke and fill colors and stroke thickness.
5. **CircleArc** defined by a center point, a start point on the circle and an angle. Notice that the arc will be drawn clock-wise.

# 4. Collor Filling Algorithms
1. **ScanLine Algorithm** To fill the color of Polygon primitives a ScanLine Algorithm is used.
2. **Flood Fill** Flood filling is also supported. Must be provided a start point and desired Color. All Flood Fill actions must be put in the scene file, in the "flood_fill" array, after the primitive objects.
3. **Circle Fill** To fill the color of Circle primitives a different algorithm was used, based on the Midpoint Algorithm.

# 5. Anti-aliasing
Anti-aliasing is supported, implemented with an unweighted sample technique.

![Alt text](anti_aliasing_compare.png?raw=true "AntiAliasing Comparison")

# 6. Scene File Manual

**Colors**  The scene file receives color in a 6-digit hexadecimal format. This guarantees support to any possible color in that format.(www.color-hex.com) is a good reference to pick.
Or you can also set you own Pallete and use it's colors by name. Under the "pallete" key you may provide the colors in the format "name":"hexa_value", i.e:

```json
"pallete":{
    "cyan":"00FFFF",
    "royalblue":"4169E1",
    "violet":"EE82EE",
    "red":"FF0000"
}
```

1. **General** 

The scene file follows a JSON format using Key, Value, Arrays and Child objects.
You must start your scene with the keys "width", "height", "background_color", "anti_aliasing" and provide according value to each of them. 

```json
{
  "width": 800,
  "height": 600,
  "background_color": "000000",
  "anti_aliasing":false,
  "pallete":{"..."},
  "objects": [ "..." ],
  "flood_fill":["..."]

```

After that, you must start a key "objects" and place an JSON Array as it's value. Than each object in that array will be treated as the follow examples:


2. **Line** 
```json
{
    "type":"line",
    "color":"red",
    "thickness":3,
    "start":[320,195],
    "end":[355,195]
}
```

3. **Circle**
```json
{
    "type":"circle",
    "stroke_color":"230192",
    "fill_color":"FF3333",
    "start":[60,60],
    "radius":30
}
```
4. **Polygon**
```json
 {
    "type":"polygon",
    "stroke_color":"FF3333",
    "fill_color":"010101",
    "thickness":1,
    "points":[350,75,379,161,469,161,397,215,423,301,350,250,277,301,303,215,231,161,321,161]
}
```
5. **Polyline**
```json
{
    "type":"polyline",
    "stroke_color":"FF3333",
    "thickness":1,
    "points":[350,75,379,161,469,161,397,215,423,301,350,250,277,301,303,215,231,161,321,161]
}
```
6. **CircleArc**
```json
{
    "type":"circle_arc",
    "stroke_color":"FF002F",
    "center":[300,300],
    "start":[200,250],
    "angle":70
}
```

And finally in the "flood_fill" key you may provide an array of all desired Flood Fill with it's start point and desired color.

6. **Flood Fill**
```json
{
    "color":"0000FF",
    "start":[350,200]
}
```

An example file is provided at "scene_files/scene.json"

--------------------------------