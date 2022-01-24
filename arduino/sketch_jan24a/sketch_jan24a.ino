#include "WiFi.h"
#include <Firebase_ESP_Client.h>

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

  /* Assign the api key (required) */
  config.api_key = API_KEY;

   /* Assign the user sign in credentials */
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);

  //Comment or pass false value when WiFi reconnection will control by your code or third party library
  Firebase.reconnectWiFi(true);

  Firebase.setDoubleDigits(5);

  Serial.println("Setup end");
  
}
void loop() {
  delay(5000);
  Serial.printf("Set int... %s\n", Firebase.RTDB.setInt(&fbdo, "/test/int", count++) ? "ok" : fbdo.errorReason().c_str());
}
