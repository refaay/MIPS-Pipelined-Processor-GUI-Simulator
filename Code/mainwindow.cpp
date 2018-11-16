#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // disable lineEdits
        ui->clk->setEnabled(false);
        ui->pc->setEnabled(false);

        ui->c0->setEnabled(false);
        ui->c1->setEnabled(false);
        ui->c2->setEnabled(false);
        ui->c3->setEnabled(false);
        ui->c4->setEnabled(false);
        ui->c5->setEnabled(false);
        ui->c6->setEnabled(false);
        ui->c7->setEnabled(false);
        ui->c8->setEnabled(false);
        ui->c9->setEnabled(false);

        ui->btbi1->setEnabled(false);
        ui->btbi2->setEnabled(false);
        ui->btbi3->setEnabled(false);
        ui->btbi4->setEnabled(false);
        ui->btbi5->setEnabled(false);

        ui->btbt1->setEnabled(false);
        ui->btbt2->setEnabled(false);
        ui->btbt3->setEnabled(false);
        ui->btbt4->setEnabled(false);
        ui->btbt5->setEnabled(false);

        ui->btbp1->setEnabled(false);
        ui->btbp2->setEnabled(false);
        ui->btbp3->setEnabled(false);
        ui->btbp4->setEnabled(false);
        ui->btbp5->setEnabled(false);

        ui->r0->setEnabled(false);
        ui->r1->setEnabled(false);
        ui->r2->setEnabled(false);
        ui->r3->setEnabled(false);
        ui->r4->setEnabled(false);
        ui->r5->setEnabled(false);
        ui->r6->setEnabled(false);
        ui->r7->setEnabled(false);
        ui->r8->setEnabled(false);
        ui->r9->setEnabled(false);
        ui->r10->setEnabled(false);
        ui->r11->setEnabled(false);
        ui->r12->setEnabled(false);
        ui->r13->setEnabled(false);
        ui->r14->setEnabled(false);
        ui->r15->setEnabled(false);

        ui->m0->setEnabled(false);
        ui->m1->setEnabled(false);
        ui->m2->setEnabled(false);
        ui->m3->setEnabled(false);
        ui->m4->setEnabled(false);
        ui->m5->setEnabled(false);
        ui->m6->setEnabled(false);
        ui->m7->setEnabled(false);
        ui->m8->setEnabled(false);
        ui->m9->setEnabled(false);
        ui->m10->setEnabled(false);
        ui->m11->setEnabled(false);
        ui->m12->setEnabled(false);
        ui->m13->setEnabled(false);
        ui->m14->setEnabled(false);
        ui->m15->setEnabled(false);

        ui->p1->setEnabled(false);
        ui->p2->setEnabled(false);
        ui->p3->setEnabled(false);
        ui->p4->setEnabled(false);

        ui->s1->setEnabled(false);
        ui->s2->setEnabled(false);
        ui->s3->setEnabled(false);
        ui->s4->setEnabled(false);
        ui->s5->setEnabled(false);
        ui->s6->setEnabled(false);
        ui->s7->setEnabled(false);
        ui->s8->setEnabled(false);

        ui->h1->setEnabled(false);
        ui->h2->setEnabled(false);
        ui->h3->setEnabled(false);
        ui->h4->setEnabled(false);
        ui->h5->setEnabled(false);
        ui->h6->setEnabled(false);
        ui->h7->setEnabled(false);
        ui->h8->setEnabled(false);

        ui->load->setEnabled(false);
        ui->branch->setEnabled(false);
        ui->jump->setEnabled(false);
        ui->done->setEnabled(false);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked()
{
    dont_start = false;

    // load the I_cache with the instructions
    I_cache.resize(0);

    //Fill instructions

    int n = (ui->inumber->text()).toInt();

    std::vector<bool> errors;
    errors.resize(0);
    I_cache.resize(0);

    std::string expr;
    uint32_t machine;
    vector<string> temp, final_instr;
    for(int i = 0; i < n; i++){
        temp.clear();
               switch (i){
               case 0: expr = (ui->i0->text()).toStdString(); break;
               case 1: expr = (ui->i1->text()).toStdString(); break;
               case 2: expr = (ui->i2->text()).toStdString(); break;
               case 3: expr = (ui->i3->text()).toStdString(); break;
               case 4: expr = (ui->i4->text()).toStdString(); break;
               case 5: expr = (ui->i5->text()).toStdString(); break;
               case 6: expr = (ui->i6->text()).toStdString(); break;
               case 7: expr = (ui->i7->text()).toStdString(); break;
               case 8: expr = (ui->i8->text()).toStdString(); break;
               case 9: expr = (ui->i9->text()).toStdString(); break;
               default: expr = "";
               }

               // was in a try block
               temp.push_back(expr);
               PSEUDOCONVERTER::convert_to_true(temp);

               for (int j = 0; j < temp.size(); j++){
                   try{
                        final_instr.push_back((temp[j]));
                        machine = MIPS_Assembler::exprToMachine(temp[j]);
                        I_cache.insert(machine, true);
                        errors.push_back(false);
                   }
                   catch(...){
                       errors.push_back(true);

                   }
               }
    }

    ui->i0->setText("");
    ui->i1->setText("");
    ui->i2->setText("");
    ui->i3->setText("");
    ui->i4->setText("");
    ui->i5->setText("");
    ui->i6->setText("");
    ui->i7->setText("");
    ui->i8->setText("");
    ui->i9->setText("");

    ui->c0->setText("");
    ui->c1->setText("");
    ui->c2->setText("");
    ui->c3->setText("");
    ui->c4->setText("");
    ui->c5->setText("");
    ui->c6->setText("");
    ui->c7->setText("");
    ui->c8->setText("");
    ui->c9->setText("");

    for(int k = 0; k < final_instr.size(); k++){
        switch (k){
        case 0:  ui->i0->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c0->setText("X");
            else ui->c0->setText("");
            break;
        case 1:  ui->i1->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c1->setText("X");
            else ui->c1->setText("");
            break;
        case 2:  ui->i2->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c2->setText("X");
            else ui->c2->setText("");
            break;
        case 3:  ui->i3->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c3->setText("X");
            else ui->c3->setText("");
            break;
        case 4:  ui->i4->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c4->setText("X");
            else ui->c4->setText("");
            break;
        case 5:  ui->i5->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c5->setText("X");
            else ui->c5->setText("");
            break;
        case 6:  ui->i6->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c6->setText("X");
            else ui->c6->setText("");
            break;
        case 7:  ui->i7->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c7->setText("X");
            else ui->c7->setText("");
            break;
        case 8:  ui->i8->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c8->setText("X");
            else ui->c8->setText("");
            break;
        case 9:  ui->i9->setText(QString::fromStdString(final_instr[k]));
            if(errors[k]) ui->c9->setText("X");
            else ui->c9->setText("");
            break;
        }
    }

    for(int i = 0; i < errors.size(); i++)
        if(errors[i]){
            dont_start = true;
            return;
        }

    //end of fill instructions

    // empty and resize the D_cache
    D_cache.resize(0);
    D_cache.resize(16);

    // empty and resize the register_file
    register_file.resizeAndReset(16);

    // empty the BTB
    hazard_unit.Branch_Predictor.clear();

    // empty and resize the pipeline buffers
    Pipelined_Registers.resize(0);
    Pipelined_Registers.resize(8);

    Pipeline_Buffers_Handler::enableBuffers(Pipelined_Registers, PC_index, WB_index, true);

    // resize outer wires to correct size
    Pipeline_Buffers_Handler::resizeBuffers(Pipelined_Registers, PC_index, WB_index, 0);

    Pipeline_Buffers_Handler::resizeBuffers(Pipelined_Registers, PC_index, PC_index, 2);
    Pipeline_Buffers_Handler::resizeBuffers(Pipelined_Registers, IS_index, RF_index, 3);
    Pipeline_Buffers_Handler::resizeBuffers(Pipelined_Registers, EX_index, EX_index, 22);
    Pipeline_Buffers_Handler::resizeBuffers(Pipelined_Registers, DF_index, DS_index, 24);
    Pipeline_Buffers_Handler::resizeBuffers(Pipelined_Registers, TC_index, WB_index, 25);

    // resize internal buffers to correct size
    Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, PC_index, WB_index, false);
    Pipeline_Buffers_Handler::assignInputBuffers(Pipelined_Registers, PC_index, WB_index);
    Pipeline_Buffers_Handler::updateBuffers(Pipelined_Registers, PC_index, WB_index);

    // reset all buffers
    Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, PC_index, WB_index, true);
    Pipeline_Buffers_Handler::updateBuffers(Pipelined_Registers, PC_index, WB_index);

    // prepare buffers for simulation
    Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, PC_index, WB_index, false);
    Pipeline_Buffers_Handler::updateBuffers(Pipelined_Registers, PC_index, WB_index);

    while(!procedure_stack.empty())
        procedure_stack.pop();

    clkCount = 0;
    reset_branch = should_stall = reset_jump = false;

    // clear lineEdits
        ui->clk->setText(QString::number(clkCount));
        ui->pc->setText(QString::number(clkCount*4));

        ui->btbi1->clear();
        ui->btbi2->clear();
        ui->btbi3->clear();
        ui->btbi4->clear();
        ui->btbi5->clear();

        ui->btbt1->clear();
        ui->btbt2->clear();
        ui->btbt3->clear();
        ui->btbt4->clear();
        ui->btbt5->clear();

        ui->btbp1->clear();
        ui->btbp2->clear();
        ui->btbp3->clear();
        ui->btbp4->clear();
        ui->btbp5->clear();

        ui->r0->clear();
        ui->r1->clear();
        ui->r2->clear();
        ui->r3->clear();
        ui->r4->clear();
        ui->r5->clear();
        ui->r6->clear();
        ui->r7->clear();
        ui->r8->clear();
        ui->r9->clear();
        ui->r10->clear();
        ui->r11->clear();
        ui->r12->clear();
        ui->r13->clear();
        ui->r14->clear();
        ui->r15->clear();

        ui->m0->clear();
        ui->m1->clear();
            ui->m2->clear();
            ui->m3->clear();
            ui->m4->clear();
            ui->m5->clear();
            ui->m6->clear();
            ui->m7->clear();
            ui->m8->clear();
            ui->m9->clear();
            ui->m10->clear();
            ui->m11->clear();
            ui->m12->clear();
            ui->m13->clear();
            ui->m14->clear();
            ui->m15->clear();

            ui->p1->clear();
                ui->p2->clear();
                ui->p3->clear();
                ui->p4->clear();

                ui->s1->clear();
                    ui->s2->clear();
                    ui->s3->clear();
                    ui->s4->clear();
                    ui->s5->clear();
                    ui->s6->clear();
                    ui->s7->clear();
                    ui->s8->clear();
}
uint32_t checkRealBranchDecision(bool branch, bool branch_on_equal, uint32_t RS_contents, uint32_t RT_contents){
    if(!branch)
        return 0;
    if(branch_on_equal)
        return RS_contents == RT_contents;
    else
        return RS_contents != RT_contents;
}
void MainWindow::on_advance_clicked()
{
    if(dont_start)
        return;



        // read data from pipeline buffers
        Pipeline_Buffers_Handler::readDataBuffers(Pipelined_Registers, PC_index, WB_index);

        // set flags to false
        reset_branch = should_stall = reset_jump = false;

        // detect load hazard
        should_stall = hazard_unit.getStallingDecision(Pipelined_Registers[EX_index].output[INDEX_RS], Pipelined_Registers[EX_index].output[INDEX_RT], Pipelined_Registers[DF_index].output[INDEX_RT], Pipelined_Registers[DF_index].output[INDEX_mem_to_reg], Pipelined_Registers[DS_index].output[INDEX_RT], Pipelined_Registers[DS_index].output[INDEX_mem_to_reg]);

        // ****** IF stage ******

        // get branch predictions on program counter
        Pipelined_Registers[PC_index].input[INDEX_branch_prediction] = hazard_unit.Branch_Predictor.shouldBranch(Pipelined_Registers[PC_index].output[INDEX_pc]);

        // decide next address of program counter
        if(Pipelined_Registers[PC_index].input[INDEX_branch_prediction])
            Pipelined_Registers[PC_index].input[INDEX_pc] = hazard_unit.Branch_Predictor.getSpeculatedAddress(Pipelined_Registers[PC_index].output[INDEX_pc]);
        else
            Pipelined_Registers[PC_index].input[INDEX_pc] = Pipelined_Registers[PC_index].output[INDEX_pc] + 4;

        // copy forward to IS_buffer from PC_register
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[IS_index], Pipelined_Registers[PC_index]);

        // read next instruction
        Pipelined_Registers[IS_index].input[INDEX_instr_word] = I_cache.read(Pipelined_Registers[PC_index].output[INDEX_pc] >> 2);

        // ****** IS stage ******

        // copy forward to RF_buffer from IS_buffer
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[RF_index], Pipelined_Registers[IS_index]);

        // ****** RF stage ******

        // copy forward to EX_buffer from RF_buffer
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[EX_index], Pipelined_Registers[RF_index]);

        // decode current instruction
        MIPS_Decoder::decodeInstruction(Pipelined_Registers[RF_index].output[INDEX_instr_word], Pipelined_Registers[EX_index].input[INDEX_opcode], Pipelined_Registers[EX_index].input[INDEX_funct], Pipelined_Registers[EX_index].input[INDEX_RS], Pipelined_Registers[EX_index].input[INDEX_RT], Pipelined_Registers[EX_index].input[INDEX_RD], Pipelined_Registers[EX_index].input[INDEX_immi_ext]);

        // get control signals of decoded instruction
        MIPS_Control_Unit::getControlSignals(Pipelined_Registers[EX_index].input[INDEX_opcode], Pipelined_Registers[EX_index].input[INDEX_funct], Pipelined_Registers[EX_index].input[INDEX_mem_to_reg], Pipelined_Registers[EX_index].input[INDEX_mem_write], Pipelined_Registers[EX_index].input[INDEX_ALU_src], Pipelined_Registers[EX_index].input[INDEX_reg_dst], Pipelined_Registers[EX_index].input[INDEX_reg_write], Pipelined_Registers[EX_index].input[INDEX_branch], Pipelined_Registers[EX_index].input[INDEX_branch_on_equal], Pipelined_Registers[EX_index].input[INDEX_jump], Pipelined_Registers[EX_index].input[INDEX_link_on_jumping], Pipelined_Registers[EX_index].input[INDEX_stack_jumping], Pipelined_Registers[EX_index].input[INDEX_ALU_ctrl]);

        // (** WB stage **) write back data to register file
        uint32_t write_data = Pipelined_Registers[WB_index].output[INDEX_mem_to_reg] ? Pipelined_Registers[WB_index].output[INDEX_mem_data] : Pipelined_Registers[WB_index].output[INDEX_ALU_result];
        uint32_t write_address = Pipelined_Registers[WB_index].output[INDEX_ALU_src] ? Pipelined_Registers[WB_index].output[INDEX_RT] : Pipelined_Registers[WB_index].output[INDEX_RD];

        register_file.write(write_address, write_data, Pipelined_Registers[WB_index].output[INDEX_reg_write]);

        // read data from register file
        Pipelined_Registers[EX_index].input[INDEX_RS_data] = register_file.read(Pipelined_Registers[EX_index].input[INDEX_RS]);
        Pipelined_Registers[EX_index].input[INDEX_RT_data] = register_file.read(Pipelined_Registers[EX_index].input[INDEX_RT]);

        // adjust for jump instruction
        if(Pipelined_Registers[EX_index].input[INDEX_jump]){
            reset_jump = true;
            if(Pipelined_Registers[EX_index].input[INDEX_link_on_jumping]){
                Pipelined_Registers[PC_index].input[INDEX_pc] = (((Pipelined_Registers[EX_index].input[INDEX_instr_word] << 2) & 0x0FFFFFFF) | (Pipelined_Registers[EX_index].input[INDEX_pc] & 0xF0000000)) + 4;
                procedure_stack.push(Pipelined_Registers[EX_index].input[INDEX_pc] + 4);
            }
            else if(Pipelined_Registers[EX_index].input[INDEX_stack_jumping]){
                Pipelined_Registers[PC_index].input[INDEX_pc] = procedure_stack.top();
                procedure_stack.pop();
            }
            else{
                Pipelined_Registers[PC_index].input[INDEX_pc] = (((Pipelined_Registers[EX_index].input[INDEX_instr_word] << 2) & 0x0FFFFFFF) | (Pipelined_Registers[EX_index].input[INDEX_pc] & 0xF0000000)) + 4;
            }
        }

        // ****** EX stage ******

        // copy forward to DF_buffer from EX_buffer
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[DF_index], Pipelined_Registers[EX_index]);

        uint32_t reg_addr_rs[3];
        for(int i = 0; i < 3; i++)
            reg_addr_rs[i] = Pipelined_Registers[DF_index + i].output[INDEX_ALU_src] ? Pipelined_Registers[DF_index + i].output[INDEX_RT] : Pipelined_Registers[DF_index + i].output[INDEX_RD];

        MIPS_R4000_Forwarding_Unit::Final_Source RS_source = hazard_unit.getForwardingDecision(Pipelined_Registers[EX_index].output[INDEX_RS], reg_addr_rs[0], Pipelined_Registers[DF_index].output[INDEX_reg_write], reg_addr_rs[1], Pipelined_Registers[DS_index].output[INDEX_reg_write], reg_addr_rs[2], Pipelined_Registers[TC_index].output[INDEX_reg_write], Pipelined_Registers[TC_index].output[INDEX_RT], Pipelined_Registers[TC_index].output[INDEX_mem_to_reg]);

        switch(RS_source){
            case MIPS_R4000_Forwarding_Unit::Final_Source::EX:
                Pipelined_Registers[DF_index].input[INDEX_RS_data] = Pipelined_Registers[EX_index].output[INDEX_RS_data];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::DF:
                Pipelined_Registers[DF_index].input[INDEX_RS_data] = Pipelined_Registers[DF_index].output[INDEX_ALU_result];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::DS:
                Pipelined_Registers[DF_index].input[INDEX_RS_data] = Pipelined_Registers[DS_index].output[INDEX_ALU_result];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::TC_mem:
                Pipelined_Registers[DF_index].input[INDEX_RS_data] = Pipelined_Registers[TC_index].output[INDEX_mem_data];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::TC_alu:
                Pipelined_Registers[DF_index].input[INDEX_RS_data] = Pipelined_Registers[TC_index].output[INDEX_ALU_result];
                break;
        }

        uint32_t reg_addr_rt[3];
        for(int i = 0; i < 3; i++)
            reg_addr_rt[i] = Pipelined_Registers[DF_index + i].output[INDEX_ALU_src] ? Pipelined_Registers[DF_index + i].output[INDEX_RT] : Pipelined_Registers[DF_index + i].output[INDEX_RD];

        MIPS_R4000_Forwarding_Unit::Final_Source RT_source = hazard_unit.getForwardingDecision(Pipelined_Registers[EX_index].output[INDEX_RT], reg_addr_rt[0], Pipelined_Registers[DF_index].output[INDEX_reg_write], reg_addr_rt[1], Pipelined_Registers[DS_index].output[INDEX_reg_write], reg_addr_rt[2], Pipelined_Registers[TC_index].output[INDEX_reg_write], Pipelined_Registers[TC_index].output[INDEX_RT], Pipelined_Registers[TC_index].output[INDEX_mem_to_reg]);

        switch(RT_source){
            case MIPS_R4000_Forwarding_Unit::Final_Source::EX:
                Pipelined_Registers[DF_index].input[INDEX_RT_data] = Pipelined_Registers[EX_index].output[INDEX_RS_data];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::DF:
                Pipelined_Registers[DF_index].input[INDEX_RT_data] = Pipelined_Registers[DF_index].output[INDEX_ALU_result];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::DS:
                Pipelined_Registers[DF_index].input[INDEX_RT_data] = Pipelined_Registers[DS_index].output[INDEX_ALU_result];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::TC_mem:
                Pipelined_Registers[DF_index].input[INDEX_RT_data] = Pipelined_Registers[TC_index].output[INDEX_mem_data];
                break;
            case MIPS_R4000_Forwarding_Unit::Final_Source::TC_alu:
                Pipelined_Registers[DF_index].input[INDEX_RT_data] = Pipelined_Registers[TC_index].output[INDEX_ALU_result];
                break;
        }

        // get correct branch decision
        Pipelined_Registers[DF_index].input[INDEX_correct_branch_decision] = checkRealBranchDecision(Pipelined_Registers[EX_index].output[INDEX_branch], Pipelined_Registers[EX_index].output[INDEX_branch_on_equal], Pipelined_Registers[DF_index].input[INDEX_RS_data], Pipelined_Registers[DF_index].input[INDEX_RT_data]);

        // check if this is a branch instruction and add it to the table
        if((Pipelined_Registers[EX_index].output[INDEX_branch]))
            hazard_unit.Branch_Predictor.addIfNotPresent(Pipelined_Registers[EX_index].output[INDEX_pc], Pipelined_Registers[EX_index].output[INDEX_pc] + 4 + (Pipelined_Registers[EX_index].output[INDEX_immi_ext] << 2));

        // update branch table
        hazard_unit.Branch_Predictor.updateDecision(Pipelined_Registers[EX_index].output[INDEX_pc], Pipelined_Registers[DF_index].input[INDEX_correct_branch_decision]);

        // deal with incorrect branch taken hazard
        if (Pipelined_Registers[EX_index].output[INDEX_branch_prediction] && !Pipelined_Registers[DF_index].input[INDEX_correct_branch_decision]){
            Pipelined_Registers[PC_index].input[INDEX_pc] = Pipelined_Registers[EX_index].output[INDEX_pc] + 4;
            // Pipelined_Registers[PC_index].input[INDEX_branch_prediction] = 0;
            reset_branch = true;
        }

        // deal with incorrect branch not taken hazard
        if (!Pipelined_Registers[EX_index].output[INDEX_branch_prediction] && Pipelined_Registers[DF_index].input[INDEX_correct_branch_decision]){
            Pipelined_Registers[PC_index].input[INDEX_pc] = Pipelined_Registers[EX_index].output[INDEX_pc] + 4 + (Pipelined_Registers[EX_index].output[INDEX_immi_ext] << 2);
            // Pipelined_Registers[PC_index].input[INDEX_branch_prediction] = 1;
            reset_branch = true;
        }

        // operand 2 input logic
        uint32_t ALU_operand2 = Pipelined_Registers[EX_index].output[INDEX_ALU_src] ? Pipelined_Registers[EX_index].output[INDEX_immi_ext] : Pipelined_Registers[DF_index].input[INDEX_RT_data];

        uint32_t shamt = (Pipelined_Registers[EX_index].output[INDEX_immi_ext] >> 6) & 0x1F;

        // ALU module
        ALU::ALUResult(Pipelined_Registers[DF_index].input[INDEX_RS_data], ALU_operand2, Pipelined_Registers[EX_index].output[INDEX_ALU_ctrl], shamt, Pipelined_Registers[DF_index].input[INDEX_ALU_result]);

        // **** DF stage ****

        // copy forward to DS_buffer from DF_buffer
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[DS_index], Pipelined_Registers[DF_index]);

        // **** DS stage ****

        // copy forward to TC_buffer from DS_buffer
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[TC_index], Pipelined_Registers[DS_index]);

        // write data to data cache
        D_cache.insert(Pipelined_Registers[DS_index].output[INDEX_ALU_result] >> 2, Pipelined_Registers[DS_index].output[INDEX_RT_data], Pipelined_Registers[DS_index].output[INDEX_mem_write]);

        // read data from data cache
        Pipelined_Registers[TC_index].input[INDEX_mem_data] = D_cache.read(Pipelined_Registers[DS_index].output[INDEX_ALU_result] >> 2);

        // **** TC stage ****

        // copy forward to WB_buffer from DT_buffer
        Pipeline_Buffers_Handler::copyForward(Pipelined_Registers[WB_index], Pipelined_Registers[TC_index]);

        // **** WB stage ****

        // see above (in RF_stage)

        // update pipeline buffers

        // stall PC register, IS_buffer, RF_buffer, EX_buffer - if needed
        Pipeline_Buffers_Handler::enableBuffers(Pipelined_Registers, PC_index, EX_index, !should_stall);
        // flush IS and RF buffers - if needed
        Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, IS_index, RF_index, reset_branch || reset_jump);
        // flush EX_buffer - if needed
        Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, EX_index, EX_index, reset_branch);
        // flush DF_buffer - if needed
        Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, DF_index, DF_index, should_stall);

        Pipeline_Buffers_Handler::assignInputBuffers(Pipelined_Registers, PC_index, WB_index);
        Pipeline_Buffers_Handler::updateBuffers(Pipelined_Registers, PC_index, WB_index);

        // set reset to false and enable to true to prepare for next cycle
        Pipeline_Buffers_Handler::resetBuffers(Pipelined_Registers, PC_index, WB_index, false);
        Pipeline_Buffers_Handler::enableBuffers(Pipelined_Registers, PC_index, WB_index, true);

        // Display lineEdits
            ui->clk->setText(QString::number(clkCount++));
            ui->pc->setText(QString::number(Pipelined_Registers[0].output[PC_index]));

            ui->btbi1->clear();
            ui->btbi2->clear();
            ui->btbi3->clear();
            ui->btbi4->clear();
            ui->btbi5->clear();

            ui->btbt1->clear();
            ui->btbt2->clear();
            ui->btbt3->clear();
            ui->btbt4->clear();
            ui->btbt5->clear();

            ui->btbp1->clear();
            ui->btbp2->clear();
            ui->btbp3->clear();
            ui->btbp4->clear();
            ui->btbp5->clear();

            int  p, v;
            uint32_t f, t;
            for(int i = 0; i < 5; i++){
                v = hazard_unit.Branch_Predictor.access(i, f, t, p);
                switch(i){
                case 0:
                    ui->btbi1->setText(QString::number(f));
                    ui->btbt1->setText(QString::number(t));
                    ui->btbp1->setText(QString::number(p));

                    break;
                case 1:
                    ui->btbi2->setText(QString::number(f));
                    ui->btbt2->setText(QString::number(t));
                    ui->btbp2->setText(QString::number(p));

                    break;
                case 2:
                    ui->btbi3->setText(QString::number(f));
                    ui->btbt3->setText(QString::number(t));
                    ui->btbp3->setText(QString::number(p));

                    break;
                case 3:
                    ui->btbi4->setText(QString::number(f));
                    ui->btbt4->setText(QString::number(t));
                    ui->btbp4->setText(QString::number(p));

                    break;
                case 4:
                    ui->btbi5->setText(QString::number(f));
                    ui->btbt5->setText(QString::number(t));
                    ui->btbp5->setText(QString::number(p));

                    break;
                }
            }

            ui->r0->setText(QString::number(int(register_file.array[0])));
            ui->r1->setText(QString::number(int(register_file.array[1])));
            ui->r2->setText(QString::number(int(register_file.array[2])));
            ui->r3->setText(QString::number(int(register_file.array[3])));
            ui->r4->setText(QString::number(int(register_file.array[4])));
            ui->r5->setText(QString::number(int(register_file.array[5])));
            ui->r6->setText(QString::number(int(register_file.array[6])));
            ui->r7->setText(QString::number(int(register_file.array[7])));
            ui->r8->setText(QString::number(int(register_file.array[8])));
            ui->r9->setText(QString::number(int(register_file.array[9])));
            ui->r10->setText(QString::number(int(register_file.array[10])));
            ui->r11->setText(QString::number(int(register_file.array[11])));
            ui->r12->setText(QString::number(int(register_file.array[12])));
            ui->r13->setText(QString::number(int(register_file.array[13])));
            ui->r14->setText(QString::number(int(register_file.array[14])));
            ui->r15->setText(QString::number(int(register_file.array[15])));

            ui->m0->setText(QString::number(D_cache.mem_array[0]));
            ui->m1->setText(QString::number(D_cache.mem_array[1]));
                ui->m2->setText(QString::number(D_cache.mem_array[2]));
                ui->m3->setText(QString::number(D_cache.mem_array[3]));
                ui->m4->setText(QString::number(D_cache.mem_array[4]));
                ui->m5->setText(QString::number(D_cache.mem_array[5]));
                ui->m6->setText(QString::number(D_cache.mem_array[6]));
                ui->m7->setText(QString::number(D_cache.mem_array[7]));
                ui->m8->setText(QString::number(D_cache.mem_array[8]));
                ui->m9->setText(QString::number(D_cache.mem_array[9]));
                ui->m10->setText(QString::number(D_cache.mem_array[10]));
                ui->m11->setText(QString::number(D_cache.mem_array[11]));
                ui->m12->setText(QString::number(D_cache.mem_array[12]));
                ui->m13->setText(QString::number(D_cache.mem_array[13]));
                ui->m14->setText(QString::number(D_cache.mem_array[14]));
                ui->m15->setText(QString::number(D_cache.mem_array[15]));

                ui->p1->clear();
                    ui->p2->clear();
                    ui->p3->clear();
                    ui->p4->clear();

                    if(!procedure_stack.empty())
                        ui->p1->setText(QString::number(procedure_stack.top()));

                    ui->s1->setText(QString::number(Pipelined_Registers[0].output[PC_index]));
                        ui->s2->setText(QString::number(Pipelined_Registers[1].output[PC_index]));
                        ui->s3->setText(QString::number(Pipelined_Registers[2].output[PC_index]));
                        ui->s4->setText(QString::number(Pipelined_Registers[3].output[PC_index]));
                        ui->s5->setText(QString::number(Pipelined_Registers[4].output[PC_index]));
                        ui->s6->setText(QString::number(Pipelined_Registers[5].output[PC_index]));
                        ui->s7->setText(QString::number(Pipelined_Registers[6].output[PC_index]));
                        ui->s8->setText(QString::number(Pipelined_Registers[7].output[PC_index]));

                        ui->h1->setText("0x0");

                        ui->h2->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[1].output[INDEX_instr_word])));
                        ui->h3->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[2].output[INDEX_instr_word])));
                        ui->h4->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[3].output[INDEX_instr_word])));
                        ui->h5->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[4].output[INDEX_instr_word])));
                        ui->h6->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[5].output[INDEX_instr_word])));
                        ui->h7->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[6].output[INDEX_instr_word])));
                        ui->h8->setText(QString::fromStdString(int_to_hex_string(Pipelined_Registers[7].output[INDEX_instr_word])));


                            ui->load->setText(QString::number(should_stall));
                            ui->branch->setText(QString::number(reset_branch));
                            ui->jump->setText(QString::number(reset_jump));
                            ui->done->setText(QString::number((Pipelined_Registers[7].output[PC_index]) == (4*(I_cache.mem_array.size()-1))));
}

std::string MainWindow::int_to_hex_string(uint32_t num){
    std::string s;
    std::stringstream ss;

    ss << "0x" << std::hex << num;
    s = ss.str();

    return s;
}

