
// void I2C_Sen_Init(void);
// void HibernateHandler(void);
// void SleepModeInit(void);
// void I2C_Sen_Read(unsigned char *pucData, unsigned long ulOffset, unsigned long ulCount);
// void I2C_Sen_Write(unsigned char *pucData, unsigned long ulOffset, unsigned long ulCount);

void SHT_Init(unsigned char resolution);
void SHT_ResetConection(void);
unsigned char SHT_WriteByte(unsigned char Data);
unsigned char SHT_ReadByte(unsigned char ack);
unsigned int SHT_ReadSenSor(unsigned char Command);
void SHT_ReadTemHumi(float *tem, float *humi);


#define SHT_NOACK 0
#define SHT_ACK 1
#define SHT_STATUS_REG_W 0x06 //0000 0110
#define SHT_STATUS_REG_R 0x07 //0000 0111
#define SHT_MEASURE_TEMP 0x03 //0000 0011
#define SHT_MEASURE_HUMI 0x05 //0000 0101
#define SHT_RESET 0x1E //0001 1110
#define SHT_14_12_BIT 0x00// c?u hình nhi?t d? 14bit, d? ?m 12bit
#define SHT_12_8_BIT 0x01// c?u hình nhi?t d? 12bit, d? ?m 8bit

//Cac hang so voi do phan giai 14 va 12 bit[/B]
#define H_C1 -4.0
#define H_C2 0.0405
#define H_C3 -0.0000028
#define H_D1 -40.00
#define H_D2 0.01
#define H_T1 0.01
#define H_T2 0.00008

//Cac hang so voi do phan giai 12 va 8 bit[/B]
#define L_C1 -4.0
#define L_C2 0.648
#define L_C3 -0.00072
#define L_D1 -40.00
#define L_D2 0.04
#define L_T1 0.01
#define L_T2 0.00128