#include <SoftwareSerial.h>
#include "VoiceRecognitionV3.h"
#include "Arduino.h"
#include "DFRobotDFPlayerMini.h"

bool HEY_ELI = false;
bool play_music = false;
bool stop_music = false;
bool remedy = false;
bool symptoms = false;
bool emergency_number = false;
bool food_choices = false;
bool riddle = false;
bool podcast = false;
bool stories = false;
bool quotes = false;

DFRobotDFPlayerMini myDFPlayer;
VR myVR(6, 7);
uint8_t buf[64];

void stop_music_commands(); // Declaration of stop_music_commands function

void setup() {
  /** initialize */
  myVR.begin(9600);
  Serial.begin(9600);

  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (!myDFPlayer.begin(Serial)) {  // Initialize the DFPlayer Mini using hardware serial
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while (true);  // Wait indefinitely if DFPlayer Mini initialization fails
  } else {
    Serial.println("DFPlayer Mini initialized successfully.");
    myDFPlayer.volume(25); // Set volume to 30 (adjust as needed)
    myDFPlayer.playMp3Folder(8); // Turn on
  }

  myVR.load((uint8_t)0);   // "Hey Eli" command is saved on position 0
}

void loop() {
  int ret;
  ret = myVR.recognize(buf, 50);

  if (ret > 0) {
    if (buf[1] == 0) { // "Hey Eli" command
      HEY_ELI = true;
      myDFPlayer.playMp3Folder(1); // Voice confirmation
      Serial.println("Hey Eli");
      myVR.clear();          // Clear previous commands
      myVR.load((uint8_t)1); // Load play command
      myVR.load((uint8_t)2); // Load stop command
      myVR.load((uint8_t)183); 
      myVR.load((uint8_t)193);
      myVR.load((uint8_t)190);
      myVR.load((uint8_t)120);
      myVR.load((uint8_t)224);
      myVR.load((uint8_t)204);
      myVR.load((uint8_t)223);
    }
    if (HEY_ELI) {
      if (buf[1] == 1) { // "Play_music" command
        myDFPlayer.playMp3Folder(3);
        Serial.println("Play");
        play_music = true;
        myVR.clear();
        myVR.load((uint8_t)7); // Load lofi command
        myVR.load((uint8_t)8); // Load nature command
        myVR.load((uint8_t)9); // Load chill command
        myVR.load((uint8_t)206); // Load Bruno mars command
        myVR.load((uint8_t)215); // Load cigarettes command
        myVR.load((uint8_t)212); // Load december avenue command
        myVR.load((uint8_t)218); // Load eraserhead command   
        myVR.load((uint8_t)205); // Load hit vibe music command
        myVR.load((uint8_t)214); // Load silent sanctuary command
        myVR.load((uint8_t)216); // Load Taylor swift command
        myVR.load((uint8_t)217); // Load parokya ni edgar command
      }
      if (buf[1] == 2) { // "Stop" command
        myDFPlayer.playMp3Folder(7);
        Serial.println("Stopping Music");
        myVR.clear();
        myVR.load((uint8_t)0);
      }
    
      if (buf[1] == 183) { // "Remedy" command
        myDFPlayer.playMp3Folder(49);
        Serial.println("Remedy");
        remedy = true;
        myVR.clear();
        myVR.load((uint8_t)182); // Load Vomiting Medication Command
        myVR.load((uint8_t)181); // Load tooth Decay medication Command      
        myVR.load((uint8_t)180); // Load allergic rhinitis medication Command
        myVR.load((uint8_t)179); // Load UTI medication Command
        myVR.load((uint8_t)178); // Load high cholesterol medication Command
        myVR.load((uint8_t)177); // Load constipation medication Command
        myVR.load((uint8_t)176); // Load sore throat medication Command
        myVR.load((uint8_t)175); // Load burn medication Command
        myVR.load((uint8_t)174); // Load Chicken pox medication Command
        myVR.load((uint8_t)173); // Load cough medication Command
        myVR.load((uint8_t)172); // Load diarrhea  medication Command
        myVR.load((uint8_t)171); // Load flu medication Command
        myVR.load((uint8_t)170); // Load chest pain medication Command
        myVR.load((uint8_t)169); // Load indigestion medication Command
        myVR.load((uint8_t)168); // Load abdominal medication Command
        myVR.load((uint8_t)167); // Load arthritis medication Command
      }
      if (buf[1] == 193) { // "Emergency" command
        myDFPlayer.playMp3Folder(47);
        Serial.println("Emergency");
        emergency_number = true;
        myVR.clear();
        myVR.load((uint8_t)192); // Load ambulance command
        myVR.load((uint8_t)191); // Load Police command
        myVR.load((uint8_t)165); // Load Firefighter command
      }
      if (buf[1] == 190) { // "Foods" command
        myDFPlayer.playMp3Folder(37);
        Serial.println("Foods");
        food_choices = true;
        myVR.clear();
        myVR.load((uint8_t)189); // Load sweets Command
        myVR.load((uint8_t)188); // Load Dish Command
        myVR.load((uint8_t)187); // Load Snacks Command
        myVR.load((uint8_t)186); // Load drinks Command
        myVR.load((uint8_t)185); // Load soup Command
        myVR.load((uint8_t)184); // Load fruit Command
      }
      
      if (buf[1] == 120) { // "Quotes" command
        myDFPlayer.playMp3Folder(641);
        Serial.println("quotes");
        quotes = true;
        myVR.clear();
        myVR.load((uint8_t)246); // Load One Command
        myVR.load((uint8_t)245); // Load Two Command
        myVR.load((uint8_t)244); // Load Three Command
        myVR.load((uint8_t)243); // Load Four Command
        myVR.load((uint8_t)242); // Load Five Command
        myVR.load((uint8_t)241); // Load Six Command
        myVR.load((uint8_t)240); // Load Seven Command
        myVR.load((uint8_t)239); // Load Eight Command
        myVR.load((uint8_t)238); // Load NineCommand
        myVR.load((uint8_t)237); // Load Ten Command
        myVR.load((uint8_t)236); // Load Eleven Command
        myVR.load((uint8_t)235); // Load Twelve Command
        myVR.load((uint8_t)234); // Load Thirteen Command
        myVR.load((uint8_t)233); // Load Fourteen Command
        myVR.load((uint8_t)232); // Load Fifteen Command
        myVR.load((uint8_t)231); // Load Sixteen Command
        myVR.load((uint8_t)230); // Load Seventeen Command
        myVR.load((uint8_t)229); // Load Eighteen Command
        myVR.load((uint8_t)228); // Load Nineteen Command
        myVR.load((uint8_t)227); // Load Twenty Command
}
      if (buf[1] == 224) { // "Ask me" command
        myDFPlayer.playMp3Folder(642);
        Serial.println("Ask me");
        riddle = true;
        myVR.clear();
        myVR.load((uint8_t)246); // Load One Command
        myVR.load((uint8_t)245); // Load Two Command
        myVR.load((uint8_t)244); // Load Three Command
        myVR.load((uint8_t)243); // Load Four Command
        myVR.load((uint8_t)242); // Load Five Command
        myVR.load((uint8_t)241); // Load Six Command
        myVR.load((uint8_t)240); // Load Seven Command
        myVR.load((uint8_t)239); // Load Eight Command
        myVR.load((uint8_t)238); // Load NineCommand
        myVR.load((uint8_t)237); // Load Ten Command

      } if (buf[1] == 204) { // "podcast" command
        myDFPlayer.playMp3Folder(643);
        Serial.println("podcast");
        podcast = true;
        myVR.clear();
        myVR.load((uint8_t)196); // Load am i toxic command
        myVR.load((uint8_t)195); // Load wala ng spark command
        myVR.load((uint8_t)194); // Load TOTGA command
        myVR.load((uint8_t)203); // Load anxiety command
        myVR.load((uint8_t)202); // Load saving relationship command
        myVR.load((uint8_t)201); // Load trust command
        myVR.load((uint8_t)200); // Load depress command
        myVR.load((uint8_t)199); // Load toxic pinoy parents command
        myVR.load((uint8_t)198); // Load stop overthink command
        myVR.load((uint8_t)197); // Load love vs friends command
        myVR.load((uint8_t)207); // Load random command
      }
      
      if (buf[1] == 223) { // "stories" command
        myDFPlayer.playMp3Folder(644);
        Serial.println("narrate_stories");
        stories = true;
        myVR.clear();
        myVR.load((uint8_t)221); // Load mysteries command
        myVR.load((uint8_t)220); // Load romance command
        myVR.load((uint8_t)219); // Load inspire command
      }
    }
    
    if (play_music) {
      if (buf[1] == 7) { // "Lofi" command
        myDFPlayer.playMp3Folder(4);
        Serial.println("Lofi");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 8) { // "Nature" command
        myDFPlayer.playMp3Folder(5);
        Serial.println("Nature");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 9) { // "Chill" command
        myDFPlayer.playMp3Folder(6);
        Serial.println("Chill");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 206) { // "Bruno mars" command
        myDFPlayer.playMp3Folder(100);
        Serial.println("Bruno mars");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 215) { // "cigarettes" command
        myDFPlayer.playMp3Folder(101);
        Serial.println("cigarettes");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 212) { // "December Avenue" command
        myDFPlayer.playMp3Folder(102);
        Serial.println("December Avenue");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 218) { // "Eraserhead" command
        myDFPlayer.playMp3Folder(103);
        Serial.println("eraserhead");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 205) { // "Hit Vibe Music" command
        myDFPlayer.playMp3Folder(104);
        Serial.println("Hit Vibe Music");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 214) { // "Silent sanctuary" command
        myDFPlayer.playMp3Folder(105);
        Serial.println("Silent sanctuary");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 216) { // "Taylor Swift" command
        myDFPlayer.playMp3Folder(106);
        Serial.println("Taylor Swift");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 217) { // "Parokya ni Edgar" command
        myDFPlayer.playMp3Folder(107);
        Serial.println("Parokya ni Edgar");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }
    }
    if (remedy) {
      if (buf[1] == 182) { // "Vomiting Medication" command
        myDFPlayer.playMp3Folder(51);
        Serial.println("Vomiting Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 181) { // "Tooth Decay Medication" command
        myDFPlayer.playMp3Folder(53);
        Serial.println("Tooth Decay Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 180) { // "Allergic Rhinitis Medication" command
        myDFPlayer.playMp3Folder(55);
        Serial.println("Allergic Rhinitis Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 179) { // "UTI Medication" command
        myDFPlayer.playMp3Folder(57);
        Serial.println("UTI Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 178) { // "High Cholesterol Medication" command
        myDFPlayer.playMp3Folder(59);
        Serial.println("High Cholesterol Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 177) { // "Constipation Medication" command
        myDFPlayer.playMp3Folder(61);
        Serial.println("Constipation Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 176) { // "Sore Throat Medication" command
        myDFPlayer.playMp3Folder(63);
        Serial.println("Sore Throat Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 175) { // "Burn Medication" command
        myDFPlayer.playMp3Folder(65);
        Serial.println("Burn Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 174) { // "Chicken Pox Medication" command
        myDFPlayer.playMp3Folder(67);
        Serial.println("Chicken Pox Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 173) { // "Cough Medication" command
        myDFPlayer.playMp3Folder(69);
        Serial.println("Cough Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 172) { // "Diarrhea Medication" command
        myDFPlayer.playMp3Folder(71);
        Serial.println("Diarrhea Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 171) { // "Flu Medication" command
        myDFPlayer.playMp3Folder(73);
        Serial.println("Flu Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 170) { // "Chest Pain Medication" command
        myDFPlayer.playMp3Folder(75);
        Serial.println("Chest Pain Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 169) { // "Indigestion Medication" command
        myDFPlayer.playMp3Folder(77);
        Serial.println("Indigestion Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 168) { // "Abdominal Medication" command
        myDFPlayer.playMp3Folder(79);
        Serial.println("Abdominal Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 167) { // "Arthritis Medication" command
        myDFPlayer.playMp3Folder(81);
        Serial.println("Arthritis Medication");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
  }
  
    }if (symptoms) {
      if (buf[1] == 182) { // "Vomiting Symptoms" command
        myDFPlayer.playMp3Folder(50);
        Serial.println("Vomiting Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 181) { // "Tooth Decay Symptoms" command
        myDFPlayer.playMp3Folder(52);
        Serial.println("Tooth Decay Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 180) { // "Allergic Rhinitis Symptoms" command
        myDFPlayer.playMp3Folder(54);
        Serial.println("Allergic Rhinitis Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 179) { // "UTI Symptoms" command
        myDFPlayer.playMp3Folder(56);
        Serial.println("UTI Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 178) { // "High Cholesterol Symptoms" command
        myDFPlayer.playMp3Folder(58);
        Serial.println("High Cholesterol Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 177) { // "Constipation Symptoms" command
        myDFPlayer.playMp3Folder(60);
        Serial.println("Constipation Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 176) { // "Sore Throat Symptoms" command
        myDFPlayer.playMp3Folder(62);
        Serial.println("Sore Throat Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 175) { // "Burn Symptoms" command
        myDFPlayer.playMp3Folder(64);
        Serial.println("Burn Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 174) { // "Chicken Pox Symptoms" command
        myDFPlayer.playMp3Folder(66);
        Serial.println("Chicken Pox Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 173) { // "Cough Symptoms" command
        myDFPlayer.playMp3Folder(68);
        Serial.println("Cough Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 172) { // "Diarrhea Symptoms" command
        myDFPlayer.playMp3Folder(70);
        Serial.println("Diarrhea Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 171) { // "Flu Symptoms" command
        myDFPlayer.playMp3Folder(72);
        Serial.println("Flu Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 170) { // "Chest Pain Symptoms" command
        myDFPlayer.playMp3Folder(74);
        Serial.println("Chest Pain Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 169) { // "Indigestion Symptoms" command
        myDFPlayer.playMp3Folder(76);
        Serial.println("Indigestion Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 168) { // "Abdominal Symptoms" command
        myDFPlayer.playMp3Folder(78);
        Serial.println("Abdominal Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 167) { // "Arthritis Symptoms" command
        myDFPlayer.playMp3Folder(80);
        Serial.println("Arthritis Symptoms");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
  }
    }if (emergency_number) {
      if (buf[1] == 192) { // "Ambulance" command
        myDFPlayer.playMp3Folder(44);
        Serial.println("Ambulance");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
     } else if (buf[1] == 191) { // "Police" command
        myDFPlayer.playMp3Folder(45);
        Serial.println("Police");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
     } else if (buf[1] == 165) { // "Firefighter" command
        myDFPlayer.playMp3Folder(46);
        Serial.println("Firefighter");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
  }
    }
    if (food_choices) {
      if (buf[1] == 189) { // "Sweets" command
        myDFPlayer.playMp3Folder(40);
        Serial.println("Sweets");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 188) { // "Dish" command
        myDFPlayer.playMp3Folder(43);
        Serial.println("Dish");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 187) { // "Snacks" command
        myDFPlayer.playMp3Folder(41);
        Serial.println("Snacks");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 186) { // "Drinks" command
        myDFPlayer.playMp3Folder(42);
        Serial.println("Drinks");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 185) { // "Soup" command
        myDFPlayer.playMp3Folder(38);
        Serial.println("Soup");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 184) { // "Fruit" command
        myDFPlayer.playMp3Folder(39);
        Serial.println("Fruit");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
    }
    } 
    if (quotes) {
      if (buf[1] == 246) { // "One" command
        myDFPlayer.playMp3Folder(601);
        Serial.println("One");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 245) { // "Two" command
        myDFPlayer.playMp3Folder(602);
        Serial.println("Two");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 244) { // "Three" command
        myDFPlayer.playMp3Folder(603);
        Serial.println("Three");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 243) { // "Four" command
        myDFPlayer.playMp3Folder(604);
        Serial.println("Four");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 242) { // "Five" command
        myDFPlayer.playMp3Folder(605);
        Serial.println("Five");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 241) { // "six" command
        myDFPlayer.playMp3Folder(606);
        Serial.println("Six");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 240) { // "Seven" command
        myDFPlayer.playMp3Folder(607);
        Serial.println("Seven");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 239) { // "Eight" command
        myDFPlayer.playMp3Folder(608);
        Serial.println("Eight");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 238) { // "Nine" command
        myDFPlayer.playMp3Folder(609);
        Serial.println("Nine");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }else if (buf[1] == 237) { // "Ten" command
        myDFPlayer.playMp3Folder(610);
        Serial.println("Ten");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 236) { // "Eleven" command
        myDFPlayer.playMp3Folder(611);
        Serial.println("Eleven");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 235) { // "Twelve" command
        myDFPlayer.playMp3Folder(612);
        Serial.println("Twelve");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 234) { // "Thirteen" command
        myDFPlayer.playMp3Folder(613);
        Serial.println("Thirteen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 233) { // "Fourteen" command
        myDFPlayer.playMp3Folder(614);
        Serial.println("Fourteen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 232) { // "Fifteen" command
        myDFPlayer.playMp3Folder(615);
        Serial.println("Fifteen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 231) { // "Sixteen" command
        myDFPlayer.playMp3Folder(616);
        Serial.println("Sixteen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 230) { // "Seventeen" command
        myDFPlayer.playMp3Folder(617);
        Serial.println("Seventeen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 229) { // "Eighteen" command
        myDFPlayer.playMp3Folder(618);
        Serial.println("Eighteen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 228) { // "Nineteen" command
        myDFPlayer.playMp3Folder(619);
        Serial.println("Nineteen");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 227) { // "Twenty" command
        myDFPlayer.playMp3Folder(620);
        Serial.println("Twenty");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }
      
    }if (riddle) {
      if (buf[1] == 246) { // "One" command
        myDFPlayer.playMp3Folder(621);
        Serial.println("One");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 245) { // "Two" command
        myDFPlayer.playMp3Folder(622);
        Serial.println("Two");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 244) { // "Three" command
        myDFPlayer.playMp3Folder(623);
        Serial.println("Three");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 243) { // "Four" command
        myDFPlayer.playMp3Folder(624);
        Serial.println("Four");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 242) { // "Five" command
        myDFPlayer.playMp3Folder(625);
        Serial.println("Five");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 241) { // "six" command
        myDFPlayer.playMp3Folder(626);
        Serial.println("Six");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 240) { // "Seven" command
        myDFPlayer.playMp3Folder(627);
        Serial.println("Seven");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 239) { // "Eight" command
        myDFPlayer.playMp3Folder(628);
        Serial.println("Eight");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 238) { // "Nine" command
        myDFPlayer.playMp3Folder(629);
        Serial.println("Nine");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 237) { // "Ten" command
        myDFPlayer.playMp3Folder(630);
        Serial.println("Ten");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      }
      }
      
     
     if (podcast) {
      if (buf[1] == 204) { // "podcast" command
        myDFPlayer.playMp3Folder(643);
        Serial.println("podcast");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 196) { // "am i toxic" command
        myDFPlayer.playMp3Folder(651);
        Serial.println("am i toxic");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 195) { // "wala ng spark" command
        myDFPlayer.playMp3Folder(652);
        Serial.println("wala ng spark");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 194) { // "TOTGA" command
        myDFPlayer.playMp3Folder(653);
        Serial.println("TOTGA");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 203) { // "anxiety" command
        myDFPlayer.playMp3Folder(654);
        Serial.println("anxiety");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 202) { // "saving relationship" command
        myDFPlayer.playMp3Folder(655);
        Serial.println("saving relationship");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 201) { // "trust" command
        myDFPlayer.playMp3Folder(656);
        Serial.println("trust");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 200) { // "depress" command
        myDFPlayer.playMp3Folder(657);
        Serial.println("depress");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 199) { // "toxic pinoy parents" command
        myDFPlayer.playMp3Folder(658);
        Serial.println("toxic pinoy parents");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 197) { // "love vs friend" command
        myDFPlayer.playMp3Folder(659);
        Serial.println("love vs friend");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
    }
    } 
    
    if (stories) {
      if (buf[1] == 221) { // "mysteries" command
        myDFPlayer.playMp3Folder(645);
        Serial.println("mysteries");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 220) { // "romance" command
        myDFPlayer.playMp3Folder(646);
        Serial.println("romance");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
      } else if (buf[1] == 219) { // "inspire" command
        myDFPlayer.playMp3Folder(647);
        Serial.println("inspire");
        stop_music_commands();
        myVR.clear();
        myVR.load((uint8_t)2);
        myVR.load((uint8_t)0); // Return to "Hey Eli" command
       }
      }
   }
}

void stop_music_commands() {
  play_music = false;
  stop_music = false;
  remedy = false;
  symptoms = false;
  emergency_number = false;
  food_choices = false;
  riddle = false;
  podcast = false;
  stories = false;
  quotes = false;
}
