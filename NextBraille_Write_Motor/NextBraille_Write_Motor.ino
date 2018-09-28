int myPins[] = {11, 10, 9, 6, 5, 3};

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  for (int i=0; i < (sizeof(myPins)/sizeof(myPins[0])) ; i++){
    pinMode(myPins[i],1);
   }
  
}

void loop() {
  // put your main code here, to run repeatedly:

  int write_value = 100;

  String characters;


   if (Serial.available() > 0) {
        
    // read the incoming characters
    characters = Serial.readString();

    // say what you got
    Serial.println(characters);

    
   for(int i =0; i<characters.length(); i++){
    
     if (characters[i] == '1'){
        
        analogWrite(myPins[i],write_value);
      }

     else{
      analogWrite(myPins[i],0);
      }
   }  


//   for (int i=0; i < (sizeof(myPins)/sizeof(myPins[0])) ; i++){
//    analogWrite(myPins[i],write_value);
//   }
 
  delay(1000);

   }
}
