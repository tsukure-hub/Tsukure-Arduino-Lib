/*

	CyberDynamic-NEO

*/

#include "Arduino.h"

#include "CyberDynamic-NEO.h"
#include <FastLED.h>

#define NEOLED_DATA_PIN 5	// LED Data Pin


CyberDynamic_NEO::CyberDynamic_NEO(bool isDebug, int thisLEDCount)
{
	// Set Debug Mode
	isDebug = isDebug;
	LEDCount = thisLEDCount;
	NEOLEDS = new CRGB[LEDCount];	

	// tell FastLED about the LED strip configuration
	FastLED.addLeds< LED_DRIVER, NEOLED_DATA_PIN, COLOR_ORDER >(NEOLEDS, LEDCount).setCorrection(TypicalLEDStrip);
	//FastLED.addLeds<LED_DRIVER,NEOLED_DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

	// set master brightness control
	FastLED.setBrightness(0);	
}

void CyberDynamic_NEO::Init(void)
{
	
}


// Do NEO LED Loop Stuff

void CyberDynamic_NEO::Loop(void)
{


  if (CurrentFX == FX_Off)
  {
      FastLED.setBrightness(0);
      FastLED.show();  
      // insert a delay to keep the framerate modest
      FastLED.delay(1000 / FRAMES_PER_SECOND); 
  }
  else
  {
      FastLED.setBrightness(MAX_BRIGHTNESS);
      
      // Colours
      if (CurrentFX == FX_On)
      {
         for( int i = 0; i < LEDCount; i++) {
            NEOLEDS[i] = CurrentColour;
         }
      }
      else
      {
        switch (CurrentFX)
        {
			case FX_Vortex:
			
				// EVERY_N_SECONDS( 2 ) { nextPattern(); } // change patterns periodically
				Vortex();
				break;

			default:
				FastLED.setBrightness(MAX_BRIGHTNESS);
				break;
				
        }
      }

      // send the 'leds' array out to the actual LED strip
      FastLED.show();  
      // insert a delay to keep the framerate modest
      FastLED.delay(1000 / FRAMES_PER_SECOND); 
     
         
  }	
}


// Basic Methods

void CyberDynamic_NEO::SelectFX(byte thisFX) // rotating "base color" used by many of the patterns
{
	CurrentFX	= thisFX;
}

int CyberDynamic_NEO::CurrentFX()
{
	return CurrentFX;
}


void CyberDynamic_NEO::SetColour(CRGB thisColour) // rotating "base color" used by MOST of the patterns
{
	CurrentColour = thisColour;
}

void CyberDynamic_NEO::SetHue(uint8_t thisHue) // Global Hue State
{
	CurrentHue = thisHue;
}

void CyberDynamic_NEO::SetRainbow(bool IsRainbow)
{
	IsRainbow = IsRainbow;
}

CRGB CyberDynamic_NEO::SelectColour(CRGB thisCurrentColour)
{
	if (IsRainbow)
	{
		return thisCurrentColour += CHSV( CurrentHue + random8(64), 200, 255);
	}
	else
	{
		return CurrentColour;
	}
	
}


// FX
void CyberDynamic_NEO::Stars()
{
	FXF_Stars(NEOPROBABLILITY);
}

void CyberDynamic_NEO::Wind()
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( NEOLEDS, LEDCount, FADEBY_MS / 2);
  
  int pos = random16(NEOLEDS);
  
  NEOLEDS[pos] = SelectColour(NEOLEDS[pos]);
  
}

void CyberDynamic_NEO::Whirl()
{
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( NEOLEDS, LEDCount, FADEBY_MS);
  
  byte dothue = 0;
  
  for( int i = 0; i <= 4; i++) {
	if (IsRainbow)
	{
	  NEOLEDS[beatsin16( i + 4, 0, LEDCount - 1 )] |= CHSV(dothue, 200, 255);
	}
	else
	{
	  NEOLEDS[beatsin16( i + 4, 0, LEDCount - 1 )] = CurrentColour;
	}

	dothue += 32;
  }
	
}

void CyberDynamic_NEO::Follow()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( NEOLEDS, LEDCount, FADEBY_MS);
  
  int pos = beatsin16( (LEDCount / 2), 0, LEDCount - 1 );

  if (IsRainbow)
  {
    NEOLEDS[pos] += CHSV( CurrentHue, 255, 192);
  }
  else
  {
    NEOLEDS[pos] = CurrentColour;
  }
	
}

