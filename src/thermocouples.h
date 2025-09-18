#pragma once

#define Reg_num 2 // кол-во регистров
#define Reg_pins Reg_num * 8 // Общее кол-во пинов на всех регистрах
boolean Reg_state_outPins[Reg_pins]; // массив состояний пинов

#define THERMOCOUPLES_NUM 8

namespace thermocouples
{
    void init();
    void read_all_temp_once();
    void read_all_temp();
    void read_one_temp_point();
    void stop_reading_temp();
}

