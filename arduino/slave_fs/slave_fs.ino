#include <SPI.h>
#include <SD.h>
#define MAX_PATH 64

#define DEBUG
//#define MY_SERIAL

// Software spi pins
const byte pinClk = 5;
const byte pinMosi = 6;
const byte pinMiso = 7;

// Command type
const int CMD_NB_GROUPS    =   0x02;
const int CMD_GROUP        =   0x03;
const int CMD_NB_PATTERNS  =   0x04;
const int CMD_PATTERN_NAME =   0x05;
const int CMD_PATTERN      =   0x06;

const int CMD_INIT = 0x1;

// Error message
const int RET_ERR = 0x0;
const int RET_OK  = 0x1;

// using of SPI
// see examples to know pins (11,12,13)

// Cubicle dir
File Cubicle_dir;

void setup() {
        
        // Setup software spi
	pinMode(pinClk, INPUT);
	pinMode(pinMosi, INPUT);
	pinMode(pinMiso, OUTPUT);

        // Serial for debug purposes
        #ifdef DEBUG
	Serial.begin(9600);
        #endif
}

int getClk() {
  // active at high
   return digitalRead(pinClk);
}

// wait Low clock
void wLClk() {
	while (getClk());
}

void wHClk() {
	while (!getClk());
}

// wait Falling clock
void wFClk() {
	wHClk();
	wLClk();
}

// wait Rising clock
void wRClk() {
	wLClk();
	wHClk();
}

int recv4() {
	int data = 0;
	
        #ifdef MY_SERIAL
        while (Serial.available() == 0);
        data = Serial.read();
        return data-'0';
        #else
	wLClk();
	for (int i=0; i<4;i++) {
		wRClk();
		int bit = digitalRead(pinMosi);
		data = (data << 1) | bit;
                
	}
 	return data;
        #endif
}

int recv8() {
	int h = recv4();
	int l = recv4();
	return (h<<4) | l;
}

void send4(int data) {
  //Serial.print("send4 d=");
  //Serial.println(data);
  //*
  #ifndef MY_SERIAL
	wLClk();
	for (int i=0; i<4;i++) {
                int b = (data & 0x8) >> 3;
		digitalWrite(pinMiso, b);
		data <<= 1;
                //Serial.print("send4 b");
                //Serial.println(b);
		wFClk();
	}
  #endif
  //*/
}

void send8(int data) {
        //Serial.print("send8 d=");
        //Serial.println(data);
	send4((data & 0xF0) >> 4);
	send4(data & 0x0F);
}

void recvString(char *buffer) {
	int i=0;
	do {
		buffer[i] = recv8();
		i++;
	} while (buffer[i-1] != '\0');
        #ifdef DEBUG
	Serial.print("recv String: '");
	Serial.print(buffer);
        Serial.println("'");
        #endif
}

void sendString(const char *buffer) {
        #ifdef DEBUG
        Serial.print("send String: '");
        Serial.print(buffer);
        Serial.println("'");
        #endif
	int i=0;
	do {
		send8(buffer[i]);
		i++;
	} while(buffer[i-1]);
}

File current_group;
int current_group_num;
int current_group_num_patterns;

int count_groups()
{
  Cubicle_dir.rewindDirectory();
   if (Cubicle_dir) {
     int count = 0;
     while(true) {
       File entry = Cubicle_dir.openNextFile();
       if (! entry) {
         break; // No more groups
       }
       if (entry.isDirectory()){
         count++;
       }
       entry.close();
     }
     return count;
   } else {
     return -1;
   }
}

int count_patterns(File group)
{
  group.rewindDirectory();
  int count = 0;
  
  while(true) {
    File entry = group.openNextFile();
    if (!entry){
      break;
    }
    if (!entry.isDirectory()) {
      count++;
    }
    entry.close();
  }
  
  return count;
}

File get_pattern(int num)
{
  File entry;
  current_group.rewindDirectory();
  int i=0;
  do {
    entry = current_group.openNextFile();
    i++;
  } while(i<=num);
  return entry;
}

void update_current_group_name(int num)
{
  Cubicle_dir.rewindDirectory();
  int i=0;
  do {
    File entry = Cubicle_dir.openNextFile();
    current_group = entry;
    i++;
  } while(i<=num);
}

void s_command() {
    int command;
    while (true) {
        #ifdef DEBUG
        Serial.println("wait for command");
        #endif
	command = recv4();

	if (command == CMD_NB_GROUPS) {
  
                int response = count_groups();
                send8(response);
                #ifdef DEBUG
		Serial.print("received CMD_NB_GROUPS and sent ");
                Serial.println(response);
                #endif
                
	} else if (command == CMD_GROUP) {
  
		current_group_num = recv8();
                update_current_group_name(current_group_num);
                sendString(current_group.name());
                #ifdef DEBUG
		Serial.print("received CMD_GROUP ");
                Serial.print(current_group_num);
                Serial.print(" and sent ");
                Serial.println(current_group.name());
                #endif
                
        } else if (command == CMD_NB_PATTERNS) {
                
                current_group_num_patterns = count_patterns(current_group);
                send8(current_group_num_patterns);
                #ifdef DEBUG
                Serial.print("received CMD_NB_PATTERNS and sent ");
                Serial.println(current_group_num_patterns);
                #endif
                
        } else if (command == CMD_PATTERN_NAME) {
          
                int pattern_num = recv8();
                File pattern = get_pattern(pattern_num);
                #ifdef DEBUG
                Serial.print("received CMD_PATTERN_NAME and sent ");
                #endif
                sendString(pattern.name());
                
        } else if (command == CMD_PATTERN) {
          
                int pattern_num = recv8();
                File pattern = get_pattern(pattern_num);
                #ifdef DEBUG
                Serial.print("Sending content of ");
                Serial.print(pattern.name());
                Serial.print(" of size ");
                Serial.println(pattern.size());
                long t1=millis();
                #endif
                
                while(pattern.available()) {
                  char data = pattern.read();
                  send8(data);
                }
                send8(0);
                
                #ifdef DEBUG
                long t2=millis();
                Serial.print("Transfert time dt = ");
                Serial.print(t2-t1);
                Serial.println(" milliseconds");
                Serial.print("received CMD_PATTERN ");
                Serial.println(pattern_num);
                #endif
                
	} else if (command == CMD_INIT) {
  
                #ifdef DEBUG
		Serial.println("receive INIT");
                #endif
		if (SD.begin(4)) {
                        Cubicle_dir = SD.open("Cubicle");
                        if (Cubicle_dir) {
                           #ifdef DEBUG
                           Serial.println("Init successfull");
                           #endif
                           send4(RET_OK);
                        } else {
                           #ifdef DEBUG
                           Serial.println("Init failure Cubicle dir not found");
                           #endif
                           send4(RET_ERR);
                        }
			
		} else {
			send4(RET_ERR);
                        #ifdef DEBUG
                        Serial.println("Init failure initialising sd card");
                        #endif
		}

	}

    }
}

void loop() {
	s_command();
}
