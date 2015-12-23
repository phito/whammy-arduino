#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const float TEMPO = 120;
const float DELAY = 60 / TEMPO / 4 * 1000;
const float MIN_TREADLE = 0;
const float MAX_TREADLE = 125;
const int LED = 13;

void setup() 
{
  pinMode(LED, OUTPUT);
  MIDI.begin();
}

void loop() 
{
  motp();
}

void down()
{
  MIDI.sendProgramChange(7, 1);
  MIDI.sendControlChange(11, MAX_TREADLE, 1);
  delay(DELAY);
}

void normal()
{
  MIDI.sendControlChange(11, MIN_TREADLE, 1);
  delay(DELAY);
}

void up()
{
  MIDI.sendProgramChange(1, 1);
  MIDI.sendControlChange(11, MAX_TREADLE, 1);
  delay(DELAY);
}

// MUSE - Map of the Problematique
void motp()
{
  digitalWrite(LED, HIGH);
  down();
  digitalWrite(LED, LOW);
  normal();
  up();
  normal();
  up();
  normal();
  down();
  normal();
  up();
  normal();
  up();
  normal();
  down(); 
  normal();
  up();
  normal();
}

