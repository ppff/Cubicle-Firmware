const byte pinClk = 5;
const byte pinMosi = 6;
const byte pinMiso = 7;


const int COMMAND=	0x01;
const int LS=		0x02;
const int CAT=		0x03;
const int DATA=	0x04;

const int CMD_LS = 0x2;
const int CMD_CAT = 0x3;
const int CMD_INIT = 0x4;

const int RET_ERR = 0x0;
const int RET_OK  = 0x1;

// using of SPI
// see examples to know pins (11,12,13)

#define MAX_PATH 64

int state;

#include <SPI.h>
#include <SD.h>

void setup() {
  // put your setup code here, to run once:

	pinMode(pinClk, INPUT);
	pinMode(pinMosi, INPUT);
	pinMode(pinMiso, OUTPUT);

	Serial.begin(9600);
	Serial.println("Waiting for master");
	state = COMMAND;
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
	
	wLClk();
	for (int i=0; i<4;i++) {
		wRClk();
		int bit = digitalRead(pinMosi);
		data = (data << 1) | bit;
                Serial.print("recv4 b");
                Serial.println(bit);
	}
	Serial.print("recv4 ");
	Serial.println(data);
	return data;
}

int recv8() {
	int h = recv4();
	int l = recv4();
	return (h<<4) | l;
}

void send4(int data) {
  Serial.print("send4 d=");
  Serial.println(data);
	wLClk();
	for (int i=0; i<4;i++) {
                int b = (data & 0x8) >> 3;
		digitalWrite(pinMiso, b);
		data <<= 1;
                Serial.print("send4 b");
                Serial.println(b);
		wFClk();
	}
}

void send8(int data) {
	send4((data & 0xF0) >> 4);
	send4(data & 0x0F);
}

void recvString(char *buffer) {
	int i=0;
	do {
		buffer[i] = recv8();
		i++;
	} while (buffer[i-1] != '\0');
	Serial.print("recv String: '");
	Serial.print(buffer);
        Serial.println("'");
}

void sendString(const char *buffer) {
        Serial.print("send String: '");
        Serial.print(buffer);
        Serial.println("'");
	int i=0;
	do {
		send8(buffer[i]);
		i++;
	} while(buffer[i-1]);
}


void s_command() {

        Serial.println("wait cmd");
	int command = recv4();

	if (command == CMD_LS) {
		state = LS;
		Serial.println("receive LS");
	} else if (command == CMD_CAT) {
		state = CAT;
		Serial.println("receive CAT");
	} else if (command == CMD_INIT) {
		Serial.println("receive INIT");

		if (SD.begin(4)) {
			send4(RET_OK);
		} else {
			send4(RET_ERR);
		}
	}
}

void s_ls() {

	char buffer[MAX_PATH];
	recvString(buffer);

	// find dir and list files
	if (strcmp(buffer, "/")==0) {
		Serial.println("list /");
		// dir separates by ':', if a file ends with '/',
		// it is a dir.
		strcpy(buffer, "/group1/:/a.txt:/group2/:/b");
		sendString(buffer);
	}

	state = COMMAND;
}

void s_cat() {
	char buffer[MAX_PATH];
	recvString(buffer);

	if (strcmp(buffer, "/b")==0) {
		Serial.println("cat b");
		strcpy(buffer, "plop plop");
		sendString(buffer);
	}

	state = COMMAND;
}

void s_data() {

}

void loop() {
	if (state == COMMAND) {
		s_command();
	} else if (state == LS) {
		s_ls();
	} else if (state == CAT) {
		s_cat();
	} else if (state ==	DATA) {
		s_data();
	}
}
