// ALUControl

#define ADD 0
#define SUB 1
#define AND 2
#define OR 3
#define XOR 4
#define SLL 5
#define SRL 6
#define SRA 7
#define SLT 8
#define NOR  9
#define SLLV 10
#define SRLV 11
#define SRAV 12
#define LUI 13

// R_type Functions

#define R_OPCODE 0
#define ADD_FUNC 0x20
#define ADDU_FUNC 0x21
#define AND_FUNC 0x24
#define NOR_FUNC 0x27
#define OR_FUNC 0x25
#define SLL_FUNC 0x0
#define SLLV_FUNC 0x4
#define SLT_FUNC 0x2A
#define SLTU_FUNC 0x2B
#define SRA_FUNC 0x3
#define SRAV_FUNC 0x7
#define SRL_FUNC 0x2
#define SRLV_FUNC 0x6
#define SUB_FUNC 0x22
#define SUBU_FUNC 0x23
#define XOR_FUNC 0x26
#define JR_FUNC 0x8
#define RPR_FUNC 0x1B

// I_Type Opcode

#define LW_OP 0x23
#define SW_OP 0x2B
#define BEQ_OP 0x4
#define BNE_OP 0x5
#define ADDI_OP 0x8
#define ADDIU_OP 0x9
#define ANDI_OP 0xC
#define ORI_OP 0xD
#define SLTI_OP 0xA
#define XORI_OP 0xE
#define LUI_OP 0xF


// J_Type Opcode

#define J_OP 0x2
#define JAL_OP 0x3
#define JPR_OP 0x1C
