#include <SPI.h>

#define Reg_num 2 // кол-во регистров
#define Reg_pins Reg_num * 8 // Общее кол-во пинов на всех регистрах
boolean Reg_state_outPins[Reg_pins]; // массив состояний пинов


#define NANO_CLK_PIN 13 // Пин SCK термопар
#define NANO_MISO_PIN 12 // ПИН MISO термопар
#define HC595_DS_PIN 2 // Пин данных для сдвиговых регистов ("путешествующий ноль")
#define HC595_STcp_PIN 3 // Пин для защелкивания выходов сдвиговых регистов
#define HC595_SHcp_PIN 4 // Пин тактовых импульсов для сдвиговых регистов

#define THERMOCOUPLES_NUM 8

namespace thermocouples
{
    void init();
    void read_all_temp();
}

