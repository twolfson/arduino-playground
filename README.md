# arduino-playground
Playground environment for one-offs as I learn [Arduino][] and electronics in general

Based off of [sunfounder/Sunfounder_SuperKit_for_Arduino][] but ported to C++ and integrated via [PlatformIO][] for quick iteration

[SunFounder]: https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino
[sunfounder/Sunfounder_SuperKit_for_Arduino]: https://github.com/sunfounder/Sunfounder_SuperKit_for_Arduino

[Arduino]: https://www.arduino.cc/
[PlatformIO]: http://platformio.org/

## Documentation
Projects are arranged by folders, initial top level items are from [PlatformIO][]

- ##-{{title}} - Lesson from [SunFounder][]
- ##extra-{{title}} - Tangent based on [SunFounder][] lesson

### Finding appropriate part
Most parts are relatively obvious (e.g. LED, potentiometer) but some are hard to identify. Here are some tips:

- To identify a resistor, use a multimeter as demonstrated by SparkFun: https://learn.sparkfun.com/tutorials/how-to-use-a-multimeter

### Uploading a project
As mentioned, all folders are using [PlatformIO][] to make iterating a breeze. To upload a specific folder:

```bash
# Navigate to our folder
cd 01-blinking-led

# If you are using a virtualenv, switch to it now
#   workon platformio

# Upload to our Arduino
platformio run --target upload
```

### Interacting with serial monitor
[PlatformIO][] can attach to the serial monitor via:

```bash
platformio device monitor
```

Unfortunately, when the monitor is active, we can't upload new firmware so be sure to only have 1 running at a time

## Concepts to implement/explore
- [ ] Using PlatformIO CI setup
- [x] Using Arduino serial debugger (a la https://www.arduino.cc/en/Tutorial/ColorCrossfader)
- [ ] Implement RS-232
- [ ] Implement other buses

## Relevant links
- [twolfson/shenzhen-io-solutions](https://github.com/twolfson/shenzhen-io-solutions)
    - Solutions from Shenzhen I/O which helped push me further along in my electronics understanding
- [SparkFun tutorials](https://learn.sparkfun.com/tutorials/tags/concepts?page=all)
    - Great tutorials to put knowledge behind the lessons

## Donating
Support this project and [others by twolfson][twolfson-projects] via [donations][twolfson-support-me].

<http://twolfson.com/support-me>

[twolfson-projects]: http://twolfson.com/projects
[twolfson-support-me]: http://twolfson.com/support-me

## Unlicense
As of Nov 07 2016, Todd Wolfson has released this repository and its contents to the public domain.

It has been released under the [UNLICENSE][].

[UNLICENSE]: UNLICENSE
