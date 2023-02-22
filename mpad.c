#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Disassemble8080(unsigned char *buffer, int pc, FILE *f){     // read main first
    unsigned char *com = &buffer[pc];   // yeah get used to using strings/tables like this in c
    fprintf(f, "%04x ", pc);     // program counter in hex version
    int bytes = 1;
    switch(*com){
        case 0x00: fprintf(f, "NOP"); break;
        case 0x01: fprintf(f, "LXI    B,$%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0x02: fprintf(f, "STAX   B"); break;
        case 0x03: fprintf(f, "INX    B"); break;
        case 0x04: fprintf(f, "INR    B"); break;
        case 0x05: fprintf(f, "DCR    B"); break;
        case 0x06: fprintf(f, "MVI    B,#$%02x", com[1]); bytes=2; break;
        case 0x07: fprintf(f, "RLC"); break;
        case 0x08: fprintf(f, "-"); break;
        case 0x09: fprintf(f, "DAD    B"); break;
        case 0x0a: fprintf(f, "LDAX   B"); break;
        case 0x0b: fprintf(f, "DCX    B"); break;
        case 0x0c: fprintf(f, "INR    C"); break;
        case 0x0d: fprintf(f, "DCR    C"); break;
        case 0x0e: fprintf(f, "MVI    C,#$%02x", com[1]); bytes=2; break;
        case 0x0f: fprintf(f, "RRC"); break;
        case 0x10: fprintf(f, "-"); break;
        case 0x11: fprintf(f, "LXI    D,$%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0x12: fprintf(f, "STAX   D"); break;
        case 0x13: fprintf(f, "INX    D"); break;
        case 0x14: fprintf(f, "INR    D"); break;
        case 0x15: fprintf(f, "DCR    D"); break;
        case 0x16: fprintf(f, "MVI    D,#$%02x", com[1]); bytes=2; break;
        case 0x17: fprintf(f, "RAL"); break;
        case 0x18: fprintf(f, "-"); break;
        case 0x19: fprintf(f, "DAD    D"); break;
        case 0x1a: fprintf(f, "LDAX   D"); break;
        case 0x1b: fprintf(f, "DCX    D"); break;
        case 0x1c: fprintf(f, "INR    E"); break;
        case 0x1d: fprintf(f, "DCR    E"); break;
        case 0x1e: fprintf(f, "MVI    E,#$%02x", com[1]); bytes=2; break;
        case 0x1f: fprintf(f, "RAR"); break;
        case 0x20: fprintf(f, "RIM"); break;
        case 0x21: fprintf(f, "LXI    H,$%02x%02x",com[2],com[1]); break;
        case 0x22: fprintf(f, "SHLD   $%02x%02x",com[2],com[1]); break;
        case 0x23: fprintf(f, "INX    H"); break;
        case 0x24: fprintf(f, "INR    H"); break;
        case 0x25: fprintf(f, "DCR    H"); break;
        case 0x26: fprintf(f, "MVI    H,#$%02x", com[1]); bytes=2; break;
        case 0x27: fprintf(f, "DAA"); break;
        case 0x28: fprintf(f, "-"); break;
        case 0x29: fprintf(f, "DAD    H"); break;
        case 0x2a: fprintf(f, "LHLD   $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0x2b: fprintf(f, "DCX    H"); break;
        case 0x2c: fprintf(f, "INR    L"); break;
        case 0x2d: fprintf(f, "DCR    L"); break;
        case 0x2e: fprintf(f, "MVI    L, #$%02x", com[1]); bytes=2; break;
        case 0x2f: fprintf(f, "CMA"); break;
        case 0x30: fprintf(f, "SIM"); break;
        case 0x31: fprintf(f, "LXI    SP, $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0x32: fprintf(f, "STA    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0x33: fprintf(f, "INX    SP"); break;
        case 0x34: fprintf(f, "INR    M"); break;
        case 0x35: fprintf(f, "DCR    M"); break;
        case 0x36: fprintf(f, "MVI    M,#$%02x", com[1]); bytes=2; break;
        case 0x37: fprintf(f, "STC"); break;
        case 0x38: fprintf(f, "-"); break;
        case 0x39: fprintf(f, "DAD    SP"); break;
        case 0x3a: fprintf(f, "LDA    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0x3b: fprintf(f, "DCX    SP"); break;
        case 0x3c: fprintf(f, "INR    A"); break;
        case 0x3d: fprintf(f, "DCR    A"); break;
        case 0x3e: fprintf(f, "MVI    A,#$%02x", com[1]); bytes=2; break;
        case 0x3f: fprintf(f, "CMC"); break;
        case 0x40: fprintf(f, "MOV    B,B"); break;
        case 0x41: fprintf(f, "MOV    B,C"); break;
        case 0x42: fprintf(f, "MOV    B,D"); break;
        case 0x43: fprintf(f, "MOV    B,E"); break;
        case 0x44: fprintf(f, "MOV    B,H"); break;
        case 0x45: fprintf(f, "MOV    B,L"); break;
        case 0x46: fprintf(f, "MOV    B,M"); break;
        case 0x47: fprintf(f, "MOV    B,A"); break;
        case 0x48: fprintf(f, "MOV    C,B"); break;
        case 0x49: fprintf(f, "MOV    C,C"); break;
        case 0x4a: fprintf(f, "MOV    C,D"); break;
        case 0x4b: fprintf(f, "MOV    C,E"); break;
        case 0x4c: fprintf(f, "MOV    C,H"); break;
        case 0x4d: fprintf(f, "MOV    C,L"); break;
        case 0x4e: fprintf(f, "MOV    C,M"); break;
        case 0x4f: fprintf(f, "MOV    C,A"); break;
        case 0x50: fprintf(f, "MOV    D,B"); break;
        case 0x51: fprintf(f, "MOV    D,C"); break;
        case 0x52: fprintf(f, "MOV    D,D"); break;
        case 0x53: fprintf(f, "MOV    D,E"); break;
        case 0x54: fprintf(f, "MOV    D,H"); break;
        case 0x55: fprintf(f, "MOV    D,L"); break;
        case 0x56: fprintf(f, "MOV    D,M"); break;
        case 0x57: fprintf(f, "MOV    D,A"); break;
        case 0x58: fprintf(f, "MOV    E,B"); break;
        case 0x59: fprintf(f, "MOV    E,C"); break;
        case 0x5a: fprintf(f, "MOV    E,D"); break;
        case 0x5b: fprintf(f, "MOV    E,E"); break;
        case 0x5c: fprintf(f, "MOV    E,H"); break;
        case 0x5d: fprintf(f, "MOV    E,L"); break;
        case 0x5e: fprintf(f, "MOV    E,M"); break;
        case 0x5f: fprintf(f, "MOV    E,A"); break;
        case 0x60: fprintf(f, "MOV    H,B"); break;
        case 0x61: fprintf(f, "MOV    H,C"); break;
        case 0x62: fprintf(f, "MOV    H,D"); break;
        case 0x63: fprintf(f, "MOV    H,E"); break;
        case 0x64: fprintf(f, "MOV    H,H"); break;
        case 0x65: fprintf(f, "MOV    H,L"); break;
        case 0x66: fprintf(f, "MOV    H,M"); break;
        case 0x67: fprintf(f, "MOV    H,A"); break;
        case 0x68: fprintf(f, "MOV    L,B"); break;
        case 0x69: fprintf(f, "MOV    L,C"); break;
        case 0x6a: fprintf(f, "MOV    L,D"); break;
        case 0x6b: fprintf(f, "MOV    L,E"); break;
        case 0x6c: fprintf(f, "MOV    L,H"); break;
        case 0x6d: fprintf(f, "MOV    L,L"); break;
        case 0x6e: fprintf(f, "MOV    L,M"); break;
        case 0x6f: fprintf(f, "MOV    L,A"); break;
        case 0x70: fprintf(f, "MOV    M,B"); break;
        case 0x71: fprintf(f, "MOV    M,C"); break;
        case 0x72: fprintf(f, "MOV    M,D"); break;
        case 0x73: fprintf(f, "MOV    M,E"); break;
        case 0x74: fprintf(f, "MOV    M,H"); break;
        case 0x75: fprintf(f, "MOV    M,L"); break;
        case 0x76: fprintf(f, "HLT"); break;
        case 0x77: fprintf(f, "MOV    M,A"); break;
        case 0x78: fprintf(f, "MOV    A,B"); break;
        case 0x79: fprintf(f, "MOV    A,C"); break;
        case 0x7a: fprintf(f, "MOV    A,D"); break;
        case 0x7b: fprintf(f, "MOV    A,E"); break;
        case 0x7c: fprintf(f, "MOV    A,H"); break;
        case 0x7d: fprintf(f, "MOV    A,L"); break;
        case 0x7e: fprintf(f, "MOV    A,M"); break;
        case 0x7f: fprintf(f, "MOV    A,A"); break;
        case 0x80: fprintf(f, "ADD    B"); break;
        case 0x81: fprintf(f, "ADD    C"); break;
        case 0x82: fprintf(f, "ADD    D"); break;
        case 0x83: fprintf(f, "ADD    E"); break;
        case 0x84: fprintf(f, "ADD    H"); break;
        case 0x85: fprintf(f, "ADD    L"); break;
        case 0x86: fprintf(f, "ADD    M"); break;
        case 0x87: fprintf(f, "ADD    A"); break;
        case 0x88: fprintf(f, "ADC    B"); break;
        case 0x89: fprintf(f, "ADC    C"); break;
        case 0x8a: fprintf(f, "ADC    D"); break;
        case 0x8b: fprintf(f, "ADC    E"); break;
        case 0x8c: fprintf(f, "ADC    H"); break;
        case 0x8d: fprintf(f, "ADC    L"); break;
        case 0x8e: fprintf(f, "ADC    M"); break;
        case 0x8f: fprintf(f, "ADC    A"); break;
        case 0x90: fprintf(f, "SUB    B"); break;
        case 0x91: fprintf(f, "SUB    C"); break;
        case 0x92: fprintf(f, "SUB    D"); break;
        case 0x93: fprintf(f, "SUB    E"); break;
        case 0x94: fprintf(f, "SUB    H"); break;
        case 0x95: fprintf(f, "SUB    L"); break;
        case 0x96: fprintf(f, "SUB    M"); break;
        case 0x97: fprintf(f, "SUB    A"); break;
        case 0x98: fprintf(f, "SBB    B"); break;
        case 0x99: fprintf(f, "SBB    C"); break;
        case 0x9a: fprintf(f, "SBB    D"); break;
        case 0x9b: fprintf(f, "SBB    E"); break;
        case 0x9c: fprintf(f, "SBB    H"); break;
        case 0x9d: fprintf(f, "SBB    L"); break;
        case 0x9e: fprintf(f, "SBB    M"); break;
        case 0x9f: fprintf(f, "SBB    A"); break;
        case 0xa0: fprintf(f, "ANA    B"); break;
        case 0xa1: fprintf(f, "ANA    C"); break;
        case 0xa2: fprintf(f, "ANA    D"); break;
        case 0xa3: fprintf(f, "ANA    E"); break;
        case 0xa4: fprintf(f, "ANA    H"); break;
        case 0xa5: fprintf(f, "ANA    L"); break;
        case 0xa6: fprintf(f, "ANA    M"); break;
        case 0xa7: fprintf(f, "ANA    A"); break;
        case 0xa8: fprintf(f, "XRA    B"); break;
        case 0xa9: fprintf(f, "XRA    C"); break;
        case 0xaa: fprintf(f, "XRA    D"); break;
        case 0xab: fprintf(f, "XRA    E"); break;
        case 0xac: fprintf(f, "XRA    H"); break;
        case 0xad: fprintf(f, "XRA    L"); break;
        case 0xae: fprintf(f, "XRA    M"); break;
        case 0xaf: fprintf(f, "XRA    A"); break;
        case 0xb0: fprintf(f, "ORA    B"); break;
        case 0xb1: fprintf(f, "ORA    C"); break;
        case 0xb2: fprintf(f, "ORA    D"); break;
        case 0xb3: fprintf(f, "ORA    E"); break;
        case 0xb4: fprintf(f, "ORA    H"); break;
        case 0xb5: fprintf(f, "ORA    L"); break;
        case 0xb6: fprintf(f, "ORA    M"); break;
        case 0xb7: fprintf(f, "ORA    A"); break;
        case 0xb8: fprintf(f, "CMP    B"); break;
        case 0xb9: fprintf(f, "CMP    C"); break;
        case 0xba: fprintf(f, "CMP    D"); break;
        case 0xbb: fprintf(f, "CMP    E"); break;
        case 0xbc: fprintf(f, "CMP    H"); break;
        case 0xbd: fprintf(f, "CMP    L"); break;
        case 0xbe: fprintf(f, "CMP    M"); break;
        case 0xbf: fprintf(f, "CMP    A"); break;
        case 0xc0: fprintf(f, "RNZ"); break;
        case 0xc1: fprintf(f, "POP    B"); break;
        case 0xc2: fprintf(f, "JNZ    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xc3: fprintf(f, "JMP    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xc4: fprintf(f, "CNZ    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xc5: fprintf(f, "PUSH   B"); break;
        case 0xc6: fprintf(f, "ADI    #$%02x", com[1]); bytes=2; break;
        case 0xc7: fprintf(f, "RST    0"); break;
        case 0xc8: fprintf(f, "RZ"); break;
        case 0xc9: fprintf(f, "RET"); break;
        case 0xca: fprintf(f, "JZ     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xcb: fprintf(f, "-"); break;	
        case 0xcc: fprintf(f, "CZ     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xcd: fprintf(f, "CALL   $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xce: fprintf(f, "ACI    #$%02x", com[1]); bytes=2; break;
        case 0xcf: fprintf(f, "RST    1"); break;
        case 0xd0: fprintf(f, "RNC"); break;
        case 0xd1: fprintf(f, "POP    D"); break;
        case 0xd2: fprintf(f, "JNC    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xd3: fprintf(f, "OUT    #$%02x", com[1]); bytes=2; break;
        case 0xd4: fprintf(f, "CNC    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xd5: fprintf(f, "PUSH   D"); break;
        case 0xd6: fprintf(f, "SUI    #$%02x", com[1]); bytes=2; break;
        case 0xd7: fprintf(f, "RST    2"); break;
        case 0xd8: fprintf(f, "RC"); break;
        case 0xd9: fprintf(f, "-"); break;
        case 0xda: fprintf(f, "JC     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xdb: fprintf(f, "IN     #$%02x", com[1]); bytes=2; break;
        case 0xdc: fprintf(f, "CC     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xdd: fprintf(f, "-"); break;
        case 0xde: fprintf(f, "SBI    #$%02x", com[1]); bytes=2; break;
        case 0xdf: fprintf(f, "RST    3"); break;
        case 0xe0: fprintf(f, "RPO"); break;
        case 0xe1: fprintf(f, "POP    H"); break;
        case 0xe2: fprintf(f, "JPO    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xe3: fprintf(f, "XTHL"); break;
        case 0xe4: fprintf(f, "CPO    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xe5: fprintf(f, "PUSH   H"); break;
        case 0xe6: fprintf(f, "ANI    #$%02x", com[1]); bytes=2; break;
        case 0xe7: fprintf(f, "RST    4"); break;
        case 0xe8: fprintf(f, "RPE"); break;
        case 0xe9: fprintf(f, "PCHL"); break;
        case 0xea: fprintf(f, "JPE    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xeb: fprintf(f, "XCHG"); break;
        case 0xec: fprintf(f, "CPE    $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xed: fprintf(f, "-"); break;
        case 0xee: fprintf(f, "XRI    #$%02x", com[1]); bytes=2; break;
        case 0xef: fprintf(f, "RST    5"); break;
        case 0xf0: fprintf(f, "RP"); break;
        case 0xf1: fprintf(f, "POP    PSW"); break;
        case 0xf2: fprintf(f, "JP     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xf3: fprintf(f, "DI"); break;
        case 0xf4: fprintf(f, "CP     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xf5: fprintf(f, "PUSH   PSW"); break;
        case 0xf6: fprintf(f, "ORI    #$%02x", com[1]); bytes=2; break;
        case 0xf7: fprintf(f, "RST    6"); break;
        case 0xf8: fprintf(f, "RM"); break;
        case 0xf9: fprintf(f, "SPHL"); break;
        case 0xfa: fprintf(f, "JM     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xfb: fprintf(f, "EI"); break;
        case 0xfc: fprintf(f, "CM     $%02x%02x",com[2],com[1]); bytes= 3; break;
        case 0xfd: fprintf(f, "-"); break;
        case 0xfe: fprintf(f, "CPI    #$%02x", com[1]); bytes=2; break;
        case 0xff: fprintf(f, "RST    7"); break;
        default: break;
    }
    fprintf(f, "\n");
    return bytes;
}

int main(int argc, char** argv){
    (void)argc; // lole
    FILE *f = fopen(argv[1], "rb");     // open .h file in read binary mode
    if (f == NULL){         // failsafe
        printf("ERROR: could not read file %s\n", argv[1]);
        exit(1);
    }
    char filename[strlen(argv[1])];
    strncpy(filename, argv[1], strlen(argv[1])-4);    // generate output name
    FILE *fo = fopen(strcat(filename, ".asm"), "w");     // open output file in write mode
    if (fo == NULL){         // failsafe
        printf("ERROR: could not write an output file %s\n", filename);
        exit(1);
    }

    fseek(f, 0L, SEEK_END);     // catch filesize by seeking EOF
    int fsize = ftell(f);       // ...and telling cursor location...
    fseek(f, 0L, SEEK_SET);     // ...then returning it to where we need it

    unsigned char *buffer = malloc(fsize);  // all this shit just to malloc the file in memory lol
    fread(buffer, fsize, 1, f);
    fclose(f);
    int pc = 0;     // program counter

    printf("converting %s into %s... ", argv[1], filename);
    while(pc < fsize){
        pc += Disassemble8080(buffer, pc, fo);
    }
    printf("done");

    fclose(fo);
    return 0;
}