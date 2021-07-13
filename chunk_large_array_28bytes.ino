/*
 * Author: Juan Pablo Gomez
 * Date: July 2021
 * 
 * This code takes a large array and break it in chunks of 28bytes, so they can be
 * send via RF with an NRF24L01+ module
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 */

//large array
char dummy_text[] = "Virgin Galactic owner Richard Branson rocketed into space Sunday, an edge-of-the-seat sub-orbital test flight intended to demonstrate his company's air-launched spaceplane is ready for passengers who can afford the ultimate thrill ride. And it appeared to do just that, zooming to an altitude just above 50 miles and giving Branson and his five crewmates about three minutes of weightlessness and spectacular views of Earth before plunging back into the atmosphere for a spiraling descent to touchdown at Virgin's New Mexico launch site. I have dreamt of this moment since I was a kid but honestly, nothing could prepare you for the view of Earth from space,Branson, 70, said after landing, at a rare loss for words. It was just magical.... I'm just taking it all in, it's unreal.";
char chunk[28]; //28bytes is the maximum payload size for NRF24 Radiohead library

char chunk_message(char *message, int chunks, int counter, int last_chunk);

void setup() {
  
  Serial.begin(9600);
}

void loop() {

  Serial.println(dummy_text);
  int text_size = strlen(dummy_text);

  int chunks = text_size / 28; //how many chunks will be the text divided into

  int last_chunk = text_size % chunks; //how many bytes are left in the last chunk

  //break the message taking into account how many chunks are needed 
  for(int i = 0; i <= chunks; i++){
    
    chunk_message(dummy_text, chunks, i, last_chunk);
    Serial.print(i);
    Serial.print(": ");
    Serial.println(chunk);
  }   
  
  delay(10000);
  
}


/* This functions breaks a large array into chunks of 28 bytes, taking into account
 * the counter given by the for loop that is calling this function
 *  
 * arguments: 1) large array
 *            2) how many chunks will the large array be divided into
 *            3) in which chunk of the array are we right now
 *            4) how many bytes has the last chunk
 *            
 * returns: 28 bytes array so it can be send with the Radiohead library 
 */
char chunk_message(char *message, int chunks, int counter, int last_chunk){

  int i = 0;

  //this means we are ar the final chunk, so we use the last_chunk variable
  if(counter == chunks){
    
    for(i = counter * 28; i <= (counter * 28) + last_chunk; i++){
      
      chunk[i - (counter * 28)] = message[i];
    }
  }
  else{
    //iterate the large array from the beggining
    for(i = 0 + (counter * 28); i < 28 + (counter * 28); i++){
 
      chunk[i - (counter * 28)] = message[i];
    }
  }

  return 0;
}
