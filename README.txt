This is a wrapper around JsonCpp which reads and stores Qt 4 QVariants.
I wrote this to replace QJson, which didn't give detailed parsing errors,
and didn't format the files it wrote very well.

It's a bit inefficient, of course, since in addition to the normal parsing
or serialization it has to create a parallel data structure composed of
QVariants, but it should be fine for smaller JSON files.

JsonCpp itself is included in amalgamated form.

The examples can be built with CMake; for example:

    mkdir build
    cd build
    cmake .. # or ccmake or cmake-gui
    make
