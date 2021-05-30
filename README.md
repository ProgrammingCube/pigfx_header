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
  - pgXor()
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

  Cursor invisible

- pgCBlnk()

  Cursor blinking

- pgCVis()

  Cursor visible

- pgCZero()

  Move cursor to 0,0

- pgCSave()

  Save the cursor position

- pgCRstr()

  Move cursor to previously saved position

- pgCMove(`x`,`y`)

  Moves cursor to `y`,`x`

- pgCUp(`x`)

  Move the cursor up `x` lines

- pgCDown(`x`)

  Move the cursor down `x` lines

- pgCFwrd(`x`)

  Move the cursor to the right `x` columns

- pgCBack(`x`)

  Move the cursor to the left `x` columns

### Screen clearing routines
- pgClEnd()

  Clear text from cursor to end of line

- pgClBeg()

  Clear text from beginning of line to cursor

- pgClLin()

  Clear the whole line

- pgClCur(`x`)
  - If `x` == 0, clear the screen from cursor
  - If `x` == 1, clear the screen from cursor position

- pgClScr()

  Clears the screen and moves the cursor to `0`,`0`. Defined sprites are removed, loaded bitmaps are kept.
  **This is different from the normal VT100 code.** Double check your source code for conflicts.
### <a name="insertdel-routines"></a>Insert/Delete routines
- pgInsCh()

  Insert a blank character position (shift line to the right)

- pgDelCh()

  Delete a blank character position (shift line to the left)

- pgInsLn()

  Insert a blank line at current row (shift screen down)

- pgDelLn()

  Delete the current line (shift screen up)
### Graphics routines
- 
### Bitmap routines

### Scrolling routines

### PiGFX Settings