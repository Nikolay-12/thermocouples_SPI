#include "thermocouples.h"
#include "74HC595_register_and_MAX6675_thermocouple.h"
#include <SPI.h>
namespace HC595 = register_74HC595;
namespace MAX6675 = thermocouple_MAX6675;

namespace thermocouples
{
  struct instance_t
  {
    float temp_celsius;
  };
  instance_t instances[THERMOCOUPLES_NUM];

  void init() 
  {
    HC595::setting_up_reg_pins();
    MAX6675::setting_pin_values_for_SPI();
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    HC595::set_11111111_in_reg();
  }

  void read_all_temp_once() 
  {
    HC595::add_0_to_reg();
    instances[0].temp_celsius = MAX6675::readCelsius();
    for (size_t i = 1; i <= THERMOCOUPLES_NUM - 1; i++) {
      HC595::shift_and_save_0_in_reg();
      instances[i].temp_celsius = MAX6675::readCelsius();
    }
  }
  void read_all_temp() 
  {
    void read_all_temp_once();
  }

  void read_temp_from_one_thermocouple_once(uint8_t thermocouple_index) 
  {
    HC595::set_bit_on_DS_pin(LOW);
    HC595::shift_bit_in_reg();
    HC595::set_bit_on_DS_pin(HIGH);
    if (thermocouple_index - 1 == 0)
    {
      HC595::save_data_in_reg();
      instances[0].temp_celsius = MAX6675::readCelsius();
    }
    else
    {
      for (size_t i = 1; i <= thermocouple_index - 1; i++) {
        HC595::shift_bit_in_reg();
        HC595::save_data_in_reg();
        instances[i].temp_celsius = MAX6675::readCelsius();
      }
    }
  }
  void read_temp_from_one_thermocouple(uint8_t thermocouple_index) 
  {
    void read_temp_from_one_thermocouple_once(uint8_t thermocouple_index);
  }

  void stop_reading_temp()
  {
    HC595::set_11111111_in_reg();
  }

  double get_temp_celsius(uint8_t thermocouple_index)
  {  
    if (thermocouple_index >= THERMOCOUPLES_NUM) return NAN;
    return instances[thermocouple_index].temp_celsius;
  }
}
