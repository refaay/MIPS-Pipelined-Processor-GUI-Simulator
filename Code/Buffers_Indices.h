

#ifndef Buffers_Indices_h
#define Buffers_Indices_h

const int INDEX_pc = 0;
const int INDEX_branch_prediction = INDEX_pc + 1;

const int INDEX_instr_word = INDEX_branch_prediction + 1;

const int INDEX_opcode = INDEX_instr_word + 1;
const int INDEX_funct = INDEX_opcode + 1;
const int INDEX_RS = INDEX_funct + 1;
const int INDEX_RT = INDEX_RS + 1;
const int INDEX_RD = INDEX_RT + 1;
const int INDEX_immi_ext = INDEX_RD + 1;
const int INDEX_mem_to_reg = INDEX_immi_ext + 1;
const int INDEX_mem_write = INDEX_mem_to_reg + 1;
const int INDEX_ALU_src = INDEX_mem_write + 1;
const int INDEX_reg_dst = INDEX_ALU_src + 1;
const int INDEX_reg_write = INDEX_reg_dst + 1;
const int INDEX_branch = INDEX_reg_write + 1;
const int INDEX_branch_on_equal = INDEX_branch + 1;
const int INDEX_jump = INDEX_branch_on_equal + 1;
const int INDEX_link_on_jumping = INDEX_jump + 1;
const int INDEX_stack_jumping = INDEX_link_on_jumping + 1;
const int INDEX_ALU_ctrl = INDEX_stack_jumping + 1;
const int INDEX_RS_data = INDEX_ALU_ctrl + 1;
const int INDEX_RT_data = INDEX_RS_data + 1;

const int INDEX_correct_branch_decision = INDEX_RT_data + 1;
const int INDEX_ALU_result = INDEX_correct_branch_decision + 1;

const int INDEX_mem_data = INDEX_ALU_result + 1;

#endif /* Buffers_Indices_h */
