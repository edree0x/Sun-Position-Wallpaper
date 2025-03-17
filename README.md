# Sun Position Wallpaper Selector (C++)

## Overview
This program selects a desktop wallpaper based on the position of the sun at the time of execution.

## Requirements
- C++ Compiler (g++)
- A Linux Bash environment

## Compilation & Usage
1. Place the program in a folder with an `images/` subfolder containing the following images:
   - `night.png`
   - `sunset.png`
   - `evenlng.png`
   - `noon.png`
   - `morntng.png`
   - `sunnse.png`

2. Compile the program:
   ```bash
   g++ -o sun_wallpaper sun_position_wallpaper.cpp -lm
   ```

3. Run the program with latitude and longitude as arguments:
   ```bash
   ./sun_wallpaper <latitude> <longitude>
   ```
   Example:
   ```bash
   ./sun_wallpaper 30.0444 31.2357
   ```

4. The program outputs the appropriate image file name based on the sun's position.

## Logic
- The program calculates the sun’s altitude angle based on the given latitude, longitude, and current UTC time.
- Depending on the altitude angle, it selects a corresponding image.
  - `night.png` (Sun below the horizon)
  - `sunset.png` (Altitude < 15 degrees)
  - `evenlng.png` (Altitude < 30 degrees)
  - `noon.png` (Altitude < 60 degrees)
  - `morntng.png` (Altitude < 85 degrees)
  - `sunnse.png` (Sun near zenith)

## Notes
- Ensure system time is correct.
- The program assumes the given location is in a region where the sun rises and sets daily.

