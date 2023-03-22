# clotter

<div>
  <p align="center">
    <img src="pictures/clotter.PNG" width="200"> 
  </p>
</div>

Clotter is a terminal based plotter, written in C. Improve your efficiency by
quicky analyzing trends in data without booting up Matlab or writing a pesky
Python script.

## Installation/Dependencies

You will need the following on your system:

- Criterion
- A terminal capable of displaying TTF Unicode characters

## Usage

Clotter comes with a number of flags to specify options:

- _-t_ specifies plot type
- _-f_ specifies file path, from the current directory
- _-c_ specifies the number of colors to use (somewhat dependent on how you have
  your terminal configured)

A call to clotter might look something like this:

`./clotter -f /path/to/file.csv -t countplot -c 3`

<div>
  <p align="center">
    <img src="pictures/singlecolorclotter.PNG" width="800"> 
  </p>
</div>

Please do not put quotation marks around the file path. This will break things. 

## Limitations
