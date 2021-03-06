#ifndef ADC_H_
#define ADC_H_


//#define ADS1248_RESET       0x20
#define ADS1248_START       0x80
#define ADS1248_DRDY        0x40
#define ADS1248_DIN         0x02
#define ADS1248_DOUT_DRDY   0x04
#define ADS1248_SCLK        0x08
#define ADS1248_CS          0x10

#define CH_0	0x07
#define CH_1	0x0F
#define CH_2	0x17
#define CH_3	0x1F
#define CH_4	0x27
#define CH_5	0x2F
#define CH_6	0x37
#define CH_7	0x37




#define ADS1248_MUX0_REGISTER    0x00
#define ADS1248_VBIAS_REGISTER   0x01
#define ADS1248_MUX1_REGISTER    0x02
#define ADS1248_SYS0_REGISTER    0x03
#define ADS1248_OFC0_REGISTER    0x04
#define ADS1248_OFC1_REGISTER    0x05
#define ADS1248_OFC2_REGISTER    0x06
#define ADS1248_FSC0_REGISTER    0x07
#define ADS1248_FSC1_REGISTER    0x08
#define ADS1248_FSC2_REGISTER    0x09
#define ADS1248_IDAC0_REGISTER   0x0A
#define ADS1248_IDAC1_REGISTER   0x0B
#define ADS1248_GPIOCFG_REGISTER 0x0C
#define ADS1248_GPIODIR_REGISTER 0x0D
#define ADS1248_GPIODAT_REGISTER 0x0E


#define ADS1248_CMD_WAKEUP    0x01
#define ADS1248_CMD_SLEEP     0x02
#define ADS1248_CMD_SYNC      0x04
#define ADS1248_CMD_RESET     0x06
#define ADS1248_CMD_NOP       0xFF
#define ADS1248_CMD_RDATA     0x12
#define ADS1248_CMD_RDATAC    0x14
#define ADS1248_CMD_SDATAC    0x16
#define ADS1248_CMD_RREG      0x20
#define ADS1248_CMD_WREG      0x40
#define ADS1248_CMD_SYSOCAL   0x60
#define ADS1248_CMD_SYSGCAL   0x61
#define ADS1248_CMD_SELFOCAL  0x62
#define TS12A_CH8_SELECT 	  0x10
#define TS12A_CH7_SELECT 	  0xEF
#define BUFFER_SIZE  4000

void ADC_Setup();

void ADS1248AssertCS( int fAssert);
int ADS1248SPIInit(void);
int ADS1248CargaInicial(char chansel);

int ADS1248WriteRegister(int StartAddress, int NumRegs);
void ADS1248ReadRegister();
long ADS1248ReadData();
int ADS1248SendResetCommand(void);
void ADS1248Stop(void);
void adc_reading(int i);
void ADS1248INIT();
void ADC_Setup(void);
interrupt void ADC12ISR (void);
void switching();
void rtdcurrsel(int i);
void crRTD(int i,int cr);
void cr420(int i,int cr);
void crthermo(int i,int cr);

extern long value[8];
extern signed int firstch_data, secondch_data, thirdch_data, fourthch_data,ret;
extern char channel[8],c[8];
extern char ambient_temp,ambient_flag;
extern char dispat,active;

#endif /*ADC_H_*/
