# PIGFX.H

This project is to make it easier and more accesible to use [PiGFX](https://github.com/fbergama/pigfx)'s many functions.

This is specifically formatted with Aztec C 1.06d in mind:
* Most functions use 7 characters

  I did this to keep below the 8 character limit
* Most functions begin with `pg`

  This allows you to write similar sounding functions in your own code, and to maintain compatibility with my `conio.h` implementation. Certain functions, like the bitmap functions, do not follow this because I assume you have no other hardware capable of drawing/loading bitmaps in this way.
* Defines and variable declarations are C89 standard
## Definitions

- [Defines](#defines)
  - Escape key
  - Fill/nofill
  - Font size
  - Palette
  - Base
## Functions
- [Cursor routines](#cursor-routines)
  - pgCInvs()
  - pgCBlnk()
  - pgCZero()
  - pgCSave()
  - pgCRstr()
  - pgCMove(`x, y`)
  - pgCUp(`x`)
  - pgCDown(`x`)
  - pgCFwrd(`x`)
  - pgCBack(`x`)
- [Screen clearing routines](#screen-clearing-routines)
  - pgClEnd()
  - pgClBeg()
  - pgClLin()
  - pgClCur(`x`)
  - pgClScr()*
- [Insert/delete routines](#insertdel-routines)
  - pgInsCh()
  - pgDelCh()
  - pgInsLn()
  - pgDelLn()
- [Graphics routines](#graphics-routines)
  - pgLine(`x1, y1, x2, y2`)
  - pgRect(`x, y, x, h, fill`)
  - pgCirc(`x, y, r, fill`)
  - pgTri(`x1, y1, x2, y2, x3, y3`)
- [Bitmap routines](#bitmap-routines)
  - ldAscBmp(`idx, x, y, base`)
  - ldRAscBmp(`idx, x, y, base`)
  - ldRawBmp(`idx, x, y`)
  - ldRleBmp(`idx, x, y`)
  - drawBmp(`idx, x, y`)
  - drawSprt(`idx, ref, x, y`)
  - remvSprt(`idx`)
  - moveSprt(`idx, x, y`)
- [Scrolling routines](#scrolling-routines)
  - pgScUp(`x`)
  - pgScDwn(`x`)
  - pgScLft(`x`)
  - pgScRgt(`x`)
- [PiGFX Settings](#pigfx-settings)
  - pgRsClr()
  - pgFgClr(`x`)
  - pgFgClrD(`x`)
  - pgBgClr(`x`)
  - pgBgClrD(`x`)
  - pgTrClr(`x`)
  - pgRstDrw()
  - pgXorDrw()
  - pgTrDrw()
  - pgStFnt(`font`)
  - pgStTab(`x`)
  - pgDspMd(`x`)
  - pgLdPal(`palette`)
  - pgStPal(`palette`)
### Defines
- ESC
  - The ESCAPE key (`ESC`) ASCII code is defined here
- Fill/nofill
  - `FILL`/`NOFILL` are defined in order to draw a filled or empty shape.
- Font size

  All fonts here are TRS-80 fonts
  - `_8X8`
  - `_8X16`
  - `_8X24`
- Palette

  These defines are used to change the color palette.
  - `XTERM`
  - `VGA`
  - `CUSTOM`
  - `C64`
- Base

  These defines are used to specify the base of encoded bitmaps
  - `HEX`
  - `DEC`
### Cursor routines
- pgCInvs()

  Cursor invisible.

- pgCBlnk()

  Cursor blinking.

- pgCVis()

  Cursor visible.

- pgCZero()

  Move cursor to 0,0

- pgCSave()

  Save the cursor position.

- pgCRstr()

  Move cursor to previously saved position.

- pgCMove(`x`,`y`)

  Moves cursor to `y`,`x`.

- pgCUp(`x`)

  Move the cursor up `x` lines.

- pgCDown(`x`)

  Move the cursor down `x` lines.

- pgCFwrd(`x`)

  Move the cursor to the right `x` columns.

- pgCBack(`x`)

  Move the cursor to the left `x` columns.
### Screen clearing routines
- pgClEnd()

  Clear text from cursor to end of line.

- pgClBeg()

  Clear text from beginning of line to cursor.

- pgClLin()

  Clear the whole line.

- pgClCur(`x`)
  - If `x` == 0, clear the screen from cursor.
  - If `x` == 1, clear the screen from cursor position.

- pgClScr()

  Clears the screen and moves the cursor to `0`,`0`. Defined sprites are removed, loaded bitmaps are kept.
  **This is different from the normal VT100 code.** Double check your source code for conflicts.
### <a name="insertdel-routines"></a>Insert/Delete routines
- pgInsCh()

  Insert a blank character position (shift line to the right).

- pgDelCh()

  Delete a blank character position (shift line to the left).

- pgInsLn()

  Insert a blank line at current row (shift screen down).

- pgDelLn()

  Delete the current line (shift screen up).
### Graphics routines
- pgLine(`x1`, `y1`, `x2`, `y2`)

  Draw a line from `x1`,`y1` to `x2`,`y2`.

- pgRect(`x`, `y`, `w`, `w`, `FILL/NOFILL`)

  Draws a rectangle at `x`,`y` with dimensions of `w`,`h` and `FILL`ed or `NOFILL`ed.

- pgCirc(`x`, `y`, `r`, `FILL/NOFILL`)

  Draws a circle at `x`,`y` with a radius of `r` and `FILL`ed or `NOFILL`ed.

- pgTri(`x1`, `y1`, `x2`, `y2,`, `x3`, `y3`)

  Draw a triangle with 3 verticies of `x1`,`y1`,`x2`,`y2,`,`x3`,`y3`.
### Bitmap routines
- ldAscBmp(`idx`, `x`, `y`, `BASE`)

  Load ASCII encoded bitmap to index (`idx`) 0-127 with width `x` and height `y` pixels. Specify `BASE` as decimal or hexadecimal.

- ldRAscBmp(`idx`, `x`, `y`, `BASE`)

  Load RLE compressed ASCII encoded bitmap to index (`idx`) 0-127 with width `x` and height `y` pixels. Specify `BASE` as decimal or hexadecimal. Expects RLE compressed ASCII encoded semicolon separated pixel data after this command, e.g. 15;32; or with hex 10;20;. Draws color 16 for the next 32 pixels. Repeat values must be between 1 and 255 (1 and FF for hex). A semicolon after the last repeat value must be sent.

- ldRawBmp(`idx`, `x`, `y`)

  Load raw bitmap to index (`idx`) 0-127 with width `x` and height `y` pixels. Expects x*y binary pixel bytes after this command.

- ldRleBmb(`idx`, `x`, `y`)

  Load RLE compressed bitmap to index (`idx`) 0-127 with width `x` and height `y`. Expects RLE compressed binary pixel data after this command, e.g. 0x10 0x20 draws color 16 for the next 32 pixels.

- drawBmp(`idx`, `x`, `y`)

  Draw bitmap with index (`idx`) 0-127 at position `x`,`y`.

- drawSprt(`idx`, `ref`, `x`, `y`)

  Draw a sprite with index (`idx`) 0-255 from bitmap `ref` at position `x`,`y`.

- remvSprt(`idx`)

  Remove sprite with index (`idx`) 0-255, restore background.

- moveSprt(`idx`, `x`, `y`)

  Move sprite with index (`idx`) 0-255 to `x`,`y`, restore background.
### Scrolling routines
- pgScUp(`x`)

  Scroll up by `x` pixels, fill with background color.

- pgScDwn(`x`)

  Scroll down by `x` pixels, fill with background color.

- pgScLft(`x`)

  Scroll left by `x` pixels, fill with background color.

- pgScRgt(`x`)

  Scroll right by `x` pixels, fill with background color.
### PiGFX Settings
**Refer to [conio.h](https://github.com/ProgrammingCube/Mayze/blob/main/CONIO.H) terminal color and mode settings**
- pgRsClr()

  Reset color attributes

- pgFgClr(`x`)

  Set foreground color to `x` (0-255).

- pgFgClrD(`x`)

  Set foreground color to `x` (0-255) and save as default.

- pgBgClr(`x`)

  Set background color to `x` (0-255).

- pgBgClrD(`x`)

  Set background color to `x` (0-255) and save as default.

- pgTrClr(`x`)

  Set transparent color to `x` (0-255).

- pgRstDrw()

  Reset color attributes and sets normal drawing (sprites and characters).

- pgXorDrw()

  Set XOR drawing (sprites and characters).

- pgTrDrw()

  set transparent drawing (sprites and characters).

- pgStFnt(`x`)

  Sets `FONT`. Currently, only 3 fonts are supported, TRS-80 8x8, 8x16, and 8x24. If you wish to change the font pack, you must create a new font file and recompile the pigfx binaries from source. This isn't too difficult to do, and there are build environments for both Windows and Linux.

- pgStTab(`x`)

  Set tabulation width (8 by default)

- pgDspMd(`x`)

  Change display mode `x` (legacy PC [ANSI.SYS](https://en.wikipedia.org/wiki/ANSI.SYS#Features)).

- pgLdPal(`x`)

  Load color palette `x`. Choose between `XTTERM` (default), `VGA`, `CUSTOM`, and `C64`.

- pgStPal(`BASE`, `x`)

  Set custom palette, with `x` as the number of colors to follow (1-256) and `BASE` for the base. `x` colors need to follow this command. Color information is always 8 bit RGB, e.g. 000000 for black or FFFFFF for white. A semicolon after the last color needs to be sent. Here's an example for color 0:red, 1: green, 2:blue ->

  `<ESC\>[=HEX;3pFF0000;FF00;FF;`

**Collision detection is not yet implemented**