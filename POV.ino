#include<SPI.h>

int nch=5;

//int SS = 10;  // pin 10 is by default the slave select pin
void setup()
{
  pinMode(SS,OUTPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
  SPI.begin();
}

  // make the character array of what name you want to show and add '/' at the end as the last element
char atmos[7]={'A','T','M','O','S','/'};
char arc[13]={' ',' ',' ',' ',' ',' ',' ',' ','A','R','C',' ','/'};
char in[4]={'I','N',' ','/'};

void Send_data(unsigned char c)  // it sends a number to the shift register to show the pattern of leds glowing as a binary number
{
  digitalWrite(SS,LOW);                               // led numbering 7 6 5 4 3 2 1 0   0=off=0 *=on=1
  SPI.transfer(c);                                    // sending 4 =   0 0 0 0 0 * 0 0   binary value = 100
  digitalWrite(SS,HIGH);                              // sending 223 = * * 0 * * * * *   binary value = 11011111
}                                                     // sending 255 = * * * * * * * *   binary vaue = 11111111


// data base of characters from A to Z and last charcter is space
unsigned char data_base[27][5]={ {252,18,17,18,252}, // A
                             {255,145,145,145,254},  // B
                             {126,129,129,129,129}, // C 
                             {255,129,129,129,126}, // D
                             {255,137,137,137,129}, // and so on
                             {255,9,9,9,1},
                             {255,129,145,145,243},
                             {255,8,8,8,255},
                             {195,129,255,129,195},
                             {195,129,255,1,3},
                             {255,40,68,130,129},
                             {255,128,128,128,128},
                             {255,1,6,1,255},
                             {255,4,8,32,255},
                             {255,129,129,129,255},
                             {255,17,17,17,31},
                             {126,129,161,193,254},
                             {255,49,81,145,159},    //R                                                                      //R            formation of R
                             {159,145,145,145,241},                                                                           //                 255 = 11111111  first showing 159,049,081,145,159
                             {2,1,255,1,2},                                                                                   //                 049 = 00110001    1 0 0 1 1
                             {127,128,128,128,127},                                                                           //                 081 = 01010001    1 0 1 0 0
                             {63,64,128,64,63},                                                                               //                 145 = 10010001    1 1 0 0 0
                             {255,32,8,32,255},                                                                               //                 159 = 10011111    1 1 1 1 1     and that is an inverted R
                             {129,36,8,38,129},                                                                               //                                   1 0 0 0 1     to make it MOST SPI uses MSBFIRST by default
                             {128,36,8,36,1},                                                                                 //                                   1 0 0 0 1     i.e. most significnt bit is first to be pushed out from SPI communication
                             {131,161,137,133,193},                                                                           //                                   1 0 0 0 1     so MSB is pushed to the end and LSB is seen st the top
                             {0,0,0,0,0}   };                                                                                 //                                   1 1 1 1 1     hence the image visible is inverted
                           
// data 



int d=300; // delay controls character width
          
void send_char(char c) // this function sends the array of numbers creating a screen of a character
{
  int i;
   for(i=0;i<5;i++)  // each character is formed of 5 strips
   {
     if(c!=' ')
     {
      Send_data(data_base[((unsigned char)c)-'A'][i]);   // 0 - 25 is A - Z alphabets
     }
     else
     {
       Send_data(data_base[26][i]);  // 26th elecment in database 
     }
      delayMicroseconds(d);  // this delay controls character width
   }
   Send_data(0); // a blank strip is sent after every character for creating character spacings
   delay(1);    // this delay controls character spacing
}

int j=0;

void show_char_arr(char* c) // takes in an char array that is to be shown on pov
{
  
  for(j=0;(*(c+j))!='/';j++)  // '/'  is the end of string and is not to be shown 
  {
    send_char(*(c+j));  
  }
  
  
 
}



void loop()
{
  show_char_arr(arc);
  show_char_arr(atmos);   // just call show_char_arr( <name of array that you want to show> );  
                          // following code will show "ARC ATMOS" on the rotating stick
  
  
  
  // execute this while loop at the end of each loop to ensure that the pattern appears only after completion of one revolution
  while(pulseIn(9,LOW)==0)
  {
  }
   
}
  
