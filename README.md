# Memory usage library for Arduino
This library can be used to print memory diagnostics on the serial console, 
get stack, heap, .data and .bss size at run-time.

## Installation
1. Start the Arduino IDE.
2. Click File | Preferences:
   Add the following link to Additional Boards Manager URLs:
   https://github.com/Erriez/ArduinoLibraryMemoryUsage.git
   and click OK. 
3. Click Sketch | Include Library | Manage Libraries
4. Search for "Memory Usage" by Erriez and click Install.
5. Run the examples. 

## Examples

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
