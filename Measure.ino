#include <ESP8266WiFi.h>
//#include <Mux.h>
#define ARDUINO_WORK_VOLTAGE 3.7

String apiKey = "ARYJHZTX48RV17I9";     // Write API key from ThingSpeak

const char *ssid =  "RAWAN 2744";     
const char *pass =  "70413,bE";
const char* server = "api.thingspeak.com";

String channelID = "1613328";

WiFiClient client;


#define MUX_A 4
#define MUX_B 3
#define MUX_C 2


#define ANALOG_INPUT A0


void setup()
{

   //Deifne output pins for Mux
  pinMode(MUX_A, OUTPUT);
  pinMode(MUX_B, OUTPUT);     
  pinMode(MUX_C, OUTPUT);   
    
  Serial.begin(115200);  // opens serial port, sets data rate to 115200 bps
  delay(10);

  Serial.println("Connecting to ");
  Serial.println(ssid);


  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");


}

void changeMux(int c, int b, int a) {
  digitalWrite(MUX_A, a);
  digitalWrite(MUX_B, b);
  digitalWrite(MUX_C, c);
}

void loop()
{


  max471();

 
}

void max471()
{ 
    changeMux(LOW, LOW, LOW);
   int vt_test = analogRead(ANALOG_INPUT);
   
   changeMux(LOW, LOW, HIGH);
  int at_test = analogRead(ANALOG_INPUT);
  
  double voltage = (vt_test * (ARDUINO_WORK_VOLTAGE / 1023.0) * 3);
  double current =at_test * (ARDUINO_WORK_VOLTAGE / 2600.0);
 double POWER = voltage * current ;
  
Serial.print("Voltage= " + (String)voltage + "V  ");
  Serial.print("Current= " + (String)current + "A  ");
   Serial.print("POWER= " + (String)POWER + "W ");

  delay(10);
   if (client.connect(server, 80))  //   api.thingspeak.com
  {
    
      String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(current);
    postStr += "\r\n\r\n";

    String postStr2 = apiKey;
    postStr2 += "&field2=";
    postStr2 += String(voltage);
    postStr2 += "\r\n\r\n";
   
    String postStr3= apiKey;
    postStr3 += "&field3=";
    postStr3 += String(POWER );
    postStr3 += "\r\n\r\n";

client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);
    
 
    client.print(postStr2.length());
        client.print("\n\n");
     client.print(postStr2);


    client.print(postStr3);
        client.print("\n\n");
    client.print(postStr3.length());  
   
  }
  client.stop();

  Serial.println("Waiting...");

  // thingspeak needs minimum 15 sec delay between updates
  delay(20);
}