void CyberDynamic_NEO::FadeIn()
{
	float r, g, b;
      
	for(int k = 0; k < 256; k=k+1) { 
		r = ( k / 256.0) * CurrentColour.red;
		g = (k / 256.0) * CurrentColour.green;
		b = (k / 256.0) * CurrentColour.blue;
		setAll(r, g, b);
		FastLED.show();
	}

}

void CyberDynamic_NEO::FadeOut()
{
	float r, g, b;

	for(int k = 255; k >= 0; k=k-2) {
		r = (k / 256.0) * CurrentColour.red;
		g = (k / 256.0) * CurrentColour.green;
		b = (k / 256.0) * CurrentColour.blue;
		setAll(r, g, b);
		FastLED.show();
	}
	
}


void CyberDynamic_NEO::Rainbow() 
{
  // FastLED's built-in rainbow generator
  fadeToBlackBy( NEOLEDS, LEDCount, FADEBY_MS);
  fill_rainbow( NEOLEDS, LEDCount, CurrentHue, ( LEDCount / 4 ) /* Delta Hue between NEOLEDS */ );
}

void CyberDynamic_NEO::RainbowStars() 
{
  fadeToBlackBy( NEOLEDS, LEDCount, FADEBY_MS);
  Rainbow();
  Stars();
}


