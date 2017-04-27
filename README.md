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
cd lesson-01

# If you are using a virtualenv, switch to it now
#   workon platformio

# Upload to our Arduino
platformio run --upload target
```

## Concepts to implement/explore
- [ ] Using PlatformIO CI setup
- [ ] Implement RS-232
- [ ] Implement other buses

## Relevant links
- [twolfson/shenzhen-io-solutions](https://github.com/twolfson/shenzhen-io-solutions)
    - Solutions from Shenzhen I/O which helped push me further along in my electronics understanding
- [SparkFun tutorials](https://learn.sparkfun.com/tutorials/tags/concepts?page=all)
    - Great tutorials to put knowledge behind the lessons
