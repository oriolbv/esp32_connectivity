#include "WiFi.h"
#include <Firebase_ESP_Client.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert Firebase project API Key
#define API_KEY "AIzaSyAoaOHW5Ub1yxZy5K4MHiTnT0LBSVTYHVA"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://vobu-test-default-rtdb.europe-west1.firebasedatabase.app/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long dataMillis = 0;

unsigned long count = 0;
bool signupOK = false;

unsigned long myTime;

/* 4. Define the user Email and password that alreadey registerd or added in your project */
#define USER_EMAIL "oriolbv@gmail.com"
#define USER_PASSWORD "gasgas"


void setup() {
  Serial.begin(115200);
  /* Set ESP32 to WiFi Station mode */
  WiFi.mode(WIFI_AP_STA);
  /* start SmartConfig */
  WiFi.beginSmartConfig();

  /* Wait for SmartConfig packet from mobile */
  Serial.println("Waiting for SmartConfig.");
  while (!WiFi.smartConfigDone()) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("SmartConfig done.");

  /* Wait for WiFi to connect to AP */
  Serial.println("Waiting for WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi Connected.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());




  
  /* Assign the api key (required) */
  //config.api_key = API_KEY;

   /* Assign the user sign in credentials */
  //auth.user.email = USER_EMAIL;
  //auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  //config.database_url = DATABASE_URL;

  /* Sign up */
  //if (Firebase.signUp(&config, &auth, "", "")){
  //  Serial.println("ok");
  //  signupOK = true;
  //}
  //else{
  //  Serial.printf("%s\n", config.signer.signupError.message.c_str());
  //}

  /* Assign the callback function for the long running token generation task */
  //config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  //Firebase.begin(&config, &auth);

  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  //Firebase.reconnectWiFi(true);

  //Firebase.setDoubleDigits(5);

  Serial.println("Setup end");
  
}
void loop() {
  ArduinoOTA.handle();
  Serial.println("Test2");
  //delay(5000);
  //myTime = millis();
  //String hola = "/test/"+ (String)myTime +"/temperature_degrees";
  //Serial.printf("Set temperature... %s\n", Firebase.RTDB.setInt(&fbdo, hola, random(-20, 48)) ? "ok" : fbdo.errorReason().c_str());
  //Serial.printf("Set humidity... %s\n", Firebase.RTDB.setInt(&fbdo, "/test/humidity", random(1, 100)) ? "ok" : fbdo.errorReason().c_str());
  //Serial.printf("Set ppp... %s\n", Firebase.RTDB.setFloat(&fbdo, "/test/ppp", random(1, 99) / 100.0) ? "ok" : fbdo.errorReason().c_str());
}
