# Real Time Clock (RTC) Implementation

## Assembly Implementation (libc.S)

The RTC functionality is implemented using BIOS interrupt 0x1A with function 0x02 to read the current time. Here's how it works:

1. Function Interface:
   - Function name: `rtc_read`
   - Return value: packed in EAX register
   - No input parameters required

2. Register preservation:
   - Pushes BX and CX onto the stack at the start
   - Pops them back before returning to preserve their values

3. BIOS Call:
   - Uses INT 0x1A with AH = 0x02 to read time
   - Returns:
     - CH = hours in BCD format
     - CL = minutes in BCD format
     - DH = seconds in BCD format

4. Return Value Format:
   - Packs time components into EAX register
   - Bits 0-7: Hours (BCD)
   - Bits 8-15: Minutes (BCD)
   - Bits 16-23: Seconds (BCD)
   - Bits 24-31: Unused (zero)

## C Implementation (main.c)

The C code processes the packed BCD time value from the assembly function:

1. Time Reading:
   - Calls rtc_read() which returns packed time value
   - Extracts individual components using bitwise operations:
     - Hours: (time & 0xFF)
     - Minutes: ((time >> 8) & 0xFF)
     - Seconds: ((time >> 16) & 0xFF)

2. BCD to ASCII Conversion:
   - Each BCD value is split into tens and ones digits
   - Converts each digit to ASCII by adding '0'
   - Stores result in null-terminated strings

3. Display Formats:
   - Shows time in two formats:
     - Standard time format (HH:MM:SS)
     - Hexadecimal representation
   - Uses printf function for output
   - Adds "\n\r" for proper line endings in BIOS environment

4. Timing:
   - Implements a delay loop to prevent too frequent updates
   - Uses a simple counting loop (1 billion iterations)

## Notes:

- The implementation uses BCD (Binary-Coded Decimal) format which is standard for RTC
- Each digit in BCD takes 4 bits (one nibble)
- The code assumes the RTC is running and properly configured by BIOS
- The implementation runs in 16-bit real mode