void CyberDynamic_NEO::FadeInOut() 
{
	// FadeInOut - Color (red, green. blue)
	FXF_FadeInOut(CurrentColour.red, CurrentColour.green, CurrentColour.blue); // red

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::Strobe() 
{
	// Strobe - Color (red, green, blue), number of flashes, flash speed, end pause
	FXF_Strobe(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 10, 50, 1000);

	FXF_UpdateRainbow(FADEBY_MS);

}

void CyberDynamic_NEO::CylonBounce() 
{
	// CylonBounce - Color (red, green, blue), eye size, speed delay, end pause
	FXF_CylonBounce(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 4, 10, 50);

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::NewKITT() 
{
	// NewKITT - Color (red, green, blue), eye size, speed delay, end pause
	FXF_NewKITT(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 4, 10, 50);

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::Twinkle() 
{
	// Twinkle - Color (red, green, blue), count, speed delay, only one twinkle (true/false) 
	FXF_Twinkle(CurrentColour.red, CurrentColour.green, CurrentColour.blue, (LEDCount / 2), 100, false);

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::TwinkleRandom() 
{
	// TwinkleRandom - twinkle count, speed delay, only one (true/false)
	FXF_TwinkleRandom((LEDCount / 2), 100, false);	
}

void CyberDynamic_NEO::Sparkle() 
{
	// Sparkle - Color (red, green, blue), speed delay
	FXF_Sparkle(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 0);
}

void CyberDynamic_NEO::SnowSparkle() 
{
	// SnowSparkle - Color (red, green, blue), sparkle delay, speed delay
	FXF_SnowSparkle(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 20, random(100,1000));

	FXF_UpdateRainbow(10);
}

void CyberDynamic_NEO::RunningLights() 
{
	// Running Lights - Color (red, green, blue), wave dealy
	FXF_RunningLights(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 50);  // red

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::colorWipe() 
{
	// colorWipe - Color (red, green, blue), speed delay
	FXF_colorWipe(CurrentColour.red, CurrentColour.green, CurrentColour.blue, 50);

	FXF_UpdateRainbow(FADEBY_MS);	
}

void CyberDynamic_NEO::theatherChase() 
{
	// theatherChase - Color (red, green, blue), speed delay
	FXF_theaterChase(CurrentColour.red, CurrentColour.green, CurrentColour.blue,50);

	FXF_UpdateRainbow(10);
}

void CyberDynamic_NEO::Fire() 
{
	// Fire - Cooling rate, Sparking rate, speed delay
	FXF_Fire(55, 120, 15);
}

void CyberDynamic_NEO::BouncingBalls() 
{
	// mimic BouncingBalls
	byte onecolor[1][3] = { {CurrentColour.red, CurrentColour.green, CurrentColour.blue} };
	FXF_BouncingColoredBalls(1, onecolor, false);

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::BouncingColoredBalls() 
{
	// multiple colored balls
	byte colors[3][3] = { {CurrentColour.red, CurrentColour.green, CurrentColour.blue}, 
						  {CurrentColour.red, CurrentColour.green, CurrentColour.blue}, 
						  {CurrentColour.red, CurrentColour.green, CurrentColour.blue} };
	FXF_BouncingColoredBalls((LEDCount / 4), colors, false);

	FXF_UpdateRainbow(FADEBY_MS);
}

void CyberDynamic_NEO::meteorRain() 
{
	// meteorRain - Color (red, green, blue), meteor size, trail decay, random trail decay (true/false), speed delay 
	FXF_meteorRain(CurrentColour.red, CurrentColour.green, CurrentColour.blue,10, 64, true, FADEBY_MS);
	FXF_UpdateRainbow(FADEBY_MS);
	
}




void CyberDynamic_NEO::Hazard()
{
    CRGB thisColour = CRGB::DarkOrange;

    if (HazardColour == 1) 
    {
      thisColour = CRGB::DarkOrange;
      HazardColour = 0;
    }
    else 
    {
      thisColour = CRGB::White;
      HazardColour = 1;
    }
  
    for( int i = 0; i < LEDCount; i++) {
      NEOLEDS[i] = thisColour;
    }
  
    FastLED.setBrightness(100);
    FastLED.show();    
    delay(10);
	
    FastLED.setBrightness(0);
    FastLED.show();    
    delay(100);
	
    FastLED.setBrightness(100);
    FastLED.show();    
    delay(10);
	
    FastLED.setBrightness(0);
    FastLED.show();    
    delay(600);
	
}

void CyberDynamic_NEO::Police()
{
    CRGB thisColour = CRGB::Red;

    if (HazardColour == 0) 
    {
      delay(300);
      thisColour = CRGB::Red;
      HazardColour = 1;
    }
    else if (HazardColour == 1) 
    {
      delay(300);
      thisColour = CRGB::Blue;
      HazardColour = 2;
    }
    else
    {
      thisColour = CRGB::Blue;
      HazardColour = 0;
    }
  
    for( int i = 0; i < (LEDCount / 4); i++) {
      NEOLEDS[i] = thisColour;
    }
    for( int i = (LEDCount / 4); i < LEDCount; i++) {
		if (HazardColour == 1) 
		{
		  NEOLEDS[i] = CRGB::Blue;
		}
		else if (HazardColour == 2) {
		  NEOLEDS[i] = CRGB::Blue;
		}
		else 
		{
		  NEOLEDS[i] = CRGB::Red;
		}
    }
  
    FastLED.setBrightness(100);
    FastLED.show();    

    delay(50);
    FastLED.setBrightness(0);
    FastLED.show();   
	
    if (HazardColour == 1) 
    {
      delay(100);
    }
    else
    {
      delay(25);
    }

    FastLED.setBrightness(100);
    FastLED.show();    
    
	if (HazardColour == 1) 
    {
      delay(50);
    }
    else
    {
      delay(25);
    }

    FastLED.setBrightness(0);
    FastLED.show();    

    delay(100);
    	
}

// FX Functions

void CyberDynamic_NEO::FXF_Stars(int thisProbability)
{
  fadeToBlackBy( NEOLEDS, LEDCount, FADEBY_MS);

  if( random8() < thisProbability) {
    NEOLEDS[ random16(LEDCount) ] = CurrentColour;
  }	
}



void CyberDynamic_NEO::FXF_FadeInOut(byte red, byte green, byte blue)
{
	
	float r, g, b;
	  
	for(int k = 0; k < 256; k=k+1) { 
		r = (k/256.0)*red;
		g = (k/256.0)*green;
		b = (k/256.0)*blue;
		setAll(r,g,b);
		FastLED.show();

		}
	 
	for(int k = 255; k >= 0; k=k-2) {
		r = (k/256.0)*red;
		g = (k/256.0)*green;
		b = (k/256.0)*blue;
		setAll(r,g,b);
		FastLED.show();

	}

}


void CyberDynamic_NEO::FXF_Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause)
{
	
	for(int j = 0; j < StrobeCount; j++) 
	{
		setAll(red,green,blue);
		FastLED.show();
		delay(FlashDelay);
	
		setAll(0,0,0);
		FastLED.show();
		delay(FlashDelay);
   } 
 
   delay(EndPause);
 
}

void CyberDynamic_NEO::FXF_CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay){

  for(int i = 0; i < LEDCount - EyeSize - 2; i++) 
  {
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
	
    FastLED.show();
    delay(SpeedDelay);
  }

  delay(ReturnDelay);

  for(int i = LEDCount - EyeSize - 2; i > 0; i--) 
  {
    setAll(0, 0, 0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    FastLED.show();
    delay(SpeedDelay);
  }
  
  delay(ReturnDelay);
}


void CyberDynamic_NEO::FXF_NewKITT(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay)
{
  FXF_RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_LeftToRight(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_RightToLeft(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_OutsideToCenter(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
  FXF_CenterToOutside(red, green, blue, EyeSize, SpeedDelay, ReturnDelay);
}



// used by NewKITT
void CyberDynamic_NEO::FXF_CenterToOutside(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
{
  for(int i =((LEDCount-EyeSize)/2); i>=0; i--) {
    setAll(0,0,0);
    
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    
    setPixel(LEDCount-i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(LEDCount-i-j, red, green, blue); 
    }
    setPixel(LEDCount-i-EyeSize-1, red/10, green/10, blue/10);
    
    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

// used by NewKITT
void CyberDynamic_NEO::FXF_OutsideToCenter(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
{
  for(int i = 0; i<=((LEDCount-EyeSize)/2); i++) {
    setAll(0,0,0);
    
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    
    setPixel(LEDCount-i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(LEDCount-i-j, red, green, blue); 
    }
    setPixel(LEDCount-i-EyeSize-1, red/10, green/10, blue/10);
    
    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

// used by NewKITT
void CyberDynamic_NEO::FXF_LeftToRight(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
{
  for(int i = 0; i < LEDCount-EyeSize-2; i++) {
    setAll(0,0,0);
    setPixel(i, red/10, green/10, blue/10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i+j, red, green, blue); 
    }
    setPixel(i+EyeSize+1, red/10, green/10, blue/10);
    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}

// used by NewKITT
void CyberDynamic_NEO::FXF_RightToLeft(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay) 
{
  for(int i = LEDCount - EyeSize - 2; i > 0; i--) 
  {
    setAll(0,0,0);
    setPixel(i, red / 10, green / 10, blue / 10);
    for(int j = 1; j <= EyeSize; j++) {
      setPixel(i + j, red, green, blue); 
    }
    setPixel(i + EyeSize + 1, red / 10, green / 10, blue / 10);
    FastLED.show();
    delay(SpeedDelay);
  }
  delay(ReturnDelay);
}


void CyberDynamic_NEO::FXF_Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne) 
{
  setAll(0, 0, 0);
  
  for (int i = 0; i < Count; i++) {
     setPixel(random(LEDCount), red, green, blue);
     FastLED.show();
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(0, 0, 0); 
     }
   }
  
  delay(SpeedDelay);
}


void CyberDynamic_NEO::FXF_TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne) {
  setAll(0,0,0);
  
  for (int i = 0; i < Count; i++) {
     setPixel(random(LEDCount), random(0,255), random(0,255), random(0,255));
     FastLED.show();
     delay(SpeedDelay);
     if(OnlyOne) { 
       setAll(0, 0, 0); 
     }
   }
  
  delay(SpeedDelay);
}


void CyberDynamic_NEO::FXF_Sparkle(byte red, byte green, byte blue, int SpeedDelay) 
{
  int Pixel = random(LEDCount);
  setPixel(Pixel, red, green, blue);
  FastLED.show();
  delay(SpeedDelay);
  setPixel(Pixel, 0, 0, 0);
}


void CyberDynamic_NEO::FXF_SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay) 
{
  setAll(red,green,blue);
  
  int Pixel = random(LEDCount);
  setPixel(Pixel,0xff,0xff,0xff);
  FastLED.show();
  delay(SparkleDelay);
  setPixel(Pixel,red,green,blue);
  FastLED.show();
  delay(SpeedDelay);
}

void CyberDynamic_NEO::FXF_RunningLights(byte red, byte green, byte blue, int WaveDelay) 
{
  int Position = 0;
  
  for(int i = 0; i < (LEDCount / 4); i++)
  {
      Position++; // = 0; //Position + Rate;
      for(int i = 0; i < LEDCount; i++) 
	  {
        // sine wave, 3 offset waves make a rainbow!
        //float level = sin(i+Position) * 127 + 128;
        //setPixel(i,level,0,0);
        //float level = sin(i+Position) * 127 + 128;
        setPixel(i,((sin(i + Position) * 127 + 128) / 255) * red,
                   ((sin(i + Position) * 127 + 128) / 255) * green,
                   ((sin(i + Position) * 127 + 128) / 255) * blue);
      }
      
      FastLED.show();
      delay(WaveDelay);
  }
}

void CyberDynamic_NEO::FXF_colorWipe(byte red, byte green, byte blue, int SpeedDelay) 
{

  if (ColourWipeFull == false)
  {
    for(uint16_t i = 0; i < LEDCount; i++) 
	{
        setPixel(i, red, green, blue);
        FastLED.show();
        delay(SpeedDelay);
    }
    ColourWipeFull = true;
  }
  else
  {
    for(uint16_t i = (LEDCount - 1); i > 0; i--) 
	{
        setPixel(i, 0x00, 0x00, 0x00);
        FastLED.show();
        delay(SpeedDelay);
    }
    ColourWipeFull = false;
  }
}


// used by rainbowCycle and theaterChaseRainbow
byte * CyberDynamic_NEO::FXF_Wheel(byte WheelPos) 
{
  static byte c[3];
  
  if(WheelPos < 85) {
   c[0] = WheelPos * 3;
   c[1] = 255 - WheelPos * 3;
   c[2] = 0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0] = 255 - WheelPos * 3;
   c[1] = 0;
   c[2] = WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0] = 0;
   c[1] = WheelPos * 3;
   c[2] = 255 - WheelPos * 3;
  }

  return c;
}


void CyberDynamic_NEO::FXF_theaterChase(byte red, byte green, byte blue, int SpeedDelay) 
{
  for (int j=0; j< (LEDCount / 4); j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < LEDCount; i=i+3) {
        setPixel(i+q, red, green, blue);    //turn every third pixel on
      }
      FastLED.show();
     
      delay(SpeedDelay);
     
      for (int i=0; i < LEDCount; i=i+3) {
        setPixel(i+q, 0,0,0);        //turn every third pixel off
      }
    }
  }
}


void CyberDynamic_NEO::FXF_Fire(int Cooling, int Sparking, int SpeedDelay) 
{
  byte heat[LEDCount];
  int cooldown;
  
  // Step 1.  Cool down every cell a little
  for( int i = 0; i < LEDCount; i++) {
    cooldown = random(0, ((Cooling * 10) / LEDCount) + 2);
    
    if(cooldown > heat[i]) {
      heat[i] = 0;
    } else {
      heat[i] = heat[i] - cooldown;
    }
  }
  
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k = LEDCount - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
    
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] = heat[y] + random(160,255);
    //heat[y] = random(160,255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < LEDCount; j++) {
    FXF_setPixelHeatColor(j, heat[j] );
  }

  FastLED.show();
  delay(SpeedDelay);
}

void CyberDynamic_NEO::FXF_setPixelHeatColor (int Pixel, byte temperature) 
{
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
 
  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
		setPixel(Pixel, 255, 255, heatramp);
  } else if( t192 > 0x40 ) {             // middle
		setPixel(Pixel, 255, heatramp, 0);
  } else {                               // coolest
		setPixel(Pixel, heatramp, 0, 0);
  }
}


void CyberDynamic_NEO::FXF_BouncingColoredBalls(int BallCount, byte colors[][3], boolean continuous) 
{
  float Gravity = -9.81;
  int StartHeight = 1;
  
  float Height[BallCount];
  float ImpactVelocityStart = sqrt( -2 * Gravity * StartHeight );
  float ImpactVelocity[BallCount];
  float TimeSinceLastBounce[BallCount];
  int   Position[BallCount];
  long  ClockTimeSinceLastBounce[BallCount];
  float Dampening[BallCount];
  boolean ballBouncing[BallCount];
  boolean ballsStillBouncing = true;
  
  for (int i = 0 ; i < BallCount ; i++) {   
    ClockTimeSinceLastBounce[i] = millis();
    Height[i] = StartHeight;
    Position[i] = 0; 
    ImpactVelocity[i] = ImpactVelocityStart;
    TimeSinceLastBounce[i] = 0;
    Dampening[i] = 0.90 - float(i)/pow(BallCount,2);
    ballBouncing[i]=true; 
  }

  while (ballsStillBouncing) {
    for (int i = 0 ; i < BallCount ; i++) {
      TimeSinceLastBounce[i] =  millis() - ClockTimeSinceLastBounce[i];
      Height[i] = 0.5 * Gravity * pow( TimeSinceLastBounce[i]/1000 , 2.0 ) + ImpactVelocity[i] * TimeSinceLastBounce[i]/1000;
  
      if ( Height[i] < 0 ) {                      
        Height[i] = 0;
        ImpactVelocity[i] = Dampening[i] * ImpactVelocity[i];
        ClockTimeSinceLastBounce[i] = millis();
  
        if ( ImpactVelocity[i] < 0.01 ) {
          if (continuous) {
            ImpactVelocity[i] = ImpactVelocityStart;
          } else {
            ballBouncing[i]=false;
          }
        }
      }
      Position[i] = round( Height[i] * (LEDCount - 1) / StartHeight);
    }

    ballsStillBouncing = false; // assume no balls bouncing
    for (int i = 0 ; i < BallCount ; i++) {
      setPixel(Position[i],colors[i][0],colors[i][1],colors[i][2]);
      if ( ballBouncing[i] ) {
        ballsStillBouncing = true;
      }
    }
    
    FastLED.show();
    setAll(0,0,0);
  }
}

void CyberDynamic_NEO::FXF_meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay) 
{  
  setAll(0, 0, 0);
  
  for(int i = 0; i < LEDCount + LEDCount; i++) 
  {
    
    // fade brightness all LEDs one step
    for(int j = 0; j < LEDCount; j++) {
      if( (!meteorRandomDecay) || (random(10) > 5) ) {
        fadeToBlack(j, meteorTrailDecay );        
      }
    }
    
    // draw meteor
    for(int j = 0; j < meteorSize; j++) {
      if( ( i - j < LEDCount) && (i - j >= 0) ) {
        setPixel(i - j, red, green, blue);
      } 
    }
   
    FastLED.show();
    delay(SpeedDelay);
  }
}


void CyberDynamic_NEO::FXF_UpdateRainbow(int thisAmount)
{
	if (IsRainbow){
		CurrentHue+=thisAmount; 
		
		if (CurrentHue > 255) CurrentHue = 0;
		CurrentColour = CHSV( CurrentHue, 255, 192);
	}

}




// Randomize FX
void CyberDynamic_NEO::Vortex()
{
	
}

// Cyclic FX
void CyberDynamic_NEO::NextFX()
{
	if (CurrentFX >= FX_Count)	CurrentFX = 1;
	else CurrentFX++;
}

void CyberDynamic_NEO::PreviousFX()
{
	if (CurrentFX <= 1) CurrentFX = FX_Count;
	else CurrentFX--;
}

// FX Support Methods

void CyberDynamic_NEO::UpdateColourCycle(void)
{
	CurrentHue++;
	
    if (CurrentHue > 255) CurrentHue = 0;

    if (IsRainbow){
        CurrentColour = CHSV( CurrentHue, 255, 192);
    }
	
}

// Set all LEDs to a given color and apply it (visible)
void CyberDynamic_NEO::setAll(byte red, byte green, byte blue) {
	
	for(int i = 0; i < LEDCount; i++ ) {
		setPixel(i, red, green, blue); 
	}
	
	FastLED.show();
}

// Set a LED color (not yet visible)
void CyberDynamic_NEO::setPixel(int Pixel, byte red, byte green, byte blue) {

   // FastLED
   NEOLEDS[Pixel].r = red;
   NEOLEDS[Pixel].g = green;
   NEOLEDS[Pixel].b = blue;
}




// used by meteorrain
void CyberDynamic_NEO::fadeToBlack(int ledNo, byte fadeValue) 
{
   NEOLEDS[ledNo].fadeToBlackBy( fadeValue );
}


