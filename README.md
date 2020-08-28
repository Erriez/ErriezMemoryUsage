# Memory Usage library for Arduino AVR targets
[![Build Status](https://travis-ci.org/Erriez/ErriezMemoryUsage.svg?branch=master)](https://travis-ci.org/Erriez/ErriezMemoryUsage)

This Arduino library prints memory usage on the Serial port.

![Memory usage](https://raw.githubusercontent.com/Erriez/ErriezMemoryUsage/master/extras/ErriezMemoryUsage.png)


## Features
This library provides:
* Print memory usage on the serial console 
* Get stack and heap size
* Get .data and .bss sections size


## Examples

Arduino IDE | Examples | Erriez Memory Usage:

* [PrintMemoryUsage](https://github.com/Erriez/ErriezMemoryUsage/blob/master/examples/ErriezPrintMemoryUsage/ErriezPrintMemoryUsage.ino)


## Documentation

* [Doxygen online HTML](https://erriez.github.io/ErriezMemoryUsage)
* [Doxygen PDF](https://github.com/Erriez/ErriezMemoryUsage/raw/master/ErriezMemoryUsage.pdf)


### Print memory usage on serial port
```c++
void setup()
{
  // Initialize serial port
  Serial.begin(115200);
  
  // Print memory usage
  printMemoryUsage();
}
```

#### Output serial port Arduino Uno
```c++
SRAM size:  2048 Bytes
.data size: 22 Bytes
.bss size:  170 Bytes
Stack size: 2 Bytes
Heap size:  0 Bytes
Free mem:   1854 Bytes
```

### Get RAM size
Get total on-chip SRAM size in Bytes:
```c++
unsigned int ramSize = getRamSize();
```

### Get free memory
Get free memory size which can be allocated between stack and heap: 
```c++
unsigned int freeMemSize = getFreeMemSize();
```

### Get stack size
```c++
unsigned int stackSize = getStackSize();
```

### Get heap size
```c++
unsigned int heapSize = getHeapSize();
```

### Get .data section size
```c++
unsigned int dataSize = getDataSectionSize();
```

### Get .bss section size
```c++
unsigned int bssSize = getBssSectionSize();
```


## Library installation

Please refer to the [Wiki](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches/wiki) page.


## Other Arduino Libraries and Sketches from Erriez

* [Erriez Libraries and Sketches](https://github.com/Erriez/ErriezArduinoLibrariesAndSketches)
