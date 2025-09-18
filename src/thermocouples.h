#pragma once

#define THERMOCOUPLES_NUM 8

namespace thermocouples
{
    void init();
    void read_all_temp_once();
    void read_all_temp();
    void read_one_temp_point();
    void stop_reading_temp();
    float get_temp_celsius(thermocouple_index);
}

