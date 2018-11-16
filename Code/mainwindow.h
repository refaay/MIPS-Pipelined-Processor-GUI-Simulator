#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "MIPS_Assembler.hpp"
#include "MIPS_R4000_Hazard_Unit.hpp"
#include "Register.hpp"
#include "Pipeline_Buffers_Handler.hpp"
#include "Memory.hpp"
#include "MIPS_Decoder.hpp"
#include "MIPS_Control_Unit.hpp"
#include "RegisterFile.hpp"
#include "ALU.hpp"
#include "Buffers_Indices.h"
#include "pseudoconverter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <stack>

#define PC_index 0
#define IS_index 1
#define RF_index 2
#define EX_index 3
#define DF_index 4
#define DS_index 5
#define TC_index 6
#define WB_index 7


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
       // declare instruction memory
        Memory I_cache;
        // declare data memory
        Memory D_cache;
        // declare register file
        RegisterFile register_file;
        // declare hazard unit
        MIPS_R4000_Hazard_Unit hazard_unit;
        // declare pipeline buffers
        std::vector<Pipeline_Buffers_Handler::Register_Logic> Pipelined_Registers;
        // declare procedure stack
        std::stack<uint32_t> procedure_stack;
        // clk count
        int clkCount;
        // boolians
        bool reset_branch = false, should_stall = false, reset_jump = false;
        bool dont_start;
private slots:
        void on_start_clicked();

        void on_advance_clicked();

        std::string int_to_hex_string(uint32_t num);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
