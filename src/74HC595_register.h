#pragma once

#include <SPI.h>

#define NANO_CLK_PIN 13 // Пин SCK термопар
#define NANO_MISO_PIN 12 // ПИН MISO термопар
#define HC595_DS_PIN 2 // Пин данных для сдвиговых регистов ("путешествующий ноль")
#define HC595_STcp_PIN 3 // Пин для защелкивания выходов сдвиговых регистов
#define HC595_SHcp_PIN 4 // Пин тактовых импульсов для сдвиговых регистов

namespace 74HC595
{
  void set_bit_to_reg(HC595_DS_PIN, bit);
  void shift_bit_in_reg(HC595_SHcp_PIN);
  void save_data_in_reg(HC595_STcp_PIN);
}
