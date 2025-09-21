#pragma once

#define THERMOCOUPLES_NUM 8

namespace thermocouples
{
    void init();
    void read_all_temp_once();
    void read_all_temp();
    void read_temp_from_one_thermocouple_once(uint8_t thermocouple_index);
    void read_temp_from_one_thermocouple(uint8_t thermocouple_index);
    void stop_reading_temp();
    double get_temp_celsius(uint8_t thermocouple_index);
}

