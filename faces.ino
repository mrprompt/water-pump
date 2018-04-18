void drawSadFace()
{
  byte nf[8]= {B00111100,B01000010,B10100101,B10000001,B10011001,B10100101,B01000010,B00111100};

  draw(nf);
}

void drawHappyFace()
{
  byte nf[8]= {B00111100,B01000010,B10100101,B10000001,B10100101,B10011001,B01000010,B00111100};

  draw(nf);
}

void drawNeutralFace()
{
  byte nf[8]={B00111100,B01000010,B10100101,B10000001,B10111101,B10000001,B01000010,B00111100};
  
  draw(nf);
}

void drawScaredFace()
{
  byte nf[8]={B00111100,B01000010,B10100101,B10011001,B10100101,B10100101,B01011010,B00111100};
  
  draw(nf);
}

void drawHearth()
{
  byte nf[8]={B00000000,B01100110,B11111111,B11111111,B01111110,B00111100,B00011000,B00000000};
  
  draw(nf);
}

void drawFull()
{
  byte nf[8]={B11111111,B11000011,B10100101,B10011001,B10011001,B10100101,B11000011,B11111111};
  
  draw(nf);
}

void draw(byte* nf)
{
  lc.setRow(0,0,nf[0]);
  lc.setRow(0,1,nf[1]);
  lc.setRow(0,2,nf[2]);
  lc.setRow(0,3,nf[3]);
  lc.setRow(0,4,nf[4]);
  lc.setRow(0,5,nf[5]);
  lc.setRow(0,6,nf[6]);
  lc.setRow(0,7,nf[7]);
}

