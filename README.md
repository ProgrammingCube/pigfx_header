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
  - pgClCur()
  - pgClScr()
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

### Screen clearing routines

### <a name="insertdel-routines"></a>Insert/Delete routines

### Graphics routines

### Bitmap routines

### Scrolling routines

### PiGFX Settings