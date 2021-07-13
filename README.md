# Arduino-chunk-28bytes
This code takes an array and break it in chunks of 28bytes, so they can be  send via RF with an NRF24L01+ module. The idea is to use the ESP32-CAM board and apply this code to the very large buffer generated when taking an image, and then, send the image to a different microcontroller via RF.
