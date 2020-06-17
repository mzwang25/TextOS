#include "keyboard.h"
#include "ports.h"
#include "../mlib/types.h"
#include "../cpu/isr.h"

void print_letter(uint8_t scancode);

void keyboard_callback(registers_t r)
{
    uint8_t scancode = read_port_byte(0x60);
    print_letter(scancode);
}

void print_letter(uint8_t scancode) {
    switch (scancode) {
        case 0x0:
            strprint("ERROR");
            break;
        case 0x1:
            strprint("ESC");
            break;
        case 0x2:
            strprint("1");
            break;
        case 0x3:
            strprint("2");
            break;
        case 0x4:
            strprint("3");
            break;
        case 0x5:
            strprint("4");
            break;
        case 0x6:
            strprint("5");
            break;
        case 0x7:
            strprint("6");
            break;
        case 0x8:
            strprint("7");
            break;
        case 0x9:
            strprint("8");
            break;
        case 0x0A:
            strprint("9");
            break;
        case 0x0B:
            strprint("0");
            break;
        case 0x0C:
            strprint("-");
            break;
        case 0x0D:
            strprint("+");
            break;
        case 0x0E:
            strprint("Backspace");
            break;
        case 0x0F:
            strprint("Tab");
            break;
        case 0x10:
            strprint("Q");
            break;
        case 0x11:
            strprint("W");
            break;
        case 0x12:
            strprint("E");
            break;
        case 0x13:
            strprint("R");
            break;
        case 0x14:
            strprint("T");
            break;
        case 0x15:
            strprint("Y");
            break;
        case 0x16:
            strprint("U");
            break;
        case 0x17:
            strprint("I");
            break;
        case 0x18:
            strprint("O");
            break;
        case 0x19:
            strprint("P");
            break;
		case 0x1A:
			strprint("[");
			break;
		case 0x1B:
			strprint("]");
			break;
		case 0x1C:
			strprint("ENTER");
			break;
		case 0x1D:
			strprint("LCtrl");
			break;
		case 0x1E:
			strprint("A");
			break;
		case 0x1F:
			strprint("S");
			break;
        case 0x20:
            strprint("D");
            break;
        case 0x21:
            strprint("F");
            break;
        case 0x22:
            strprint("G");
            break;
        case 0x23:
            strprint("H");
            break;
        case 0x24:
            strprint("J");
            break;
        case 0x25:
            strprint("K");
            break;
        case 0x26:
            strprint("L");
            break;
        case 0x27:
            strprint(";");
            break;
        case 0x28:
            strprint("'");
            break;
        case 0x29:
            strprint("`");
            break;
		case 0x2A:
			strprint("LShift");
			break;
		case 0x2B:
			strprint("\\");
			break;
		case 0x2C:
			strprint("Z");
			break;
		case 0x2D:
			strprint("X");
			break;
		case 0x2E:
			strprint("C");
			break;
		case 0x2F:
			strprint("V");
			break;
        case 0x30:
            strprint("B");
            break;
        case 0x31:
            strprint("N");
            break;
        case 0x32:
            strprint("M");
            break;
        case 0x33:
            strprint(",");
            break;
        case 0x34:
            strprint(".");
            break;
        case 0x35:
            strprint("/");
            break;
        case 0x36:
            strprint("Rshift");
            break;
        case 0x37:
            strprint("Keypad *");
            break;
        case 0x38:
            strprint("LAlt");
            break;
        case 0x39:
            strprint("Spc");
            break;
        default:
            /* 'keuyp' event corresponds to the 'keydown' + 0x80 
             * it may still be a scancode we haven't implemented yet, or
             * maybe a control/escape sequence */
            if (scancode <= 0x7f) {
                strprint("Unknown key down");
            } else if (scancode <= 0x39 + 0x80) {
                strprint("key up ");
                print_letter(scancode - 0x80);
            } else strprint("Unknown key up");
            break;
    }
}
